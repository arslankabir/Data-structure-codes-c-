#include<iostream>
#include<conio.h>
using namespace std;
class TreeNode
{
	private:
		int *obj;
		TreeNode *left;
		TreeNode *right;
		public:
			int *get()
			{
				return this->obj;
			}
			void set(int *obj)
			{
				this->obj=obj;
			}
			TreeNode *getleft()
			{
				return left;
			}
			void setleft(TreeNode *left)
			{
				this->left=left;
			}
			TreeNode *getright()
			{
				return right;
			}
			void setright(TreeNode *right)
			{
				this->right=right;
			}
			TreeNode()
			{
				this->obj=NULL;
				this->left=this->right=NULL;
			}
			TreeNode(int *obj)
			{
				this->obj=obj;
				this->left=this->right=NULL;
			}
};
class queue
{
	TreeNode *arr[100];
	int front,rear;
	public:
	queue()
	{
		front = rear = -1;
	}	
	bool isempty()
	{
		if(front==-1&&rear==-1)
		return true;
		else
		return false;
	}
	void enqueue(TreeNode *data)
	{
		if(isempty())
		{
			front = rear =0;
		}
		else
		{
			rear=rear+1;
		}
		 arr[rear] =data;
	}
	TreeNode *dequeue()
	{
		if(!isempty())
		{
			int q=front;
			front=front+1;
			return arr[q];
		}
	}
	
};
void level(TreeNode *treeNode);
void level(TreeNode *treeNode)
{
	queue q;
	if( treeNode == NULL ) return;
    q.enqueue( treeNode);
    while( !q.isempty() ) 
    {
        treeNode = q.dequeue();
        cout << *(treeNode->get()) << " ";
        if(treeNode->getleft() != NULL )
			q.enqueue( treeNode->getleft());
        if(treeNode->getright() != NULL )
			q.enqueue( treeNode->getright());
    }
    cout << endl;

}
void inorder(TreeNode *treeNode);
void insert(TreeNode *root,int *info);
void insert(TreeNode *root,int *info)
{
	TreeNode *newnode=new TreeNode(info);
	TreeNode *p;
	TreeNode *q;
	p=q=root;
	while(*info!=*(p->get())&&q!=NULL)
	{
		p=q;
		if(*info<*(p->get()))
		{
			q=p->getleft();
			
		}
		else
		{
			q=p->getright();
			
		}
		
}
	if(*info==*(p->get()))
	{
		cout<<"it is a duplicate number:="<<*info<<endl;
		delete newnode;
	}
	else if(*info<*(p->get()))
	p->setleft(newnode);
	else
	p->setright(newnode);
}
void inorder(TreeNode *treeNode)
{
	if(treeNode!=NULL)
	{
		inorder(treeNode->getleft());
		cout<<"Element:="<<*(treeNode->get())<<endl;
		inorder(treeNode->getright());
	}
}
void preorder(TreeNode *treeNode);
void preorder(TreeNode *treeNode)
{
	if(treeNode!=NULL)
	{
		cout<<"Element:="<<*(treeNode->get())<<endl;
		preorder(treeNode->getleft());
		preorder(treeNode->getright());
	}
}
void postorder(TreeNode *treeNode);
void postorder(TreeNode *treeNode)
{
	if(treeNode!=NULL)
	{
		postorder(treeNode->getleft());
		postorder(treeNode->getright());
		cout<<"Element:="<<*(treeNode->get())<<endl;
	}
}
void maximum_value(TreeNode *root);
void maximum_value(TreeNode *root)
{
	TreeNode *e;
	e=root;
	while(e->getright()!=NULL)
	{
		e=e->getright();
	}
	cout<<"The Maximum Value is:="<<*(e->get())<<endl;
}
void minimum_value(TreeNode *root);
void minimum_value(TreeNode *root)
{
	TreeNode *r;
	r=root;
	while(r->getleft()!=NULL)
	{
		r=r->getleft();
	}
	cout<<"The Minimum Value is:="<<*(r->get())<<endl;
}
TreeNode *remove(TreeNode *tree,int info)
{
	TreeNode *k;
	int com=info-*(tree->get());
	if(com<0)
	{
		k=remove(tree->getleft(),info);
		tree->setleft(k);
	}
	else if(com>0)
	{
		k=remove(tree->getright(),info);
		tree->setright(k);
	}
	else if(com=0)
	{
		TreeNode *ntd;
		ntd=tree;
		if(ntd->getleft()==NULL && ntd->getright()==NULL)
		{
			delete ntd;
			tree=NULL;
			return tree;
		}
	/*	else if(ntd->getleft()==NULL && )*/
	}
}
void srch(TreeNode *root,int *data)
{
	TreeNode *p,*q;
	p=q=root;
	while(*data==*(root->get()))
	{
	if(*data<*(p->get()))
	q=p->getleft();
	else
	q=p->getright();
	}	
cout<<"srched: "<<*(q->get());
}
int main()
{
	
	
	
	int array[]={ 14, 15, 4, 9, 7, 18, 3, 5, 16,4, 20, 17, 
			 9, 14,5, -1};
			 TreeNode *root=new TreeNode();
			 root->set(&array[0]);
			 for(int a=1;array[a]>0;a++)
			 {
			 	insert(root,&array[a]);
			 }
			 while(1)
			 {
			 
			 cout<<"\nNow Choice order\n\n";
			 cout<<"1 for preorder\n2 for inorder\n3 for postorder\n4 for maximum value\n5 for minimum value\n6 for delete\n7 for level:";
			 cout<<"Enter your choice:-\n";
			 int b;
			 cin>>b;
			 if(b==1)
			 {
			 	
			 preorder(root);	
		}
		else if(b==2)
		{		
			 inorder(root);
		}
		else if(b==3)
		{
					postorder(root);
		}
		else if(b==4)
		{
			maximum_value(root);
		}
		else if(b==5)
		{
			minimum_value(root);
		}
		else if(b==6)
		{
			int val;
			cout<<"enter the value that u want to delete\n";
			cin>>val;
			remove(root,val);
		}
		else if(b==7)
		{
			level(root);
		}
		else
		{
			cout<<"invalid entry\n";
		}
	}
	getch();
	return 0;
}
