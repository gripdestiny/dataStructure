#include <iostream>
#include <stdio.h>

#define OK 1
#define Error 0

typedef int Elemtype;
typedef int Status;

typedef struct LNode
{
	Elemtype data;
	struct LNode *next;		
}LNode, *LinkList;

//��ʼ�� 
Status Initlist(LNode *L)
{
	L->next=NULL;
}

//����
Status ListInsert(LNode *L, int i, Elemtype e) 
{
	int j=0;
	LNode *p = L;

	while(p && j < i-1)
	{
		p = p->next;
		j++;	
	}
	
	if(!p || j >= i)
	{
		return Error;
	}
	LinkList q = (LNode *)malloc(sizeof(LNode));	
	q->data = e;
	q->next = p->next;
	p->next = q; 
	return OK;
}

//��ȡָ��λ��Ԫ��
Status getElem(LinkList L, int i, Elemtype *e) 
{
	int j=0;
	LNode *p = L;

	while(p && j < i)
	{
		p = p->next;
		j++;	
	}	
	if(!p || j > i)
	{
		return Error;
	}
	*e = p->data;	
}
//ɾ��ָ��λ��Ԫ��
Status ListDelete(LinkList L, int i, Elemtype *e) 
{
	int j=0;
	LNode *p = L;

	while(p && j < i-1)
	{
		p = p->next;
		j++;	
	}
	
	if(!p || j >= i)
	{
		return Error;
	}
	LinkList q;
	q = p->next;
	*e = q->data;
	p->next=q->next;
	free(q)	;
	return OK;
}
int main()
{
	LNode L;
	Elemtype e;
	Initlist(&L);
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 3, 4);
	ListDelete(&L, 2, &e);
	getElem(&L,2,&e);
	printf("%d \n", e);
	
	return 0;
}
