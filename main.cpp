#include <iostream>
using namespace std; // using the standard namespace "std",

int infinitePointerLoop(int *p, int *q){
    while (*p >= *q) {
        *p = *p - 1;
    }
    return 1;
}

int infiniteIntLoop(int n, int m){
    while (n >= m){
        n = n - 1;
    }
    return 1;
}

int main() {
    int n = 10, m = 5;
    int *p = &n;
    int *q = &m;

    infiniteIntLoop(n,m);

    infinitePointerLoop(p,q);
}

/* Problem 1: For each of the following loops, where n and m are integer variables
 * and p and q are pointers, are they guaranteed to terminate?
 * If yes, explain.
 * If not, write a program that initializes variables used in the loop in such a way that the
 * program goes into an infinite loop.

 while(n >= m) {
    n = n - 1;
  }
This loop is guaranteed to terminate because when n becomes less than or equal to m,
 the loop will end.  And if n starts out as smaller than m, the loop won't begin.


  while (*p >= *q) {
    *p = *p - 1;
  }
This loop is also guaranteed to terminate, since we dereference p when we reassign it's values.
 */


/* Problem 2: Define a typedef datetime that contains the following:
 * time in hours, minutes, seconds
 * date in day, month (number), year (assume year goes to 2047)
 *
 * Design the structure that takes the smallest amount of memory, implement it and check its size,
 * making sure you can set and get the right values
 */

/* Problem 3: Implement a typedef for a structure that represents an array list (i.e. a growing array)
 * of integers.
 *
 * It allocates some initial capacity and stores elements there. Once it reaches the end of the capacity,
 * it uses the function memcpy to allocate a chunk of memory twice the previous capacity, copies the elements
 * there, and frees the old memory.
 * The structure contains:
 *      The length of the array
 *      The capacity (the amount of allocated memory)
 *      A pointer to the allocated memory
 *
 * Define the following functions that take the array list and any other necessary parameters:
 * init - to initialize the array at the starting capacity 1
 * print - to print the elements up to the length
 * add - to add an element to the array list at the index i (if needed, to increase/reallocate the memory).
Shift everything else accordingly.
 * delete - takes an index and deletes an element at that index. Shift everything else accordingly.
 * set, get - to set or get an element at a given index
 * copy - to copy the entire structure to a new structure; the memory for the new array gets allocated in a new place;
the length and the capacity are the same; returns the new structure
 * trim - trim the capacity array to the length
 * empty - restore the array to the initial capacity of 1 and no elements
 */