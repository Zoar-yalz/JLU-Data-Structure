#include iostream
class Stack
{
public
	int top;
	int data[20000];
	void push(int n);
	int pop(void);
	Stack();
};
int main()
{
	Stack s = new Stack();
	int n;
	stdcin  n;
	for (int i = 0; i  n; i++)
	{
		int mode;
		int value;
		stdcin  mode;
		if (mode == 0)
		{
			s-pop();
		}
		else if(mode == 1)
		{
			stdcin  value;
			s-push(value);
		}
	}
	
}

void Stackpush(int n)
{
	top++;
	data[top] = n;
}

int Stackpop(void)
{
	if (top == -1)
	{
		stdcout  invalidn;
		return NULL;
	}
	stdcout  data[top--]n;
	return data[top + 1];
}


StackStack()
{
	top = -1;
	data[0] = 0;
}
