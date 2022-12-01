#ifndef __FS_PARSING_H__
#define __FS_PARSING_H__
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/types.h>

typedef struct ext2_super_block super_block_t;
typedef struct ext2_group_desc group_desc_t;
typedef struct ext2_dir_entry_2 entry_t;
typedef struct ext2_inode inode_t;

inode_t *ReadInode(const int fd, const int inode_num, inode_t *buffer);
int FindInDir(int fd, const char *file_name, inode_t *inode);
super_block_t *GetSuperBlock(const char *device_path);
group_desc_t *GetGroupDesc(const char *device_path);
void PrintSuperBlock(super_block_t *device_path);
void PrintFileContent(inode_t *file_inode);
void PrintGroupDesc(group_desc_t *group);

#endif
