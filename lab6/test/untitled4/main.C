#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
FILE *f = fopen("yy.txt","w"); //лень морочиться с файлом))
struct Node
  {char key ;                   // ключ узла
  Node *left ;               // указатель на левого потомка
  Node *right  ;             // указатель на правого потомка
  Node *parent;              // указатель на предка
  };
void inorderTraversal(Node *x)
  { if (x != NULL)
      {inorderTraversal(x->left);
      cout<<setw(2)<<x->key;
      inorderTraversal(x->right);}
      return ;
    }


//нерекурсивная реализаця
void insert(Node *&x, char u)            // x — корень поддерева, z — вставляемый элемент
   {
    Node *z=new Node;
    z->key=u;
    z->left=z->right=NULL;
    //cout<<x;
    if (x== NULL) { //создание дерева

            Node* tmp = new Node ;
             tmp->left = tmp->right = NULL;
             tmp->key = u;
            tmp->parent = NULL;
           x=tmp;
// cout<<"inside "<<x->key<<" "<<(x==NULL)<<endl;
          return;
       }
    //cout<<"\noutside";
    Node *y=x;
    while (x != NULL)
    {  cout<<"\nLR "<<x->left<<x->right;
        if (z->key > x->key)
        if (x->right != NULL)
           x = x->right;
        else
          { z->parent = x;
           x->right = z;
           break;
        }
     else if (z->key < x->key)
        if (x->left != NULL)
           x = x->left;
        else
          { z->parent = x;
           x->left = z;
           break;}}
    x=y;
   return;
   }

Node *minimum(Node *x)
 { if (x->left == NULL)
     return x;

  return minimum(x->left);
 }
Node *delete1(Node *&root , char z)              // корень поддерева, удаляемый ключ
 {
    if (root == NULL)
      return root;
   // Node *x=root;
  if (z < root->key)
    root->left = delete1(root->left, z);
  else
      if (z > root->key)
    (root->right) = delete1(root->right, z);
  else
      if (root->left != NULL && root->right != NULL)
   { root->key = minimum(root->right->right)->key;
    root->right = delete1(root, root->right->key);}
  else
    if (root->left != NULL)
      root = root->left;
    else
      root = root->right;
  //root=x;
  return root;
 }

void printTree(Node *root, const char *dir, int level) {
    if (root) {
        printf("lvl %d %s = %c\n", level, dir, root->key);
        printTree(root->left, "left", level+1);
        printTree(root->right, "right", level+1);
    }
}
Node *search( Node *&x, char k)
  { if (x == NULL || k == x->key)
      return x;
   if (k < x->key)
      return search(x->left, k);
   else
      return search(x->right, k);
  }
//переводим в дот
void to_dot(Node *x)
{


    if (x->left)
        fprintf(f, "%s -> %s;\n", x->key, x->left->key);

    if (x->right)
        fprintf(f, "%s -> %s;\n", x->key, x->right->key);
}
void  preorderTraversal_apply(Node *x)
  { if (x != NULL)
      {
        //cout<<setw(2)<< x->key;
        to_dot(x);
      preorderTraversal_apply(x->left);
      preorderTraversal_apply(x->right);
    }
    return;
  }

//обход для перевода в dot
void apply(Node *tree,
                 void (*f)(Node *),  void *arg)
{
    if (tree == NULL)
        return;

    // pre-order
     f(tree);
    apply(tree->left, f, arg);
    // in-order
   // f(tree, arg);
   // apply(tree->right, f, arg);
   // // post-order
    // f(tree, arg);
}

//экспорт в dot
void export_to_dot( const char *tree_name,
                                       Node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);
  preorderTraversal_apply(tree);
    //apply(tree, to_dot, f);
  // preorderTraversal(Node *x);
    fprintf(f, "}\n");
}



int main()
{

      Node *root = NULL;
      cout<<"before a"<<root;

cout<<"after a"<<root;
        insert(root, 'b');
        insert(root, 'c');
        insert(root, 'e');
        insert(root, 'i');
        insert(root, 'g');

        insert(root, 'l');
           insert(root, 'd');
        cout<<"LOL"<<endl;
        printTree(root, "root", 0);
       delete1(root , 'b') ;insert(root, 'a'); //хм, по идее смещается указатель, но чет все равно работает, лол
        //deleteValue(root, 4);
       // printf("parent of 7 is %d\n", getNodeByValue(root, 7)->parent->data);
        //printTree(root, "root", 0);
       // deleteValue(root, 8);
        //printTree(root, "root", 0);
        printf("------------------\n");
       // deleteValue(root, 10);
        printTree(root, "root", 0);
  inorderTraversal(root);
   printTree(search( root, 'e'), "root", 0);

   export_to_dot("tree_tree",root);
return 0;
}
