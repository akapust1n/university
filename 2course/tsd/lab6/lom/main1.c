
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct tree_node* lookup_1(struct tree_node *tree, const char *name)
{
    int cmp;

    if (tree == NULL)
        return NULL;

    cmp = strcmp(name, tree->name);
    if (cmp == 0)
        return tree;
    else if (cmp < 0)
        return lookup_1(tree->left, name);
    else
        return lookup_1(tree->right, name);
}

struct tree_node* lookup_2(struct tree_node *tree, const char *name)
{
    int cmp;

    while (tree != NULL)
    {
        cmp = strcmp(name, tree->name);

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
        fprintf(f, "%c -> %c;\n", tree->name, tree->right->name);
}

void export_to_dot(FILE *f, const char *tree_name, struct tree_node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);
 printf("all is normal here\n");
    apply_pre(tree, to_dot, f);

    fprintf(f, "}\n");
}

int main(void)
{
    struct tree_node *root = NULL;
    struct tree_node *node;


/*for(int i=0;i<7;i++)
{char uu[2];
 uu[0]=i+97;
 uu[1]='\0';

    node = create_node(uu);
    assert(node);
    assert(lookup_1(root, node->name) == NULL);
    root = insert(root, node);
}
*/

    char uu[2];
     uu[0]='a';
     uu[1]='\0';
     printf("%d %d", sizeof("a"),sizeof(uu));
    node = create_node(uu[0]);

    //assert(node);
    //assert(lookup_1(root, node->name) == NULL);
    root = insert(root, node);

    uu[0]='c';
    uu[1]='\0';
    node = create_node(uu[0]);
    //assert(node);
   // assert(lookup_1(root, node->name) == NULL);
    root = insert(root, node);
/*
    node = create_node("d");
    assert(node);
    assert(lookup_1(root, node->name) == NULL);
    root = insert(root, node);

    node = create_node("i");
    assert(node);
    assert(lookup_2(root, node->name) == NULL);
    root = insert(root, node);

    node = create_node("f");
    assert(node);
    assert(lookup_2(root, node->name) == NULL);
    root = insert(root, node);

    node = create_node("g");
    assert(node);
    assert(lookup_2(root, node->name) == NULL);
    root = insert(root, node);
*/
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

    apply_post(root, free_node, NULL);
    system("dot test.gv -Tpng -og.png");
    system("g.png");
}
