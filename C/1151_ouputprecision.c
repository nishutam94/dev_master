#include <stdio.h>

/*
%d - will print the value
%10d - will print the value with width of 10
%10.3 - will print the value with width 10 but last 3 charatcer 
%-10.3 - alighn form right 


getch() - wait 
getche() - wait and print char
gets - wait for string
getchar() - wait for char

puts() - print
putchar() - print


*/

int main()
{
    int num = 2451;
    float dec = 12.45126;
    char* str = "GeeksforGeeks";

    long var = 3000000000;
   
    // printing var using %d
    printf("Using %%d: %d", var);
    // printing var using %ld
    printf("\nUsing %%ld: %ld", var);

    // precision for integral data
    printf("For integers: %.10d\n", num);
    // precision for numbers with decimal points
    printf("For floats: %.2f\n", dec);
    // for strings
    printf("For strings: %.5s", str);


   
    // printing the num with 10 width and getting the
    // printed characters in char_printed
    printf("Printing num with width 10: ");
    int chars_printed = printf("%10d", num);
    printf("\nNumber of characters printed: %d",
           chars_printed);

    // specifying with using other method
    printf("\nPrinting num with width 3: ");
    chars_printed = printf("%*d", 3, num);
    printf("\nNumber of characters printed: %d",
           chars_printed);

    str = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n",str);
    printf("%40s\n",str);
    printf("%-40s\n",str);
    printf("%10.5s\n",str);
    printf("%-10.5s\n",str);
    printf("%.10s\n",str);

    return 0;
}