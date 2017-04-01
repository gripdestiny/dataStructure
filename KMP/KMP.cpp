#include <stdio.h>
#include <string.h>
void getNext(char *T, int * next)
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while( i < T[0])
	{
		if( j == 0 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP(char *S, char *T, int Pos)
{
	int i = Pos;
	int j = 0;
	int next[255];
	getNext(T, next);
	while( i <= S[0] && j <= T[0])
	{
		if (j == 0 || T[j] == S[i])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	
	if( i > S[0])
	{
		return 0;
	}
	if( j > T[0])
	{
		return i - j + 1 ;
	}
}

int main()
{
	char S[] = " aabcaadef";
	char T[] = " aad";
	T[0] = strlen(T) - 1;
	S[0] = strlen(S) - 1;	
	

	printf("%d", KMP(S, T, 1));
	
}
