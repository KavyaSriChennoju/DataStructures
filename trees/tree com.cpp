#include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	char data;
	bstnode *rchild;
};
void   compare(bstnode *t1,bstnode *t2);
void insert(bstnode *t,char  n);
int main()
{
    char a;
	bstnode *t1,*t2,*s1,*s2;
		t1=new(bstnode);
	t1->lchild=NULL;
	t1->rchild=NULL;
	s1=t1;
	cout<<"enter the root of the tree  1\n";
	cin>>a;
	t1->data=a;
	insert(t1,a);
		t2=new(bstnode);
	t2->lchild=NULL;
	t2->rchild=NULL;
	s2=t2;
	cout<<"enter root of tree 2\n";
	cin>>a;
	t2->data=a;
	insert(t2,a);
	t1=s1;t2=s2;
	compare(t1,t2);
	
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
	{
		cout<<"enter the leftchild "<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			n=ch;
			insert(t->lchild,n);
		}}
   	if(t->rchild==NULL)
			cout<<"enter right child "<<"\n";
			cin>>ch;
			if(ch!='.' )
			{insert(t->rchild,n);
				n=ch;
			}	
	}
}
void   compare(bstnode *t1,bstnode *t2)
{
	if(t1!=NULL)
	{
    	compare(t1->lchild,t2->lchild);
     	if(t1->data==t2->data)
     	
		  {if(t2->rchild==NULL)
     		cout<<"trees are similar\n";
     	}
     	else
     	{
     		if(t2->rchild==NULL)
     		cout<<"trees are not similar\n";
     	}
		compare(t1->rchild,t2->rchild);
	}
}
