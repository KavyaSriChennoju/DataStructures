#include<iostream>
using namespace std;
struct btnode
{
	char data;
	btnode *parent;
	btnode *lchild;
	btnode *rchild;
};
void create(btnode *&m,char a);
void create(btnode *&m,char a)
{
	char ch;
	if(m->lchild==NULL)
	{
		cout<<"enter left child of "<<a<<" \n";
		cin>>ch;
		if(ch!='.')
		{
			btnode *t;
			t=new(btnode);
			t->data=ch;
			t->lchild=NULL;t->parent=NULL;
			t->rchild=NULL;m->lchild=t;m->lchild->parent=m;
			create(m->lchild,ch);
		}
	}
	if(m->rchild==NULL)
	{
		cout<<"enter right child of "<<a<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			btnode *t;
			t=new(btnode);
			t->data=ch;
			t->lchild=NULL;t->parent=NULL;
			t->rchild=NULL;m->rchild=t;m->rchild->parent=m;
			create(m->rchild,ch);
		}
	}
}
int pwr(int d)
{
	int k=1;
	for(int i=0;i<d;i++)
	k=k*2;
	return k;
}
int height(btnode *l)
{
	if(l==NULL)
	return 0;
	else
	{
		int a=height(l->lchild),b=height(l->rchild);
		if(a>b)
		return(a+1);
		else
		return(b+1);
	}
}static int n=0;
void print(btnode *l,int k)
{
	if(l!=NULL)
	{
	if(k==0)
	{
		int d=height(l);
		d=pwr(d-1);
		d=d+n;n=d-n;
		for(int i=0;i<d;i++)
		cout<<" ";
		cout<<l->data;
	}
	else
	{
		print(l->lchild,k-1);
		print(l->rchild,k-1);
	}
    }
}
int main()
{
	char c;int d;
	btnode *l,*s,*t;
	l=new(btnode);
	l->parent=NULL;
	l->lchild=NULL;
	l->rchild=NULL;
	cout<<"enter the root \n";
	cin>>c;
	l->data=c;s=l;t=l;
	create(l,c);
	d=height(l);
	for(int i=0;i<d;i++)
	{
	print(l,i);cout<<endl;n=0;
    }
	return 0;
		
}
