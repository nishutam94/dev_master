/*
Pointer vs references -  Reference only assigned once, It cannot be void, Can not be null, Must be initialized when declared.
What is daggling pointer - Pointer which is referenced but deleted. 
What is null pointer -  int *ptr =  NULL; 
 */

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int* ptr = (int*)malloc(sizeof(int));
 
    // After below free call, ptr becomes a dangling pointer
    free(ptr);
    printf("Memory freed\n");
 
    // removing Dangling Pointer
    ptr = NULL;
 
    return 0;
}