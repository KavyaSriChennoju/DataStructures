#include<iostream> 
using namespace std;
struct bstnode
{
	char data;
	bstnode *lchild;
	bstnode *rchild;
};
class stack
{ 
    public:
    bstnode *b[20];
	int top;
	bstnode * pop();
	void push(bstnode *a);
	stack()
	{
		top=-1;
	}
};
bstnode * stack::pop()
{
	if(top>-1)
	return b[top--];
}
void stack::push(bstnode *a)
{
	if(top<9)
	b[++top]=a;
}
void create(bstnode *&m,char c);
void sort(bstnode *m,int p);
void print(bstnode *m);
int main()
{
	char c;
	int d;
		stack s1;
	bstnode *l,*s,*t;
	l=new(bstnode);
	l->lchild=NULL;
	l->rchild=NULL;
	cout<<"enter the root \n";
	cin>>c;
	l->data=c;
	s1.push(l);
	s=l;t=l;
   char ch;
	if(l->lchild==NULL)
	{
	l1:	cout<<"enter left child of   "<<c<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;
			l->lchild=t;
			l=l->lchild;
			s1.push(l);
			if(l->lchild==NULL)
			{
			c=ch;
			goto l1;}	
        }
        if(ch=='.')
        	{
        	if( l->rchild==NULL)
			{
		     bstnode *t;
		     t=s1.pop();
		     c=t->data;
			goto l2;
			}}
	}
	if(l->rchild==NULL)
	{
	l2:	cout<<"enter right child  "<<c<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			bstnode *t;
			t=new(bstnode);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;
			l->rchild=t;
			l=l->rchild;
			s1.push(l);
			if(s1.top!=-1)
		     {
		     	c=ch;
			goto l1;}
			if(l->rchild==NULL)
			{
			c=ch;
			goto l2;}}
		 if(ch=='.')
        	{
        	if( l->rchild==NULL)
			{

		     if(s1.top!=-1)
		     {
		     			     bstnode *t;
		     t=s1.pop();
		     c=t->data;
			goto l2;}
			}}	
	}
	l=s;
	print(l);
	return 0;		
}

void print(bstnode *m)
{
	
	if(m!=NULL)
	{
		if(m->lchild!=NULL)
		print(m->lchild);
		cout<<m->data<<" ";
		if(m->rchild!=NULL)
		print(m->rchild);
	}

}

