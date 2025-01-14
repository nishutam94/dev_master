#include<string.h>
#include<stdio.h>
int main()
{

    char arr[] = {'a','b','c'};

    char arr2[] = "abc";

    for (int i=0;arr[i]!='\0';i++)
        printf("%c\n",arr[i]);
        
    printf("%s",arr);
    printf("%d",strlen(arr));
    return 0;
}