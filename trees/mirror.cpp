#include<iostream> 
using namespace std;
struct bstnode
{
	char data;
	bstnode *lchild;
	bstnode *rchild;
};
void create(bstnode *&m);
void   compare(bstnode *t1,bstnode *t2);
void    mcompare(bstnode *t1,bstnode *t2);
void print(bstnode *m);
int main()
{
	char c;
	int d;
	bstnode *l1,*s1,*t1;
	l1=new(bstnode);
	l1->lchild=NULL;
	l1->rchild=NULL;
	cout<<"enter the root \n";
	cin>>c;
	l1->data=c;
	s1=l1;t1=l1;
	create(l1);
	bstnode *l2,*s2,*t2;
	l2=new(bstnode);
	l2->lchild=NULL;
	l2->rchild=NULL;
	cout<<"enter the root \n";
	cin>>c;
	l2->data=c;
	s2=l2;t2=l2;
	create(l2);
compare(l1,l2);
l1=s1;l2=s2;
//mcompare(l1,l2);
	return 0;		
}
void create(bstnode *&m)
{
	char ch;int h;
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
		  {if(t2->rchild==NULL && t2->lchild==NULL )
     		cout<<"trees are similar\n";
          }
       	else 
     	{if(t2->rchild==NULL && t2->lchild==NULL)
     		cout<<"trees are not similar\n";}
		compare(t1->rchild,t2->rchild);	
	}

}
void   mcompare(bstnode *t1,bstnode *t2)
{

	if(t1!=NULL)
{
	mcompare(t1->lchild,t2->rchild);
     	if(t1->data==t2->data)
	     {
		   if(t2->rchild==NULL && t2->lchild==NULL )
     		cout<<"trees are mirror similar\n";
     	}
     	else
     	{
     		if(t2->rchild==NULL && t2->lchild==NULL)
     		cout<<"trees are not similar\n";
     	}
		mcompare(t1->rchild,t2->lchild);
	}}

