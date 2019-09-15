#include<iostream>
#include<stdlib.h>
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
    Node *rearNode;
    Node *frontNode;


public:
List() 
{
	
headNode   =   new Node;
	headNode->setNext(NULL);
	currentNode   =   NULL;
	lastCurrentNode  =   NULL;
	frontNode = rearNode = NULL;
	size   =   0;
}
	void   add (int   addObject) 
{
    Node *   newNode   =   new   Node;
    newNode->set(addObject);
    Node *l=headNode->getNext();
   
      if(currentNode==NULL||addObject<l->get())
     {
	newNode->setNext(headNode->getNext());
	headNode->setNext(newNode);
	lastCurrentNode   =   headNode;
	currentNode   =   newNode;
	return;
      }
    else
    {
	
    currentNode=headNode->getNext();
	
	 while( currentNode->getNext()!=NULL &&addObject>currentNode->getNext()->get())
    {
        currentNode=currentNode->getNext();
     }
     
     newNode->setNext(currentNode->getNext());
     currentNode->setNext(newNode);
 	
 	if(newNode->getNext()==NULL)
 	{
 		rearNode=newNode;
	 }
     
 }
 
 
      size ++;
}//end of insertion
int dequeue()
{
	if(headNode->getNext()!=NULL)
	{
		Node *p=headNode->getNext();
		currentNode=p->getNext();
		headNode->setNext(currentNode);
		delete p;
		
	}
	
}
void display()
{
	int i=1;
	Node *p;
	p=headNode->getNext();
	if(p==NULL)
	{
		cout<<"\n>>>>>>Queue is empty<<<<<<\n>>>>>>Enter the values<<<<<<<\n";
	}
	while(p!=NULL)
	{
	cout<<"element  "<<i<<"is :"<<p->get();
	cout<<endl;
		p=p->getNext();
		i++;
	}
	cout<<"size of link list is:"<<size<<endl;

}



};
	
/* add() class method */


main()
{



    List   *list;
    List a;
    list=&a;
    while(1)
    {
    	cout<<"enter 1 for insertion \n";
    	cout<<"enter 2 for display \n";
    	cout<<"enter 3 to dequeue\n";
    	int op;
    	cin>>op;
    	cout<<endl;
	switch(op)
	{
	case 1:
		{
		
		int val;
		cout<<" enter value you want to insert \n";
		cin>>val;
    list->add(val);
    break;
}
    case 2:
    	{
		
    list->display();
    break;
}
case 3:
	list->dequeue();
	list->display();
	break;
	
	default:
		cout<<"u have enterd wrong option please enter again  \n";

}//end of switch
}//end of while
}//end of main

