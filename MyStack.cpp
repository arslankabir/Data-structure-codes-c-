#include<iostream>
using namespace std;
class stack
{
		int data;
		stack *top;
		stack *next;
	public:
	stack()
	{
		top=NULL;
	}
	void push()
	{
		int val;
		stack *node;
		cout<<"Enter Value You want To Enter \n";
		cin>>val;
		node=new stack;
		node->data=val;
		if(top!=NULL)
		node->next=top;
		else
		node->next=NULL;
		top=node;
	}
	void pop()
	{
		if(top==NULL)
		cout<<"Stack Empty \n";
		else
		{
			stack *t;
			t=top;
			top=top->next;
			delete t;
		}
	}
	void display()
	{
		stack *p;
		p=top;
		while(p!=NULL)
		{
			cout<<p->data<<endl;
			p=p->next;
		}
	}
};
int main()
{
	stack o;
	int ch;
	do{
		cout<<"Enter 1 to Enter Value in Stack\n";
		cout<<"Enter 2 to delete Value from stack\n";
		cout<<"Enter 3 to show Values in stack\n";
		cout<<"Enter 0 to Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					o.push();
					break;
				}
			case 2:
				{
					o.pop();
					break;
				}
			case 3:
				{
					o.display();
					break;
				}
			case 0:
			 break;
		}
	}while(ch!=0);
	return 0;
}
