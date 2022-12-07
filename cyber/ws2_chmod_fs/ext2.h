#ifndef __ILRD_CR02_EXT2_SPIDER_H__
#define __ILRD_CR02_EXT2_SPIDER_H__

/*
Description:     
    Receives device & path and opens file. 
Return value:     
    inode num as int. when failure return -1; 
Arguments: 
    device name - path of device (in RAW format)
    path - the requested file path (relate to device root) 
*/
int OpenFile(const char *device, const char *path);

/* 
Description: 
    Reads 'bytes_to_read' bytes from file. 
RV: 
    buffer w/ contents of file
EV: 
    NULL if open operation failed     
Parameters: 
    receives valid inode num, buffer, bytes_to_read 
*/
void *ReadBytes(const int inode_num, void *buffer, const size_t bytes_to_read);

/* 
Description: 
    Reads all bytes from a file. 
Return value: 
    buffer with content of file. Error value: NULL if failed
Parameters: 
    valid inode_num, buffer. 
*/
void *Read(const int inode_num, void *buffer);

void MyChmod(const int inode_num, int chmod_num);

#endif
