#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;
using namespace std;

typedef struct
{
    ElemType data;
    ElemType *next;
}QNode;

typedef struct
{
    QNode *front;
    QNode *rare;
}LinkQueen;

Status InitQueen(LinkQueen *q)
{
    q->front = q->rare =(QNode *)malloc(sizeof(QNode));
    if(!q->rare)
    {
        return -1;
    }
    q->rare->next = NULL;
    return 0;
}

Status InsertQueen(LinkQueen *q, ElemType e)
{
    QNode *p  = (QNode *)malloc(sizeof(QNode));
    if(!p)
    {
        return -1;
    }
    p->next = NULL;
    q->rare->next = p;
    q->rare = p;
    q->rare->data = e;
}

Status DeleteQueen(LinkQueen *q, ElemType *e)
{
    if( q->front == q->rare)
    {
        return -1;
    }
    QNode *p = q->front->next;
    q->front->next = p->next;
    *e = p->data;
    if(!p->next)
    {
        q->rare = q->front;
    }
    free(p);
    return 0;
}

Status Destroy(LinkQueen *q)
{
    ElemType e;
    while(q->rare != q->front)
    {
        DeleteQueen(q, &e);
    }
    free(q->front);
}

int main()
{
    LinkQueen q;
    InitQueen( &q );
    cout << "请输入一系列字符，以#表示结束：" << endl;
    ElemType c = scanf("%c", c);
    while(c != '#')
    {
        InsertQueen(&q, c);
        c = scanf("%c", c);
    }
    while(q.front != q.rare)
    {
        DeleteQueen(&q, &c);
        cout<<c;
    }
    cout<<endl;


    return 0;
}
