#include <stdio.h> //�������ʵ��
#define scanf_s scanf

class LinkedList//������
{
public:
	class Node	//����ڵ���
	{
	public:
		int value = NULL;
		Node* next = NULL;
		Node(int v);
	};
	LinkedList();//���캯��
	~LinkedList();//��������
	Node* add(int value);//��β����ӽڵ�
	void del(int k);	//ɾ���±�Ϊk�Ľڵ�
	void insert(int n, int value);//���±�Ϊn�Ľ�������ֵΪvalue�Ľ��
	void print();//����Ŀ��ʽ���
private:

	Node* tail;//β�ڵ�
	Node* head;//ͷ�ڵ�
	int length;//�洢�����ȵ���
};
LinkedList::LinkedList()//Ĭ�Ϲ�����
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
LinkedList::Node* LinkedList::add(int value)//���
{
	if (tail == nullptr)//���������������ʱ
	{
		head = tail = new Node(value);
		length++;
		return tail;
	}
	tail->next = new Node(value);//һ�������ֱ����β�����ӽ�㣻
	tail = tail->next;
	length++;
	return tail;
}
void LinkedList::del(int k)//ɾ��
{
	if (k > length)//���˴������
		return;
	Node* p = head;
	Node* d = head;
	if (k == 0)
	{
		return;
	}
	else if (k == 1)//���������ɾ��ͷ�ڵ�
	{
		head = head->next;
		delete p;
	}
	else
	{
		for (int i = 0; i < k - 2; i++)//һ�����������Ѱ��Ŀ��ڵ㣬��λ��ǰһ����㲢ɾ��
		{
			p = p->next;
		}
		d = p->next;
		p->next = d->next;
		delete d;
	}
	length--;//���³���
}
void LinkedList::insert(int n, int value)
{
	if (n > length)//���˴������
		return;
	Node* p = head;
	if (n == 0)//���������������
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
		for (int i = 0; i < n - 1; i++)//һ�����������������λ��ǰ������
		{
			p = p->next;
		}
		Node* temp = p->next;
		p->next = new Node(value);
		p->next->next = temp;
	}
	length++;//���³���
}
void LinkedList::print()//���
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
	scanf_s("%d", &cnt_1);//ʹ��cin��cout���ܻᵼ�³�ʱ
	LinkedList* list = new LinkedList();
	for (int i = 0; i < cnt_1; i++)//��������
	{
		int temp;
		scanf_s("%d", &temp);
		list->add(temp);
	}
	scanf_s("%d", &cnt_2);
	for (int j = 0; j < cnt_2; j++)//������ĿҪ����
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
	list->print();//���
}
LinkedList::Node::Node(int v)//�ڵ��Ĭ�Ϲ�����
{
	value = v;
	next = nullptr;
}
