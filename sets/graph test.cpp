# include<iostream>
using namespace std;
struct graph
{
  char data;
   int in;
};
int main()
{
	int size,d;char a,b,c;
	cout<<"enter the no of vertices\n";
	cin>>size;
    graph **arr=new graph *[size];
	for(int i=0;i<size;i++)
	arr[i]=new graph[size];
	cout<<"enter the vertices\n";	
	for(int i=0;i<size;i++)
	{
		cin>>a;
		arr[i][0].data=a;
		arr[0][i].data=a;
	}
	for(int i=1;i<size;i++)
    for(int j=1;j<size;j++)
    arr[i][j].data=arr[i-1][j].data;
    for(int i=0;i<size;i++)
	{  for(int j=0;j<size;j++)
	cout<<arr[i][j].data<<"  ";
		cout<<"\n";
	}
	 for(int i=0;i<size;i++)
	{  for(int j=0;j<size;j++)
        arr[i][j].in=0;
    }
    do{
    	int i,j;
    	cout<<"enter the edge vertices\n";
    	cin>>b>>c;
    	cout<<"enter eddge length\n";
    	cin>>d;
    	for( i=0;i<size;i++)
    	if(arr[i][0].data==b)
    	break;
    	for( j=0;j<size;j++)
    	if(arr[j][0].data==c)
    	break;
    	arr[i][j].in=d;	arr[j][i].in=d;
    	cout<<"to continue\n";
    	cin>>a;	
    }while(a=='y');
    for(int i=0;i<size;i++)
	{  for(int j=0;j<size;j++)
	cout<<arr[i][j].in<<"  ";
	cout<<"\n";
    }
}
  
	
	

