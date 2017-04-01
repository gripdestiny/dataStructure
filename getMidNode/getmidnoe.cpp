#include <iostream>
#include <stdio.h>
#define numOfElem 5

using namespace std;

typedef int Elemtype;
 
typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}LNode, *LinkList;

void createList(LinkList L)
{
	L->next=NULL;


	for (int i = 0; i < numOfElem; i++)
	{
		LinkList p = (LinkList) malloc(sizeof(LNode));
		if(!p)
		{
			exit(0);
		}		
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
}

Elemtype findMidElem(LinkList L)
{
	LinkList p, q;
	p = L->next;
	q = L->next;
	while(q->next!=NULL)
	{
		if(q->next->next != NULL)
		{
			p = p->next;
			q = q->next->next;
		}
		else
		{
			q = q->next;
		}
	}
	return p->data;
}
 
int main()
{
	LNode L;
	createList(&L);
	LinkList p;
	p=L.next;
	cout<<"Ô­±í£º";
	for (int i = 0; i < numOfElem; i++)
	{
		cout<<p->data<<" ";
		p = p->next ;
	}	
	cout<<endl<<findMidElem(&L)<<endl;
	
	return 0;	
}
