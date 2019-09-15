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
    
public:
List() 
{
	
headNode   =   new Node();
	headNode->setNext(NULL);
	size   =   0;
}
void push(int x)
{
	Node *temp = new Node();
	temp->set(x);
	temp->setNext(headNode->getNext());
	headNode->setNext(temp);
	size++;
}
void pop()
{
	
	Node *temp;
	temp=headNode->getNext();
	headNode->setNext(temp->getNext());
	delete temp;
	size--;

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
//	cout<<"size of link list is: "<<size;
}
};
main()
{
	List list;
	list.push(2);list.display();
	cout<<"\n";
	list.push(4);list.display();
	cout<<"\n";
	list.push(5);list.display();
	cout<<"\n";
	list.pop();list.display();
	cout<<"\n";
	list.pop();list.display();
	cout<<"\n";
	list.push(6);list.display();
	cout<<"\n";
	
}
