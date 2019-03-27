#include<iostream>
using namespace std;int s[10];int a;int b[10];int i1=0;
int find(int x)
{
	if(s[x]!=0)
	{a=find(s[x]);}
	else
	return(x);
}
int findandcompress(int x)
{
	if(s[x]!=0)
	{
	b[i1++]=s[x];
	a=findandcompress(s[x]);
	}
	else
	{ 
	    int n=i1;
		for(int i1=0;i1<n;i1++)
		s[b[i1]]=x;
		i1=0;
		return(x);
	}	
}
void union1 (int x,int y)
{
	if(s[y]==0)
	s[y]=x;
	else
	{ if(s[x]==0)
	union1(x,s[y]);
    else
    union1(find(x),s[y]);
	}	
}
void unionbyheight(int x,int y)
{
	 if(s[x]==s[y])
	{	s[y]=x;
	 --s[x];	}
	 else
	 {
	if(s[x]==0)
	s[x]=s[y];
	if(s[y]==0)
    s[y]=s[x];
	if(s[x]<0 && s[y]<0)
	{
	if(s[x]>s[y])
	s[x]=y;
	else if(s[x]>s[y])
	s[y]=x;
	}
	if(s[x]<0 &&s[y]>0) 
	{
		y=find(s[y]);
		unionbyheight(x,y);
	}
		if(s[x]>0 &&s[y]<0) 
	{
		x=find(s[x]);
		unionbyheight(x,y);
	}}
	
}
int main()
{
	int x,y;
	for(int i=0;i<10;i++)
	s[i]=0;
	do{
		cout<<"enter two no's which are in same set to stop -1\n";
		cin>>x>>y;
		if(x!=-1)
		{
		//	union1(x,y);
		  unionbyheight(x,y);
		}
     }while(x!=-1);
     	for(int i=0;i<10;i++)
	cout<<s[i];
	cout<<"enter a no to find \n";
	cin>>x;
/*int k1=find(x);
cout<<k1;
  	for(int i=0;i<10;i++)
	cout<<s[i];*/cout<<"\n";
int k2=findandcompress(x);
cout<<k2<<"\n";
s[x]=k2;
if(s[k2]==k2)
s[k2]=0;
  	for(int i=0;i<10;i++)
	cout<<s[i];

}
