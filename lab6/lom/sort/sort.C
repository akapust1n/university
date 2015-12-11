#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//левый сын - родитель - правый сын in-order обход(поперечный)
unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__("rdtsc": "=A"(d));

    return d;
}
typedef struct tree
  {
    int a;
    struct tree *left;
    struct tree *right;
  } TREE;

TREE *add_to_tree(TREE *root, int new_value)
{
   if (root==NULL)
     {
        root = (TREE*)malloc(sizeof(TREE));
        root->a = new_value;
        root->left = root->right = 0;
        return root;
     }
   if (root->a < new_value)
     root->right = add_to_tree(root->right, new_value);
   else
     root->left  = add_to_tree(root->left,  new_value);
   return root;
}

void tree_to_array(TREE *root, int a[])
  {
    static max2=0;
    if (root==NULL) return;
    tree_to_array(root->left, a);
    a[max2++] = root->a;
    tree_to_array(root->right, a);
    free(root);
  }

void sort_tree(int a[], int elem_total)
{
   TREE *root;
   int i;

   root = NULL;
   for (i=0; i<elem_total; i++)
      root = add_to_tree(root, a[i]);
   tree_to_array(root, a);
}

void main() {
   int i,n;
   /* Это будем сортировать */
  // int a[14]={ 0,7,52,3,52,14,16,18,15,13,42,30,35,26 };
    printf("Input size of array");
    scanf("%d",&n);
    int a[n];
    printf("input array\n");
    for(int j=0;j<n;j++)
        scanf("%d",&a[j]);
    clock_t time_start=tick();
   sort_tree(a, n);
clock_t time_end=tick();
printf("\nTime of sorting:%e secunds %d ticks\n",(time_end-time_start)/2900000.0,(time_end-time_start));
   printf("sorted array:\n");
   for (i=0;i<n;i++) printf("%d ",a[i]);
}
