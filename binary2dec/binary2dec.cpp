#include <iostream>
#include <stdlib.h>
using namespace std;

const int OK = 1;
const int ERROR = 0;
const int MAXSIZE = 100;
const int INCREMENT = 10;

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType *top;
    ElemType *base;
    int stacksize;
}Sqstack;
//��ʼ��
Status InitStack(Sqstack *s)
{
    s->base = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    s->top = s->base;
    s->stacksize = MAXSIZE;
    return OK;
}
//��ջ
Status Push(Sqstack *s, ElemType e)
{
    if(s->top == s->base + s->stacksize)
    {
        s->base = (ElemType*) realloc(s->base,(s->stacksize+INCREMENT)*sizeof(ElemType));
        s->top = s->base + s->stacksize;
        s->stacksize = s->stacksize+INCREMENT;
    }
    if(!s->base)
    {
        exit(0);
    }
    *(s->base) = e;
    s->top++;
    return OK;
}
//��ջ
Status Pop(Sqstack *s, ElemType *e)
{
    if(s->top == s->base)
    {
        return ERROR;
    }
    *e = *--(s->top);
    return OK;
}

//���*
Status ClearStact(Sqstack *s)
{
    s->top = s->base;
    return OK;
}

//����
Status DestroyStack(Sqstack *s)
{
    int i, len;
    len =s->stacksize;
    for(i = 0; i < len; i++)
    {
        free(s->base);
        s->base++;
    }
    s->base = s->top = NULL;
    s->stacksize = 0;
    return OK;
}

//ջ�ĳ���
int StackLen(Sqstack s)
{
    return (s.top - s.base);
}

int main()
{
    ElemType c,e;
    int a;
    Sqstack s;
    int len, i, sum=0;

	InitStack(&s);
	
    cout <<"�����������������#����:";
	cin >> c;
	Push(&s, c);
    Pop(&s, &e);
    cout<<"e="<< e << " ";
    return 0;
}
