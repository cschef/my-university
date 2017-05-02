#include<iostream>
using namespace std;

typedef struct
{
	int *stk;
	int top;

} stack;
void initstack(stack *s, int n)
{
	s->stk = new int [20];
	s->top = 0;
}

int count=1;
void outputstack(stack* s)
{
	int i;
	for(i=0; i<s->top; i++)
	cout<<s->stk[i]<<" ";
	cout<<endl;
}

int stackempty(stack* s)
{
	return !s->top;
}

void push(stack* s, int x)
{
	s->stk[s->top++] = x;
}

int pop(stack* s)
{
	return s->stk[--s->top];
}

void stackseq(stack *input, stack *s, stack *output)
{
	if(stackempty(input) && stackempty(s))
	outputstack(output);
	else
	{
		
		if(!stackempty(input))
		{
			push(s, pop(input));
			stackseq(input, s, output);
			push(input, pop(s));
		}
		if(!stackempty(s))
		{
			push(output, pop(s));
			stackseq(input, s, output);
			push(s, pop(output));
		}
	}
}


int main() {
    int i,n;
	stack input, s, output;
	initstack(&input, 20);
	initstack(&s, 20);
	initstack(&output, 20);
	cin>>n;
    for(i=n;i>=1;i--)
		push(&input,i);
	stackseq(&input, &s, &output);
	return 0;
}
