#include<iostream>
using namespace std;
class Node
{
	public:
	int get()
	{
		return object;
	}
	void set(int object)
	{
		this->object=object;
	}
	Node * getnext()
	{
		return nextnode;
	}
	void setnext(Node * nextnode)
	{
		this->nextnode=nextnode;
	}
	private:
		Node *nextnode;
		int object;
};
class List
{
	Node *hn,*cn,*lcn;
	public:
	List()
	{
		hn=new Node;
		hn->setnext(NULL);
		cn=NULL;
		lcn=NULL;
	}
	void add(int object)
	{
		Node *newnode=new Node;
		newnode->set(object);
		if(cn!=NULL)
		{
			newnode->setnext(cn->getnext());
			cn->setnext(newnode);
			lcn=cn;
			cn=newnode;
		}
		else
		{
			newnode->setnext(NULL);
			hn->setnext(newnode);
			cn=newnode;
			lcn=hn;
		}
	}
	void display()
	{
		Node *p;
		p=hn->getnext();
		while(p!=NULL)
		{
			cout<<"   "<<p->get();
			p=p->getnext();
		}
	}
};
int main()
{
	List arr[10];
	int ch,k;
	do
	{
	cout<<"Enter One For entry \n";
	cout<<"Enter Two For Display\n";
	cout<<"Enter Zero For Exit\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				int val;
				cout<<"Enter Value you want to Store \n";
				cin>>val;
				k=val%10;
				arr[k].add(val);
				break;
			}
		case 2:
			{
				for(int l=0;l<10;l++)
				{
				arr[l].display();
				cout<<endl;
			    }
			    break;
			}
		case 0:
			break;
	}
}while(ch!=0);
	return 0;
}
