#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include  <ctype.h>
#include <D:\13\TSD\lab7\hash.h>
#include <D:\13\TSD\lab7\hash_op.h>
#pragma pack(1)
#define  table_size 35
/*struct node_st{
    node_st *p1; 	// левая ветка
    node_st *p2; 	// правая ветка
    int value;	// значение узла
    int b; 		// фактор баланса
    };
*/

struct Node
{
char key;
char height;
struct Node *right;
struct Node *left;
};

int bin_iter=0;//количество сравнений при поиске элемента
void iniz(char k,struct Node * p)
{
    // printf("Iniz succ\n");
    p->key=k;
    p->height=1;
    p->left=p->right=0;

return ;
}

char height(struct Node *p)
{
if (p) return p->height;
else return 0;
}

int BF(struct Node *p)
{ return height(p->right)-height(p->left); }

void OverHeight(struct Node *p)
{
char hleft=height(p->left);
char hright=height(p->right);
p->height=(hleft>hright ? hleft : hright)+1;
}

struct Node* RightRotation(struct Node *x)
{
struct Node *y=x->left;
x->left=y->right;
y->right=x;
OverHeight(x);
OverHeight(y);
return y;
}
struct Node *LeftRotation(struct Node *y)
{
 struct Node *x=y->right;
y->right=x->left;
x->left=y;
OverHeight(y);
OverHeight(x);
return x;
}
struct Node *Balance(struct Node *x)
{
OverHeight(x);
if (BF(x)==2)
{
if (BF(x->right)<0) x->right=RightRotation(x->right);
return LeftRotation(x);
}
if (BF(x)==-2)
{
if (BF(x->left)>0) x->left=LeftRotation(x->left);
return RightRotation(x);
}
return x;
}
struct Node *Insert(struct Node *x, char k) //к авл дереву
{

if (!x)
{

    struct Node *r=malloc(sizeof(struct Node));
    iniz( k,r);
    return r;
}
// printf("%c",k);
if (k<x->key) x->left=Insert(x->left, k);
else x->right=Insert(x->right, k);

return Balance(x);
}

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__("rdtsc": "=A"(d));

    return d;
}
struct tree_node
{
    char name;

    // меньшие
    struct tree_node *left;
    // большие
    struct tree_node *right;
};
struct tree_node* create_node( char name)
{
    struct tree_node *node;

    node = malloc(sizeof(struct tree_node));

