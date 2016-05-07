#include <iostream>
using namespace std;

typedef struct Node
{
	int  data;
	Node *next;
}Node, *ListLink;

Node * InitNoNode(ListLink L, int n)
{
	Node * head = NULL;
	Node * rear = NULL;
	Node * temp = NULL;
	srand(time_t());

	for (int i = 0; i < n; ++i)
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->data = rand() % 100 + 1;
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

//反转链表
//定义一个链表的头结点，反转该链表并输出反转后链表的头结点。
Node * ReverseList(ListLink L)
{
	if (NULL == L)
	{
		return NULL;
	}
	Node *pNewHead = NULL;
	Node *pNode = L;
	Node *pPre = NULL;
	while (pNode != NULL)
	{
		Node *pNext = pNode->next;
		if (pNext == NULL)
		{
			pNewHead = pNode;
		}
		pNode->next = pPre;
		pPre = pNode;
		pNode = pNext;
	}

	return pNewHead;
}

int main()
{
	ListLink L = NULL;
	Node *Head = InitNoNode(L, 10);
	Show_No(Head);
	Node *newHead = ReverseList(Head);
	Show_No(newHead);
	return 0;
}
