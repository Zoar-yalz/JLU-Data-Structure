#include <stdio.h> //单链表的实现
#define scanf_s scanf

class LinkedList//单链表
{
public:
	class Node	//单向节点类
	{
	public:
		int value = NULL;
		Node* next = NULL;
		Node(int v);
	};
	LinkedList();//构造函数
	~LinkedList();//析构函数
	Node* add(int value);//在尾部添加节点
	void del(int k);	//删除下标为k的节点
	void insert(int n, int value);//在下标为n的结点后增加值为value的结点
	void print();//按题目格式输出
private:

	Node* tail;//尾节点
	Node* head;//头节点
	int length;//存储链表长度的域
};
LinkedList::LinkedList()//默认构造器
{
	tail = NULL;
	head = NULL;
	length = 0;
}
LinkedList::~LinkedList()
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
LinkedList::Node* LinkedList::add(int value)//添加
{
	if (tail == nullptr)//特殊情况：空链表时
	{
		head = tail = new Node(value);
		length++;
		return tail;
	}
	tail->next = new Node(value);//一般情况，直接在尾部增加结点；
	tail = tail->next;
	length++;
	return tail;
}
void LinkedList::del(int k)//删除
{
	if (k > length)//过滤错误操作
		return;
	Node* p = head;
	Node* d = head;
	if (k == 0)
	{
		return;
	}
	else if (k == 1)//特殊情况：删除头节点
	{
		head = head->next;
		delete p;
	}
	else
	{
		for (int i = 0; i < k - 2; i++)//一般情况：遍历寻找目标节点，定位到前一个结点并删除
		{
			p = p->next;
		}
		d = p->next;
		p->next = d->next;
		delete d;
	}
	length--;//更新长度
}
void LinkedList::insert(int n, int value)
{
	if (n > length)//过滤错误操作
		return;
	Node* p = head;
	if (n == 0)//特殊情况：空链表
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
		for (int i = 0; i < n - 1; i++)//一般情况：遍历到插入位置前并插入
		{
			p = p->next;
		}
		Node* temp = p->next;
		p->next = new Node(value);
		p->next->next = temp;
	}
	length++;//更新长度
}
void LinkedList::print()//输出
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
	scanf_s("%d", &cnt_1);//使用cin，cout可能会导致超时
	LinkedList* list = new LinkedList();
	for (int i = 0; i < cnt_1; i++)//输入数据
	{
		int temp;
		scanf_s("%d", &temp);
		list->add(temp);
	}
	scanf_s("%d", &cnt_2);
	for (int j = 0; j < cnt_2; j++)//按照题目要求处理
	{
		int mode;
		int pos;
		int value;
		scanf_s("%d", &mode);
		if (mode == 1)
		{
			scanf_s("%d", &pos);
			list->del(pos);
		}
		else
		{
			scanf_s("%d", &pos);
			scanf_s("%d", &value);
			list->insert(pos, value);
		}
	}
	list->print();//输出
}
LinkedList::Node::Node(int v)//节点的默认构造器
{
	value = v;
	next = nullptr;
}
