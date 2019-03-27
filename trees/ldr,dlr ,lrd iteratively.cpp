#include<iostream>
using namespace std;
struct bst
{
	char data;
	bst *lchild;
	bst *rchild;
};
class stack
{
	public:
	bst *a[20];
	int top;
	stack()
	{
		top=-1;
	}
	bst* pop();
	void push(bst *t);
};
void stack::push(bst *t)
{
	if(top<19)
	a[++top]=t;
}
bst* stack::pop()
{
	if(top>-1)
	return a[top--];
}
void create(bst *&m);
void create(bst *&m)
{
	char ch;
	if(m->lchild==NULL)
	{	
		cout<<"enter left child of"<<m->data<<" \n";
		cin>>ch;
		if(ch!='.')
		{
			bst *t;
			t=new(bst);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;m->lchild=t;
			create(m->lchild);
		}
	}
	if(m->rchild==NULL)
	{
		cout<<"enter right child of"<<m->data<<"  \n";
		cin>>ch;
		if(ch!='.')
		{
			bst *t;
			t=new(bst);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;m->rchild=t;
			create(m->rchild);
		}
	}
}
int main()
{
	char c,m[100];stack b;
	bst *l,*s,*t,*p;int r=0;
	l=new(bst);
	l->lchild=NULL;
	l->rchild=NULL;
	cout<<"enter the root  \n";
	cin>>c;
	l->data=c;s=l;t=l;
	create(l);l=s;
	l1:
	{	
	while(l!=NULL)
	{
		b.push(l);
		l=l->lchild;
	}
	while(b.top!=-1)
	{
		p=b.pop();
		cout<<p->data;
		if(p->rchild!=NULL)
		{
			l=p->rchild;
			goto l1;
	    }
	}}l=s;cout<<endl;
	l2:
	{
		while(l!=NULL)
		{
			b.push(l);
			cout<<l->data;
			l=l->lchild;
		}
		while(b.top!=-1)
		{
			p=b.pop();
			if(p->rchild!=NULL)
			{
				l=p->rchild;
				goto l2;
			}
		}
	}l=s;cout<<endl;
	l3:
	{
	   while(l!=NULL)
	   {
	   	  b.push(l);
	   	  l=l->lchild;
	   }
	   while(b.top!=-1)
	   {
	   	p=b.pop();
	  	   	if(p->rchild!=NULL)
	   	{
	   		l=p->rchild;
			m[r++]=p->data;
	   		goto l3;
	   	}
	   	else
	   {
	   	m[r++]=p->data;
	   	m[r++]=-1;}
	   }	
	}
	for(int i=0;i<r;i++)
	{
		if(m[i]==-1)
		{
		int k=i-1;
		while(m[k]!=-1&&k!=-1)
		cout<<m[k--];	
		}
	}
	return 0;	
}
