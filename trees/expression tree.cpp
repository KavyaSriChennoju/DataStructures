#include<iostream> 
using namespace std;
struct etnode
{
	etnode *lchild;
	union
	{
		int opnd;
		char oper;
		int tag;
	}data;
	etnode *rchild;
};
void create(etnode *&m,char c);
int calc(char a,int b,int c);
int eval (etnode *t);
int main()
{
	char c;
	int d,t;
	etnode *l,*s;
	l=new(etnode);
	l->lchild=NULL;
	l->rchild=NULL;
	cout<<"enter the tag  0/1 for operand/operator  \n";
	cin>>t;
	l->data.tag=t;
	if(t==0)
	{
		cout<<"enter operand\n";
		cin>>d;
		l->data.opnd=d;
		
	}
	else
{
	cout<<"enter operator\n";
	cin>>c;
		l->data.oper=c;
}
	s=l;int k;
	create(l,c);
	l=s;
k=eval(l);
cout<<k;
	return 0;		
}
void create(etnode *&m,char c)
{
	char ch;int h;int d;
	if(m->lchild==NULL)
	{
		cout<<"enter tag of lchild\n";
			cin>>h;
	
		if(h!=99)
		{
			
			etnode *t;
			t=new(etnode);
		    t->data.tag=h;
     	if(h==0)
    	{
		   cout<<"enter operand\n";
		   cin>>d;
	     	t->data.opnd=d;
		
     	}
    	else if(h==1)
        {
         	cout<<"enter operator\n";
         	cin>>c;
	     	t->data.oper=c;
         }

			t->lchild=NULL;
			t->rchild=NULL;
			m->lchild=t;
			create(m->lchild,ch);
		}
	}
	if(m->rchild==NULL)
	{
	     cout<<"enter tag of rchild \n";
			cin>>h;
		if(h!=99)
		{
			etnode *t;
			t=new(etnode);
		   t->data.tag=h;
     	if(h==0)
    	{
		   cout<<"enter operand\n";
		   cin>>d;
	     	t->data.opnd=d;
		
     	}
    	else if(h==1)
        {
         	cout<<"enter operator\n";
         	cin>>c;
	     	t->data.oper=c;
         }
			t->lchild=NULL;
			t->rchild=NULL;
			m->rchild=t;
			create(m->rchild,ch);
		}
	}
}
int eval(etnode *t)
{   int k;
if(t!=NULL)
{
	if(t->data.tag==0)
	return(t->data.opnd);
	else
	return(calc(t->data.oper,eval(t->lchild),eval(t->rchild)));
}}
int calc(char a,int b,int c)
{
	if(a=='*')
	return(b*c);
	if(a=='+')
	return(b+c);
	if(a=='-')
	return(b-c);
}
