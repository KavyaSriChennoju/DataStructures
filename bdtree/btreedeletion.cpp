#include<iostream>
using namespace std;
struct bdtree;
void create(bdtree *&t,int c,int d);
struct bdtree
{
	bdtree *parent;
	int key[5];
	bdtree *child[6];
	int count;
};
bool isleaf(bdtree *t);
bool isleaf(bdtree *t)
{
		for(int i=0;i<t->count+1;i++)
		if(t->child[i]!=NULL)
		return false;
	    return true;
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
int  height(bdtree *a4);
int height(bdtree *a4)
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
bdtree *root;
bdtree* leaf(bdtree *t,int c);
bdtree* leaf(bdtree *t,int c)
{
	int d=0,r=0;
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
bdtree* node();
bdtree* node()
{
	bdtree *l;
	l=new(bdtree);
	for(int i=0;i<5;i++)
	{
		l->child[i]=NULL;
		l->key[i]=-1;
	}
	l->child[6]=NULL;
	l->parent=NULL;l->count=0;
	return l;
}
int maxi(bdtree *l);
int maxi(bdtree *l)
{
	if(isleaf(l))
	return(l->key[l->count-1]);
	else
	return maxi(l->child[l->count]);
}
void nodesplit(bdtree *&m);
void nodesplit(bdtree *&m)
{
	 bdtree *p,*n;
	 p=m;
     n=node();
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
     if(p->parent==NULL)
     {
     	bdtree *d1=node();
     	d1->key[0]=p->key[2];
     	d1->child[0]=m;
     	d1->child[1]=n;
     	n->parent=d1;
     	m->parent=d1;
     	d1->count=1;
     	root=d1;
     }
     else
     {
        n->parent=m->parent;
	    int a1=0;
	    for(int i=0;i<m->parent->count;i++)
	    {
	 	if(m->parent->key[i]>p->key[2])
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
		m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
		m->parent->key[a1]=p->key[2];
		(m->parent->count)++;
		if(m->parent->count>4)
		nodesplit(m->parent);	
     }
}
void create(bdtree *&t,int c,int d);
void create(bdtree *&t,int c,int d)
{
	static int k=0;
	bdtree *l,*m,*n;
	if(k==0)
	{
		t=node();
		t->key[0]=c;
		k++;t->count=1;root=t;
	}
	else
	{
			m=leaf(root,c);int k1=0;
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
		nodesplit(m);
	}
}
bdtree* search(bdtree *t,int g);
bdtree* search(bdtree *t,int g)
{
	for(int i=0;i<t->count;i++)
	{
		if(g<t->key[i])
		return (search(t->child[i],g));
		else if(g==t->key[i])
		return (t);
		else if(i==t->count-1&&t->key[i]<g)
		return search(t->child[i+1],g);
	}
}
void dlte(bdtree *&l,int a);
void dlte(bdtree *&l,int a)
{
	if(isleaf(l))
	{
		if(l->count>2)
		{
		  int b=0;
		  for(int i=0;i<l->count;i++)
		  {
			 if(l->key[i]==a)
			 break;
			 b++;
		  }
		  for(int i=b;i<l->count-1;i++)
		  l->key[i]=l->key[i+1];
		  l->count--;
		  l->key[l->count]=-1;
	    } 
	    else
	    {
	    	int b=0;
		   for(int i=0;i<l->count;i++)
		   {
			 if(l->key[i]==a)
			 break;
			 b++;
		   }
		   for(int i=b;i<l->count-1;i++)
		   l->key[i]=l->key[i+1];
		   l->count--;
		   l->key[l->count]=-1;
		   if(l->parent!=NULL)
           {
     	     int r1=0;
     	     for(int i=0;i<l->parent->count+1;i++)
     	     {
     		    if(l->parent->child[i]==l)
     		    break;
     		    r1++;
     	     }
     	     if(r1!=0&&l->parent->child[r1-1]->count>2)
     	     {
     	        l->key[1]=l->key[0];
     	        l->key[0]=l->parent->key[r1-1];
     	        l->count++;
     	        l->parent->key[r1-1]=l->parent->child[r1-1]->key[l->parent->child[r1-1]->count-1];
     	        l->parent->child[r1-1]->count--;
     	     }
     	     else if(r1!=l->parent->count&&l->parent->child[r1+1]->count>2)
     	     {
     	     	l->key[1]=l->parent->key[r1];
     	     	l->count++;
     	     	l->parent->key[r1]=l->parent->child[r1+1]->key[0];
     	     	for(int i=0;i<l->parent->child[r1+1]->count-1;i++)
     	     	l->parent->child[r1+1]->key[i]=	l->parent->child[r1+1]->key[i+1];
     	     	l->parent->child[r1+1]->count--;
     	     }
     	     else
     	     {
     	     	if(r1!=l->parent->count)
     	     	{
     	     		l->key[1]=l->parent->key[r1];
     	     		l->count++;
     	     		for(int i=0;i<l->parent->child[r1+1]->count;i++)
     	     		{
     	     			l->key[2+i]=l->parent->child[r1+1]->key[i];
     	     			l->count++;
     	     		}
     	     		for(int i=r1;i<l->parent->count-1;i++)
     	     		{
     	     			l->parent->key[i]=l->parent->key[i+1];
     	     			l->parent->child[i+1]=l->parent->child[i+2];
     	     		}
     	     		l->parent->count--;
     	     	}
     	     	else
     	     	{
     	     		l->parent->child[r1-1]->key[l->parent->child[r1-1]->count]=l->parent->key[r1-1];
     	     		l->parent->child[r1-1]->count++;
     	     		for(int i=0;i<l->count;i++)
     	     		{
     	     			l->parent->child[r1-1]->key[l->parent->child[r1-1]->count]=l->key[i];
     	     			l->parent->child[r1-1]->count++;
     	     		}
     	     		l->parent->count--;
     	     	}
     	     }
           }  	
	    }
	}
	else
	{
		int b=0;
		for(int i=0;i<l->count;i++)
		{
			if(l->key[i]==a)
			break;
			b++;
		}
		int c=maxi(l->child[b]);
		bdtree *p=search(root,c);
	l->key[b]=c;	dlte(p,c);
	}
}
void level(bdtree *t,int l);
void level(bdtree* t, int l)
{
 if(t == NULL)
 return;
 if(l==1)
 for(int i=0;i<t->count;i++)
 cout<<t->key[i]<<" ";
 else if (l > 1)
 {
for(int i=0;i<5;i++)
  level(t->child[i], l-1);
  cout<<" ";
 }
}
void print(bdtree *t);
void print(bdtree* t)
{
 int h = height(t)+2;
 int i;
 for(i=1;i<=h;i++)
 {
  level(t, i);
  cout<<endl;
 }
}   
int main()
{
	bdtree *l=NULL;int a;
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
	cout<<endl;
	print(root);cout<<endl;
	while(1)
	{
	cout<<"enter the no to be deleted\n";
	cin>>a;if(a==0)break;
	if(root->count==1&&root->child[0]->count==2&&root->child[1]->count==2)
	{
		if(a==root->key[0])
		{
			root->child[0]->count=4;
			root->child[0]->key[2]=root->child[1]->key[0];
			root->child[0]->key[3]=root->child[1]->key[1];
			root=root->child[0];
			root->parent=NULL;
		}
		else if(a==root->child[0]->key[0]||a==root->child[0]->key[0])
		{
			root->child[0]->count=4;
			root->child[0]->key[2]=root->key[0];
			root->child[0]->key[3]=root->child[1]->key[0];
			root->child[0]->key[4]=root->child[1]->key[1];
			int r3=0;
			for(int i=0;i<2;i++)
			{
				if(	root->child[0]->key[i]==a)
				break;
				r3++;
			}
			for(int i=0;i<4-r3;i++)
			root->child[0]->key[r3+i]=root->child[0]->key[r3+i+1];
		    root=root->child[0];
		    root->parent=NULL;
		}
		else
		{
			for(int i=0;i<2;i++)
			root->child[1]->key[3+i]=root->child[1]->key[i];
			root->child[1]->key[2]=root->key[0];
			root->child[1]->key[0]=root->child[0]->key[0];
			root->child[1]->key[1]=root->child[0]->key[1];
			 root=root->child[0];
			 root->parent=NULL;
			 root->count=4;
			 if(root->key[3]==a)
			 root->key[3]=root->key[4];
	    }
	    for(int i=0;i<root->count;i++)
		cout<<root->key[i];cout<<endl;}
		else if(isleaf(root))
		{
			for(int i=0;i<root->count;i++)
			{
				if(root->key[i]==a)
				{
					for(int j=i;j<root->count-i;j++)
					root->key[j]=root->key[j+1];
					break;
				}
			}
			root->count--;
			for(int i=0;i<root->count;i++)
			cout<<root->key[i];cout<<endl;
		}
        else
	    {
	      l=search(root,a);
          dlte(l,a);
	      print(root);
		  cout<<endl;
		}
	}
	cout<<endl;
	return 0;
}
