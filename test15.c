
//��Ŀ����
//�������У���һ���������ݸ������ڶ�����������n���������ÿո�ֿ���������������Ҫɾ��������m
//������������е�һ��������ɾ����ĵ������ȵڶ�������������ɾ����ĵ���������
#include<stdio.h>
struct Node
{
	int data;
	struct Node* next;
};

int main()
{
	struct Node* list = NULL;
	struct Node* tail = NULL;
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int m = 0;
	int d = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		struct Node *pn=malloc(sizeof(struct Node));
		pn->data = m;
		pn->next = NULL;

		if (list == NULL)
		{
			list = pn;
			tail = pn;
		}
		else
		{
			tail->next = pn;
			tail = pn;
		}
	}
	scanf("%d", &d);
	struct Node* cur = list;
	struct Node* pri = NULL;
	while (cur)
	{
		if (cur->data = d)
		{
			struct Node* pd = cur;
			if (cur = list)
			{
				list = list->next;
				cur = list;
			}
			else
			{
				pri->next = cur->next;
				cur = cur->next;


			}
			free(pd);
		}
		else
		{
			cur = cur->next;
		}

	}
	print("%d", n);
	while (cur)
	{
		printf("%d", cur->data);
		cur = cur->next;

	}
	cur = list;
	struct Node* del = NULL;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}
	list = NULL;
	return 0;
}