#include <stdio.h>
#include <stdlib.h>
#include <D:\13\TSD\lab7\hash.h>
int hash_op;
int hash1(char name)
{
return (name %20+10);
}
Node1 search_op(char letter, Node1 z[], int size)
{
    Node1 *p;

    int i=hash1(letter);
    while((z[i].key.data!=letter)&&(i<size))
    {
        i++;
        hash_op++;
    }
    if(z[i].key.data==letter) hash_op++;
    if (i==size)
    { hash_op++;

        i=0;
        while(z[i].key.data!=letter)
        { hash_op++;
            i++;
        }
        hash_op++;
    }


    return z[i];
}

void put(char letter,int number, Node1 z[], int size)
{
    int i=hash1(letter);
    while((z[i].key.data!=0)&&(i<size)) i++;
    if (i==size)
    {
        i=0;
        while(z[i].key.data!=0) i++;
    }
    z[i].key.data=letter;
    z[i].key.number=number;

    return;
}
