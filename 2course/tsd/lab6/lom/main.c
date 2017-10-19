#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include <iostream>

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
    if (cmp == 0)
    {
        assert(1);
    }
    else if (cmp < 0)
    {
        tree->left = insert(tree->left, node);
    }
    else
    {
        tree->right = insert(tree->right, node);
    }

    return tree;
}

struct tree_node* lookup_1(struct tree_node *tree,char name)
{
    int cmp;

    if (tree == NULL)
        return NULL;

   // cmp = strcmp(name, tree->name);
    if (name==tree->name) {cmp=0;}
    else
        if ( name> tree->name) cmp=1 ;
        else cmp=-1;
    if (cmp == 0)
        return tree;
    else if (cmp < 0)
        return lookup_1(tree->left, name);
    else
        return lookup_1(tree->right, name);
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

        if (cmp == 0)
            return tree;
        else if (cmp < 0)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return NULL;
}

void apply_pre(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg)
{
    if (tree == NULL)
        return;

    f(tree, arg);
    apply_pre(tree->left, f, arg);
    apply_pre(tree->right, f, arg);
}

void apply_in(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg)
{
    if (tree == NULL)
        return;

    apply_in(tree->left, f, arg);
    f(tree, arg);
    apply_in(tree->right, f, arg);
}

void apply_post(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg)
{
    if (tree == NULL)
        return;

    apply_post(tree->left, f, arg);
    apply_post(tree->right, f, arg);
    f(tree, arg);
}

void print(struct tree_node *node, void *param)
{
    const char *fmt = param;

    printf(fmt, node->name);
}

void free_node(struct tree_node *node, void *param)
{
    free(node);
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

void export_to_dot(FILE *f, const char *tree_name, struct tree_node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);
    apply_pre(tree, to_dot, f);


}
struct tree_node *min(struct tree_node  *x)
 { if (x->left == NULL)
     return x;

  return min(x->left);
 }
//пробуем удалить элемент из дерева
struct tree_node* delete1(struct tree_node* root , char z)              // корень поддерева, удаляемый ключ
{
   if (root == NULL)
     return root;
  // Node *x=root;
 if (z < root->name)
   root->left = delete1(root->left, z);
 else
     if (z > root->name)
   (root->right) = delete1(root->right, z);
 else
     if (root->left != NULL && root->right != NULL)
  { struct tree_node *tmp=malloc(sizeof(struct tree_node));
         tmp=min(root->right);
   root->name = tmp->name;
   root->right = delete1(root, root->right->name);}
 else
   if (root->left != NULL)
     root = root->left;
   else
     root = root->right;
 //root=x;
 return root;
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
    printf("2)Add one letter \n");
    printf("3)Delete letter\n");
    printf("4)Show graph \n");
    printf("5)Delete repeating elements \n");
    printf("6)Bypass graph pre-order\n");
    printf("7)Bypass graph in-order\n");
    printf("8)Bypass graph post-order\n");
    printf("9)Find element\n");
    printf("10)Exit\n>>");

    scanf("%d",&i);
    return i;
}

void retree(int abc[], struct tree_node *root,struct tree_node *node)
{
    root=NULL;
    for (int i=0;abc[i]!=0;i++)
       {
        node = create_node(abc[i]);
        printf("Name %c",node->name );
       // printf("one");
       root = insert(root, node);
    }

}

