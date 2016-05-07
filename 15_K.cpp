#include <iostream>
using namespace std;

typedef struct Node
{
	int  data;
	Node *next;
}Node, *ListLink;

void InitList(ListLink *L, int n)
{
	//头插
	Node *p;
	srand(time_t());

	*L = (Node*)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (int i = 0; i < n; ++i)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//链表中倒数第k个结点
Node * FindKthToTail(ListLink L, unsigned int k)
{
	if (L == NULL || k <= 0)
	{
		return NULL;
	}
	Node *fast = L;
	//先走k-1步
	Node *low = L;
	//从第k步开始，第二个指针也开始从链表的头指针
	//开始遍历。由于两个指针的距离保持在k-1,
	//当第一个（走在前面的）指针到达链表的尾结点
	//第二个指针（走在后面的）指针正好是倒数第k个结点
	//相当于low指针走了n-k+1步，刚好指向倒数第k个结点
	for (int i = 0; i < k - 1; ++i)
	{
		if(fast->next != NULL)
		{
			fast = fast->next;
		}
		else
		{
			return NULL;
		}
	}
	while (fast->next != NULL)
	{
		fast = fast->next;
		low = low->next;
	}

	return low;
}

void Show(ListLink *L)
{
	if (*L == NULL)
	{
		return;
	}
	Node *p = (*L)->next;
	while (p != NULL)
	{
		cout << p->data << "-->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	ListLink L;
	InitList(&L,10);
	Show(&L);
	Node *p = FindKthToTail(L, 4);
	cout << p->data << endl;
	return 0;
}