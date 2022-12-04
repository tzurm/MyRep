#include <stdio.h>  /*printf*/
#include <stdlib.h> /*exit*/
#include <fcntl.h>  /*open*/
#include <unistd.h> /*close, read*/
#include <string.h> /*trncmp*/

#include "ext2.h"

#define BLOCK_SIZE 4096
#define SUPER_BLOCK_OFFSET 1024
#define SUPER_BLOCK_SIZE 1024
#define GROUP_DESCRIPTOR_OFFSET 4096
#define GROUP_DESCRIPTOR_SIZE 32
#define INODE_TABLE_OFFSET (4096 * 3)
#define INODE_SIZE 256
#define BLOCK_OFFSET(num) ((num)*4096)

/*get the disk memory at the begin and go to the offset
where the super block address*/

super_block_t *GetSuperBlock(const char *device_path)
{
    int fd = 0;
    super_block_t *super_block_struct = (super_block_t *)malloc(sizeof(super_block_t));
    if (NULL == super_block_struct)
    {
        return NULL;
    }

    if ((fd = open(device_path, O_RDONLY)) < 0)
    {
        perror(device_path);
        printf("error in opening the file\n");
        exit(1); /* error while opening the device */
    }
    /*this moves the pointer 1024 positions ahead from the current position in the file*/
    lseek(fd, SUPER_BLOCK_OFFSET, SEEK_CUR);
    read(fd, super_block_struct, SUPER_BLOCK_SIZE);
    close(fd);

    return super_block_struct;
}

void PrintSuperBlock(super_block_t *super_block)
{
    printf("Reading super-block from device ram0 :\n\n"
           "Inodes count            : %u\n"
           "Blocks count            : %u\n"
           "Reserved blocks count   : %u\n"
           "Free blocks count       : %u\n"
           "Free inodes count       : %u\n"
           "First data block        : %u\n"
           "Block size              : %u\n"
           "Blocks per group        : %u\n"
           "Inodes per group        : %u\n"
           "Creator OS              : %u\n"
           "First non-reserved inode: %u\n"
           "Size of inode structure : %u\n\n\n",
           super_block->s_inodes_count,
           super_block->s_blocks_count,
           super_block->s_r_blocks_count,
           super_block->s_free_blocks_count,
           super_block->s_free_inodes_count,
           super_block->s_first_data_block,
           super_block->s_log_block_size,
           super_block->s_blocks_per_group,
           super_block->s_inodes_per_group,
           super_block->s_creator_os,
           super_block->s_first_ino, /* first non-reserved inode */
           super_block->s_inode_size);
}

group_desc_t *GetGroupDesc(const char *device_path)
{
    int fd = 0;
    group_desc_t *group_descriptor_struct = (group_desc_t *)malloc(sizeof(group_desc_t));
    if (NULL == group_descriptor_struct)
    {
        return NULL;
    }

    if ((fd = open(device_path, O_RDONLY)) < 0)
    {
        perror(device_path);
        printf("error in opening the file\n");
        exit(1); /* error while opening the device */
    }
    /*this moves the pointer 4096 positions ahead from the current position in the file*/
    lseek(fd, GROUP_DESCRIPTOR_OFFSET, SEEK_CUR);
    read(fd, group_descriptor_struct, GROUP_DESCRIPTOR_SIZE);
    close(fd);

    return group_descriptor_struct;
}

void PrintGroupDesc(group_desc_t *group_descriptor)
{
    printf("Reading group_dscriptor from device ram0 :\n\n"
           "Blocks bitmap block            : %u\n"
           "Inodes bitmap block            : %u\n"
           "Inodes table block             : %u\n"
           "Free blocks count              : %u\n"
           "Free inodes count              : %u\n"
           "Directories count              : %u\n",
           group_descriptor->bg_block_bitmap,
           group_descriptor->bg_inode_bitmap,
           group_descriptor->bg_inode_table,
           group_descriptor->bg_free_blocks_count,
           group_descriptor->bg_free_inodes_count,
           group_descriptor->bg_used_dirs_count);
}

