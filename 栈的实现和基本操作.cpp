#include <iostream>
class Stack
{
public:
	int top;
	int data[20000];
	void push(int n);
	int pop(void);
	Stack();
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
