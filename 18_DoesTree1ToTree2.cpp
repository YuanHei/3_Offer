#include <iostream>
using namespace std;

//输入两棵二叉树A和B,判断B是不是A的子结构。
//用递归实现
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

	if ( ' ' == c )
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

bool DoesTree1HaveTree2(BiTree pRoot1, BiTree pRoot2)
{
	//判断A中以R为根结点的子树是不是包含和B一样的结构
	if (pRoot2 == NULL)
	{
		return true;
	}
	if (pRoot1 == NULL)
	{
		return false;
	}
	if (pRoot1->data != pRoot2->data)
	{
		return false;
	}
	return DoesTree1HaveTree2(pRoot1->lchild, pRoot2->lchild) &&
		DoesTree1HaveTree2(pRoot1->rchild, pRoot2->rchild);
}

bool HasSubtree(BiTree pRoot1, BiTree pRoot2)
{
	//找到与根结点值相同的结点R
	bool result = false;

	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->data == pRoot2->data)
		{
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->lchild, pRoot2);
		}
		if (!result)
		{
			result = HasSubtree(pRoot1->rchild, pRoot2);
		}
	}
	return result;
}

int main()
{
	BiTree T1, T2;
	CreateTree(&T1);
	PreOrder(T1);
	cout << endl;
	fflush(stdin);
	CreateTree(&T2);
	PreOrder(T2);
	cout << endl;
	if (HasSubtree(T1, T2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
