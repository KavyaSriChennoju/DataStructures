#include<iostream>
using namespace std;
int d;
struct bptnode
{
	int count;
	int *key;
	bptnode **child;

};
int set(bptnode* parent,bptnode* t,bptnode* &new_node,int &x);
void create_newnode(bptnode* &t)
{
	t=new bptnode;
	t->count=0;
	t->key=new int[2*d];
	t->child=new bptnode*[2*d+1];
	for(int i=0;i<2*d+1;i++)
	t->child[i]=NULL;
}
int check_leaf(bptnode* t)
{
	int flag=0;
	for(int i=0;i<2*d+1;i++)
	if(t->child[i]!=NULL) flag=1;
	if(flag==0) return 1;
	else return (0);
}
void insert(bptnode* parent,bptnode* &t,int x)
{
	bptnode* new_node=NULL;
	int flag=set(parent,t,new_node,x);
	if(flag)
	{
		bptnode* root=NULL;
		create_newnode(root);
		root->key[0]=x;
		root->child[0]=t;
		root->child[1]=new_node;
		(root->count)++;
		t=root;
	}
}
void rightshift(bptnode* t,int pos)
{
	int i;
	for(i=t->count-1;i>=pos;i--)
	{
		t->key[i+1]=t->key[i];
		t->child[i+2]=t->child[i+1];
	}
}
void add(bptnode* t,bptnode* new_node,int pos,int x)
{
	rightshift(t,pos);
	t->key[pos]=x;
	(t->count)++;
	t->child[pos+1]=new_node;
}
void nodesplit(bptnode* t,bptnode* &new_node,int pos,int &x)
{
	int i;
	bptnode* temp=NULL;
	create_newnode(temp);
	if(pos<=d)
	{
		for(i=d;i<2*d;i++)
		{
			temp->key[i-d]=t->key[i];
			temp->child[i-d+1]=t->child[i+1];
			t->count--;temp->count++;
		}
		temp->child[0]=t->child[d];
		t->child[d]=NULL;
		add(t,new_node,pos,x);
	}
	else
	{
		for(i=d+1;i<2*d;i++)
		{
			temp->key[i-(d+1)]=t->key[i];
			temp->child[i-d]=t->child[i+1];
			t->count--;temp->count++;
		}
		temp->child[0]=t->child[d+1];
		t->child[d+1]=NULL;
		add(temp,new_node,pos-(d+1),x);
	}
	x=t->key[d];
	//if(!check_leaf(t))
	t->count--;
	new_node=temp;
}
int set(bptnode* parent,bptnode* t,bptnode* &new_node,int &x)
{
	int pos;
	if(t==NULL) return (1);
	for(pos=0;pos<t->count;pos++)
	{
		if(x<t->key[pos]) break;
	}
	if(check_leaf(t))
	{
		if(t->count<2*d)
		{
			add(t,new_node,pos,x);
			return (0);
		}
		else
		{
			nodesplit(t,new_node,pos,x);
			return (1);
		}
	}
	else
	{
		int flag=set(t,t->child[pos],new_node,x);
		if(flag)
		{
			if(t->count<2*d)
			{
				add(t,new_node,pos,x);
				return (0);
			}
			else
			{
				nodesplit(t,new_node,pos,x);
				return (1);
			}
		}
	}
}
void print(bptnode* &l)
{
	if(l==NULL) return;
	else
	{
	for(int i=0;i<2*d;i++)
	{
	   if(i<l->count)
		cout<<l->key[i]<<" ";}
		cout<<"\n";
		for(int j=0;j<((2*d)+1);j++)
       {
		print(l->child[j]);}}
}
int main()
{
	bptnode* root=NULL;
	int i;
	cout<<"enter d\n";
	cin>>d;
	cout<<"enter data at last -1\n";
	while(cin>>i)
	{
		if(i==-1) break;
		else insert(NULL,root,i);
	}
	print(root);
	return (0);
}
