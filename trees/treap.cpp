#include <iostream>
using namespace std;
struct tnode
{
	char key;
	int pri;
	tnode *lchild;
	tnode *rchild;
	tnode *parent;
};
int k=0;
void insert(tnode* &t,char ch,int d)
{
	if(t==NULL)
	{
		t=new(tnode);
		t->key=ch;
		t->pri=d;
		t->lchild=NULL;
		t->rchild=NULL;
		if(k==0)
		{
			t->parent=NULL;
			k=1;
		}
	}
	else if(ch<t->key)
	{
		insert(t->lchild,ch,d);
		t->lchild->parent=t;
		if(t->pri>t->lchild->pri)
		{
			tnode* k1=t->lchild;
			t->lchild=k1->rchild;
			if(k1->rchild!=NULL)
			k1->rchild->parent=t;
			k1->rchild=t;
			if(t->parent!=NULL)
			{
				if(t->parent->lchild==t)
					t->parent->lchild=k1;
				else
					t->parent->rchild=k1;
			}
				k1->parent=t->parent;
				t->parent=k1;
				t=k1;
		}

	}
	else if(ch>t->key)
	{
		insert(t->rchild,ch,d);
		t->rchild->parent=t;
		if(t->pri>t->rchild->pri)
		{
			tnode* k1=t->rchild;
			t->rchild=k1->lchild;
			if(k1->lchild!=NULL)
				k1->lchild->parent=t;
			k1->lchild=t;
			if(t->parent!=NULL)
			{
				if(t->parent->rchild==t)
					t->parent->rchild=k1;
				else
					t->parent->lchild=k1;
			}
				k1->parent=t->parent;
				t->parent=k1;
				t=k1;
		}
	}
}
void print(tnode* t)
{
	if(t->lchild!=NULL)
	print(t->lchild);
	cout<<t->key;
	cout<<t->pri<<endl;
	if(t->rchild!=NULL)
	print(t->rchild);	
}
int main()
{
	tnode *b1,*b2;
	b1=NULL;
	int p;char k;
	cout<<"enter key value and priority value or -1 to stop entering:";
	cin>>k>>p;
	while(p!=-1)
	{
		insert(b1,k,p);
		cout<<"enter key value and priority value or -1 to stop entering:";
		cin>>k>>p;
	}
	print(b1);
	return 0;
}
