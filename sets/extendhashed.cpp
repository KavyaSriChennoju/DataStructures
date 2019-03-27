#include<iostream>
#include<fstream>
using namespace std;
int d=0;
struct bckt    
{
	int d1,count;    
	int recrds[5];
	bckt()
	{
		d1=0;count=0;
	}
};
void del(int k,bckt **&drctry,int rno,int *bnry,int key);
void getbin(int *bnry,int rno)
{
	for(int i=0;i<8;i++)
	bnry[i]=0;
	int c=7;
	while(rno>0)
	{
		bnry[c--]=rno%2;
		rno=rno/2;
	}
}
void check(bckt **&drctry,int *bnry,int rno,int key,int limit);
int pwr(int a)
{
	int k=1;
	for(int i=0;i<a;i++)
	k=k*2;
	return k;
}
int getdec(int *bnry,int a)
{
	int c=0;
	for(int i=a;i>0;i--)
  	{
		c=c+bnry[i-1]*pwr(a-i);
	}
	return c;
}
void create(int k,bckt **&drctry,int rno,int *bnry,int key,int limit)
{
	if(drctry[k]->count<5)
	drctry[k]->recrds[drctry[k]->count++]=key;
	else if(drctry[k]->d1<d)
	{
	   bckt *p1=new(bckt),*p2=new(bckt);
	   int *e=new int[8];
	   	   for(int i=0;i<5;i++)
	   	   {
	   	      getbin(e,drctry[k]->recrds[i]%limit);
	   	      if(e[drctry[k]->d1]==0)
	   	      p1->recrds[p1->count++]=drctry[k]->recrds[i];
	   	      else
	   	      p2->recrds[p2->count++]=drctry[k]->recrds[i];
	   	   }
	   	   p1->d1=drctry[k]->d1+1;p2->d1=drctry[k]->d1+1;
		   bckt *s=drctry[k];
	   	   if(k%2==0)
	   	   {
	   	   drctry[k]=p1;drctry[k+1]=p2;
	       }
	   	   else
	   	   {
	   	   drctry[k-1]=p1;drctry[k]=p2;
	       }
		   delete s;
	   	   check(drctry,bnry,rno,key,limit);
	   }
	   else
	   {
	   	 d++;
	   	 bckt **ndrctry=new bckt*[pwr(d)];
		 for(int i=0;i<pwr(d);i++)
		 ndrctry[i]=new(bckt);
		 for(int i=0;i<pwr(d-1);i++)
		 {
		 	ndrctry[2*i]=drctry[i];
		 	ndrctry[2*i+1]=drctry[i];
		 }
		 drctry=ndrctry;
		 check(drctry,bnry,rno,key,limit);	  
	   }	
}
void contract(bckt **&drctry)
{
	int p;
	for(p=0;p<d;p++)
	if(drctry[2*p]!=drctry[2*p+1])
	break;
	if(p==d)
	{
		d--;
		bckt **ndrctry=new bckt*[pwr(d)];
		for(int i=0;i<pwr(d);i++)
		ndrctry[i]=new(bckt);
		for(int i=0;i<pwr(d);i++)
		ndrctry[i]=drctry[2*i];
		bckt **s=drctry;
		drctry=ndrctry;
		for(int i=0;i<pwr(d+1);i++)
		delete(s[i]);delete s;
	}
}
void del(int k,bckt **&drctry,int rno,int *bnry,int key)
{
	int p;
	for(p=0;p<drctry[k]->count;p++)
	{
		if(drctry[k]->recrds[p]==key)
		break;
	}
	for(int i=p;i<drctry[k]->count-1;i++)  
	{
		drctry[k]->recrds[i]=drctry[k]->recrds[i+1];
	}
	drctry[k]->count--;
	if(k%2==0&&(drctry[k]->count+drctry[k+1]->count)<=5&&d!=0)
	{
		for(int i=0;i<drctry[k+1]->count;i++)					
		drctry[k]->recrds[drctry[k]->count++]=drctry[k+1]->recrds[i];
		drctry[k]->d1--;
		bckt *s=drctry[k+1];drctry[k+1]=drctry[k];
		delete s;
	}
	if(k%2==1&&(drctry[k]->count+drctry[k-1]->count)<=5&&d!=0)
	{
		for(int i=0;i<drctry[k]->count;i++)
		drctry[k-1]->recrds[drctry[k-1]->count++]=drctry[k]->recrds[i];
		drctry[k-1]->d1--;
		bckt *s=drctry[k];drctry[k]=drctry[k-1];
		delete s;
	}
	contract(drctry);
}
void check(bckt **&drctry,int *bnry,int rno,int key,int limit)
{
	int k=getdec(bnry,d);
	create(k,drctry,rno,bnry,key,limit);
}
void take(bckt **&drctry,int *bnry,int rno,int key)
{
	int k=getdec(bnry,d);
	del(k,drctry,rno,bnry,key);
}
int main()
{
	int a,key,rno,*bnry,k;char ch;
	bnry=new int[8];
	cout<<"enter the limit\n";
	cin>>a;
	cout<<"enter the key\n";
	cin>>key;
	bckt **drctry=new bckt*[pwr(d)];
	for(int i=0;i<pwr(d);i++)
	drctry[i]=new(bckt);
	do
	{
		rno=key%a;
		getbin(bnry,rno);
		check(drctry,bnry,rno,key,a);	
		cout<<"enter the key\n";
		cin>>key;
	}while(key!=-1);
	cout<<"enter the record key to be deleted\n";
	cin>>key;
	do
	{
	  rno=key%a;
	  getbin(bnry,rno);
	  take(drctry,bnry,rno,key);
	  cout<<"enter the record key to be deleted\n";
	  cin>>key;	
	}while(key!=-1);
	return 0;
}
