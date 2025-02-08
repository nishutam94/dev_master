#include<stdio.h>

char * mymemcpy(char * src,char * dest,int size)
{
    if (src == NULL || dest == NULL)
        return NULL;
    
    int n = size;
    for(int i=0;i<n;i++)
    {
        dest[i]=src[i];
    }

    return dest;
}

int main()
{
    char src[]="hello,this need to be copied";
    char dest[100];
   
    mymemcpy(src,dest,sizeof(src));
    printf("%s",dest);
    return 0;
}