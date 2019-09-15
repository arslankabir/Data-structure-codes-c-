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
	cout<<"sa";
}
{
	
		TreeNode *i;
	if(root==NULL)
	{
	TreeNode *root = new TreeNode();
	root->set(data);
return root;
	}
	else if (*data<*(root->get()))
	{
		i=insert(root->getleft(),data);
		root->setleft(i);
	return root;
	}
	
		else{			
		i=insert(root->getright(),data);
		root->setright(i);
		return root;
		}
	
			return root;
}
void show(TreeNode *root,int *data)
{

	if(*data!=*(root->get()))
	{
	if(*data<*(root->get()))
	return show(root->getleft(),data);
	else
	return show(root->getright(),data);
	}
	else if(root->getleft()&&root->getright()!=NULL)
	{
		TreeNode *p,*q;
		p=root->getleft();
		q=root->getright();
		cout<<"\ndata: "<<*(root->get());
		cout<<"\nleft child: "<<*(p->get());
		cout<<"\nright child: "<<*(q->get());
	}
	else
	cout<<"\ndata with no any child: "<<*(root->get());
	
}
void inorder(TreeNode *root)
{
	if(root!=NULL){
	
	
	inorder(root->getleft());
	cout<<"\nelement: "<<*(root->get());
	inorder(root->getright());
}
	
	
}
int main()
{
	int op;
	TreeNode *root=NULL;
		
	while(1)
	{
		cout<<"\nenter  1 to insert value: ";
		cout<<"\nenter 2 to show: ";
		cout<<"\nenter 3 to search: "<<endl;
	cin>>op;
	switch(op)
	{
	case 1:
		int a;
	cout<<"\nenter value to insert: ";
	cin>>a;
	root = insert(root,&a);
	break;
	case 2:
		int k;
	//	cout<<"enter value to show: ";
	//	cin>>k;
		//show(root,&k);
		inorder(root);
		break;
		case 3:
			int n;
			cout<<"\nenter value: ";
			cin>>n;
			show(root,&n);
			break;
	exit(0);
	break;
	}
}
}
