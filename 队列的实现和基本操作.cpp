#include <stdio.h>
#include <iostream>
class Node
{
public:
	int value = NULL;
	Node* next = NULL;
	Node* prev = NULL;
	Node(int v);
};
Node::Node(int v)
{
	value = v;
	next = nullptr;
	prev = nullptr;
}
class Deque
{
public:
	Deque();
	~Deque();
	void inQueue(int n);
	void outQueue(void);
	bool isEmpty(void);
private:
	Node* tail;
	Node* head;
	int length;
};

Deque::Deque()
{
	tail = nullptr;
	head = nullptr;
	length = 0;
}

Deque::~Deque()
{
}
void Deque::inQueue(int n)
{
	if (this->isEmpty())
	{
		tail = new Node(n);
		head = tail;
	}
	else if (head == tail)
	{
		Node* p = new Node(n);
		p->next = tail;
		head = p;
		tail->prev = head;
	}
	else
	{
		Node* p = new Node(n);
		p->next = head;
		head->prev = p;
		head = p;
	}
	length++;
}
void Deque::outQueue(void)
{
	if (this->isEmpty())
	{
		std::cout << "invalid\n";
		return;
	}
	else if (length == 1)
	{
		std::cout << tail->value << "\n";
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		std::cout << tail->value << "\n";
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	length--;
}
bool Deque::isEmpty(void)
{
	return length == 0;
}
int main()
{
	Deque* d = new Deque();
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
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