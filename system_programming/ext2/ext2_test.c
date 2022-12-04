#include <stdio.h>/*printf*/
#include <stdlib.h>/*free*/


#include "ext2.h"
#define SIZE 30
void PrintInode(inode_t *inode);

int main()
{
    char device_path[SIZE] = "/dev/ram0";
    char file_name[SIZE] = "findme.txt";
    super_block_t *super_block = GetSuperBlock(device_path);
    group_desc_t *group_descriptor = GetGroupDesc(device_path);
    inode_t *inode = ReadInode(2, device_path);
    
    PrintSuperBlock(super_block);
    PrintGroupDesc(group_descriptor);
    PrintInode(inode);
    FindInDir(file_name, inode, device_path);
    inode = ReadInode(13, device_path);
    PrintInode(inode);
    PrintFileContent(inode, device_path);
    

    free(super_block);
    return 0;
}