int main(void)
{
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


         for(int i=0;i<strlen(line);i++)
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
        case 2:{
            char u[2];
            printf("Input letter:");
            fflush(stdin);
            gets(u);
            int p=tolower(u[0]);
            letter[p-'a']++;

            strcat(line,u);
            puts(line);
            node = create_node(u[0]);

        printf("\nElement was successfully to line\n");
          if (lookup_2(root, node->name) != NULL)
          {
              printf("\nTree just has such element.Element didnt add to tree.\n");
              break;
          }
        printf("\nElement was successfully to tree\n");
        int i=0;
        for(;abc[i];i++);
            abc[i]=u[0];
            printf("NUMBER %d",i);
           root = insert(root, node);
            break;
        }
        case 3:
        {
            char a;
            printf("Input letter: ");
            fflush(stdin);
            scanf("%c",&a);
            int i;
            for( i=0;abc[i];i++) //проверяем есть ли такая буква
               if (abc[i]==a) break;
            if (!abc[i])
            {
                printf("There arent this element");
                break;
            }
            //printf("hm2");
               for(int i=0;abc[i];i++) printf("%c", abc[i]);
            letter[a-'a']=0;

            int size;
            for (size=0;abc[i]; i++,size++); //размер abc
              size++;
             for( i=0;abc[i];i++)
                    if (abc[i]==a) {
                        abc[i]=0;
                        break;
                    }
                for (int j = i; j<=size; j++)
                {//printf(" before %c \n",abc[j]);
                    abc[j] = abc[j+1];
                   // printf("%c \n",abc[j]);
                }
                //abc[size]=0;


            break;
        }
        case 4:
        {
          // for (int i=0;abc[i]!=0;i++) printf("%c\n",abc[i]);
           root = NULL; //обнуляем дерево
             for (int i=0;abc[i]!=0;i++)
                {

                 node = create_node(abc[i]);

                 //printf("Name %c",node->name );
               // assert(node);
               // printf("em");
               // assert(lookup_1(root, node->name) == NULL);
                root = insert(root, node);
             }
             apply_pre(root, print, "%c ");
             printf("\n");
            // работа с файлом и вывод
            FILE *f = fopen("test.gv", "w");
            assert(f);
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
        case 5:
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
                    printf("abc%c\n",abc[i]);

               root = insert(root, node);
            }
         apply_pre(root, print, "%c ");

           // delete1(root,'l');
           //dtree(root,'l'); // я не понимаю почему
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
             {char c=letter[k];
             int i = 0;//индекс для исходной строки
              int j = i;//индекс для модифицированной строки

              //цикл модификации исходной строки

              while (line[i])//пока в строке не нулевой байт
              {
                  //проверить текущий символ строки
                  if(line[i] != c) //если s[i] не равен 'a'

                  //переписать текущий символ строки по новому индексу j
                  // и  увеличить индекс j единицу
                      line[j++] =  line[i];
                  // и увеличить индекс i на единицу
                      i++;
              }
               //запись нулевого байта в конец модифицированной строки
              line[j] = '\0';
             }
             clock_t time_end2=tick();
             printf("\nTime of deleting from line:%e secunds %d ticks\n",(time_end2-time_start2)/2900000.0,(time_end2-time_start2));

            FILE *f = fopen("test.gv", "w");
            assert(f);
            export_to_dot(f, "test_tree", root);
              fprintf(f, "}\n");
            fclose(f);
            system("dot test.gv -Tpng -og.png");
            system("g.png");
            break;
            //заполняем дерево заново(чисто в угоду подсчету времени)

        }
         case 6:
        {
            printf("Pre-order:");
            apply_pre(root, print, "%c ");
            printf("\n");
            break;
        }
        case 7:
       {
           printf("In-order:");
           apply_in(root, print, "%c ");
           printf("\n");
           break;
       }
        case 8:
       {
           printf("Post-order:");
           apply_post(root, print, "%c ");
           printf("\n");
           break;
       }
        case 9:
        {
          char a;
          printf("Input letter: ");
          fflush(stdin);

          scanf("%c",&a);

           clock_t time_start=tick();
          if (lookup_2(root, a) == NULL)
          {
              printf("\nThere arent this element\n");
          }
           clock_t time_end=tick();
          printf("\nTime of search:%e secunds %d ticks",(time_end-time_start)/2900000.0,(time_end-time_start));

        //  node = create_node(a);
         //root = insert(root, a);
          printf("\nSubtree post-order");
           apply_post(lookup_2(root, a), print, "%c ");

        }
        }
        }
       while(y!=0);


    apply_pre(root, print, "%c ");
    printf("\n");

    apply_in(root, print, "%c ");
    printf("\n");

    apply_post(root, print, "%c ");
    printf("\n");

    {
        FILE *f = fopen("test.gv", "w");

        assert(f);

        export_to_dot(f, "test_tree", root);

        fclose(f);
    }
system("dot test.gv -Tpng -og.png");
system("g.png");
    apply_post(root, free_node, NULL);
}
