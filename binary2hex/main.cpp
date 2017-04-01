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
    ElemType c;
    Sqstack input , output;
    int len, i, flag, sum=0;
    InitStack(&input);
    InitStack(&output);
    cout <<"input your binary number: \n";
    scanf("%c",&c);
    while(c >= '0' && c <= '1')
    {
        Push(&input, c);
        scanf("%c",&c);
    }
    len = StackLen(input);
    flag = 0;
    for(i = 0; i < len; i++)
    {
        Pop(&input, &c);
        sum += (c-48) * pow(2,flag);
        flag++;
        if(flag > HEX)
        {
            switch(sum)
            {
                case 10: sum = 'A';break;
                case 11: sum = 'B';break;
                case 12: sum = 'C';break;
                case 13: sum = 'D';break;
                case 14: sum = 'E';break;
                case 15: sum = 'F';break;
                default: sum += 48;
            }
            Push(&output, char(sum));
            sum = 0;
            flag =0;
        }
    }
    if(sum)
    {
        Push(&output, char(sum+48));
    }

    len = StackLen(output);
    for(int i = 0; i < len; i++)
    {
        Pop(&output,&c);
        printf("%c",c);
    }
    //cout<<"转化为十进制是："<<sum<<endl;
    return 0;
}
