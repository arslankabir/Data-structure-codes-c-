#include   <iostream>
#include   <stdlib.h>
using namespace std;

/* The Node class */
class   Node 
{
    public:
	    int      get() { return   object; };
	    void   set(int   object) { this->object   =   object; };

	    Node   * getNext() { return   nextNode; };
	    void     setNext(Node   * nextNode) { this->nextNode   =   nextNode; };
	    Node   * getprev() { return   prevNode; };
	    void     setprev(Node   * prevNode) { this->prevNode   =   prevNode; };

     private:
       int   object;
       Node   * nextNode;
       Node *prevNode;

};	

/* The List class */
class   List 
{

   
    
private:
    int      size;
    Node *   headNode;
    Node *   currentNode;
    Node *   lastCurrentNode;


public:
List() 
{
	
headNode   =   new Node();
	headNode->setNext(NULL);
	currentNode   =   NULL;
	lastCurrentNode  =   NULL;
	size   =   0;
}
	void   add (int   addObject) 
{
    Node *   newNode   =   new   Node();
    newNode->set(addObject);
    if( currentNode   !=   NULL )
    {
        newNode->setNext(currentNode->getNext());
        currentNode->setNext( newNode );
        newNode->setprev(currentNode);
        lastCurrentNode   =   currentNode;
        currentNode   =   newNode;
     }
     else
     {
	newNode->setNext(NULL);
	newNode->setprev(headNode);
	headNode->setprev(NULL);
	headNode->setNext(newNode);
	lastCurrentNode   =   headNode;
	currentNode   =   newNode;
      }
      size ++;
}
void dlt(int n)
{
	Node *p=headNode;
	if(n==1)
	{
		headNode=p->getNext();
		delete p;
		
	} 
	
	for(int i=0;i<n-1;i++)
	p=p->getNext();
	
	Node *temp;
	Node *temp1;
	temp=p->getNext();
	if(temp->getNext()==NULL)
	{
		p->setNext(NULL);
		delete temp;
		return;
	}
	temp1=temp->getNext();
	
	p->setNext(temp1);
	temp1->setprev(p);
	delete temp;
	
}
void dltany(int data)
{
	Node *p=headNode->getNext();
	while(p->get()!=data)
	{
		p=p->getNext();
	}
	Node *p1=p->getprev();
	Node *p2=p->getNext();
	//link
	p1->setNext(p2);
	if(p2!=NULL)
	{
	p2->setprev(p1);
	}
	delete p;
}
void reverse()
{
	Node *p = currentNode;
	while(p->getprev()!=NULL)
	{
		cout<<"\nelement: "<<p->get();
		p=p->getprev();
		
	}
}
void display()
{
	int i=1;
	Node *p;
	p=headNode->getNext();
	while(p!=NULL)
	{
	cout<<"element  "<<i<<" is :"<<p->get();
	cout<<endl;
		p=p->getNext();
		i++;
	}
	cout<<"size of link list is: "<<size;
	cout<<endl;
}

};
int main()
{
	List l;
	 while(1)
    {
    	cout<<" enter 1 for insertion: \n";
    	cout<<"enter 2 for display: \n";
    	cout<<"Enter 3 for dlt \n";
    	cout<<"enter 4 for exit: \n";
    	int op;
    	cin>>op;
	switch(op)
	{
	case 1:
		int v;
		cout<<" enter : ";
		cin>>v;
		l.add(v);
		break;
		case 2:
			l.reverse();
			break;
			case 3:
				int a;
				cout<<"enter deletetion position: ";
				cin>>a;
				l.dltany(a);
				break;
		
	case 4:
	exit(0);
	break;

}//end of switch
}//end of while

	
	
}