    if (node)
    {
        node->name = name;

        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

struct tree_node* insert(struct tree_node *tree, struct tree_node *node)
{
    int cmp;

    if (tree == NULL)
        return node;

   if ( node->name> tree->name) cmp=1 ; else cmp=-1;

    if (cmp < 0)
    {
        tree->left = insert(tree->left, node);
    }
    else
    {
        tree->right = insert(tree->right, node);
    }

    return tree;
}
//пробуем ещё одно удаление
struct tree_node *dtree(struct tree_node *root, char key)
{
  struct tree_node  *p,*p2;

  if(!root) return root; /* вершина не найдена */

  if(root->name == key) { /* удаление корня */
    /* это означает пустое дерево */
    if(root->left == root->right){
      free(root);
      return NULL;
    }
    /* или если одно из поддеревьев пустое */
    else if(root->left == NULL) {
      p = root->right;
      free(root);
      return p;
    }
    else if(root->right == NULL) {
      p = root->left;
      free(root);
      return p;
    }
    /* или есть оба поддерева */
    else {
      p2 = root->right;
      p = root->right;
      while(p->left) p = p->left;
      p->left = root->left;
      free(root);
      return p2;
    }
  }
  if(root->name < key) root->right = dtree(root->right, key);
  else root->left = dtree(root->left, key);
  return root;
}
int menu2()
{
    int i;
    printf("\n");
    printf("1)Input line\n");
   // printf("2)Add one letter \n");
   // printf("3)Delete letter\n");
    printf("2)Show graph \n");
    printf("3)Delete repeating elements \n");
   // printf("6)Bypass graph pre-order\n");
   // printf("7)Bypass graph in-order\n");
   // printf("8)Bypass graph post-order\n");
   // printf("9)Find element\n");
    printf("10)Exit\n>>");

    scanf("%d",&i);
    return i;
}
void apply_pre(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg)
{
    if (tree == NULL)
        return;

    f(tree, arg);
    apply_pre(tree->left, f, arg);
    apply_pre(tree->right, f, arg);
}
void apply_pre1(struct Node*tree, void (*f)(struct Node*, void*), void *arg)
{
    if (tree == NULL)
        return;

    f(tree, arg);
    apply_pre1(tree->left, f, arg);
    apply_pre1(tree->right, f, arg);
}


void print(struct tree_node *node, void *param)
{
    const char *fmt = param;

    printf(fmt, node->name);
}
void print1(struct Node *node, void *param)
{
    const char *fmt = param;

    printf(fmt, node->key);
}

void to_dot(struct tree_node *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%c -> %c;\n", tree->name, tree->left->name);

    if (tree->right)
          fprintf(f, "%c -> %c ;  \n", tree->name, tree->right->name);
   // fprintf(f,"d[shape=\"rectangle\",style=\"filled\",fillcolor=\"lightgrey\"];");


}
void to_dot1(struct Node *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%c -> %c;\n", tree->key, tree->left->key);

    if (tree->right)
          fprintf(f, "%c -> %c ;  \n", tree->key, tree->right->key);
   // fprintf(f,"d[shape=\"rectangle\",style=\"filled\",fillcolor=\"lightgrey\"];");


}
void export_to_dot(FILE *f, const char *tree_name, struct tree_node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);
    apply_pre(tree, to_dot, f);


}
void export_to_dot1(FILE *f, const char *tree_name, struct Node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);
    apply_pre1(tree, to_dot1, f);


}
struct tree_node* lookup_2(struct tree_node *tree, char name)
{
    int cmp;

    while (tree != NULL)
    {
        //cmp = strcmp(name, tree->name);
        if ( name> tree->name) cmp=1 ;
        else
            if (name== tree->name) cmp=0;
            else cmp=-1;
    bin_iter++;
        if (cmp == 0)
            return tree;
        else if (cmp < 0)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return NULL;
}
struct tree_node* lookup_2_2(struct Node *tree, char name)
{
    int cmp;

