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

     private:
       int   object;
       Node   * nextNode;
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
        lastCurrentNode   =   currentNode;
        currentNode   =   newNode;
     }
     else
     {
	newNode->setNext(NULL);
	headNode->setNext(newNode);
	lastCurrentNode   =   headNode;
	currentNode   =   newNode;
      }
      size ++;
}
void addanyplace(int objvalue,int objitem)
{
	Node * newNode = new Node();
	newNode->set(objvalue);
	Node *p = find(objitem);
	if(p!=NULL)
	{
		newNode->setNext(p->getNext());
		p->setNext(newNode);
		lastCurrentNode=p;
		p=newNode;
	}

	else
	{
		newNode->setNext(NULL);
		headNode->setNext(newNode);
		lastCurrentNode=headNode;
		p=newNode;
	}
	size++;

	
}
void dltByPos(int element)
{
	
	Node *temp1=headNode->getNext();
	if(element==1)
	{
		headNode->setNext(temp1->getNext());
		delete temp1;
		return ;
	}
	else 
	{
	int i;
	for(i=0;i<element-2;i++)
	temp1=temp1->getNext();
	
	Node *temp2=temp1->getNext();
	temp1->setNext(temp2->getNext());
	cout<<"You deleted: "<<temp2->get();
	delete temp2;
	}
	
size--;
}
void dltByValue(int item)
{
	Node *temp=find(item);
	Node *temp2=temp->getNext();
	Node *p=headNode;
	while(p->getNext()!=temp)
	{
		p=p->getNext();
	}
	p->setNext(temp2);
	cout<<"\nYou deleted: "<<temp->get();
	delete temp;
	return;
	
	size--;
}

Node *find(int item)
{
	Node *q=headNode->getNext();
	while(q->get()!=item){
		q=q->getNext();
	
	}
		return q;
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
	cout<<"size of link list is: "<<size<<endl;
}
};
	
/* add() class method */
int main()
{
    List   list;
    while(1)
    {
    	cout<<"\nenter 1 for insertion";
    	cout<<"\nenter 2 for display: ";
    	cout<<"\nenter 3 for insert at any place: ";
    	cout<<"\nenter 4 to delete by value: ";
    	cout<<"\nenter 5 to delete by position: ";
    	cout<<"\nenter 6 for exit: "<<endl;
    	int op,n;
    	cin>>op;
	switch(op)
	{
	case 1:
		int val;
		cout<<" enter value you want to insert \n";
		cin>>val;
    list.add(val);
    break;
    	case 2:
    	list.display();
    	break;
				case 3:	
				int value,item;
				cout<<"ENter the value if you want to insert: \n";
				cin>>value;
				cout<<"Enter the item after you insert value: \n";
				cin>>item;
				list.addanyplace(value,item);
				break;
					case 4:
					cout<<"Enter element you want to delete: \n";
					cin>>n;
					list.dltByValue(n);
					break;
						case 5:
						cout<<"enter position to delete: ";
						cin>>n;
						list.dltByPos(n);
						break;
							case 6:
							exit(0);
							break;

}//end of switch
}//end of while
}//end of main

