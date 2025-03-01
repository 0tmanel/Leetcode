/*Polynomial Hashing
Useful for strings; it computes a hash value based on the polynomial
 evaluation of the string's characters.*/
#include <stdio.h>
#define Hsize 4
int  hash_function(int key)
{
    return key % Hsize;
    /*Division Method with Prime Numbers
   Instead of using a fixed size, you can use a prime number close to the size
    of the hash table for the modulus operation, which often reduces collisions.
    LIKE KEY % 7*/
}

/*int search(int hashTable[], int key)
{
    int index = hash_function(key);
    while (hashTable[index] != 0)
    {
        if(hashTable[index] == key)
        {
        return index;
        }
        index = (index + 1) % Hsize;

    }
    return 0;

}*/
void insert(int hashTable[], int key)
{
    int index = hash_function(key);
    int i = 0;
    while (hashTable[index] != 0)// Quadratic Probing
    {
        i++;
        index = (index + i * i) % Hsize;
    }
    /*int index = hash_function(key);  DOUBLE HASHING
    int step = hash_function2(key);
   while (hashTable[index] != 0)
   {
    index = (index + step) % Hsize;
   }*/
   /*while (hashTable[index] != 0)// Linear Probing
   {
    index = (index + 1) % Hsize;
   }*/
    /*The modulo operation allows the index to wrap around to the beginning of the array 
    when it reaches the end. For example, 
    if the current index is size - 1 and you increment it by 1, 
    you want it to go back to 0. The expression (index + 1) % size achieves this.
    If the hash table size is size, valid indices range from 0 to size - 1.
     If you simply use index + 1, you could end up with an index that exceeds this range,
      leading to an out-of-bounds error.*/
    
    hashTable[index] = key;
    
}
int main ()
{
    int hashTable[Hsize];
    insert(hashTable, 1);
    insert(hashTable, 2);
    insert(hashTable, 4);
    insert(hashTable, 4);

   // int index = search (hashTable, 3);
   int i = 0;
   while ( i < Hsize)
   {
    printf("%d", hashTable[i]);
    i++;
   }

}
/*Sentinel Value
Definition: A sentinel value is a special value used to mark a specific condition or 
to signify the end of a data structure, such as a list or array. 
It typically does not represent valid data.
Purpose:
Boundary Marker: Often used to indicate the end of a data structure 
(e.g., the end of a linked list).
Special Condition: Can signal special conditions, such as an empty list or an invalid state.
Example:
In a linked list, a node might have a next pointer that points
 to a sentinel node to indicate the end of the list.
In algorithms, -1 or null may be used as a sentinel value to 
indicate that a search has failed or that a list is empty.*/