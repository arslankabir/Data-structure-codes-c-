#include<iostream>
#include<stdlib.h>
using namespace std;
int create();
int insert();
int insert_start();
int insert_mid();
int insert_end();
int deletion();
int delete_start();
int delete_mid();
int delete_end();
int display();
int search();
int sindex();
int svalue();
int modify();
int mindex();
int mvalue();

struct node
{
	int data;
	struct node *link;
}
*end=NULL,*q,*q1,*temp,*p;


int main()
    { int c;
	while (1){
	cout<<endl;
	cout<<" Press 1 to Create List"<<endl;
	cout<<" Press 2 to Insert Element"<<endl;
	cout<<" Press 3 to Delete Element"<<endl;	
	cout<<" Press 4 to Display Element"<<endl;
	cout<<" Press 5 to Search"<<endl;
    cout<<" Press 6 to Modify"<<endl;
	cout<<" Press 7 to exit"<<endl;
	cin>> c;
	switch (c)
	{
	case 1:
	{
	create();
	break;
	}
	case 2:
	{
	insert();
	break;
	}
    case 3:
	{
	deletion();
	break;
	}	   
	case 4:
	{
	display();
	break;	
	}          
	case 5:
	{
	search();
	break;
	}
	case 6:
	{
	modify();
	break;
	}
    case 7:
	{
	exit(0);
	}
	default:
	cout <<"Invalid Input"<<endl;
	}
	}
	}

 int create()
 {
 if(end==NULL)
 {   temp=new node;
 cout<<"Enter value: \n";
 cin>>temp->data;
 temp->link=temp;
 end=temp;
 }
 else
 {cout<<"List is already created "<<endl;
 }	
 }

 int insert()
 { int ci;
 cout<<"1-Insertion at Start\n2-Insertion At Middle\n3-Insertion At End"<<endl;
 cin>>ci;
 switch (ci)
 {
 case 1:
 insert_start();
 break;
 case 2:
 insert_mid();
 break;
 case 3:
 insert_end();
 break;
 default:
 cout <<"Invalid Input"<<endl;
 }
 }

 int insert_start()
 {
 temp=new node;
 cout<<"Enter Value ";
 cin>>temp->data;
 q=end->link;
 temp->link=q;
 end->link=temp;
 }

 int insert_mid()
 {
   if(q!=end->link)
 {
 temp=new node;
 q=end->link;
 int index;
 cout<<"Enter Index= ";
 cin>>index;
 for(int i=1;i<index;i++)
 {
 q=q->link;
 }
 cout<<"Enter value ";
 cin>>temp->data;
 p=q->link;
 q->link=temp;
 temp->link=p;
 }
 else{
 cout<<"List is not Created";
 }
 }		

 int insert_end()
 {
 temp=new node;
 cout<<"Enter value";
 cin>>temp->data;
 q=end->link;
 end->link=temp;
 temp->link=q;
 end=temp;
 }	
		
 int deletion()
 {
 int ci;
 cout<<"1-Deletion at Start\n2-Deletion At Middle\n3-Deletion At End"<<endl;
 cin>>ci;
 switch (ci)
 {
 case 1:
 delete_start();
 break;
 case 2:
 delete_mid();
 break;
 case 3:
 delete_end();
 break;
 default:
 cout <<"Invalid Input"<<endl;
 }
 }	
			
 int delete_start()
 { 
 q=end->link;
 end->link=q->link;
 delete q;	
 }

 int delete_mid()
 {
  q=end->link;
 int in;
 cout<<"Enter Index\n ";
 cin>>in;
 for(int i=1;i<in;i++)
 {
 p=q;
 q=q->link;
 }
 p->link=q->link;
 delete q;
 }			

 int delete_end()
 {
  q=end->link;
 while(q->link!=end)
 {
 q=q->link;
 }
 q->link=end->link;
 p=end;
 delete p;
 end=q;	
 }		
	
 int display()
 {
  q=end->link;
 while(q!=end)
 {
  cout<<q->data<<" ";
 q=q->link;

 }
 cout<<end->data;
 }	
							
 int search()
 { 
 int ci;
 cout<<"1-Search By Index\n2-Search By Value"<<endl;
 cin>>ci;
 switch (ci)
 {
 case 1:
 sindex();
 break;
 case 2:
 svalue();
 break;
 default:
 cout <<"Invalid Input"<<endl;
 }
 }

 int sindex()
 {
 q=end->link;
 int in;
 cout<<"Enter Index= ";
 cin>>in;
 for(int i=1;i<in;i++)
  {
 q=q->link;

  } 
 cout<<"Data Found"<<endl;
 cout<<q->data;		
 	}
	
 int svalue()
 { 
 q=end->link;
 int i=0;
 int value;
 cout<<"Value= ";
 cin>>value;
 while(q!=end)
 {
 if(q->data==value)
 {
 cout<<"Data Found"<<endl;
 i++;
 break;
 }
 q=q->link;
 }
 if(i==0)
 {
 cout<<"Data Not found !"<<endl;
 }
 }		

 int modify()
 { 
 int ci;
 cout<<"1-Modify By Index\n2-Modify By Value"<<endl;
 cin>>ci;
 switch (ci)
 {
 case 1:
 mindex();
 break;
 case 2:
 mvalue();
 break;
 default:
 cout <<"Invalid Input"<<endl;
 }
 }
 	

 int mindex()
 {
 q=end->link;
 int index;
 cout<<"Index= ";
 cin>>index;
 for(int i=1;i<index;i++)
  {
 q=q->link;
  
  } 
 cout<<"Found"<<endl;
 cout<<q->data;
 cout<<"\nEnter New data= ";	
 cin>>q->data;
 }
	
 int mvalue()
 {
 q=end->link;
 int i=0;
 int value;
 cout<<"Enter Value= ";
 cin>>value;
 while(q!=end)
{
if(q->data==value)
{
cout<< "Enter new value= ";
cin>>q->data;
i++;
break;
 }
q=q->link;
 }
 if(i==0)
{
cout<<"Data Not Found"<<endl;
}
}													
