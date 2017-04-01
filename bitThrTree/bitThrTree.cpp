#include <stdio.h>
#include <stdlib.h>

typedef enum {Link, Thread} PointerTag;

typedef struct bitThrTree
{
	char data;
	struct bitThrTree *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;	
}bitThrNode;

bitThrNode *pre;//指向刚才指向的元素 

void createTree(bitThrTree **tree)
{
	char c;
	scanf("%c",&c);
	if( ' ' == c )
	{
		*tree = NULL;
	}
	else
	{
		*tree = (bitThrNode *)	malloc(sizeof(bitThrNode));
		(*tree)->data = c;
		
		(*tree)->ltag = Link;
		(*tree)->ltag = Link;		
		
		createTree(&(*tree)->lchild);
		createTree(&(*tree)->rchild);		
	}
}


void inThreading(bitThrNode * tree)
{
	if(tree)
	{
		inThreading( tree->lchild);
		if ( !tree->lchild)
		{
			tree->ltag = Thread;
			tree->lchild = pre;
	
		}
		if( !pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = pre;
		}
		pre = tree;
		inThreading( tree->rchild);	
	}
}

void InOrderThreading ( bitThrNode **p, bitThrNode * tree)
{
	*p = (bitThrNode *)malloc(sizeof(bitThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread; 
	(*p)->lchild = NULL;
	if( !tree )
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild =  tree;
		pre = *p;
		inThreading(tree);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}
void visit(char c)
{
	printf("%c", c);
}
void inTravel(bitThrNode *p)
{
	bitThrNode *tree;
	tree = p->lchild;
	while( p != tree)
	{
		while(tree-> ltag == Link ) 
		{
			tree = tree->lchild;
		}
		visit(tree->data);
		while( tree->rtag == Thread && tree->rchild != p)
		{
			tree = tree->rchild;
			visit(tree->data);
		}
		tree = tree->rchild;
	}

	
}

int main()
{
	bitThrNode *P, *T = NULL;
	createTree(&T);
	InOrderThreading(&P, T);
	printf("\n\n");
	inTravel(P);
	
}
