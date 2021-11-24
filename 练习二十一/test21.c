#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

typedef char BTdata;
typedef struct BinaryTreeNode
{
	struct BinaryNode* left;
	struct BinaryreeNode* right;
	BTdata data;

}BTNode;

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
		
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);

}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PreOrder(root->left);
	printf("%c ", root->data);
	PreOrder(root->right);

}
void LastOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PreOrder(root->left);
	PreOrder(root->right);
	printf("%c ", root->data);

}
int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = E;
	B->left = C;
	B->right = D;

	PreOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	LastOrder(A);
	printf("\n");


	return 0;
}