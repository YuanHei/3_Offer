//包含min函数的栈
//定义栈的数据结构，在该类型实现一个能够得到
//栈最小元素的min函数。
#include <iostream>
#include <stack>
using namespace std;

typedef int ElemType;

class StackMin
{
public:
	void Push(ElemType & value);
	void Pop();
	const ElemType Min();
private:
	stack<ElemType> m_data; //数据栈存放压入数据
	stack<ElemType> m_min;  //辅助栈存放最小值
};

void StackMin::Push(ElemType & value)
{
	m_data.push(value);

	if (m_min.size() == 0 || m_min.top() > value)
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

void StackMin::Pop()
{
	if (m_data.size() < 0 || m_min.size() < 0)
	{
		return;
	}
	m_data.pop();
	m_min.pop();
}

const ElemType StackMin::Min()
{
	if (m_data.size() < 0 || m_min.size() < 0)
	{
		exit(-1);
	}
	else
	{
		return m_min.top();
	}
}

int main()
{
	StackMin min;
	ElemType tmp;
	cin >> tmp;
	while (tmp != -1)
	{
		min.Push(tmp);
		cin >> tmp;
	}
	min.Pop();
	cout << min.Min() << endl;
	return 0;
}