# include<iostream>
using namespace std;
int a[20],low,high,j,p,l,h,cnt;
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int part(int a[20],int low,int high)
{  
    if(low<high)
    {
	p=a[low];
    l=low+1; h=high;
	while(l<h)
	{
	while(a[l]<=p && l<h)
	l++;
	while(a[h]>p && l<=h)
	h--;
	if(l<=h)	
	swap(a[l],a[h]);
    }
	swap(a[low],a[h]);
	return(h);
	}
}
void quicksort(int a[20],int low,int high )
{
	if(low<high)
	{
		j=part(a,low,high);
		quicksort(a,low,j--);
		quicksort(a,j++,high);
	}
}
int main()
{ 
     int b,i=0;
	cout<<"enter numbers to stop -1\n";
	do{
		cin>>b;
		if(b!=-1)
		a[i++]=b;
	}while(b!=-1);
	cnt=i;low=0;high=cnt-1;;
	cout<<"before sorting\n";
	for(i=0;i<cnt;i++)
	cout<<a[i]<<"  ";
    cout<<"\n";
	quicksort(a,low,high);
	cout<<"after sorting\n";
	for(i=0;i<cnt;i++)
	cout<<a[i]<<"  ";

}
