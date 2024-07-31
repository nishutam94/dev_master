#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdarg.h>

int * arrayfun()
{
    static int array[] = {100,200,300,400,500,600};
    return array;
}
int main(void)
{   
    int array[] = {1000,2000,3000,4000,5000,6000};
    int *ptr = array;
    int *fptr = arrayfun();

    for (int i = 0;i<6;i++)
    {
        printf("%d",*fptr++);
    }


    printf("%d \n",ptr);
    printf("%d \n",array);
    printf("%d \n",*ptr);
    printf("%d \n",*array);

    printf("%p \n",ptr);
    printf("%p \n",array);
    printf("%p \n",&ptr);
    printf("%p \n",&array);

    printf("%p \n",*ptr);
    printf("%p \n",*array);
    printf("%d \n",&ptr);
    printf("%d \n",&array);

    char str[] = "GeeksforGeeks";
    char* ptr1 = str;
    while (*ptr1 != '\0') {
        printf("%c", *ptr1);
        ptr1++;
    }
 

    

    return 0 ;
}

