#include <stdio.h>
#include <stdlib.h>
struct node_st{
    node_st *p1; 	// левая ветка
    node_st *p2; 	// правая ветка
    int value;	// значение узла
    int b; 		// фактор баланса
    };
node_st *Rotate12(node_st *node)
{
    static const int array[6][4]={
        -1,-1,+1,+1,
        -1,+0,+1,+0,
        -1,+1,+2,+0,
        -2,-1,+0,+0,
        -2,-2,+0,+1,
        -2,+0,+1,-1
        };
    node_st *p1=node->p1;
    node_st *p12=p1->p2;
    p1->p2=node;
    node->p1=p12;
    for(int n=0;n<6;n++) if(array[n][0]==node->b && array[n][1]==p1->b) {
        p1->b=array[n][2];
        node->b=array[n][3];
        break;
    }
    return p1;
}
node_st *Rotate21(node_st *node)
{
    static const int array[6][4]={
        +1,-1,-2,+0,
        +1,+0,-1,+0,
        +1,+1,-1,-1,
        +2,+0,-1,+1,
        +2,+1,+0,+0,
        +2,+2,+0,-1
    };
    node_st *p2=node->p2;
    node_st *p21=p2->p1;
    p2->p1=node;
    node->p2=p21;
    for(int n=0;n<6;n++) if(array[n][0]==node->b && array[n][1]==p2->b) {
        p2->b=array[n][2];
        node->b=array[n][3];
        break;
    }
    return p2;
}
bool BalanceInsert(node_st **root)
{
    node_st *node=*root;
    if(node->b>1) {
        if(node->p2->b<0) node->p2=Rotate12(node->p2);
        *root=Rotate21(node);
        return true;
    }
    if(node->b<-1) {
        if(node->p1->b>0) node->p1=Rotate21(node->p1);
        *root=Rotate12(node);
        return true;
    }
    return false;
}
bool Insert(int value,node_st **root)
{
    bool res=false;
    node_st *node=*root;
    if(!node) {
        *root=NewItem(value);
        return true;
    }
    if(value==node->value) return false;
    if(value<node->value)   res=Insert(value,&node->p1) && !!--node->b;
    else                    res=Insert(value,&node->p2) && !!++node->b;
    if(BalanceInsert(root)) res=false;
    return res;
}
bool BalanceRemove(node_st **root,bool res)
{
    node_st *node=*root;
    if(node->b>1) {
        res=!!node->p2->b;
        if(node->p2->b<0) node->p2=Rotate12(node->p2);
        *root=Rotate21(node);
    }
    if(node->b<-1) {
        res=!!node->p1->b;
        if(node->p1->b>0) node->p1=Rotate21(node->p1);
        *root=Rotate12(node);
    }
    return res;
}
bool Remove(node_st **root,int value)
{
    bool ok=false;
    node_st *node=*root;
    if(!node) return ok;
    if(node->value<value) {
        if(Remove(&node->p2,value) && !--node->b) ok=true;
    }else if(node->value>value) {
        if(Remove(&node->p1,value) && !++node->b) ok=true;
    }else {					// нашли вершину кот. надо удалить
        if(!node->p2) {           	// если есть возможность вырезать сразу, вырезаем
            *root=node->p1;DelItem(node);
            return true;
        }
        ok=GetMin(&node->p2,root);   	// находим вершину, которую вставляем на место удалённой
        (*root)->b =node->b;		// ставим нашу замену на место удалённой вершины
        (*root)->p1=node->p1;
        (*root)->p2=node->p2;
        DelItem(node);
        if(ok) ok=!--(*root)->b;
    }
    return BalanceRemove(root,ok);
}
bool GetMin(node_st **root,node_st **res)
{
    node_st *node=*root;
    if(node->p1) {
        if(GetMin(&node->p1,res) && !++node->b) return true;
        return BalanceRemove(root,false);
    }
    *res=node;
    *root=node->p2;
    return true;
}
