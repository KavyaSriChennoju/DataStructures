#include <iostream>
using namespace std;
int l=0, x=0;
struct node
{
    int data;
    node *lchild;
    node *rchild;
};
void create(node *&t)
{
    if(t==NULL)
    {
        t=new node;
        t->data=-1;
        t->lchild=NULL;
        t->rchild=NULL;
    }
}
void leaf(node *t,int k)
{
	if(t!=NULL)
	{
		if(k==1)
        { l++;
        }   
		else if(k!=0)
		{
			leaf(t->lchild,k-1);
			leaf(t->rchild,k-1);
		}
	}
}
int height(node *t)
{
    if(t==NULL)
    return -1;
    else
    {
        int a=height(t->lchild);
        int b=height(t->rchild);
        if(a>b)
            return a+1;
        else
            return b+1;
    }

}
void print(node *t,int k)
{
	if(t!=NULL)
	{
		if(k==1)
			cout<<t->data<<" ";
		else if(k!=0)
		{
			print(t->lchild,k-1);
			print(t->rchild,k-1);
		}
	}
}
void insert(node *&t,int b[],int a)
{
    if(t!=NULL)
    {
        if(t->lchild==NULL&&t->rchild==NULL&&t->data==-1)
        {
            if(x<a)
            t->data=b[x++];
        }
        insert(t->lchild,b,a);
        insert(t->rchild,b,a);
    }
}
void sort(node *&t)
{
    if(t->lchild!=NULL)
    {
        sort(t->lchild);
        sort(t->rchild);
        if(t->lchild->data>t->rchild->data)
        t->data=t->lchild->data;
        else
        t->data=t->rchild->data;
    }
}
void replace(node *&t,int a)
{
    if(t!=NULL)
    {
        if(t->data==a)
            t->data=-1;
            replace(t->lchild,a);
            replace(t->rchild,a);
    }
}
int main()
{
    int a,y=0;
    node *p,*t,*s;node *q[20];int r=0,f=0;
    p=t=new node;s=new node;s->data=0;
    for(int i=0;i<20;i++)
	q[i]=new node;
    t->data=-1;t->lchild=NULL;t->rchild=NULL;p=t;q[r++]=t;q[r++]=s;
    cout<<"\nenter the no.of elements"<<endl;
    cin>>a;
    int b[a];
    while(a>l-1)
    {
        t=q[f++];
        if(t->data!=0)
        {
            create(t->lchild);
            q[r++]=t->lchild;
            create(t->rchild);
            q[r++]=t->rchild;
        }
        else
        {
            q[r++]=s;
            t=p;
            int h=height(t); l=0;
            leaf(t,h+1);l++;
        }
    }
    t=p;
        cout<<"\nenter the numbers\n";
        for(int i=0;i<a;i++)
        cin>>b[i];
        insert(t,b,a);
        int h=height(t);
        cout<<"\ntree is :\n";
        for(int i=1;i<=h+1;i++)
        {
            print(t,i);cout<<endl;
        }
        cout<<"\nsorted order is\n";
        while(y<a)
        {
        sort(t);
        cout<<t->data<<" ";
        replace(t,t->data);
        y++;
        }
        return 0;
}
