#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main()
{   
    int a;
    printf("Enter the number A:");
    scanf("%d",&a);

    //while ((getchar())!="\n");

    char string[20]="HelloWorlds";

    printf("%p",(void *)&string);
    return 0 ;
}

