#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* prev;
	Node* next;
	
};
Node* head;
Node* getnewnode(int x)
{
	Node* newNode= new Node();
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void insertathead(int x)
{
	Node* newNode = getnewnode(x);
	if (head==NULL)
	{
		head = newNode;
		return; 
	}
	else
	{
		head->next=newNode;
		newNode->prev=head;
		head = newNode;
	}
}
void reverse()
{
	Node *temp = head;
	if(temp==NULL) return;
	
	while(temp->next!=NULL)
	temp=temp->next;
	
	cout<<"Reverse: ";
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->prev;
	}
	cout<<endl;
}
void deletion(int n)
{
	Node *dtemp = head;
	if(n==1)
	{
		head=dtemp->next;
		delete dtemp;
		return;
	}
	else
	{
		
		 int i;
	for(i=0;i<n-2;i++)
	dtemp=dtemp->next;
	
	Node *temp2=dtemp->next;
	if(temp2->next==NULL)
	{
		temp2->prev=dtemp;
		dtemp->next=NULL;
		delete temp2;
		return;
	}
	Node *temp3=temp2->next;
	dtemp->next=temp3;
	temp3->prev=dtemp;
	delete temp2;
	}
}
void print()
{
	Node* temp = head;
	cout<<"Forward: ";
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->prev;
	}
	cout<<endl;
}

int main()
{
	    while(1)
    {
    	cout<<" enter 1 for insertion \n";
    	cout<<"enter 2 for display: \n";
    	cout<<"enter 3 for reverse \n";
    	cout<<"enter 4 for delete item \n";
    	cout<<" enter 5 to exit: \n";
    	int op;
    	cin>>op;
	switch(op)
	{
	case 1:
		
		
		int val;
		cout<<" enter value you want to insert \n";
		cin>>val;
    insertathead(val);
    break;
	
	case 2:
		print();
		break;
		case 3:
		reverse();
		break;	
		case 4:
			int pos;
			cout<<"ENter the position you want to delete: ";
			cin>>pos;
			deletion(pos);
		break;
	case 5:
	exit(0);
	break;
	
/*	int num;
	cout<<"enter the number you want to enter in Node: ";
	cin>>num;
	insertathead(2);
	print();
	reverse();
	
	insertathead(4);
	print();
	reverse();
	
	
	insertathead(6);
	deletion(2);
	print();
	reverse();
*/			
}
}
}
