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

/* The queue class */
class   queue 
{
private:
    int      size;
    Node *front;
	Node *rear;
public:
queue() 
{
	front=NULL;
	rear=NULL;
	size   =   0;
}
void enqueue(int data)
{
	Node *temp = new Node();
	temp->set(data);
	temp->setNext(NULL);
	if(front==NULL&&rear==NULL)
	{
		front=rear=temp;//front and rear point to the first newly created Node
	}
	else
	{
		rear->setNext(temp);
		rear=temp;
	}
	//rear->setNext(front);//to make it circular
	size++;
}
int dequeue()
{

	if(front==NULL)
	return -1;
	if(front==rear)//when we have 1 element in circular queue
	{
	
		delete front;
		front = rear = NULL;
	}
	else
	{
	
	Node *p=front;// first value of queue stored in p
	front= front->getNext();// front link to the 2nd value of the queue 
	//rear->setNext(front);//rear of next is the front of queue to stable the circular condition
	cout<<"You dequeued: "<<p->get();
	delete p; //here delete p(first element)
	}
	size--;
}
void print()
{
	int i=1;
	Node *temp=front;
	if(temp==NULL)
	{
		cout<<"\n>>>>>>Queue is empty<<<<<<\n>>>>>>Enter the values<<<<<<<\n";
		return;
	}
	while(temp->getNext()!=front)
	{
		cout<<"\nelement "<<i<<" : "<<temp->get();
		temp=temp->getNext();
		i++;
		
	}
	cout<<"\nelement "<<i<<" : "<<temp->get();
	cout<<"\nsize of queue is: "<<size;
	
}
};
int main()
{

	queue q;
	int n;
	int op;
	while(1)
	{
		cout<<"\nenter 1 for enqueue: ";
		cout<<"\nenter 2 for show: ";
		cout<<"\nenter 3 for dequeue: ";
		cout<<"\nenter 4 for exit: ";
		cout<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"\nenter value to enqueue: ";
				cin>>n;
				q.enqueue(n);
				break;
				case 2:
					q.print();
					break;
					case 3:
						q.dequeue();
						q.print();
						break;
					case 4:
					exit(0);
					break;
		}
	}
	getch();
}
