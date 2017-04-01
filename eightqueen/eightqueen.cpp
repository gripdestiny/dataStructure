#include <stdio.h>

typedef int Stasus;
#define dangerous 0
#define notdangerous 1 
int  chess[8][8];
int count = 1;
//��ӡ���� 
void printChess(int chess1[8][8])
{
	for(int i = 0; i < 8; i++)	
	{
		for(int j = 0; j < 8; j++)
		{
			printf("%2d", chess1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//���� 
Stasus leftUP(int i, int j,int chess[8][8])
{
	while(--i >= 0 && --j >= 0)	
	{
			
		if( chess[i][j]==1 )
		{
			return dangerous;
		}
	}
	return notdangerous;
}
//���� 
Stasus rightDown(int i, int j,int chess[8][8])
{

	while(++i < 8 && ++j < 8)	
	{
	
		if( chess[i][j]==1 )
		{
			return dangerous;
		}
	}
	return notdangerous;	
}
//���� 
Stasus righrUp(int i, int j,int chess[8][8])
{
	while(++i < 8 && --j >= 0)	
	{

		if( chess[i][j]==1 )
		{
			return dangerous;
		}

	}
	return notdangerous;	
}
//���� 
Stasus leftDown(int i, int j, int chess[8][8])
{
	while(--i >=0 && ++j < 8)	
	{

		if( chess[i][j]==1 )
		{
			return dangerous;
		}

	}
	return notdangerous;	
}

//�Ϸ�
Stasus up(int i, int j, int chess[8][8])
{
	while(--i >=0 )	
	{

		if( chess[i][j]==1 )
		{
			return dangerous;
		}

	}
	return notdangerous;	
} 

//�·�
Stasus down(int i, int j, int chess[8][8])
{
	while(++i < 8 )	
	{

		if( chess[i][j]==1 )
		{
			return dangerous;
		}

	}
	return notdangerous;	
} 

//�ҷ�
Stasus right(int i, int j, int chess[8][8])
{
	while(++j < 8 )	
	{

		if( chess[i][j]==1 )
		{
			return dangerous;
		}

	}
	return notdangerous;	
} 

//��
Stasus left(int i, int j, int chess[8][8])
{
	while(--j >= 0 )	
	{

		if( chess[i][j]==1 )
		{
			return dangerous;
		}

	}
	return notdangerous;	
} 

Stasus notDangerous(int i, int j, int chess[8][8])
{
	if(leftDown(i, j, chess) && leftUP(i, j, chess) && righrUp(i, j, chess) && rightDown(i , j, chess)
		&& up(i, j, chess) && down(i, j, chess) && left(i, j, chess) && right(i, j, chess))
	{
		return notdangerous;
	}
	return dangerous;
}



void eightQueen(int (*chess)[8], int row, int col)
{
	int chess2[8][8];
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}
	if( 8 == row)
	{
		printf("��%d�ְڷŷ�ʽ��\n", count);
		printChess(chess2);
		count++;
		
	}
	else
	{
		for( int j = 0; j < col; j++)
		{
			if(notDangerous(row, j, chess))
			{
				for(int i = 0; i < 8; i++)
				{
					chess2[row][i] = 0;
				}
				chess2[row][j]=1;
				printChess(chess2);  				
				eightQueen(chess2, row + 1, col);
			}
		}
		
	}
}

int main()
{
	eightQueen(chess, 0 ,8);
//	printChess(chess);
	return 0;
}
