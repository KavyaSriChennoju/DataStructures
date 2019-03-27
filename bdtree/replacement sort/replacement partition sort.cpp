#include<iostream>
#include<fstream>
using namespace std;
int getmin(int arr[],int size);
int findmin(int arr[],int size,int ele);
void sort (int arr[],int s);
int main()
{
	ofstream fout("data.txt"),fout3("A1.txt"),fout4("A2.txt");
	cout<<"Enter the numnbers to be sorted\n";
	int e,s,a,b,no=0;
	cin>>e;
	do{
		no++;
		fout<<e<< " ";
		cin>>e;
	}while(e!=-1);
	fout.close();
	cout<<"Enter the size of the array\n";
	cin>>s;
	const int size=s;
	int arr[size],count=1,min,ctr=1;
	ifstream fin1("data.txt"),fin2;
	s=0;
	fin1>>e;
	while(!fin1.eof())
	{
	    arr[s++]=e;
		while(s==size && !fin1.eof())
		{
			min=getmin(arr,size);
			if(count%2==1)
			fout3<<" "<<min;
			else
			fout4<<" "<<min;
			fin1>>e;
			while(!fin1.eof())
			{
				arr[size-1]=e;
				min=findmin(arr,size,min);
				if(min!=0)
				{
				     if(count%2==1)
			       fout3<<" "<<min;
		          	 else
         			 fout4<<" "<<min;
					 fin1>>e;	
				}
				else
				{
					if(count%2==1)
					fout3<<" "<<"-1"<<endl;
					else
					fout4<<" "<<"-1"<<endl;
					count++;
					break;
				}
			}
		}
		fin1>>e;
	}
    	if(count++%2==1)
		{
			sort(arr,s);
			for(int i=0;i<s-1;i++)
			fout3<<" "<<arr[i];
			fout3<<" "<<"-1"<<endl;
		}
		else
		{
			sort(arr,s);
			for(int i=0;i<s-1;i++)
			fout4<<" "<<arr[i];
			fout4<<" "<<"-1"<<endl;
		}
	fout3.close();
	fout4.close();
	fin1.close();
	while(s<no)
	{
		count=1;
	    s=0;
	    if(ctr++%2==1)
	    {
	  fin1.open("A1.txt");
	  fin2.open("A2.txt");
	  fout3.open("B1.txt");
	  fout4.open("B2.txt");
	    }
	    else
	    {
	  fin1.open("B2.txt");
	  fin2.open("B2.txt");
	  fout3.open("A1.txt");
	  fout4.open("A2.txt");
	    }
    	fin1>>a;
	    fin2>>b;
    	while(!fin1.eof()||!fin2.eof())
	    {
		    if(a>b)
    		{
	    		if(count%2==1)
		    	{
		    		if(b!=-1)
		    		{
			          fout3<<b<<" ";
			            s++;
			        }
	    		    if(b!=-1&&!fin2.eof())
		    	    fin2>>b;
			        else
			        {
				        while(a!=-1&&!fin1.eof())
				        {
				    	  fout3<<a<< " ";
    					    s++;
		    			  fin1>>a;
			    	    }
			    	    if(s!=no)
				       fout3<<"-1"<<endl;
    				   fin1>>a;fin2>>b;
	    			     count++;
		    	    }
		        }
    		    else if(s!=no)
	    	    {
	    	    	if(b!=-1)
		        	fout4<<b<<" ";
			        if(b!=-1&&!fin2.eof())
    			  fin2>>b;
	    		    else
		    	    {
			    	    while(a!=-1&&!fin1.eof())
				        {
				        	fout4<<a<< " ";
	    				  fin1>>a;
		    		    }
		    		    if(s!=no)
			    	   fout4<<"-1"<<endl;
				       fin1>>a;fin2>>b;
    				     count++;
	    		    }
		        }
	        }
    	    else
	        {
	        	if(count%2==1)
			    {
			    	if(a!=-1)
			    	{
			          fout3<<a<<" ";
			            s++;
			        }
	    		    if(a!=-1&&!fin1.eof())
		    	  fin1>>a;
			        else
			        {
    				    while(b!=-1&&!fin2.eof())
	    			    {
	    			    	s++;
		    		    	fout3<<b<< " ";
					      fin2>>b;
    				    }
						if(s!=no)    
		    		   fout3<<"-1"<<endl;
			    	   fin1>>a;fin2>>b;
				         count++;
    			    }    
	    	    }
		        else if(s!=no)
		        {
		        	if(a!=-1)
		    	  fout4<<a<<" ";
	    		    if(a!=-1&&!fin1.eof())
		    	  fin1>>a;
			        else
			        {
    				    while(b!=-1&&!fin2.eof())
	    			    {
		    		    	fout4<<b<< " ";
					      fin2>>b;
    				    }    
    				    if(s!=no)
	    			   fout4<<"-1"<<endl;
			      	   fin1>>a;fin2>>b;
				         count++;
    			    }
	    	    }
	        }
	    }
	  fout3.close();
	  fout4.close();
      fin1.close();
	  fin2.close();
	}
	cout<<"numbers are sorted\n";
	return 0;
}
int findmin(int arr[],int size,int ele)
{
	int min=0;
	for(int i=0;i<size;i++)
	{
		if(ele<arr[i])
		{
			if(min==0)
			min=arr[i];
			else if(arr[i]<min)
			min=arr[i];
		}
	}
	if(min!=0)
	{
		for(int i=0;i<size;i++)
		{
			if(arr[i]==min)
			{
				for(int j=i;j<size-1;j++)
				arr[j]=arr[j+1];
			}
		}
	}
	return  min;
}
int getmin(int arr[],int size)
{
	int min=arr[0];
	for(int i=0;i<size;i++)
	{
		if(min>arr[i])
			min=arr[i];
	}
	if(min!=0)
	{
		for(int i=0;i<size;i++)
		{
			if(arr[i]==min)
			{
				for(int j=i;j<size-1;j++)
				arr[j]=arr[j+1];
			}
		}
	}
	return min;
}

void sort (int arr[],int s)
{
	for(int i=0;i<s;i++)
	{
	    for(int j=0;j<s-i-1;j++)
	    if(arr[j]>arr[j+1])
	    {
	    	int t=arr[j];
	    	arr[j]=arr[j+1];
	    	arr[j+1]=t;
	    }
	}
}