    while (tree != NULL)
    {
        //cmp = strcmp(name, tree->name);
        if ( name> tree->key) cmp=1 ;
        else
            if (name== tree->key) cmp=0;
            else cmp=-1;
    bin_iter++;
        if (cmp == 0)
            return tree;
        else if (cmp < 0)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return NULL;
}
int main(){
struct tree_node *root = NULL; //для работы со строчкой
struct tree_node *node;

/* node = create_node("f");
assert(node);
assert(lookup_1(root, node->name) == NULL);
root = insert(root, node);
*/
//стартуем

int y=0;
char line[280]="";
char abc[27]; //сюда выписанные буквы
int letter[27];
for(int i=0;i<27;i++) letter[i]=0;
for(int i=0;i<27;i++) abc[i]=0;
 printf("Creating binary tree of letters\n");
 start:
do{
     y=menu2();
    switch (y)
    {
    case 1://ввод строки
    {


        for(int i=0;i<27;i++) letter[i]=0; // обнуляем массив букв
        for(int i=0;i<27;i++) abc[i]=0; // обнуляем массив букв
        printf("Input line:");
        fflush(stdin); //сброс буфера
        gets(line);


     for(int i=0;i<strlen(line);i++) //частота упоминания букв
     {
         if (isalpha(line[i])) //заполняем нужные буквы массива
         {
             int p=tolower(line[i]);
             letter[p-97]++;
         }
     }
     int t=0;
     //чтобы не было только правостронних деревьев, но только правосторонние деревья не требуют допмассива
     int letter2[27];
     for (int i=0;i<27;i++) letter2[i]=letter[i];

     for (int i=0;i<strlen(line);i++)
     {/* if (letter[i])
         {
           int z=i+97;
           printf("%d", letter[i]);
           abc[t++]=(char)z;//заполняем строчку букв
         } */
         if ((letter2[line[i]-97]-letter[line[i]-97])==0)
         {
             letter2[line[i]-97]--;
             abc[t++]=line[i];

         }
    }
     // на всякий случай делаем дерево
     root=NULL;
      for (int i=0;abc[i]!=0;i++)
         {

          node = create_node(abc[i]);

          //printf("Name %c",node->name );

         root = insert(root, node);
      }
       break;
    }


    case 2:
    {
        ///вообще всё обнуляем
       root = NULL; //обнуляем дерево

       for(int i=0;i<27;i++) letter[i]=0; // обнуляем массив букв
       for(int i=0;i<27;i++) abc[i]=0; // обнуляем массив букв

       //ещё раз пересоздаем массив ,где хранится порядок букв
       int letter2[27];
       int t=0;
       for(int i=0;i<strlen(line);i++) //частота упоминания букв
       {
           if (isalpha(line[i])) //заполняем нужные буквы массива
           {
               int p=tolower(line[i]);
               letter[p-97]++;
           }
       }
       for (int i=0;i<27;i++) letter2[i]=letter[i];

       for (int i=0;i<strlen(line);i++)
       {/* if (letter[i])
           {
             int z=i+97;
             printf("%d", letter[i]);
             abc[t++]=(char)z;//заполняем строчку букв
           } */
           if ((letter2[line[i]-97]-letter[line[i]-97])==0)
           {
               letter2[line[i]-97]--;
               abc[t++]=line[i];

           }
       }
         for (int i=0;abc[i]!=0;i++)
            {

             node = create_node(abc[i]);

            root = insert(root, node);
         }

         printf("\n");
        // работа с файлом и вывод
        FILE *f = fopen("test.gv", "w");

        export_to_dot(f, "test_tree", root);
        for (int i=0;i<27;i++)
            if (letter[i]>1)
            {
                char u=i+97;
                fprintf(f,"%c[shape=\"rectangle\",style=\"filled\",fillcolor=\"red\"]\n", u);
            }
          fprintf(f, "}\n");
        fclose(f);
        system("dot test.gv -Tpng -og.png");
        system("g.png");
        break;
    }
    case 3:
    {
        //retree(abc,&root,&node);
        printf("At start of del\n");
        for(int i=0;abc[i];i++)
        {
            printf("%c",abc[i]);
        }
        puts(line);

       // printf("4%c",abc[3]);
       root=NULL;
        for (int i=0;abc[i]!=0;i++)
           {

            node = create_node(abc[i]);
              //  printf("abc%c\n",abc[i]);

           root = insert(root, node);
        }



         clock_t time_start1=tick();
        for(int i=0;i<27;i++)
            if(letter[i]>1)
              {;root= dtree(root,(char)(i+97));}
         clock_t time_end1=tick();
         //удаление элемента из графа
         printf("\nTime of deleting from graph:%e secunds %d ticks",(time_end1-time_start1)/2900000.0,(time_end1-time_start1));

         //удаление элемента из строки
         clock_t time_start2=tick();

         for(int k=0;k<27;k++)
          {
              letter[k]--;

             // printf("\n%d letter[k]",letter[k]);
         }
          for(int i=0;line[i];i++)
          {
              yy:
             if (letter[line[i]-97]>0)
             {

                 char z=line[i]; ///ЕСЛИ ЧТО-ТО НЕ РАБОТАЕТ- ПЕРЕПРОВЕРИТЬ ТУТ
                 for (int x=i;(x<256 && line[x]!='\0');x++)
                                     line[x] = line[x+1]; // удаляем следующий
                 if(line[i]==z) goto yy;
             }
             if(i>0&&letter[line[i]-97]>0) i--;
          }
          for(int k=0;k<27;k++)
           {
               letter[k]++;

              // printf("\n%d letter[k]",letter[k]);
          }



        // puts("lol");
        // puts(line);

        FILE *f = fopen("test.gv", "w");

        export_to_dot(f, "test_tree", root);
          fprintf(f, "}\n");
        fclose(f);
        system("dot test.gv -Tpng -og.png");
        system("g.png");
        printf("\nDo you want to balance tree?(y/n) ");
        char answer;
        fflush(stdin);
         scanf("%c",&answer);
         if (answer=='y')goto haha;
         printf("\nIf you want to balance tree, pick this item again\n");
        break;
        //заполняем дерево заново(чисто в угоду подсчету времени)

    }

    case 9:
    {
      char a;
      printf("Input letter: ");
      fflush(stdin);

      scanf("%c",&a);



    }
    }
    }
   while(y!=0);
  haha:
   //конец 6ой лабы и начала баланса
  // printf("\nlol\n");
  for(int i=0;abc[i];i++);
  int maxnum=0;
 for (int y=0;abc[y];y++,maxnum++);
  //printf("%c\n", abc[i]);//чтобы адекватно метка работала
   struct Node *root1=malloc(sizeof(struct Node));
    iniz(line[0],root1);
    puts(line);
   for(int i=1;line[i];i++)
   {
       root1=Insert(root1,line[i]);
       //printf("%c",root1->key);
   }
   FILE *f = fopen("test1.gv", "w");

   export_to_dot1(f, "test_tree", root1);

     fprintf(f, "}\n");
   fclose(f);
   system("dot test1.gv -Tpng -og1.png");
   system("g1.png");
   printf("Do you want to start work with hash tables?(y/n): ");
   char answer;
   char *a; //хэш таблица открытая адресация
   fflush(stdin);
   scanf("%c",&answer);
   if(answer=='n') goto start;
   do
   {
          printf("\nChain method\n");
   printf("\nHash function : askii_code mod number");
   printf("\nInput number for hash function(1-26): ");
   int i;
   fflush(stdin);
   scanf("%d",&i);
   if(i<1||i>26) continue;
   hashTableSize=i;
   //memory
   int maxnum=0;
  for (int y=0;abc[y];y++,maxnum++);
//printf("MAXNUM%d ",maxnum);
   a = malloc(maxnum * sizeof(*a)); //не проверяем выделение памяти с:
   hashTable = malloc((hashTableSize)* sizeof(Node1 *));
   for(int u=0;abc[u];u++)
   {
      insertNode(abc[u],letter[i]);
   }

   //обход  и построение хэш таблицы

   printf("\n-----------------------------\n");//30

   printf("|Hash key | Letter |Quantity|\n");
  for(int u=0;abc[u];u++)
  {
      printf("|%9d",hash(abc[u])); //это печается не хэш-таблица, а данные из неё
      int p=abc[u];
      printf("|%8c|%8d|\n",abc[u],letter[p-97]);
  }
  printf("-----------------------------\n");//30
  printf("Open adress method\n");
  printf("\nHash function : askii_code mod 20 +10\n");
  Node1 op[table_size];
    for(int h=0;h<table_size;h++) op[h].key.data=0;
  for(int z=0;abc[z];z++)
  {
    int p=tolower(abc[z]);
  put(abc[z],letter[p-97], op, table_size);
  }
  //распечатка таблицы
   printf("\n--------------------------------------\n");//30
   printf("|Hash key | Letter |Quantity|Position|\n");
  for(int h=0;h<table_size;h++)
  {
      if (op[h].key.data!=0)
      {
          printf("|%9d",hash1(op[h].key.data)); //это печается не хэш-таблица, а данные из неё

          printf("|%8c|%8d|%8d|\n",op[h].key.data,op[h].key.number,h);
      }
  }
  printf("--------------------------------------\n");
  printf("Do you want go to search elements?(y/n)");
  fflush(stdin);
   scanf("%c",&answer);
   if(answer=='y') break;
  }while(1);
   printf("\nAvalibles elements: ");
     apply_pre(root, print, "%c ");

     do
     {   char element;
         printf("\nInput element: ");
           fflush(stdin);
         scanf("%c",&element);
         printf("\nChoose structure for searching\n");
         printf("1)Binary tree\n");
         printf("2)Balanced tree\n");
         printf("3)Chain method hash table\n");
         printf("4)Oped adress hash table\n");
         printf("5)Information about memory for stuctures\n>>");
         int z;
         fflush(stdin);
         scanf("%d",&z);
         switch (z)
         {
             case 1:
             {
                 clock_t time_start=tick();
                 bin_iter=0;
                if (lookup_2(root, element) == NULL)
                {
                    printf("\nThere arent this element\n");
                }
                 clock_t time_end=tick();
                printf("\nTime of search:%e secunds %d ticks\n",(time_end-time_start)/2900000.0,(time_end-time_start));
                printf("Comparisons: %d\n", bin_iter);
              //  node = create_node(a);
               //root = insert(root, a);
                printf("\nSubtree pre-order:  ");
                apply_pre(lookup_2(root, element), print, "%c ");
                printf("\n");
                break;

             }
             case 2:
             {
                 clock_t time_start=tick();
                 bin_iter=0;
                if (lookup_2_2(root1, element) == NULL)
                {
                    printf("\nThere arent this element\n");
                }
                 clock_t time_end=tick();
                printf("\nTime of search:%e secunds %d ticks\n",(time_end-time_start)/2900000.0,(time_end-time_start));
                printf("Comparisons: %d\n", bin_iter);
              //  node = create_node(a);
               //root = insert(root, a);
                printf("\nSubtree pre-order:  ");
                apply_pre1(lookup_2_2(root1, element), print, "%c ");
                printf("\n");
                break;
             }
             case 3:
             {

                 clock_t time_start=tick();
                 hash_open=0;
                Node1* p1;
                       p1 = findNode (element);
                clock_t time_end=tick();
                printf("Element's search complete\n");
               printf("\nTime of search:%e secunds %d ticks\n",(time_end-time_start)/2900000.0,(time_end-time_start));
                printf("Comparisons: %d\n", hash_open);

                 break;

             }

             case 4:
             {

                  //подсчет кол-ва элементов. ещё раз, да
                Node1 op[table_size];
                  for(int h=0;h<table_size;h++) op[h].key.data=0;
                for(int z=0;abc[z];z++)
                {
                  int p=tolower(abc[z]);
                put(abc[z],letter[p-97], op, table_size);
                }
                 clock_t time_start=tick();
                 hash_op=0;
                Node1 p1;
                       p1 = search_op(element,op,table_size);
                clock_t time_end=tick();
                printf("Element's search complete\n");
               printf("\nTime of search:%e secunds %d ticks\n",(time_end-time_start)/2900000.0,(time_end-time_start));
                printf("Comparisons: %d\n", hash_op);

                 break;

             }
            case 5:
             {
                   printf("\nRequired memory\n");
                   int i,sch=0;
                   for( i=0;line[i];i++)
                   {
                       if (line[i]!=' ') sch++;
                   }
               //   printf("tree node %d Node %d\n",sizeof(struct tree_node*), sizeof(struct Node*));
                 //  printf("maxnum%d",maxnum);
                   printf("1)Binary  search tree              %d bytes\n", sch*sizeof(struct tree_node));
                   printf("2)AVL tree                 %d bytes\n", sch*sizeof(struct Node));
                   printf("3)Chain method hash table  %d bytes\n", maxnum*sizeof(Node1)+ ((hashTableSize)* sizeof(Node1 *)));
                   printf("4)Open adress hash table   %d bytes\n", table_size*(sizeof(Node1)));

                   break;
             }
         }

     } while(1);
return 0;
}
