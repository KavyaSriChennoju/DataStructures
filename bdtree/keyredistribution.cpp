#include<iostream>
using namespace std;
struct btnode;
void create(btnode *&t,int c,int d);
struct btnode
{
	btnode *parent;
	int key[5];
	btnode *child[6];
	int count;
};
bool isleaf(btnode *t);
bool isleaf(btnode *t)
{
		int d=0;
	for(int i=0;i<t->count+1;i++)
	{
		if(t->child[i]==NULL)
		d++;
		else
		break;
	}
	if(d==t->count+1)
	return true;
	else
	return false;
}
int max(int a[],int b);
int max (int a[],int b)
{
	for(int i=0;i<b-1;i++)
	for(int j=i+1;j<b;j++)
	if(a[j]>a[i])
	{
		int y=a[j];a[j]=a[i];a[i]=y;
	}
	return a[0];
}
int  height(btnode *a4);
int height(btnode *a4)
{
	if(!isleaf(a4))
	{
		int a[5];
		for(int i=0;i<a4->count+1;i++)
		a[i]=height(a4->child[i]) ;
		return (1+(max(a,a4->count+1)));	
	}
	else
	return (-1);
}
btnode *root;
btnode* leaf(btnode *t,int c);
btnode* leaf(btnode *t,int c)
{
	int d=0,r=0;
	if(c>t->key[t->count-1]&&t->child[t->count]==NULL)
	return t;
	for(int i=0;i<t->count+1;i++)
	{
		if(t->child[i]==NULL)
		d++;
		else
		break;
	}
	if(d==t->count+1)
	return (t);
	else
	{
		if(c>t->key[t->count-1])
		return leaf(t->child[t->count],c);
	    for(int i=0;i<t->count;i++)
	    {
	    	if(c<t->key[i])
	    	break;
	    	r++;
	    }
	    return leaf(t->child[r],c);
   }
}
btnode* node();
btnode* node()
{
	btnode *l;
	l=new(btnode);
	for(int i=0;i<5;i++)
	{
		l->child[i]=NULL;
		l->key[i]=-1;
	}
	l->child[6]=NULL;
	l->parent=NULL;l->count=0;
	return l;
}
void onlykey(btnode *&m);
void onlykey(btnode *&m)
{
	 btnode *p,*n;
	 p=m;int a2=0;
     n=node();
     if(m->parent!=NULL)
     {
     	int r1=0;
     	for(int i=0;i<m->parent->count+1;i++)
     	{
     		if(m->parent->child[i]==m)
     		break;
     		r1++;
     	}
     	if(m->parent->child[m->parent->count]!=m)
     	{
     	    for(int i=m->parent->child[r1+1]->count;i>0;i++)
     	    {
     	    	m->parent->child[r1+1]->key[i]=	m->parent->child[r1+1]->key[i-1];
     	    	m->parent->child[r1+1]->child[i+1]=m->parent->child[r1+1]->child[i];
     	    }
     	    	m->parent->child[r1+1]->child[1]=m->parent->child[r1+1]->child[0];
     	    	m->parent->child[r1+1]->key[0]=m->parent->key[r1];
     	    	m->parent->child[r1+1]->count++;
     	    	m->parent->child[r1+1]->child[0]=m->child[5];
     	    	m->count=4;
     	    	if(m->parent->child[r1+1]->count>4)
     	        onlykey(m->parent->child[r1+1]);	
     	}
     	else
     	{
     		m->parent->key[m->parent->count]=m->key[4];
     		m->parent->child[m->parent->count+1]=m->child[5];
     		m->count=4;m->parent->count++;
     		if(m->parent->count>4)
     		onlykey(m->parent);
     	}
     }
    else
     {
     for(int i=0;i<2;i++)
     {
     n->key[i]=p->key[3+i];
     n->child[i+1]=p->child[4+i];
     }
     n->child[0]=p->child[3];
     n->count=2;
     for(int i=0;i<3;i++)
     {
     	if(n->child[i]!=NULL)
		 n->child[i]->parent=n;
     }
      m=p;
      m->count=2;
      for(int i=0;i<3;i++)
      m->child[3+i]=NULL;
     	btnode *d1=node();
     	d1->key[0]=p->key[2];
     	d1->child[0]=m;
     	d1->child[1]=n;
     	n->parent=d1;
     	m->parent=d1;
     	d1->count=1;
     	root=d1;
      }
}
void create(btnode *&t,int c,int d);
void create(btnode *&t,int c,int d)
{
	static int k=0;
	btnode *l,*m,*n;
	if(k==0)
	{
		t=node();
		t->key[0]=c;
		k++;t->count=1;root=t;
	}
	else
	{
			m=leaf(root,c);
		int k1=0;
		if(!isleaf(m))
		{
			m->child[m->count]=node();
			m->child[m->count]->key[0]=c;
			m->child[m->count]->count=1;
			m->child[m->count]->parent=m;
		}
		else
		{
		for(int i=0;i<m->count;i++)
		{
			if(c<m->key[i])
			break;
			k1++;
		}
		for(int j=m->count;j>k1;j--)
		{
		m->key[j]=m->key[j-1];
		m->child[j+1]=m->child[j];
	    }
	    m->child[k1+1]=NULL;
		m->key[k1]=c;
		(m->count)++;
		if(m->count>4)
		onlykey(m);}
	}
}
void print(btnode *l);
void print(btnode *l)
{
	if(l!=NULL)
	{
		for(int i=0;i<l->count;i++)
		{
			print(l->child[i]);
			cout<<l->key[i]<<" ";
		}
		print(l->child[l->count]);
	}
}
void level(btnode *t,int a);
void level(btnode *t,int a)
{
 if(t!=NULL)
 {
 if(a==0)
 {
 for(int i=0;i<t->count;i++)
 cout<<t->key[i]<<" ";
 for(int i=t->count;i<4;i++)
 cout<<"  ";}
 else if(a>0)
 {
 	for(int i=0;i<t->count;i++)
 	{
 		level(t->child[i],a-1);
 		cout<<" ";
 	}
  level(t->child[t->count],a-1);
 }}
}
void order(btnode *t);
void order(btnode *t)
{
 int a=height(t)+2;
 for(int i=0;i<a;i++)
 {for(int j=0;j<4*(a-i);j++)
  cout<<" ";
  level(t,i);cout<<endl;
 }
}   
int main()
{
	btnode *l=NULL;int a;
	int b=0;
	cout<<"enter the starting no\n";
	cin>>a;
	while(a!=-1)
	{
		b=0;
		create(l,a,b);l=root;
		cout<<"enter the next no\n";
		cin>>a;
	}
	print(root);
	cout<<endl;
	order(root);
	return 0;
}
