#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int capacity;
	int top;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps,STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
int StackEmpty(ST* ps);



