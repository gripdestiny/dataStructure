#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct DulaNode
{
    ElemType data;
    struct DulaNode *next;
    struct DulaNode *prior;
}DulaNode, *DuLinkList;

Status InitList(DuLinkList *L)
{
    DulaNode *p, *q;
    int i;
    *L = (DuLinkList) malloc(sizeof(DulaNode));
    if( !( *L) )
    {
        return ERROR;
    }

    (*L)->next = (*L)->prior = NULL;
    p = (*L);
    for(i = 0; i < 26; i++)
    {
        q = (DulaNode*)malloc(sizeof(DulaNode));
        if(!q)
        {
            return ERROR;
        }
        q->data = 'A'+i;
        q->next = p->next;
        q->prior = p;
        p->next = q;
        p = q;
    }
    p->next = (*L)->next;
    (*L)->next->prior = p;
    return OK;
}

void Caesar(DuLinkList *L, int i)
{
    if(i > 0)
    {
        do
        {
            (*L)=(*L)->next;
        }while(--i);
    }
    if(i < 0)
    {
        (*L) = (*L)->next;
        do
        {
            (*L) = (*L)->prior;
        }while(i++);
    }
}

int main()
{
    DuLinkList L;
    InitList(&L);
    Caesar(&L, -26);
    for(int i = 0; i < 26; i++)
    {
        L=L->next;
        cout<<L->data<<" ";
    }
    system("pause");
    return 0;
}
