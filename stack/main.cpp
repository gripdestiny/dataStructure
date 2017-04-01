#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

const int OK = 1;
const int ERROR = 0;
const int MAXSIZE = 100;
const int INCREMENT = 10;

typedef int Status;
typedef char ElemType;

typedef struct
{
    ElemType *top;
    ElemType *base;
    int stacksize;
}Sqstack;
//初始化
Status InitStack(Sqstack *s)
{
    s->base = (ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    s->top = s->base;
    s->stacksize = MAXSIZE;
    return OK;
}
//入栈
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
    *(s->top) = e;
    s->top++;
    return OK;
}
//出栈
Status Pop(Sqstack *s, ElemType *e)
{
    if(s->top == s->base)
    {
        return ERROR;
    }
    *e = *--(s->top);
    return OK;
}

//清空*
Status ClearStact(Sqstack *s)
{
    s->top = s->base;
    return OK;
}

//销毁
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

//栈的长度
int StackLen(Sqstack s)
{
    return (s.top - s.base);
}

int main()
{
    ElemType c;
    Sqstack s;
    int len, i, sum=0;
    InitStack(&s);
    cout <<"请输入二进制数，以#结束： \n";
    scanf("%c",&c);
    while(c >= '0' && c <= '1')
    {
        Push(&s, c);
        scanf("%c",&c);
    }
    len = StackLen(s);
    for(i = 0; i < len; i++)
    {
        Pop(&s, &c);
        sum += (c-48) * pow(2,i);
    }
    cout<<"转化为十进制是："<<sum<<endl;
    return 0;
}
