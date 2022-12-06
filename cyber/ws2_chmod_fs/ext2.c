#define _XOPEN_SOURCE 500

#include <fcntl.h>  /*open*/
#include <stdio.h>  /*malloc , printf*/
#include <stdlib.h> /*free*/
#include <unistd.h> /*fread ,pread*/
#include <string.h> /*strchr*/

#include "ext2_fs.h"
#include "ext2.h"

#define BOOT_BLOCK 1024
#define PATH_SIGN "/"
#define END_OF_FILE 0
#define SUPER_BLOCK_SIZE sizeof(super_block_t)
#define GROUP_DESC_SIZE sizeof(group_desc_t)

typedef struct ext2_super_block super_block_t;
typedef struct ext2_group_desc group_desc_t;
typedef struct ext2_inode inode_t;
typedef struct ext2_dir_entry_2 dir_t;

size_t block_size = 0;
int file_discriptor_key = 0;

super_block_t super;
group_desc_t group;

static int DeviceOpen(const char *device)
{
    /*add assert*/
    file_discriptor_key = open(device, O_RDWR);
    if (0 > file_discriptor_key)
    {
        perror(device);
        exit(1); /* error while opening the device */
    }
    return 0;
}
/*
static void MetaDataPrint(void)
{
    printf("Reading super-block from device \n"
           "Inodes count            : %u\n"
           "Blocks count            : %u\n"
           "Reserved blocks count   : %u\n"
           "Free blocks count       : %u\n"
           "Free inodes count       : %u\n"
           "First data block        : %u\n"
           "Blocks per group        : %u\n"
           "Inodes per group        : %u\n"
           "Creator OS              : %u\n"
           "First non-reserved inode: %u\n"
           "Size of inode structure : %hu\n",
           super.s_inodes_count,
           super.s_blocks_count,
           super.s_r_blocks_count,
           super.s_free_inodes_count,
           super.s_free_blocks_count,
           super.s_first_data_block,
           super.s_blocks_per_group,
           super.s_inodes_per_group,
           super.s_creator_os,
           super.s_first_ino,
           super.s_inode_size);

    printf("Reading first group-descriptor from device \n"
           "Blocks bitmap block: %u\n"
           "Inodes bitmap block: %u\n"
           "Inodes table block : %u\n"
           "Free blocks count  : %u\n"
           "Free inodes count  : %u\n"
           "Directories count  : %u\n",
           group.bg_block_bitmap,
           group.bg_inode_bitmap,
           group.bg_inode_table,
           group.bg_free_blocks_count,
           group.bg_free_inodes_count,
           group.bg_used_dirs_count);
}
*/
/*
static void InodePrinter(inode_t * inode)
{
    size_t i = 0;
    printf("\nReading inode\n"
        "File mode: %hu\n"
        "Owner UID: %hu\n"
        "Size     : %u bytes\n"
        "Blocks   : %u\n"
        ,
        inode -> i_mode,
        inode -> i_uid,
        inode -> i_size,
        inode -> i_blocks);

    for(i=0; i<EXT2_N_BLOCKS; i++)
        if (i < EXT2_NDIR_BLOCKS)
            printf("Block  : %u\n", inode -> i_block[i]);
        else if (i == EXT2_IND_BLOCK)
            printf("Single   : %u\n", inode -> i_block[i]);
        else if (i == EXT2_DIND_BLOCK)
            printf("Double   : %u\n", inode -> i_block[i]);
        else if (i == EXT2_TIND_BLOCK)
            printf("Triple   : %u\n", inode -> i_block[i]);
}*/

static int InodeReader(inode_t *inode, int inode_number)
{
    return pread(file_discriptor_key, inode, sizeof(inode_t),
                 (block_size * group.bg_inode_table) + ((inode_number - 1) * super.s_inode_size));
}

static int InodeWriter(inode_t *inode, int inode_number)
{
    return pwrite(file_discriptor_key, inode, sizeof(inode_t),
                  (block_size * group.bg_inode_table) + ((inode_number - 1) * super.s_inode_size));
}

static int GetInodeFromName(int directory, char *path)
{
    int return_inode = 0;
    dir_t *dir = NULL;
    char *runner = NULL;
    char *buffer = (char *)malloc(block_size);

    path = 1 + strstr(path, PATH_SIGN);
    if ((char *)1 == path)
    {
        printf("Invalid Input!\n");
        free(buffer);
        return -1;
    }

    pread(file_discriptor_key, buffer, block_size, directory * block_size);

    runner = buffer;
    dir = (dir_t *)runner;

    while (0 != strncmp(dir->name, path, dir->name_len) && EXT2_FT_UNKNOWN != dir->file_type)
    {
        write(1, dir->name, dir->name_len);
        write(1, "\n", 1);
        runner += dir->rec_len;
        dir = (dir_t *)runner;
    }

    if (EXT2_FT_UNKNOWN == dir->file_type)
    {
        printf("Invalid Input!\n");
        free(buffer);
        return -1;
    }

    return_inode = dir->inode;

    free(buffer);
    return return_inode;
}

/******************************************************************************/

int OpenFile(const char *device, const char *path)
{
    inode_t inode;

    DeviceOpen(device);
    pread(file_discriptor_key, &super, SUPER_BLOCK_SIZE, BOOT_BLOCK);
    block_size = 1024 << super.s_log_block_size;
    pread(file_discriptor_key, &group, GROUP_DESC_SIZE, block_size);
    /*MetaDataPrint();*/

    InodeReader(&inode, EXT2_ROOT_INO);
    return GetInodeFromName(inode.i_block[0], (char *)path);
}

void *ReadBytes(const int inode_num, void *buffer, const size_t bytes_to_read)
{
    inode_t inode;
    size_t i = 0;
    size_t left_bytes = bytes_to_read;
    char *runner = buffer;

    InodeReader(&inode, inode_num);
    do
    {
        pread(file_discriptor_key, runner, left_bytes % block_size, inode.i_block[i] * block_size);
        runner += block_size;
        left_bytes -= block_size;
        ++i;
    } while (left_bytes > block_size && 12 != i);

    return buffer;
}

void *Read(const int inode_num, void *buffer)
{
    inode_t inode;
    InodeReader(&inode, inode_num);
    ReadBytes(inode_num, buffer, inode.i_size);

    return buffer;
}

void ReadBytesToBit(const int inode_num, unsigned short chmod_num)
{
    inode_t inode;

    InodeReader(&inode, inode_num);
    printf("before\n");
    printf("%o", inode.i_mode);
    printf("\t-u--g--o-\n\trwxrwxrwx\n");
    printf(" %b\n", inode.i_mode);
    /*change to 777 33279*/
    /*no write 555 -> 33133*/
    if (777 == chmod_num)
    {
        inode.i_mode = (unsigned short)33279;
    }
    if (555 == chmod_num)
    {
        inode.i_mode = (unsigned short)33133;
    }
    InodeWriter(&inode, inode_num);
    InodeReader(&inode, inode_num);
    printf("after\n");
    printf("%o", inode.i_mode);
    printf("\t-u--g--o-\n\trwxrwxrwx\n");
    printf(" %b\n", inode.i_mode);
}