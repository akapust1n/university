/* hash table */

#include <stdio.h>
#include <stdlib.h>
int hash_open;
/* modify these lines to establish data type */
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


Node1 **hashTable;
int hashTableSize;

char hash(char data) {

   /***********************************
    *  hash function applied to data  *
    ***********************************/

    return (data % hashTableSize);
}

Node1 *insertNode(char data1,int number) {
    Node1  *p, *p0;
    hashTableIndex bucket;

   /************************************************
    *  allocate node for data and insert in table  *
    ************************************************/

    /* insert node at beginning of list */
    bucket = hash(data1);
   if ((p = malloc(sizeof(Node1))) == 0) {
        fprintf (stderr, "out of memory (insertNode)\n");
        exit(1);
    }
    //p= malloc(sizeof(Node1));
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->key.data = data1;
    //printf("key %c\n",p->key.data);
    p->key.number=number;
    return p;
}

void deleteNode(char data) {
    Node1 *p0, *p;
    hashTableIndex bucket;

   /********************************************
    *  delete node containing data from table  *
    ********************************************/

    /* find node */
    p0 = 0;
    bucket = hash(data);
    p = hashTable[bucket];
    while (p && !compEQ(p->key.data, data)) {
        p0 = p;
        p = p->next;
    }
    if (!p) return;

    /* p designates node to delete, remove it from list */
    if (p0)
        /* not first node, p0 points to previous node */
        p0->next = p->next;
    else
        /* first node on chain */
        hashTable[bucket] = p->next;

    free (p);
}

Node1 *findNode (char data) {
    Node1 *p;

   /*******************************
    *  find node containing data  *
    *******************************/

    p = hashTable[hash(data)];

    while (p && !compEQ(p->key.data, data))
    {

        hash_open++;

        p = p->next;

    }

    if (p) hash_open++;
    return p;
}

/*int main() {
    int i, maxnum, random;
    char *a;

    /* command-line:
     *
     *   has maxnum hashTableSize [random]
     *
     *   has 2000 100
     *       processes 2000 records, tablesize=100, sequential numbers
     *   has 4000 200 r
     *       processes 4000 records, tablesize=200, random numbers
     *
     */
/*
    maxnum = 10;
    hashTableSize = 5;
    random = 1;

    if ((a = malloc(maxnum * sizeof(*a))) == 0) {
        fprintf (stderr, "out of memory (a)\n");
        exit(1);
    }

    if ((hashTable = malloc(hashTableSize * sizeof(Node1 *))) == 0) {
        fprintf (stderr, "out of memory (hashTable)\n");
        exit(1);
    }


        for (i=0; i<maxnum; i++) a[i] = i+65;



   // root=inserNode(a[0]);

    for (i = 0; i < maxnum; i++) {
        insertNode(a[i],i);
    }
    printf("Try to watch");
 //   for(int i=0;i<maxnum;i++)
   //     printf("%c\n",a[i]);

    for (i = maxnum-1; i >= 0; i--) {
      Node1 *p=  findNode(a[i]);
      printf("%c  ",p->key.data);
      printf("%d ",hash(p->key.data));
      printf("%d\n",p->key.number);
    }

    for (i = maxnum-1; i >= 0; i--) {
        deleteNode(a[i]);
    }
    return 0;
}
    */
