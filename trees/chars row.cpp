#include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	char data;
	bstnode *rchild;
};
void insert(bstnode *t,char  n);
int main()
{
    char a;
	bstnode *t;
	t=NULL;
	cout<<"enter the root of the tree\n";
	cin>>a;
	insert(t,a);
}
void insert(bstnode *t,char n)
{  
    char ch;
	if(t==NULL)
	{
		t=new(bstnode);
		t->lchild=NULL;
		t->rchild=NULL;
		t->data=n;
		insert(t,n);
	}
	else 
	
	{
	char b;
	 if(t->lchild==NULL)
		cout<<"enter the leftchild "<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			n=ch;
			insert(t->lchild,n);
		}
   	if(t->rchild==NULL)
			cout<<"enter right child "<<"\n";
			cin>>ch;
			if(ch!='.' )
			{insert(t->rchild,n);
				n=ch;
			}	
	}
}

