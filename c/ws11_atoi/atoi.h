#ifndef __ATOI__
#define __ATOI__


	
void CheckAtoi(char **str, int n);

void CheckItoa(int num , char *buffer, int base);

int Atoi(char* str);

char *Itoa(int num, char *buffer, int base);

void CheckEndian(char *c);

size_t CheckMacroEndian();	

void IsChInArr(char *arr1, char *arr2, char *arr3, int len1, int len2, int len3);


#endif
