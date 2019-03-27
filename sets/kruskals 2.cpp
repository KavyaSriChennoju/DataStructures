#include<iostream>
using namespace std;
int s[15],b[10];int i5=0;
int find(int x)
{
	if(s[x]!=0)
	{int a=find(s[x]);}
	else
	return(x);
}
void ubyh(int a,int b)
{
	if(s[a]==0 || (s[b]<s[a]) )
	{
		s[a]=b;
		s[b]--;
	}
	else if(s[a]<=s[b] || (s[a]<0 && s[b]==0))
	{
		s[b]=a;
		s[a]--;
	}
}
struct graph
{
	int data;
	int in;
};
struct store
{
	int a1,b1, c1;
};
store st[15];
void sort(store st[],int n1)
{
	for(int i=0;i<n1-1;i++)
	{
		for(int j=i;j<n1;j++)
		{
			if(st[i].c1>st[j].c1)
			{
				store t=st[i];
				st[i]=st[j];
				st[j]=t;
			}
		}
	}
}
int main()
{
	int a,b;int c,d,i1=0;int v=0;char e;
	cout<<"enter the no of vertices\n";
	cin>>a;
	const int size=a;
	graph **arr;
	arr=new graph*[size];
	for(int i=0;i<size;i++)
	arr[i]=new graph[size];
	for(int i=0;i<size;i++)
	{
		cout<<"enter the vertex "<<i+1<<endl;
		cin>>c;
		v++;
		arr[i][0].data=c;
	}
	for(int j=1;j<size;j++)
    arr[0][j].data=arr[j][0].data;
    for(int i=1;i<size;i++)
    for(int j=1;j<size;j++)
    arr[i][j].data=arr[i-1][j].data;
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
    cout<<arr[i][j].data<<" ";
    cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
    arr[i][j].in=0;
    do
    {
    	cout<<"enter the edge vertices\n";
    	cin>>c>>d;
    	st[i1].a1=c;st[i1].b1=d;
    	cout<<"enter the edge weight\n";
    	cin>>b;
    	st[i1++].c1=b;
    	int h,k;
    	for(h=0;h<size;h++)
    	if(arr[h][0].data==c)
    	break;
    	for(k=0;k<size;k++)
    	if(arr[k][0].data==d)
    	break;
    	arr[h][k].in=b;
    	arr[k][h].in=b;
    	cout<<"do u want to continue\n";
    	cin>>e;
    }while(e=='y');
    int n1=i1;
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
    cout<<arr[i][j].in<<" ";
    cout<<endl;
    }
    cout<<endl;
    sort(st,n1);
	int i2=0,sum=0, i9=0;
    while(i2<v-1)
    {  int x=st[i9].a1;
       int y=st[i9].b1;
       int k1=find(x);int k2=find(y);
        if(k1!=k2 )
        {   i2++;
        	cout<<x<<"  "<<y<<"\n";
            sum=sum+st[i9].c1;
            ubyh(x,y); } i9++;}
    cout<<"length is\n"<<sum;  }
