#include <stdio.h>
#include <stdlib.h>
typedef  struct bitTree
{
	char data;
	struct bitTree *lchild, *rchild;
}bitTreeNode;

void createBitTree(bitTreeNode **tree)
{
	char c;
	scanf("%c", &c);
	
	if( ' ' == c)
	{
		*tree = NULL;
	}
	else
	{
		*tree = (bitTreeNode* )	malloc(sizeof(bitTreeNode));
		(*tree)->data = c;
		createBitTree(&(*tree)->lchild);
		createBitTree(&(*tree)->rchild);
	}
}

void visit(char c, int level)
{
	printf("%c: %d ",c, level);
}

void preTraversing(bitTreeNode *T, int level)
{
	if( T )  
	{
		visit(T->data, level);
		preTraversing(T->lchild, level + 1)	;
		preTraversing(T->rchild, level + 1);
	}
}

int main()
{
	bitTreeNode *tree = NULL;
	createBitTree( &tree );
	preTraversing(tree, 0);
	//printf("%c", tree->data);
	return 0;
}
