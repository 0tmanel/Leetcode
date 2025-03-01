# Hash table is a data structure in which keys are mapped to array positions by a hash function

# The storage requirement for a hash table is O(k), where k is the number of keys actually used. while time spent is O(1)

# The secret of a hash table is the way it figures out where in the table to store a particular piece of data. This determination is performed by a hash function, which accepts a piece of data to be placed in the table and generates a number that specifies the slot in the table where the data will be placed. This number is called a hash key.

 # a hash table is implemented using array, and in special cases it uses linked list, do not be confused, 
 
 # One immediate consideration is how to resolve the problem of two entries hashing to the same slot in the table. Such an occurrence is called a collision
 
 # All collision-resolution approaches fall into two categories: rehashing, in which a new hash value is computed, and chaining, in which colliding elements are added to a table by means of a linked list. 
 
 # as for hash function it has this type : hash-key = calculated-key % tablesize