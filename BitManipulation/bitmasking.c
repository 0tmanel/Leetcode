#include <stdio.h>
//The bitmask indicates which bits are to be affected by the operation. The idea is to operate on a variable, changing or affecting only the bits indicated by the bitmask:
//variable → bitmask (bit N) → variable (only bit N changed)

//common bitmask operations work on a single bit: set the bit, clear the bit, or query the value of the bit. Each of these operations can be accomplished through the following logic:

//set Nth bit  ===> x = x | (1<<N);
//clear Nth bit===> x = x & (~(1<<N));
//read Nth bit ===> (x & (1<<N)) >>N;
int main ()
{
    //setting a bit
    printf("this result is for the part of setting a bit\n");
    unsigned char  j = 17; //00010001
    j = j | (1<< 3);
    printf("%d\n", j);
    /* 
    i = i | (1 << 3);
This is where the bit manipulation happens. Let’s break it down:

1 << 3:
The number 1 in binary is 00000001.
Shifting 1 left by 3 positions (1 << 3) results in:


00001000  (which is 8 in decimal)
Now, we perform the bitwise OR (|) operation between i (which is 17 or 00010001) and the result of 1 << 3 (which is 8 or 00001000).

Let's do the bitwise OR operation step by step:

00010001  (i = 17)
OR
00001000  (1 << 3 = 8)
-----------------------
00011001  (Result = 25)*/

//clearing a bit 
printf("this result is for the part of clearing a bit\n");
unsigned char  a = 17;
a=a & (~(1<<4));
printf("%d\n",a);
/*~(1 << 4)
This part performs two operations:

Left shift (1 << 4):
The binary representation of 1 is 00000001.
Shifting 1 left by 4 positions (1 << 4) results in:


00010000  (which is 16 in decimal)
NOT (~) operation:
The ~ (bitwise NOT) inverts all the bits of 00010000, turning it into:

11101111  (this is `-17` in two's complement, but we're only interested in the bits)
So, the result of ~(1 << 4) is:


11101111  (a mask where the 4th bit is 0 and all others are 1)
Bitwise AND Operation (a & ~(1 << 4)):


a = a & (~(1 << 4));
Now, we perform the bitwise AND operation between a (which is 17 or 00010001 in binary) and the result of ~(1 << 4) (which is 11101111 in binary).

Let's do the bitwise AND operation step by step:


00010001  (a = 17)
AND
11101111  (~(1 << 4))
-----------------------
00000001  (Result = 1)*/

//
printf("this result is for the part of reading bits of j\n");

int i;
//This loop runs 8 times (from i = 7 down to i = 0).
//i represents the bit position we want to examine in j. Since the loop starts at 7 and ends at 0, it examines bits from the most significant bit (MSB) to the least significant bit (LSB).
for (i=7; i>=0; i--)

  printf("%d ",(j &(1<<i)) >> i);  /* read i’th bit */
printf("\n");
/*
For j = 25 and the loop running from i = 7 to i = 0:
25 == 00011001
i = 7: (25 & (1 << 7)) >> 7:

1 << 7 = 10000000
25 & 10000000 = 00000000 (the 7th bit is 1)
00000000 >> 7 = 0
Prints 0
i = 6: (25 & (1 << 6)) >> 6:

1 << 6 = 01000000
25 & 01000000 = 00000000 (the 6th bit is 0)
00000000 >> 6 = 0
Prints 0
i = 5: (25 & (1 << 5)) >> 5:

1 << 5 = 00100000
25 & 00100000 = 00000000 (the 5th bit is 1)
00000000 >> 5 = 0
Prints 0
i = 4: (130 & (1 << 4)) >> 4:

1 << 4 = 00010000
25 & 00010000 = 00010000 (the 4th bit is 0)
00010000 >> 4 = 1
Prints 1
i = 3: (25 & (1 << 3)) >> 3:

1 << 3 = 00001000
25 & 00001000 = 00001000 (the 3rd bit is 1)
00001000 >> 3 = 1
Prints 1
i = 2: (25 & (1 << 2)) >> 2:

1 << 2 = 00000100
130 & 00000100 = 00000000 (the 2nd bit is 0)
00000000 >> 2 = 0
Prints 0
i = 1: (25 & (1 << 1)) >> 1:

1 << 1 = 00000010
25 & 00000010 = 00000000 (the 1st bit is 1)
00000000 >> 1 = 0
Prints 0
i = 0: (130 & (1 << 0)) >> 0:

1 << 0 = 00000001
130 & 00000001 = 00000001 (the 0th bit is 0)
00000001 >> 0 = 1
Prints ; 1
*/ 

}