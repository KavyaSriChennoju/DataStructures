`#include<iostream>
using namespace std;
const int d1=2;
struct bdtree
{
	bdtree *parent;
	int key[2*d1+1];
	bdtree *child[2*d1+2];
	int count;
};
bdtree *root;
void create(bdtree *&t,int c,int d);
bool isleaf(bdtree *t);
int max(int a[],int b);
bdtree* leaf(bdtree *t,int c);
int  height(bdtree *a4);
bdtree* newnode();
void nodesplit(bdtree *&m);
void level(bdtree* t, int level);
void print(bdtree* t);
bdtree* search(bdtree *t,int g);
void delete(bdtree *&l,int a);
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
 print(root);
	while(1)
	{
	cout<<"enter the no to be deleted\n";
	cin>>a;
	if(a==0)
	break;
	l=search(root,a);
    delete(l,a);
	print(root);
	cout<<endl; }
return 0;
}
bool isleaf(bdtree *t)
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
void create(bdtree *&t,int c,int d)
{
	static int k=0;
	bdtree *l,*m,*n;
	if(k==0)
	{
		t=newnode();
		t->key[0]=c;
		k++;
		t->count=1;root=t;
	}
	else
	{
		if(d==0)
		{
			d++;
			m=leaf(root,c);
		}
		else
		m=t;int k1=0;
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
		if(m->count>2*d1)
		nodesplit(m);
	}
}

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

int height(bdtree *a4)
{
	if(!isleaf(a4))
	{
		int a[2*d1+1];
		for(int i=0;i<a4->count+1;i++)
		a[i]=height(a4->child[i]) ;
		return (1+(max(a,a4->count+1)));	
	}
	else
	return (-1);
}
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

bdtree* newnode()
{
	bdtree *l;
	l=new(bdtree);
	for(int i=0;i<2*d1+1;i++)
	{
		l->child[i]=NULL;
		l->key[i]=-1;
	}
	l->child[2*d1+2]=NULL;
	l->parent=NULL;l->count=0;
	return l;
}

void nodesplit(bdtree *&m)
{
	 bdtree *p,*n;
	 p=m;
     n=newnode();
     for(int i=0;i<d1;i++)
     {
     n->key[i]=p->key[d1+1+i];
     n->child[i+1]=p->child[d1+2+i];
     }
     n->child[0]=p->child[d1+1];
     n->count=d1;
     for(int i=0;i<d1+1;i++)
     {
     	if(n->child[i]!=NULL)
		 n->child[i]->parent=n;
     }
    m=p;
    m->count=d1;
    for(int i=0;i<d1+1;i++)
    m->child[d1+1+i]=NULL;
     if(p->parent==NULL)
     {
     	bdtree *b1=newnode();
     	b1->key[0]=p->key[d1];
     	b1->child[0]=m;
     	b1->child[1]=n;
     	n->parent=b1;
     	m->parent=b1;
     	b1->count=1;
     	root=b1;
     }
     else
     {
        n->parent=m->parent;
	    int a1=0;
	    for(int i=0;i<m->parent->count;i++)
	    {
	 	if(m->parent->key[i]>p->key[d1])
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
		m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
		m->parent->key[a1]=p->key[d1];
		(m->parent->count)++;
		if(m->parent->count>2*d1)
		nodesplit(m->parent);	
     }
}
void level(bdtree* t, int l)
{
 if(t == NULL)
 return;
 if(l==1)
 for(int i=0;i<t->count;i++)
 cout<<t->key[i]<<" ";
 else if (l > 1)
 {
for(int i=0;i<2*d1+1;i++)
  level(t->child[i], l-1);
  cout<<" ";
 }
}
void print(bdtree* t)
{
 int h = height(t)+2;
 int i;
 for(i=1;i<=h;i++)
 {for(int j=0;j<2*(h-i);j++)
  cout<<" ";
  level(t, i);
  cout<<endl;
 }
}

bdtree* search(bdtree *t,int a)
{
	for(int i=0;i<t->count;i++)
	{
		if(a<t->key[i])
		return (search(t->child[i],a));
		else if(a==t->key[i])
		return (t);
		else if(i==t->count-1&&t->key[i]<a)
		return search(t->child[i+1],a);
	}
}
void delete(bdtree * &l,int a)
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
		btnode *p=search(root,c);
	l->key[b]=c;	delete(p,c);
	}
