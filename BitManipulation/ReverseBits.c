#include <stdint.h>
/*uint32_t Meaning in C
uint32_t is a fixed-width integer type from the stdint.h header in C. It stands for:

u → Unsigned (only stores non-negative values)
int → Integer type
32 → 32-bit wide (4 bytes)
_t → Type (common convention in typedefs)
Why Use uint32_t?
Portability: Ensures that the integer is exactly 32 bits on all systems.
Avoids Ambiguity: int and long can vary in size across compilers and architectures.
Prevents Signed Issues: Since it's unsigned, it only stores values from 0 to 4294967295 (2³² - 1).
*/
uint32_t reverse_bits(uint32_t byte)
{
    uint32_t reversed = 0;
    int i = 0;
    while ( i < 8) {
        reversed = (reversed << 1) | (byte & 1);  // Shift left and add LSB
        byte >>= 1;  // Shift right to process the next bit
        i++;
    }
    return reversed;
}
int main() {
    uint32_t number = 42; // Now, uint32_t is recognized
    return 0;
}