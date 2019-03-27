# include<iostream>
# include<cstdlib>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *addend(node *l,int k);
	int delbegin( node *&l);
int main()
{
	int b[15],c[15],d[15],r[15],n,f,i,j,m=0,t=0;
    node *a[10],*e[10];
for( i=0;i<10;i++)
{
	a[i]=new(node);
	a[i]=NULL;
	e[i]=a[i];
}
cout<<"enter no of numbers\n";
cin>>n;
cout<<"enter 1st number\n";
cin>>b[0];
f=b[0];
for(i=1;i<n;i++)
{cout<<"enter number   "<<i+1<<"\n";
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
  		a[0]=addend(a[0],c[j]);
  	}
  	else if(d[j]==1)
  	{a[1]=addend(a[1],c[j]);
  	
  	}
    	else if(d[j]==2)
  	{
  	a[2]=addend(a[2],c[j]);
  	}
  	else 	if(d[j]==3)
  	{
  	a[3]=addend(a[3],c[j]);
  	}
  	else 	if(d[j]==4)
  	{
  		a[4]=addend(a[4],c[j]);
  	}
  	else 	if(d[j]==5)
  	{
  	a[5]=addend(a[5],c[j]);
  	}
  		else if(d[j]==6)
  	{
  	a[6]=addend(a[6],c[j]);
  	}
  		else if(d[j]==7)
  	{
  	a[7]=addend(a[7],c[j]);;
  	
  	}
  	else if(d[j]==8)
  	{
  	a[8]=addend(a[8],c[j]);
  	}
  	else if(d[j]==9)
  	{
  	a[9]=addend(a[9],c[j]);
  	}
  }	
  t=0;
  for(int x=0;x<10;x++)
  {
  a[x]=e[x];
  }
  for(int z=0;z<10;z++)
  {
  	while(a[z]!=NULL)
  	{
  		r[t++]=delbegin(a[z]);
		  }
  		

  }
 for(int x=0;x<10;x++)
  {
  a[x]=e[x];
  }
  }
  	cout<<"sorted list is\n";
for(i=0;i<n;i++)
{
	cout<<r[i]<<" ";
}
}
node *addend(node *l,int k)
		{node*t;
		t=l;if(l==NULL)
		{
			l=new(node);
			l->data=k;
			l->next=NULL;
			l=t;
			return(l);
		}
		else
		{
	
			while(l->next!=NULL)
			{
				l=l->next;
			}
			l->next=new(node);
			l->next->data=k;
			l->next->next=NULL;
			l=t;
			return(l);}
		}
		int delbegin( node *&l)
 {int k;
 
 k=l->data;
 node *t;
t=new(node);
 t=l;
 l=l->next;
 free(t);
 return(k);
 }
