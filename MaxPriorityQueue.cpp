#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

/* The Node class */
class   Node 
{
    public:
	    int      get() { return   object; };
	    void   set(int   object) { this->object   =   object; };

	    Node   * getNext() { return   nextNode; };
	    void     setNext(Node   * nextNode) { this->nextNode   =   nextNode; };


     private:
       int   object;
       Node   * nextNode;
};	
class queue
{
		public:
		Node *headNode;
		Node *frontNode;
		Node *rearNode;
	
		queue()
		{
			headNode = new Node();
			headNode->setNext(NULL);
			frontNode = rearNode = NULL;
		}
void enqueueMax(int data)
{
	Node *newNode = new Node();
	newNode->set(data);
	Node *p=headNode->getNext();
	if(frontNode==NULL||data>p->get())
		{
			newNode->setNext(headNode->getNext());
			headNode->setNext(newNode);
			frontNode=newNode;
			return;
		}
	else
		{
			rearNode = headNode->getNext();
			if(rearNode->getNext()!=NULL&&data<rearNode->getNext()->get())
			{
				while(rearNode->getNext()!=NULL&&data<rearNode->getNext()->get())
				{
					rearNode = rearNode->getNext();
				}
				newNode->setNext(rearNode->getNext());
				rearNode->setNext(newNode);
				newNode = rearNode;
			}
			else
			{
			frontNode=headNode->getNext();
			newNode->setNext(frontNode->getNext());
			frontNode->setNext(newNode);
			}
		}
		
	
}//end of enqueueMax
void dequeue()
{
	if(headNode->getNext()!=NULL)
	{
	Node *p=frontNode;
	frontNode=frontNode->getNext();
	headNode->setNext(frontNode);
	cout<<"\nYou dequeued: "<<p->get();
	delete p;
	}
	else
	{
		cout<<"\n	Please Enter value to Dequeue";
	}
}
void print()
	{
	int i=1;
	Node *temp=headNode->getNext();
	if(temp==NULL)
	{
		cout<<"\n	QUEUE IS EMPTY\n";
	}
	while(temp!=NULL)
	{
		cout<<"\nelement "<<i<<" : "<<temp->get();
		temp=temp->getNext();
		i++;	
	}
	
	cout<<"\nrear Node: "<<rearNode->get();
	cout<<"\nfront Node: "<<frontNode->get();
	}
};
int main()
{

	queue q;
	int n;
	int op;
	cout<<">>>>>>>MaxPriority Queue<<<<<<\n";
	while(1)
	{
		cout<<"\nenter 1 for enqueue: ";
		cout<<"\nenter 2 for show: ";
		cout<<"\nenter 3 for dequeue: ";
		cout<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"\nenter value to enqueue: ";
				cin>>n;
				q.enqueueMax(n);
				break;
				case 2:
					q.print();
					break;
					case 3:
						q.dequeue();
						break;
						default: 
						cout<<"\n invalid Entery";
					}
				}
			}
