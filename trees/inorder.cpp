#include <iostream>
#include <cstdlib>
using namespace std;
struct bstnode
{
	bstnode* lchild;
	char ch;
	bstnode* rchild;
};
class stack
{
public:
int top;
int size;
bstnode* k[100];
void push(bstnode *);
bstnode* pop();
bool isfull()
{
if(top>=size-1)
return true;
else
return false;
}

bool isempty()

{
	
if(top<0)
		
return true;

else 
return false;
}
stack(int s)
{
size=s;top=-1;}
};
void stack::push (bstnode* r)
{
k[++top]=r;}
bstnode* stack::pop()
{
return(k[top--]);}
void add(bstnode* &l,char c)
{
	if(l==NULL)
	{
		l=new(bstnode);
		l->ch=c;
		l->rchild=NULL;
		l->lchild=NULL;
	}
	cout<<"enter left child";
	cin>>c;
	if(c!='*')
	{
		add(l->lchild,c);
	}
	cout<<"enter right child";
	cin>>c;
		if(c!='*')
		{
			add(l->rchild,c);
		}
}
void print(bstnode* l)
{
	if(l->lchild!=NULL)
		print(l->lchild);
	cout<<l->ch;
	if(l->rchild!=NULL)
		print(l->rchild);
	return;
}
int main()
{
	bstnode* l;int k=1;
	stack s(50);
	l=NULL;
	cout<<"enter root";
	char c;
	cin>>c;
	add(l,c);
	bstnode* t;
	t=l;
	bstnode* t1;
	t1=l;
	
	
		while(t1->lchild!=NULL)
		{
			l=t1;
			s.push(l);
			t1=t1->lchild;
		}
		//cout<<t1->ch;
		
		do
		{
			//cout<<s.top;
			if(s.top!=-1)
				cout<<t1->ch;
			if(s.top==-1)
				s.push(t1);
			while(t1->rchild!=NULL)
			{
				t1=t1->rchild;
				if(s.top!=0)
					cout<<t1->ch;
				
				while(t1->lchild!=NULL)
				{
					l=t1;
					s.push(l);
					t1=t1->lchild;
				}
				//cout<<t1->ch;
			}
			t1=s.pop();

			if(k==1)
			{
			if(s.top==0)
			{
				//cout<<"lol";
				break;
			}
			k=0;
		}
		else
		{
			if(s.top==-1)
			{
				//cout<<"lol";
				break;
			}
			
		}
			
			
		
		}while(1);
		cout<<t1->ch;

		return 0;
}