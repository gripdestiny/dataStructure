#include <iostream>
#include <stdio.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int Elemtype; 

typedef struct List
{
	Elemtype data;
	struct List *next;
}cList, *LinkList;

Status InitList(LinkList L)
{
	L->next=L;
	return OK;
}

Status createList(LinkList L,int num)
{
	LinkList p;
	p = L;
	for(int i = 1; i <= num; i++)
	{
		LinkList q = (LinkList)malloc(sizeof(cList));
		if (!q)
		{
			exit(0);
		}
		q->data = num - i + 1;
		q->next = p->next;
		p->next = q;
	}

}

//Joseph
void Joseph(cList L, int num, int totalNum) 
{
	LinkList p, q;
	p = &L;  
	int k = 0;
	num %= totalNum;
	while(k < totalNum)
	{
		for(int i = 0; i < num ; i++)
		{
			p = p->next;
			//std::cout<< p->data<<" ";
			if( p->next == L.next )
			{
				p= p->next;
			}
			if( p->data == 0)
			{
				i--;
			}
		}
		std::cout<<p->data;
		if(k < totalNum-1)
		{
			std::cout<<"->";
		}
		p->data = 0;
		k++;
	}
}

int main()
{
	cList L,*p;
	InitList(&L);
	
	createList(&L, 41);
	p = L.next;
	std::cout<<"原本的序列：";
	for(; p != &L; )
	{
		std::cout<<p->data<<" ";
		p = p->next;
	}
	std::cout<<std::endl; 
	Joseph(L,3, 41);
	std::cout<<std::endl;
} 
