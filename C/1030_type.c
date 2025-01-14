#include<linux/types.h>
#include<stdio.h>
#include<stdint.h>
int main()
{
    struct {
        uint32_t field1 : 8;
        uint32_t field2 : 8;
        uint32_t field3 : 8;
        uint32_t field4 : 8;
    } my_struct;

    printf("Size of my_struct: %zu bytes\n", sizeof(my_struct));

    return 0;
}


/*
uint32_t x = 4294967295;
x = x + 1;  // x will become 0 due to overflow 0 - no error. to 4,294,967,295

int x = 2147483647;
x = x + 1;  // This will cause undefined behavior (overflow) error becouse signed -2,147,483,648 to 2,147,483,647

uint32_t is a 32-bit unsigned integer with a range of 0 to 4,294,967,295.
int is a signed integer with a range typically from -2,147,483,648 to 2,147,483,647 (for 32-bit systems).
uint32_t does not allow negative numbers, while int allows both positive and negative values.
The size of uint32_t is always 32 bits, whereas the size of int can vary based on the platform but is often 32 bits on modern systems.
*/

