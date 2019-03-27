#include<iostream>
#include<cstring>
using namespace std;
struct node
{
	char c;
	node *lchild;
	node *rchild;
};
node* search(node *m,char n);
node* search(node *m,char n)
{
	if(n==m->c)
	{
		return m;
	}
	else
	{
	if(m->rchild!=NULL)
	return (search(m->rchild,n));
	if(m->lchild!=NULL)
	return (search(m->lchild,n));}
}
int isleft(char f[],char g,char h);
int isleft(char f[],char g,char h)
{
	int x=0,z=0;
	while(f[x]!=h)
	{
		if(f[x]==g)
		z++;
		x++;
	}
	if(z!=0)
	return 1;
	else
	return 0;
}
int isright(char f[],char g,char h,int b);
int isright(char f[],char g,char h,int b)
{
	int x=b,z=0;
	while(f[x]!=h)
	{
		if(f[x]==g)
		z++;
		x--;
	}
	if(z!=0)
	return 1;
	else
	return 0;
}
void create(char a[],char b,char c,node *&l,int c1);
void create(char a[],char b,char c,node *&l,int c1)
{       int c4;
        c4=isleft(a,b,c);node *r,*t,*p;p=l;
		if(c4!=0)
		{
		    r=search(l,c);cout<<r->c<<endl;
			if(r->lchild==NULL)
			{
				t=new(node);
				t->c=b;
				t->lchild=NULL;
				t->rchild=NULL;
				r->lchild=t;
			}
			else
			{
					c=r->lchild->c;cout<<c<<endl;l=p;
				    create(a,b,c,l,c1);
			}
		}
		else
		{	c4=isright(a,b,c,c1);
			if(c4!=0)
			{
				r=search(l,c);cout<<r->c<<endl;
				if(r->rchild==NULL)
				{
					t=new(node);
					t->c=b;
					t->lchild=NULL;
					t->rchild=NULL;
					r->rchild=t;
				}
				else
				{
					c=r->rchild->c;cout<<c<<endl;l=p;
					create(a,b,c,l,c1);
				}}
}	
}
void print(node *l);
void print(node *l)
{
	if(l!=NULL)
	{
		print(l->lchild);
		print(l->rchild);
		cout<<l->c<<" ";
	}
}
int main()
{
	char a[100],b[100],d,c3;
	cout<<"enter the inorder sequence \n";
	cin>>a;
	cout<<"enter the preorder expression \n";
	cin>>b;
	int c1=0,c2=0,c4;
	while(a[c1]!='\0')
	c1++;
	node *l,*s,*t,*r;
	l=new(node);
	l->c=b[0];c3=b[0];
	l->lchild=NULL;s=l;
	l->rchild=NULL;
	for(int i=1;i<c1;i++)
	{
		d=b[i];
		create(a,d,c3,l,c1);l=s;
	c3=b[0];
	}l=s;
	print(l);
	return 0;
}
