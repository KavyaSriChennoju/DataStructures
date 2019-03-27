# include<iostream>
using namespace std;
int a[20],low,high,j,p,l,h,cnt;
void quicksort(int arr[20], int low, int high)
 {
  int i = low, j = high; int tmp;
  int p = arr[(low + high)/ 2];
  while (i <= j)
   {
        while (arr[i] < p)
          i++;
        while (arr[j] > p)
          j--;
        if (i <= j)
		 {   tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;j--;
          }
   }
if (low < j)
    quicksort(arr, low, j);
if (i < high)
    quicksort(arr, i, high);
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
