#include <stdio.h>
#define scanf_s scanf
class Node
{
public:
	int value = NULL;
	Node* next = NULL;
	Node(int v);
};
class LinkedList
{
public:
	LinkedList();
	Node* add(int value);
	void del(int k);
	void insert(int n, int value);
	void print();
private:
	Node* tail;
	Node* head;
	int length;
};
LinkedList::LinkedList()
{
	tail = NULL;
	head = NULL;
	length = 0;
}
Node* LinkedList::add(int value)
{
	if (tail == nullptr)
	{
		head = tail = new Node(value);
		length++;
		return tail;
	}
	tail->next = new Node(value);
	tail = tail->next;
	length++;
	return tail;
}
void LinkedList::del(int k)
{
	if (k > length)
		return;
	Node* p = head;
	Node* d = head;
	if (k == 0)
	{
		return;
	}
	else if (k == 1)
	{
		head = head->next;
		delete p;
	}
	else
	{
		for (int i = 0; i < k - 2; i++)
		{
			p = p->next;
		}
		d = p->next;
		p->next = d->next;
		delete d;
	}
	length--;
}
void LinkedList::insert(int n, int value)
{
	if (n > length)
		return;
	Node* p = head;
	if (n == 0)
	{
		p = new Node(value);
		p->next = head;
		head = p;
	}
	else if (n == length)
	{
		add(value);
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			p = p->next;
		}
		Node* temp = p->next;
		p->next = new Node(value);
		p->next->next = temp;
	}
	length++;
}
void LinkedList::print()
{
	Node* p = head;
	while (p != nullptr)
	{
		printf("%d ", p->value);
		p = p->next;
	}
}
int main()
{
	int cnt_1;
	int cnt_2;
	scanf_s("%d",&cnt_1);
	LinkedList* list = new LinkedList();
	for (int i = 0; i < cnt_1; i++)
	{
		int temp;
		scanf_s("%d",&temp);
		list->add(temp);
	}
	scanf_s("%d",&cnt_2);
	for (int j = 0; j < cnt_2; j++)
	{
		int mode;
		int pos;
		int value;
		scanf_s("%d",&mode);
		if (mode == 1)
		{
			scanf_s("%d",&pos);
			list->del(pos);
		}
		else
		{
			scanf_s("%d", &pos);
			scanf_s("%d", &value);
			list->insert(pos, value);
		}
	}
	list->print();
}
Node::Node(int v)
{
	value = v;
	next = nullptr;
}
