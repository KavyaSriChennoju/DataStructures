#include<iostream> 
using namespace std;
struct bstnode
{
	char data;
	bstnode *lchild;
	bstnode *rchild;
};
void create(bstnode *l,char  b[],char a[]);
int isleft(char b[],char a[],int i);
void print(bstnode *m);
int main()
{
	char a[20],b[20];
cout<<"enter the inorder expression\n";
cin>>a;
cout<<"enter the preorder expression\n";
cin>> b;
bstnode *l,*s,*t;	
	l=new(bstnode);
	l->data=b[0];
	l->lchild=NULL;
	l->rchild=NULL;
	s=l;
    create(l,b,a);
    l=s;
    print(l);  
}
void create(bstnode *l,char b[],char a[])
{
static int i=1;
int k;
if(b[i]!='\0')
{
k=isleft(b,a,i);
if(k==0 && l->lchild==NULL)
{
	      	bstnode *t;
			t=new(bstnode);
			t->data=b[i];
			t->lchild=NULL;
			t->rchild=NULL;
			l->lchild=t;
			i++;
	create(l->lchild,b,a);
}
if(k==1 && l->rchild==NULL)
{
    	bstnode *t;
			t=new(bstnode);
			t->data=b[i];
			t->lchild=NULL;
			t->rchild=NULL;
			l->rchild=t;
			i++;
	create(l->rchild,b,a);
}	
}}
int isleft(char b[],char a[],int i)
{
    int z=1;
    int k,m;
    if(z==1)
    {
	for(int j=0;a[j]!='\0';j++)
	{
	if(b[i]==a[j])	
	{
	k=j;	
	}
	if(b[i-1]==a[j])
	{
		m=j;
	}
    }
    z++;
	if(k<m)
	return(0);
	else if(k>m)
	return(1);
	}
	else
    {

	}	
}
void print(bstnode *t)
{
if(t!=NULL)
{

	print(t->lchild);
	    cout<<t->data;
	print(t->rchild);
		
}
}
