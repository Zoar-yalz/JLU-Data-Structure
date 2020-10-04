#include <iostream>
class Stack//栈的实现使用数组和栈顶指针
{
public:
	int top;//栈顶指针
	int data[20000];//数据栈
	void push(int n);//压栈
	int pop(void);//出栈
	Stack();//默认构造器
};
int main()
{
	Stack* s = new Stack();
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int mode;
		int value;
		std::cin >> mode;
		if (mode == 0)
		{
			s->pop();
		}
		else if(mode == 1)
		{
			std::cin >> value;
			s->push(value);
		}
	}
	
}

void Stack::push(int n)
{
	top++;
	data[top] = n;
}

int Stack::pop(void)
{
	if (top == -1)
	{
		std::cout << "invalid\n";
		return NULL;
	}
	std::cout << data[top--]<<"\n";
	return data[top + 1];
}


Stack::Stack()
{
	top = -1;
	data[0] = 0;
}
