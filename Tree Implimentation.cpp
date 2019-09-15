#include<iostream>
#include<conio.h>
#include<stdlib.h>
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
	public:
		TreeNode *arr[101];
		int front,rear;

		queue()
		{
			front=-1;
			rear=-1;
		}
		bool isempty()
		{
		 if(front==-1&&rear==-1|| front>rear)
		 return true;
		 else
		 return false;
		}
		void enqueue(TreeNode *data)
		{
			if(isempty())
			{
				front = rear =0 ;
			}
			else
			{
				rear= rear+1;
			}
			arr[rear]=data;
		}
		TreeNode* dequeue()
		{
			if(isempty())
			{
				cout<<"\nERROR: queue is empty";
				return 0;
			}
			else
			{
				int q=front;
				front = front +1;
				return arr[q];
			}
			
		}
		
		
};
void level(TreeNode *treeNode) ;
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
	{
		p->setleft(newnode);
	}
	else
	{
		p->setright(newnode);
	}
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

TreeNode *findMin(TreeNode *tree);
TreeNode *findMin(TreeNode *tree)
{
    if( tree == NULL ) 
        return NULL;
    if( tree->getleft() == NULL ) 
        return tree; 
    return findMin( tree->getleft() );
}


int main()
{
	
	int array[]={ 14,15,4,1,2,5,6,8,10,11,12,13,7,18,3,5,16,4,20,17,18,19,
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
			 cout<<"1 for preorder\n2 for inorder\n3 for levelorder\n";
			 cout<<"Enter your choice:-\n";
			 int b;
			 cin>>b;
			 
			 
		 if(b==2)
		{		
			 inorder(root);
		}
		else if(b==3)
		{
			level(root);
			
		}
		else
		{
			cout<<"Invalid Entry\n";
		}
	}
	getch();
	return 0;
}
