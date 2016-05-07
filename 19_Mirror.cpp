#include <iostream>
using namespace std;

typedef char ElemType;

typedef struct BiNode
{
	ElemType data;
	BiNode   *lchild;
	BiNode   *rchild;
}BiNode, *BiTree;

void CreateTree(BiTree *T)
{
	char c;
	scanf("%c", &c);

	if ( '#' == c )
	{
		*T = NULL;
	}
	else
	{
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateTree(&(*T)->lchild);
		CreateTree(&(*T)->rchild);
	}
}

void PreOrder(BiTree T)
{
	if ( T )
	{
		cout << T->data << " ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void MirrorRecursively(BiTree pNode)
{
	if (NULL == pNode || (pNode->lchild == NULL && pNode->rchild)
		|| (pNode->rchild == NULL && pNode->lchild))
	{
		return;
	}
	BiNode *temp = pNode->lchild;
	pNode->lchild = pNode->rchild;
	pNode->rchild = temp;

	if (pNode->lchild)
	{
		MirrorRecursively(pNode->lchild);
	}
	if (pNode->rchild)
	{
		MirrorRecursively(pNode->rchild);
	}
}

int main()
{
	BiTree T1;
	CreateTree(&T1);
	PreOrder(T1);
	cout << endl;
	MirrorRecursively(T1);
	PreOrder(T1);
	cout << endl;
	return 0;
}