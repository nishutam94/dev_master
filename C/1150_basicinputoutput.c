#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",a);

    char str[50];
    //scanf("%s",str);
    //printf("%s",str);

    scanf("%[^\n]s",str);
    printf("%s",str);

    return 0;
}