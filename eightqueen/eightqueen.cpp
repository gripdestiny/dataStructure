#include <stdio.h>

typedef int Stasus;
#define dangerous 0
#define notdangerous 1 
int  chess[8][8];
int count = 1;
//打印棋盘 
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
//左上 
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
//右下 
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
//右上 
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
//左下 
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

//上方
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

//下方
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

//右方
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

//左方
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
		printf("第%d种摆放方式：\n", count);
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
