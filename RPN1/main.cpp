#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

const int OK = 1;
const int ERROR = 0;
const int MAXSIZE = 100;
const int INCREMENT = 10;
const int HEX = 3;
const int OCT = 2;

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
    Sqstack s1, s2;
    char c, e;
    InitStack( &s1 );
    InitStack( &s2);
    cout<<"input you equation: ";
    scanf("%c", &c);
    while( c != '#')
    {
        if(isdigit(c))
        {
            cout<<c;
            //Push(&s2, c);
        }
        else if(')' == c)
        {
            Pop(&s1, &e);
            while('(' != c)
            {
                //Push(&s2, e);
                cout<<e;
                Pop(&s1, &e);
            }
        }
        else if('+' == c || '-' == c)
        {
            if(!StackLen(s1))
            {
                Push(&s1,c);
            }
            else
            {
                do
                {
                    Pop(&s1, &e);
                    if('('==e)
                    {
                        Push(&s1, e);
                    }
                    else
                    {
                        cout<<e;
                        Push(&s2 ,e);
                    }
                }while(StackLen(s1) && '('==c);
                Push(&s1, c);
            }
        }
        else if('*' == c || '/' == c)
        {
            Push(&s1, c);
        }
        else
        {
            cout<<"Error !";
            return -1;
        }
        scanf("%c",&c);
    }


    while(!StackLen(s2))
    {
        Pop(&s2, &e);
        cout<<e<<" ";
    }

}
