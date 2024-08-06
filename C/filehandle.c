#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *ptr;
    char sampletxt[] ="The quick brown fox jumps over the lazy dog.This sentence contains every letter of the alphabet, making it a pangram." ;
    //ptr=fopen("filename.txt","r");
    ptr=fopen("file.txt","a+");

    if (ptr == NULL)
    {
        printf("file is not opend");
        exit(0);
    }
    else
    {
        printf("file is opend!!");
    }
    
    if (strlen(sampletxt) > 0)
    {
        fputs(sampletxt,ptr);
        fputs("\n",ptr);

    }

    fclose(ptr);
    
    char string1[100];
    FILE *ptr2;

    ptr2=fopen("file.txt","r");
    fgets(string1,100,ptr2);
    printf("%s",string1);



    return 0;
}