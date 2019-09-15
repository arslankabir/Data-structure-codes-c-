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
//	    Node   * getprev() { return   prevNode; };
	    void     setNext(Node   * nextNode) { this->nextNode   =   nextNode; };
//	    void     setprev(Node   * prevNode) { this->prevNode  =   prevNode; };

     private:
       int   object;
       Node   * nextNode;
     //  Node   * prevNode;
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
void enqueueMin(int data)
{
	Node *newNode = new Node();
	newNode->set(data);
	Node *p=headNode->getNext();
	if(frontNode==NULL||data<p->get())
		{
			newNode->setNext(headNode->getNext());
			headNode->setNext(newNode);
			frontNode=newNode;
			return;
		}
	else
		{
			rearNode = headNode->getNext();
			if(rearNode->getNext()!=NULL&&data>rearNode->getNext()->get())
			{
				while(rearNode->getNext()!=NULL&&data>rearNode->getNext()->get())
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
	
}//end of enqueueMin

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
	
	
	}
};
int main()
{

	queue q;
	int n;
	int op;
	cout<<">>>>>>>MinPriority Queue<<<<<<\n";
	while(1)
	{
		cout<<"\nenter 1 for Min Priority Queue: ";
		cout<<"\nenter 2 for show: ";
		cout<<"\nenter 3 for dequeue: ";
		cout<<"\nenter 4 for exit window: ";
		cout<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"\nenter value to enqueue: ";
				cin>>n;
				q.enqueueMin(n);
				break;
				case 2:
					q.print();
					break;
					case 3:
						q.dequeue();
						break;
						case 4:
							exit(0);
						default:
							cout<<" \ninvalid entry ";
					}
				}
			}
