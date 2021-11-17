
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int capacity;
	int top;
}ST;

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	ps->capacity = 4;
	ps->top = 0;
}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;

}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;

		}
	}
	ps->a[ps->top] = x;
	ps->top++;

}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	return ps->top;
}
int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

bool isVaild(char* s)
{
	ST st;
	StackInit(&st);
	while (*s != '\0')
	{
		switch (*s)
		{
		case '{':
		case '[':
		case '(':
		{
			StackPush(&st, *s);
			++s;
			break;
		}
		case '}':
		case ']':
		case ')':
		{
			if (StackEmpty(&st))
			{
				StackDestory(&st);
				return false;
			}
			char top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{') || (*s == ')' && top != '(') || (*s == ']' && top != '['))
			{
				StackDestory(&st);
				return false;
			}
			else
			{
				++s;
			}
			break;
		}
			
		default:
			break;
	}
	StackDestory(&st);
	return true;

}