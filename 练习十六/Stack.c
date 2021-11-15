#include"Stack.h"
#include<assert.h>
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
	return ps->a[ps->top-1];
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