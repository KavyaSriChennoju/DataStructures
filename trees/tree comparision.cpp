#include<iostream> 
using namespace std;
struct bstnode
{
	char data;
	bstnode *lchild;
	bstnode *rchild;
};
void create(bstnode *&m,char a);
void sor(bstnode *m,bstnode *n,int &c);
void sort(bstnode *m,bstnode *n,int &c);
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
	create(l1,c);
		bstnode *l2,*s2,*t2;
	l2=new(bstnode);
	l2->lchild=NULL;
	l2->rchild=NULL;
	cout<<"enter the root \n";
	cin>>c;
	l2->data=c;
	s2=l2;t2=l2;
	create(l2,c);
	int k=1,t=1;
	sort(t1,t2,k);
	if(k==0)
	cout<<"not similar \n";
	else
	cout<<"similar \n";
	sor(t1,t2,t);
	if(t==0)
	cout<<"not mirror similar \n";
	else
	cout<<"mirror similar \n";
	return 0;		
}


void create(bstnode *&m,char c)
{
	char ch;int h;
	if(m->lchild==NULL)
	{
		cout<<"enter left child of   "<<c;
		cin>>ch;
		if(ch!='.')
		{
	
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;
			m->lchild=t;
			create(m->lchild,ch);
		}
	}
	if(m->rchild==NULL)
	{
		cout<<"enter right child  of    "<<c;
		cin>>ch;
		if(ch!='.')
		{
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;
			m->rchild=t;
			create(m->rchild,ch);
		}
	}
}

void sort(bstnode *m,bstnode *n,int &c)
{
	if(m->lchild!=NULL&&n->lchild!=NULL)
	sort(m->lchild,n->lchild,c);
	if(m->data!=n->data)
	c=0;
	if(m->rchild!=NULL&&n->rchild!=NULL)
	sort(m->rchild,n->rchild,c);
	if(m->lchild!=NULL&&n->lchild==NULL)
	c=0;
	if(m->lchild==NULL&&n->lchild!=NULL)
	c=0;
	if(m->rchild!=NULL&&n->rchild==NULL)
	c=0;
	if(m->rchild==NULL&&n->rchild!=NULL)
	c=0;
}

void sor(bstnode *m,bstnode *n,int &c)
{
	if(m->lchild!=NULL&&n->rchild!=NULL)
	sor(m->lchild,n->rchild,c);
	if(m->data!=n->data)
	c=0;
	if(m->rchild!=NULL&&n->lchild!=NULL)
	sor(m->rchild,n->lchild,c);
	if(m->lchild!=NULL&&n->rchild==NULL)
	c=0;
	if(m->lchild==NULL&&n->rchild!=NULL)
	c=0;
	if(m->rchild!=NULL&&n->lchild==NULL)
	c=0;
	if(m->rchild==NULL&&n->lchild!=NULL)
	c=0;
}