inode_t *ReadInode(const int inode_num, const char *device_path)
{
    inode_t *inode_struct = (inode_t *)malloc(sizeof(inode_t));
    int fd = 0;
    
    if (NULL == inode_struct)
    {
        return NULL;
    }

    if ((fd = open(device_path, O_RDONLY)) < 0)
    {
        perror(device_path);
        printf("error in opening the file\n");
        exit(1); /* error while opening the device */
    }
    lseek(fd, (4096*4 + (inode_num - 1) * INODE_SIZE), SEEK_CUR);
    read(fd, inode_struct, sizeof(inode_t));
    close(fd);
    /*int i = 0;

    group_desc_t *group_descriptor = GetGroupDesc(device_path);
    char *inode_tabel_address = ((char *)(group_descriptor)) + 4096 * 3;
*/
    /*for(i = 0; i < 10000000; ++i)
    {
        printf("%u\n", ((char *)inode_struct++));
    }*/
    printf("%u\n", inode_struct->i_block[0]);
    return inode_struct;
}

void PrintInode(inode_t *inode)
{
    int i = 0;
    printf("\n\nReading inode from device ram0 :\n\n"
           "File mode                           : %u\n"
           "Low 16 bits of Owner Uid            : %u\n"
           "Size in bytes                       : %u\n"
           "Access time                         : %u\n"
           "Blocks count                        : %u\n"
           "Pointers to blocks                  : %u\n",
           inode->i_mode,
           inode->i_uid,
           inode->i_size,
           inode->i_atime,
           inode->i_blocks,
           inode->i_block[i]);

    /*for(i = 0; i < 12; ++i)
    {
        printf("%d   %u\n", i, inode -> i_block[i]);
    }*/
}
void Print_entry(entry_t *entry)
{
    printf("\n\nReading enter_t from device ram0 :\n\n"
           "inode num                           : %u\n"
           "directory entry len                 : %u\n"
           "name len                            : %u\n"
           "file name                           : %s\n",

           entry->inode,
           entry->rec_len,
           entry->name_len,
           entry->name);

    /*for(i = 0; i < 12; ++i)
    {
        printf("%d   %u\n", i, entry -> name[i]);
    }*/
}
int FindInDir(const char *file_name, inode_t *inode, const char *device_path)
{
    entry_t *current_block = malloc(4096);
    size_t current_address = BLOCK_OFFSET(inode->i_block[0]);
    int fd = 0;
    if ((fd = open(device_path, O_RDONLY)) < 0)
    {
        perror(device_path);
        printf("error in opening the file\n");
        exit(1); /* error while opening the device */
    }
    lseek(fd, current_address, SEEK_SET);
    read(fd, current_block, sizeof(entry_t));
    /*memcpy(file, current_block -> name, current_block -> name_len);
    file[current_block -> name_len] = 0; */
    printf("%d\n", *(char *)(current_block));
    while (current_block->name)
    {
        if (0 == strncmp(file_name, current_block->name, (size_t)current_block->name_len))
        {
            printf("%ld\n", current_address);
            Print_entry(current_block);
            /*memcpy(file, current_block -> name, current_block -> name_len);
            file[current_block -> name_len] = 0;
            printf("%s\n", file);*/
            return current_block->inode;
        }
        Print_entry(current_block);
        printf("%ld\n", current_address);
        current_address += current_block->rec_len;
        lseek(fd, current_address, SEEK_SET);
        read(fd, current_block, sizeof(entry_t));
    }
    return -1;
}

void PrintFileContent(inode_t *file_inode, const char *device_path)
{
    size_t file_address = BLOCK_OFFSET(file_inode->i_block[0]);
    char file_block[BLOCK_SIZE] = {0};
    int fd = 0;

    if ((fd = open(device_path, O_RDONLY)) < 0)
    {
        perror(device_path);
        printf("error in opening the file\n");
        exit(1); /* error while opening the device */
    }
    lseek(fd, file_address, SEEK_SET);
    read(fd, file_block, BLOCK_SIZE);

    printf("\n\nfile content: %s\n\n", file_block);
}