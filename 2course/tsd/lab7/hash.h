#ifndef HASH_H
#define HASH_H
int hash_open;
typedef struct  T1
 {
     char data;
     int number;

 }   T ;                  /* type of item to be stored */
typedef int hashTableIndex;     /* index into hash table */
#define compEQ(a,b) (a == b)

typedef struct Node_ {
    struct Node_ *next;         /* next node */
    T key;                     /* data stored in node */
} Node1;
char hash(char data);
Node1 *insertNode(char data1,int number);
void deleteNode(char data);
Node1 *findNode (char data);
int hashTableSize;
Node1 **hashTable;
#endif // HASH_H

