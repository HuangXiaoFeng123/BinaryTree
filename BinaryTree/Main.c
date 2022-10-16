#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <malloc.h>

typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

int num = 0;
int DepthVal = 0;

void BianLi(BinaryNode* root)			//二叉树前序遍历
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->ch);
	BianLi(root->lchild);
	BianLi(root->rchild);
}
void CalcNode(BinaryNode* root)			//计算叶子节点数
{
	if (root == NULL)
	{
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL)
	{
		num++;
	}
	CalcNode(root->lchild);
	CalcNode(root->rchild);
}
int DepthTree(BinaryNode* root)			//二叉树高度
{
	int DepthLeft = 0;
	int DepthRight = 0;
	if (root == NULL)
	{
		DepthVal = 0;
	}
	else
	{
		DepthLeft = DepthTree(root->lchild);
		DepthRight = DepthTree(root->rchild);
		DepthVal = DepthLeft > DepthRight ? DepthLeft : DepthRight;
	}
	return DepthVal + 1;
}
BinaryNode* CopyTree(BinaryNode* root)			//拷贝二叉树
{
	if (root == NULL)
	{
		return NULL;
	}
	BinaryNode* lchild = CopyTree(root->lchild);
	BinaryNode* rchild = CopyTree(root->rchild);
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	return newnode;
}
void FreeTree(BinaryNode* root)				  //释放二叉树
{
	if (root == NULL)
	{
		return;
	}
	FreeTree(root->lchild);
	FreeTree(root->rchild);
	free(root);
}
void CreateBinaryNode(void)					  //创建二叉树
{
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node1.rchild = &node6;
	node6.rchild = &node7;
	node7.lchild = &node8;
	BianLi(&node1);
	printf("\n");
	CalcNode(&node1);
	DepthTree(&node1);
	BinaryNode* cptree = CopyTree(&node1);
	BianLi(cptree);
	printf("\n");
	FreeTree(cptree);
}

int main(void)
{
	CreateBinaryNode();
	printf("叶子节点数=%d\n", num);
	printf("二叉树高度=%d\n", DepthVal);
	return 0;
}