#include <iostream>
#include <cstring>
using namespace std; // using the standard namespace "std",

typedef struct {
  unsigned int seconds: 6;
  unsigned int minutes: 6;
  unsigned int hours: 5;
  unsigned int day: 5;
  unsigned int month: 4;
  unsigned int year: 11;
} dateTime;

typedef struct {
  int length; // The number of elements in the list
  int capacity; // the maximum number of elements the list can hold
  int *elements; // the elements of the list
} ArrayList;

void init(ArrayList *list){
  list->length = 0;
  list->capacity = 1;
  list->elements = (int *) malloc(sizeof(int) * list->capacity);
}

void add(ArrayList *list, int index, int element) {
    int len = list->length;
    int cap = list->capacity;
    if (len + 1 > cap) { // if the ArrayList is full, double its capacity
        list->capacity *= 2;
        int *updated = (int *) malloc(sizeof(int) * cap);
        memcpy(updated, list->elements, sizeof(int) * len);
        free(list->elements);
        list->elements = updated;
    }
    for (int i = list->length; i > index; i--) { // shift to the right
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = element; // insert
    list->length++;
}

void deleteElement(ArrayList *list, int index) {
    for (int i = index; i < list->length - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->length -= 1;
}

int get(ArrayList *list, int index){
  return list->elements[index];
}

void set(ArrayList *list, int index, int element){
  list->elements[index] = element;
}

ArrayList copy(ArrayList *list){
  ArrayList copy;
  copy.length = list->length;
  copy.capacity = list->capacity;
  copy.elements = (int *) malloc(sizeof(int) * list->capacity);
  memcpy(copy.elements,list->elements,sizeof(int) * list->length);
  return copy;
}

void trim(ArrayList *list) {
    list->capacity = list->length;
    int *newData = (int *) malloc(sizeof(int) * list->capacity);
    memcpy(newData, list->elements, sizeof(int) * list->length);
    free(list->elements);
    list->elements = newData;
}

void empty(ArrayList *list) {
    free(list->elements);
    list->length = 0;
    list->capacity = 1;
    list->elements = (int *) malloc(sizeof(int) * list->capacity);
}

void printArrayList(ArrayList list){
  cout << "Printing ArrayList: " << endl;
  for(int i = 0; i < list.length; i++){
    cout << list.elements[i] << " ";
  }
  cout << endl;
}

void printDate(dateTime dt){
  cout << dt.month << "/";
  cout << dt.day << "/";
  cout << dt.year << " ";
  cout << dt.hours << ":";
  cout << dt.minutes << ":";
  cout << dt.seconds << endl;
}

void infiniteIntLoop(int n, int m){
    while (n >= m){
        n = n - 1;
    }
}

int main() {
  int n = 10, m = 5;

  infiniteIntLoop(n,m);

  cout << sizeof(dateTime) << endl;
  
  dateTime today = {
    3,
    25,
    16,
    8,
    2,
    2024
  };
  
  printDate(today);

  ArrayList list;
  init(&list);

  cout << "Adding 5 elements to an ArrayList" << endl;
  for (int i = 0; i < 5; i++)
  {
        add(&list, i, i + 1);
  }
  printArrayList(list);

  cout << "Deleting the third element" << endl;
  deleteElement(&list, 2);
  printArrayList(list);

  cout << "Setting the second element to 10" << endl;
  set(&list, 1, 10);
  printArrayList(list);

  cout << "Creating a copy  of the ArrayList" << endl;
  ArrayList listCopy = copy(&list);

  cout << "Original: " << endl;
  printArrayList(list);
  cout << "Copy: " << endl;
  printArrayList(listCopy);

  cout << "Freeing elements of the copy" << endl;
  free(listCopy.elements);

  cout << "Trimming the ArrayList" << endl;
  trim(&list);

  cout << "Length: " << list.length << " Capacity: " << list.capacity << endl;
  printArrayList(list);

  cout << "Emptying the ArrayList" << endl;
  empty(&list);
  cout << "Length: " << list.length << " Capacity: " << list.capacity << endl;
  printArrayList(list);

  cout << "Freeing elements of the ArrayList" << endl;
  free(list.elements);

  return 0;
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
** Couldn't figure out how to write a program that makes this loop go into an infinite loop


  while (*p >= *q) {
    *p = *p - 1;
  }
This loop is not guaranteed to terminate.  As long as p and q are separate pointers, the loop will terminate.
However, if p and q point to the same variable, then they will be equal, meaning that the loop will not stop
due to the >= condition.
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