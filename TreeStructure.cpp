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
TreeNode* insert(TreeNode *root,int *data)
{
	TreeNode *newNode = new TreeNode();
	newNode->set(data);	
	TreeNode *p,*q;
	p=q=root;
		while(q!=NULL)
	{
		p=q;
		if(*data<*(p->get()))
		{
			q=p->getleft();
		}
		else
		{
			q=p->getright();
		}
	}
if(*data==*(p->get()))
	cout<<"element doublicate: "<<*data;
	else if(*data<*(p->get()))
	p->setleft(newNode);
	else
	p->setright(newNode);

}
TreeNode* insrt(TreeNode *root,int *data)
{
	TreeNode *i;
	if(root==NULL)
	{
	TreeNode *newNode = new TreeNode();
	newNode->set(data);	
	}
	else if(*data<*(root->get()))
	{
		i=insrt(root->getleft(),data);
		root->setleft(i);
	}
	else
	{
		i=insrt(root->getright(),data);
		root->setright(i);
	}
	return root;
}
void inorder(TreeNode *root)
{
	if(root==NULL) return;

		inorder(root->getleft());
		cout<<"\nelement: "<<*(root->get());
		inorder(root->getright());
}
bool search(TreeNode *root,int *data)
{
	if(root->get()==NULL) return false;
	else if(*(root->get())==*data) return true;
	else if(*data<=*(root->get())) 
	return search(root->getleft(),data);
	else
	return search(root->getright(),data);
}
void srch(TreeNode *root,int *data)
{

	
	if(*data!=*(root->get()))
	{
	if(*data<*(root->get()))
	return srch(root->getleft(),data);
	else
	return srch(root->getright(),data);
	}
	else if(root->getleft()!=NULL&&root->getright()!=NULL)
	{	
	TreeNode *p=root->getleft();
	TreeNode *q=root->getright();
	cout<<"data: "<<*(root->get());
	cout<<"\nleft child: "<<*(p->get());
	cout<<"\nright child: "<<*(q->get())<<endl;
	return;
	}
	else if(root->getleft()==NULL&&root->getright()==NULL) 
	{
	cout<<"data: "<<*(root->get());
	return ;
	}
	else
	{
		if(root->getleft()==NULL)
		{
		TreeNode *temp=root->getright();
		cout<<"\ndata: "<<*(root->get());
		cout<<"\nright child: "<<*(temp->get());
		cout<<"\nleft child: NULL";
		}
		else if(root->getright()==NULL)
		{
			TreeNode *temp=root->getleft();
		cout<<"\ndata: "<<*(root->get());
		cout<<"\nleft child: "<<*(temp->get());
		cout<<"\nright child: NULL";
		}

	}

	
	
}
void srch2(TreeNode *root,int *data)
{
	if(*data!=*(root->get()))
	{
		if(*data<*(root->get()))
		{
		srch2(root->getleft(),data);
		}
		else
		{
		srch2(root->getright(),data);
		
		}
		cout<<"\nparrent is: "<<*(root->get());
	}
		
}
TreeNode* min(TreeNode *root)
{
	
	while(root->getleft()!=NULL)
	root=root->getleft();
	return root;
}
TreeNode* max(TreeNode *root)
{
	
	while(root->getright()!=NULL)
		root=root->getright();
	return root;
}
TreeNode* dlt(TreeNode *root,int *data)
{
	TreeNode *i;
	if(*data<*(root->get()))
	{
	return dlt(root->getleft(),data);
	
	}
	else if(*data>*(root->get()))
	{
		return dlt(root->getright(),data);
		
	}
	else
	{
		// case:1 have 2 child
	if(root->getleft()&&root->getright()!=NULL)
		{
			TreeNode *temp;
			temp=min(root->getright());
			*(root->get())=*(temp->get());
			i=dlt(root->getright(),temp->get());
			root->setright(i);
		}
		// case: 2 have 1 child
		else
		{
			TreeNode *temp2=root;
			if (root->getleft()==NULL)
			root= root->getright();
			else if(root->getright()==NULL)
			root=root->getleft();
			else root=NULL;
			delete temp2;
		}
		return root;
}
}

int main()
{
	TreeNode *root = new TreeNode();
	int arr[]={15,20,10,25,8,12,17,18,16};
	root->set(&arr[0]);
	for(int i=1;i<=arr[i];i++)
	insert(root,&arr[i]);

	int op;
	while(1)
	{
		cout<<"\nEnter 1 for to search childs: ";
		cout<<"\nEnter 2 for inorder print: ";
		cout<<"\nEnter 3 for maximum number: ";
		cout<<"\nEnter 4 for delete Node: ";
		cout<<"\nEnter 5 for to exit: "<<endl;
		cin>>op;
		switch(op)
		{
	
		case 1:
			int n;
			cout<<"enter index to search: "<<endl;
			cin>>n;
			srch(root,&arr[n]);
		break;
		case 2:
			inorder(root);
			break;
		case 3:
			min(root);
			break;
			case 4:
				int i;
				cout<<"\nenter the index no: ";
				cin>>i;
				root= dlt(root,&arr[i]);
				break;
				
					
		case 5:
			exit(0);
			break;
		}//end of switch
	}//end of while
}//end of main
