//Bit manipulation generally consists of six activities: setting bits, clearing bits, inverting bits, testing and
//comparing bits, extracting bits from a bit string, and inserting bits into a bit string.


//The result of an AND operation is true only if both input values are true. 
//The result of an OR operation is true if either input value is true. 
//The result of a NOT operation is to reverse the bit value
#include <stdio.h>
int main ()
{
   /* // place value (base 10) : 128    64    32   16   8   4   2   1

     unsigned char i; //bitwise NOT  operator ~
    i = 17; // in bit representation it is like 00010001 , usally it is read 
            // from left to right but we will do the opposit , here we have 1, when we 
            //see the place value of 1 we find 1 so we store it in a variable , then we 
            // find three zero's, skip them , then we find another 1, when we look at
             //  the place value , we find it is 16 , so 1 + 16 = 17
    i = ~i; // bit we negate it to become 11101110
    printf("%d\n", i);

     unsigned char j, k;//The bitwise AND operator performs an AND  &
                        //between two variables, independently at every bit.
     j = 19;//00010011
     k = 49;//00110001
     j = k & j;
     printf("%d\n", j);

     unsigned char a, b;//The bitwise OR operator performs an OR between 
                         // two variables, indepen- dently at every bit. 
                         //It is written using the vertical bar symbol (|)
     a = 19;//00010011
     b = 49;//00110001
     a = a | b;
     printf("%d\n", a);



    //The left-shift and right-shift bit operators move bits 
    //into higher-order and lower-order bit positions, respectively.
 //A left-shift is written in C using two consecutive less-than symbols (<<)
// and a right-shift is written using two consecutive greater-than symbols (>>).
     unsigned char a, b;
   a=17; //00010001
   a=a << 2;
   b=64;//01000000
   b=b >> 3;
   printf("%d %d\n",a, b);
     */

    char a,b;
   a=17;//00010001 
   a=a >> 2;
   b=-65; //01000001
   b=b >> 2;
   printf("%d %d\n",a,b);
   //Right shifting (>> 1) means moving all bits one position to the right.







}