unsigned char swapNibbles(unsigned char x)
{
    return ( (x & 0x0F)<<4 | (x & 0xF0)>>4 );
}

int main()
{
    unsigned char x = 100;
    printf("%u", swapNibbles(x));
    return 0;
}

/* the question is here , if the input is a signed char will it work 
yes: it will work.
x -> signed char
  (x & 0xF0) >> 4 : Will be there any sign extension ?
See the experiment and behaviour below */
#include <stdio.h>

void printBinary(char val)
{
    for(int i = 7; i >=0;i--)
    {
        printf(val & (1 << i) ? "1":"0");
    }
}
int main() {
    // Write C code here
    printf("Try programiz.pro\n");
    char x = 0b10000000;
    unsigned char mask = 0xF0;
    char mask1 = 0xF0;
    char y = (x & mask)>>4; 
    printf("\n %d\n:",y);
    
    printBinary(y); //00001000 // no signextension
    char z = (x & mask1)>>4;
    printf("\n%d\n:",z);
    
    printBinary(z);//11111000 //sign extension
    return 0;
}
