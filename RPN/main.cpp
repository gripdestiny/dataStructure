/***********************************/
/**************逆波兰表达式***********/
/***********************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

const int OK = 1;
const int ERROR = 0;
const int MAXSIZE = 100;
const int INCREMENT = 10;
const int MAXBUFFER = 10;

typedef int Status;
typedef double ElemType;

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
    int i = 0;
    Sqstack s;
    char c, str[MAXBUFFER];
    double num1,num2;
    InitStack(&s);
    cout<<"Please input your RPN data: \n";
    scanf("%c", &c);
    while('#' != c)
    {
        while( isdigit(c) || c == '.')
        {
            str[i++] = c;
            str[i] = '\0';
            if( i >= 10)
            {
                cout<<"Error: the data is too big";
                return -1;
            }
            scanf("%c", &c);
            if(c == ' ')
            {
                 num1 = atof(str);
                 Push(&s, num1);
                 i = 0;
                 break;
            }
        }
        switch( c )
        {
            case '+' :
                Pop(&s, &num1);
                Pop(&s, &num2);
                Push(&s, num1+num2);
                break;
            case '-' :
                Pop(&s, &num1);
                Pop(&s, &num2);
                Push(&s, num2-num1);
                break;
            case '*' :
                Pop(&s, &num1);
                Pop(&s, &num2);
                Push(&s, num1*num2);
                break;
            case '/':
                Pop(&s, &num1);
                Pop(&s, &num2);
                if(num1)
                {
                    Push(&s, num2/num1);
                }
                else
                {
                    cout<<"Error: is zero！";
                    return -1;
                }
                break;

        }
        scanf("%c", &c);
    }
    Pop(&s, &num1);
    cout<<"The result is : "<<num1<<endl;
}
