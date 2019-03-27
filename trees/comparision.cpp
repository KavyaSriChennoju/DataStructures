#include<iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};

void   compare(bstnode *t1,bstnode *t2);
void create(bstnode *&m);
int main()
{
	int c;
	bstnode *l1,*s1,*t1,*l2,*s2,*t2;
	l1=new(bstnode);
	l1->lchild=NULL;
	l1->rchild=NULL;
	cout<<"enter the root of first tree \n";
	cin>>c;
	l1->data=c;
	create(l1);
		s1=l1;t1=l1;
	l2=new(bstnode);
	cout<<"enter the root of second tree \n";
	cin>>c;
	l2->data=c;
	l2->lchild=NULL;
	l2->rchild=NULL;
	s2=l2;t2=l2;
	create(l2);
	compare(l1,l2);
	return 0;	
}
void create(bstnode *&m)
{
	char ch;
	if(m->lchild==NULL)
	{
		cout<<"enter left child  \n";
		cin>>ch;
		if(ch!='.')
		{
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;
			m->lchild=t;
			create(m->lchild);
		}
	}
	if(m->rchild==NULL)
	{
		cout<<"enter right child  \n";
		cin>>ch;
		if(ch!='.')
		{
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;
			m->rchild=t;
			create(m->rchild);
		}
	}
}
void   compare(bstnode *t1,bstnode *t2)
{
	if(t1!=NULL)
	{
	compare(t1->lchild,t2->lchild);
	if(t1->data==t2->data)
	{
		cout<<"trees are similar\n";
	}}
	if(t1!=NULL)
	{
		compare(t1->rchild,t2->rchild);
	}
}
