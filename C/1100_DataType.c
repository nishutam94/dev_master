#include<stdio.h>
#include<math.h>

/*
primitive - int,char,float,double,void.
drived - array,pointer,function
user-defined - structure, union, enum

size -  int:4(d) char:2(c) float:4(f) double:8(lf)
     - signed:4(d) unsinged:4(u) short:2(h)
     
*/

int maxvalue(int x)
{
int size;
size=pow(2,x)-1;
printf("%d",size);
return size;
}

int main()
{
printf("Data Types \n");
int a = 10; //signed int 
printf("signed : %d\n",a);
printf("size : %d\n", sizeof(a));

unsigned int b = -20; //unsigned int 
printf("unsigned : %u\n",b);
printf("size : %d\n", sizeof(b));

short int c = 30; //unsigned int 
printf("unsigned short : %hd\n",c);
printf("size : %d\n", sizeof(c));

long int d = 40; //unsigned int 
printf("long int : %ld\n",d);
printf("size : %d\n", sizeof(d));

char e =  'a';
printf("chartcter :%c\n",e);
printf("size : %d\n", sizeof(e));

//maxvalue(8*sizeof(a));

float g = 9.0f;
// 2x10^-4
float f = 2E-4f;
printf("float : %f\n", g);
printf("float : %f\n", f);
printf("size : %d\n", sizeof(f));

double h =  123123123123.321321321; 
printf("long float : %lf\n",h);
printf("size : %d\n", sizeof(h));

char string[] = "Hello\n\t World!!!";
printf(string);  


return 0;
}
