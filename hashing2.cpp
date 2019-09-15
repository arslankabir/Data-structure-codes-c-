#include<iostream>
#include<conio.h>
using namespace std;
class Node{
private:
int 	object;
Node *nextnode;
public:
	void set(int object){ this->object=object;}
	int get(){return object;}
	Node * getnext(){return nextnode;	}
	void setnext(Node *nextnode){this->nextnode=nextnode;} 
};
class List{
	private :
		int size;
		Node *headnode,*CN,*LN;
	public:
	List() 
{
	
headnode   =   new Node();
	headnode->setnext(NULL);
	CN   =   NULL;
	LN  =   NULL;
	size   =   0;
}	
void add(int object){
Node *newnode=new Node();
newnode->set(object);
if(CN!=NULL){
	newnode->setnext(CN->getnext());
	CN->setnext(newnode);
	LN=CN;
	CN=newnode;
}
else{
	newnode->setnext(NULL);
	headnode->setnext(newnode);
	LN=headnode;
	CN=newnode;
}
size++;
}
void Display(){
	Node *p;
	int n=1;
	p=headnode->getnext();
	while(p->getnext()!=NULL){
		cout<<"\tThe node: "<<n<<" = "<<p->get();
		n++;
		p=p->getnext();
	}
			cout<<"\tThe node : "<<n<<" = "<<p->get()<<endl;

}
};
main(){
	int ch,k;
List l[10];	
	do{
	cout<<"\n1-for enteries";
	cout<<"\n2-for disply";
	cout<<"\n0-exit";
	cin>>ch;
	switch(ch){
		case 1:{
			int v;
			cout<<"\n ENTER VALUE = ";
			cin>>v;
			k=v%10;
			l[k].add(v);
		
			break;}
			case 2:{
			for(int i=0;i<10;i++){
				cout<<"index no : "<<i;
				l[i].Display();
			}
				break;}
				case 0:
					break;
	
	}
}while(ch!=0);
	


getch();
return 0;
}

