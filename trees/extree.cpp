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
class stack
{ public:
	etnode* a[50];
	int top;
	etnode* pop();
	void push(etnode* n);
	stack()
	{
		top=-1;
	}
};
etnode* stack::pop()
{
	if(top>-1)
	return a[top--];
}
void stack::push(etnode* n)
{
	if(top<49)
	a[++top]=n;
}
int calc(char a,int b,int c);
int eval (etnode *t);
int main()
{  
    int r;
	string s1;stack s2;
	cout<<"enter the postfix expresion \n";
	cin>>s1;
	etnode *l,*s,*t;
	int k=s1.length();
	for(int i=0;i<k;i++)
	{
		if(s1.at(i)!='*'&&s1.at(i)!='/'&&s1.at(i)!='-'&&s1.at(i)!='+')
		{
		l=new(etnode);
		l->data.tag=1;
		l->data.opnd=(s1.at(i)-'0')	;
		l->lchild=NULL;
		l->rchild=NULL;
		s2.push(l);
		}
		else
		{
			s=s2.pop();
			t=s2.pop();
			l=new(etnode);
			l->data.tag=2;
			l->data.oper=s1.at(i);
			l->lchild=t;
			l->rchild=s;
			s2.push(l);
		}
	}
	s=s2.pop();
	cout<<"the result is \n";
	 r=eval(s);
	 cout<<r<<"\n";

}
int eval(etnode *t)
{  
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
	if(a=='/')
	return(b/c);
}
