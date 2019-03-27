# include<iostream>
# include<cstdlib>
using namespace std;
struct node
{
	int data;
	node *next;
};
void addend(node *&l,int k);
void addend(node *&m,int b)
{
	if(m==NULL)
	{
		node *k;
		k=new(node);
		k->data=b;
		k->next=NULL;
		m=k;
	}
	else
	{
		node *q;q=m;
		while(q->next!=NULL)
		q=q->next;
		node *k;k=new(node);
		k->data=b;
		k->next=NULL;
		q->next=k;
	}
}
int delbegin( node *&l);
int delbegin(node *&t)
{
	int a2;
	node *p;p=t;
    if(t->next==NULL)
	{
	a2=t->data;
	t=NULL;	
	}
	else
	{
	a2=t->data;
	t=t->next;	
	}
	return (a2);
}
int main()
{
	int b[15],c[15],d[15],r[15],n,f,i,j,m=0,t=0;
    node *a[10],*e[10];
for( i=0;i<10;i++)
{
	a[i]=new(node);
	a[i]=NULL;
}
cout<<"enter no of numbers\n";
cin>>n;
cout<<"enter 1st number\n";
cin>>b[0];
f=b[0];
for(i=1;i<n;i++)
{
cout<<"enter number   "<<i+1<<"\n";
cin>>b[i];
if(b[i]>f)
{
	f=b[i];
}
}
while(f!=0)
{
	f=f/10;
	m++;	
}
cout<<"before sorting\n";
for(i=0;i<n;i++)
{
	c[i]=b[i];
	cout<<c[i]<<" ";
}
cout<<"\n";

for(i=0;i<m;i++)
{
  for(j=0;j<n;j++)
  {
  	d[j]=b[j]%10;
  	b[j]=b[j]/10;
  	if(d[j]==0)
  	{
  		addend(a[0],c[j]);
  	}
  	else if(d[j]==1)
  	{addend(a[1],c[j]);
  	}
    	else if(d[j]==2)
  	{
  	addend(a[2],c[j]);
  	}
  	else 	if(d[j]==3)
  	{
  	addend(a[3],c[j]);
  	}
  	else 	if(d[j]==4)
  	{
  		addend(a[4],c[j]);
  	}
  	else 	if(d[j]==5)
  	{
  	addend(a[5],c[j]);
  	}
  		else if(d[j]==6)
  	{
  	addend(a[6],c[j]);
  	}
  		else if(d[j]==7)
  	{
  	addend(a[7],c[j]);
  	
  	}
  	else if(d[j]==8)
  	{
  	addend(a[8],c[j]);
  	}
  	else if(d[j]==9)
  	{
  	addend(a[9],c[j]);
  	}
  }	
  
  for(int z=0;z<10;z++)
  {
  	while(a[z]!=NULL)
  	{
  		r[t++]=delbegin(a[z]);
   }
  }
  t=0;
 }
cout<<"sorted list is\n";
for(i=0;i<n;i++)
{
	cout<<r[i]<<" ";
}
}


