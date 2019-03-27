# include<iostream>
using namespace std;
void create(int  a[],int &i);
void swap(int &a,int& b);
int main()
{
	int a[20];int n;int i=0;
	cout<<"enter a number\n";
	cin>>n;
	a[0]=n;
	i++;
	create(a,i);
	n=i;
	for(i=0;i<n;i++)
	{
	cout<<a[i]<<"  ";}	
}
void create(int a[],int &i)
{
int n=1;
	cout<<"enter the next no\n";
	cin>>n;
	a[i]=n;
	int k=i;
	if(n!=-1)
	{
     if(n>a[(i-1)/2])
     a[i]=n;
     else
     {
	 while((a[i]<a[(i-1)/2]))
     {
     	if(a[i]<a[(i-1)/2])
     	{swap(a[i],a[(i-1)/2]);
     	i=(i-1)/2;}
     	/*else if(a[i]<a[(i-2)/2])
     	{
     	swap(a[i],a[(i-2)/2]);
     	i=(i-2)/2;}*/
     }
     }
     i=k;
     i++;
     create(a,i);}
}
void swap(int &a,int& b)
{
	int t;
	t=a;
	a=b;
	b=t;	
}

