#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef char DataType;

typedef struct BNode
{
	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}Node;

Node* CreatBinaryTree(DataType arr[], int* idx) 
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;	//空结点
	}
	//当前树的根节点
	Node* root = (Node*)malloc(sizeof(Node));
	if (root != NULL)
	{
		root->_data = arr[*idx];
	}
	else
		return NULL;
	(*idx)++;

	root->_left = CreatBinaryTree(arr, idx);
	root->_right = CreatBinaryTree(arr, idx);

	return root;
}
void InOrder(Node* root)
{
	if (root != NULL)
	{
		//左子树
		InOrder(root->_left);
		//根
		printf("%c ", root->_data);
		//右子树
		InOrder(root->_right);
	}
}

int main()
{
	char str[101];
    while(scanf("%s", &str) != EOF)
    {
       int idx = 0;
       Node* root = CreatBinaryTree(str, &idx);
       InOrder(root);
       printf("\n");
    }
	return 0;
}