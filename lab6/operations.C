#include<iostream>

using namespace std;

#define MAX_LETTER 20

struct tree { //структура для дерева
  char info;
  struct tree *left;
  struct tree *right;
};

struct tree rt;

struct tree *stree( //симметричный обход дерева
  struct tree *root,
  struct tree *r,
  char info)
{
  if(!r) {
    r = (struct tree *) malloc(sizeof(struct tree));
    if(!r) {
      printf("Не хватает памяти\n");
      exit(0);
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    if(!root) return r; /* первый вход */
    if(info < root->info) root->left = r;
    else root->right = r;
    return r;
  }
  if(info < r->info)
    stree(r,r->left,info);
  else
    stree(r,r->right,info);

  return root;
}
//обход дерева
void inorder(struct tree *root) //иникснвй обход дерева
{
  if(!root) return;

  inorder(root->left);
  if(root->info) printf("%c ", root->info);
  inorder(root->right);
}
//печать дерева
void print_tree(struct tree *r, int l)
{
  int i;

  if(r == NULL) return;

  print_tree(r->right, l+1);
  for(i=0; iinfo);
  print_tree(r->left, l+1);
}
int main()
{
    char tree[MAX_LETTER];
    gets(tree);

    return 0;
}
