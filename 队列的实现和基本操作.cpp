#include <stdio.h>
#include <iostream>

class Deque//˫�����
{
public:
	class Node//Ƕ�׽ڵ��࣬���е�ʵ��ʹ��˫������
	{
	public:
		int value = NULL;
		Node* next = NULL;
		Node* prev = NULL;
		Node(int v);
	};
	Deque();//���캯��
	~Deque();//��������
	void inQueue(int n);//���
	int outQueue(void);//����
	bool isEmpty(void);//�б��Ƿ�Ϊ��
private:
	Node* tail;//��β
	Node* head;//����
	int length;//����
};

Deque::Deque()//Ĭ�Ϲ�����
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
void Deque::inQueue(int n)//���
{
	if (this->isEmpty())//����������ն���
	{
		tail = new Node(n);
		head = tail;
	}
	else if (head == tail)//���������һ��Ԫ�ض���
	{
		Node* p = new Node(n);
		p->next = tail;
		head = p;
		tail->prev = head;
	}
	else                   //һ��������ڶ�����ӽڵ�
	{
		Node* p = new Node(n);
		p->next = head;
		head->prev = p;
		head = p;
	}
	length++;//���³���
}
int Deque::outQueue(void)//����
{
	int value = NULL;
	if (this->isEmpty())
	{
		std::cout << "invalid\n";//��Ч�������ն��г���
		return NULL;
	}
	else if (length == 1)//�����������Ԫ�ض���
	{
		std::cout << tail->value << "\n";
		value = tail->value;
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
	else//һ���������β����
	{
		std::cout << tail->value << "\n";
		value = tail->value;
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	length--;//���³���
	return value;
}
bool Deque::isEmpty(void)//�ж��Ƿ�Ϊ��
{
	return length == 0;
}
Deque::Node::Node(int v)//Ĭ�Ϲ�����
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
	for (int i = 0; i < n; i++)//���룬���
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