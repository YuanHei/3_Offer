
#include <iostream>
using namespace std;

typedef struct Node
{
	int  data;
	Node *next;
}Node, *ListLink;

Node * InitNoNode(ListLink L, int n, int flag)
{
	Node * head = NULL;
	Node * rear = NULL;
	Node * temp = NULL;
	//srand(time_t());

	for (int i = 1; i < n+1; ++i)
	{
		temp = (Node*)malloc(sizeof(Node));
		//temp->data = rand() % 100 + 1;
		temp->data = i * flag;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			rear->next = temp;
		}
		rear = temp;
	}
	if (rear != NULL)
	{
		rear->next = NULL;
	}

	return head;
}
//合并两个排序的链表
//输入两个递增排序的链表，合并这两个链表并使新链表的
//结点依然是按照递增排序的。

//方法一：非递归
Node * Merge(Node * L1, Node * L2)
{
	if (L1 == NULL)
	{
		return L2;
	}
	else if (L2 == NULL)
	{
		return L1;
	}
	Node *Head = NULL;
	if (L1->data <= L2->data)
	{
		Head = L1;
		L1 = L1->next;
	}
	else
	{
		Head = L2;
		L2 = L2->next;
	}
	Head->next = NULL;
	Node * p = Head;
	while (L1->next != NULL && L2->next != NULL)
	{
		if (L1->data <= L2->data)
		{
			p->next = L1;
			p = p->next;
			L1 = L1->next;
		}
		else
		{
			p->next = L2;
			p = p->next;
			L2 = L2->next;
		}
	}
	if (L1->next != NULL)
	{
		p->next = L1;
	}
	if (L2->next != NULL)
	{
		p->next = L2;
	}

	return Head;
}

//方法二：递归
Node * Merge_(Node * L1, Node * L2)
{
	if (L1 == NULL)
	{
		return L2;
	}
	else if (L2 == NULL)
	{
		return L1;
	}
	Node *Head = NULL;
	if (L1->data <= L2->data)
	{
		Head = L1;
		Head->next = Merge(L1->next, L2);
	}
	else
	{
		Head = L2;
		Head->next = Merge(L1, L2->next);
	}

	return Head;
}

void Show_No(ListLink L)
{
	if (NULL == L)
	{
		return;
	}
	Node * p = L;
	while (p != NULL)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	ListLink L = NULL;
	Node *Head1 = InitNoNode(L, 10, 2);
	Show_No(Head1);
	Node *Head2 = InitNoNode(L, 10, 3);
	Show_No(Head2);
	//Node *MerHead = Merge(Head1, Head2);
	//Show_No(MerHead);
	Node *MerHead_ = Merge_(Head1, Head2);
	Show_No(MerHead_);
	return 0;
}