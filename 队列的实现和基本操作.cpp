#include <stdio.h>
#include <iostream>

class Deque//双向队列
{
public:
	class Node//嵌套节点类，队列的实现使用双向链表
	{
	public:
		int value = NULL;
		Node* next = NULL;
		Node* prev = NULL;
		Node(int v);
	};
	Deque();//构造函数
	~Deque();//析构函数
	void inQueue(int n);//入队
	int outQueue(void);//出队
	bool isEmpty(void);//判别是否为空
private:
	Node* tail;//队尾
	Node* head;//队首
	int length;//长度
};

Deque::Deque()//默认构造器
{
	tail = nullptr;
	head = nullptr;
	length = 0;
}

Deque::~Deque()
{
	Node* p = head;
	Node* del = head->next;
	while (del->next != nullptr)
	{
		delete p;
		p = del;
		del = del->next;
	}
	delete del;
}
void Deque::inQueue(int n)//入队
{
	if (this->isEmpty())//特殊情况：空队列
	{
		tail = new Node(n);
		head = tail;
	}
	else if (head == tail)//特殊情况：一个元素队列
	{
		Node* p = new Node(n);
		p->next = tail;
		head = p;
		tail->prev = head;
	}
	else                   //一般情况，在队首添加节点
	{
		Node* p = new Node(n);
		p->next = head;
		head->prev = p;
		head = p;
	}
	length++;//更新长度
}
int Deque::outQueue(void)//出队
{
	int value = NULL;
	if (this->isEmpty())
	{
		std::cout << "invalid\n";//无效操作：空队列出队
		return NULL;
	}
	else if (length == 1)//特殊情况：单元素队列
	{
		std::cout << tail->value << "\n";
		value = tail->value;
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
	else//一般情况，队尾出队
	{
		std::cout << tail->value << "\n";
		value = tail->value;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	length--;//更新长度
	return value;
}
bool Deque::isEmpty(void)//判断是否为空
{
	return length == 0;
}
Deque::Node::Node(int v)//默认构造器
{
	value = v;
	next = nullptr;
	prev = nullptr;
}
int main()
{
	Deque* d = new Deque();
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)//输入，输出
	{
		int mode;
		int value;
		std::cin >> mode;
		if (mode == 1)
		{
			std::cin >> value;
			d->inQueue(value);
		}
		else if (mode == 0)
		{
			d->outQueue();
		}
	}
}