#include<iostream> 
#include<fstream>
using namespace std;
int last;
struct node
{
  int data;
  int flag;
  node *left;
  node *right;
  node()
  {
  	flag=0;
  }
};

void create(node *&m,int k)
{
	if(k<=2)
	{
	if(m==NULL)
	{
	node *l;
	l=new(node);
	l->data=-1;
	l->left=NULL;
	l->right=NULL;
	m=l;
	}
		create(m->left,k+1);
		create(m->right,k+1);
	}
}
bool check(node *l)
{
	if(l->left->left->flag==1&&l->left->right->flag==1&&l->right->left->flag==1&&l->right->right->flag==1)
	{
		l->left->left->flag=0;l->left->right->flag=0;l->right->left->flag=0;l->right->right->flag=0;
		return true;
	}
	else
	return false;
}
void replace(node *&l,int a,int b,int c)
{
   if(c==2 && l->data==a)
   l->data=b;
   else if(c==2&&l->data!=a)
   return ;
   else
   {
   	replace(l->left,a,b,c+1);
   	replace(l->right,a,b,c+1);
   }	
}
void put(node *&l,int a[],int k)
{
  static int m=0;
  if(k<=2)
  {
  	if(k==2&&m<4)
  	l->data=a[m++];
  	else
  	{
  		put(l->left,a,k+1);
  		put(l->right,a,k+1);
  	}
  }	
}
int min(node *l,int p)
{
  int n=1000;
  if(p!=1)
  return min(l->left,p+1)<=min(l->right,p+1)?min(l->left,p+1):min(l->right,p+1);
  if(p==1)
  {
  	if(l->left->flag==0&&l->right->flag==0)
  	{
  		if(l->left->data<l->right->data)
  		{
  		  if(l->left->data<last)
		  {
			l->left->flag=1;return n;
		  }
		  else
		  {
		  	return (l->left->data);
		  }	 	
  		}
  		else
  		{
  		  if(l->right->data<last)
		  {
			l->right->flag=1;return n;
		  }
		  else
		  {
		  	return (l->right->data);
		  }	 		
  		}
  	}
  	if(l->left->flag==1&&l->right->flag==0)
  	{
  		  if(l->right->data<last)
		  {
			l->right->flag=1;return n;
		  }
		  else
		  {
		  	return (l->right->data);
		  }	 
  	}
  	if(l->left->flag==0&&l->right->flag==1)
  	{
  		  if(l->left->data<last)
		  {
			l->left->flag=1;return n;
		  }
		  else
		  {
		  	return (l->left->data);
		  }	 
  	}
  	if(l->left->flag==1&&l->right->flag==1)
  	return n;
  }	
}
int main()
{
	node *l=NULL;
	ofstream fout1,fout2;fout1.open("data.txt");
	ifstream fin1,fin2;
	int a,b=0,c=0,d,e=-1,p=0,s=0,cnt=1;
	cout<<"enter the integers \n";
	cin>>a;
	int a1[4];
	create(l,b);
	while(a!=-1)
	{
		b++;
		fout1<<a<<" ";
		cin>>a;
	}
	int no=b;
	fout1.close();
    int count=1;
    fout1.open("data1.txt");fout2.open("data2.txt");fin1.open("data.txt");
	fin1>>a;
	while(!fin1.eof())
	{
		if(c<4)	
		{
			a1[c++]=a;
			if(c==4)
			put(l,a1,p);
			fin1>>a;
		}
		else
		{
		  if(check(l)) 
		  {
		  	last=-20;
		  	if(count==1)
		  	{
		  	  fout1<<e<<" ";count++;
		    }
		    else
		    {
		      fout2<<e<<" ";count--;	
		    }
		  } 
		  if(count==1 && !check(l))
		  {
		  	last=min(l,p);
		  	if(last!=0)
		  	{
		  	  fout1<<last<<" ";
		  	  replace(l,last,a,p);
		  	  fin1>>a;
		  	  if(fin1.eof())
		  	  fout1<<e<<" ";
		    }
		  }
		  if(count==2&&!check(l))
		  {
		  	last=min(l,p);
		  	if(last!=0)
		  	{
		  	  fout2<<last<<" ";
		  	  replace(l,last,a,p);
		  	  fin1>>a;
		  	  if(fin1.eof())
		  	  fout2<<e<<" ";
		    }
		  }	
		}
	}
	a1[0]=l->left->left->data;
	a1[1]=l->left->right->data;
	a1[2]=l->right->left->data;
	a1[3]=l->right->right->data;
	for(int i=0;i<3;i++)
	for(int j=i+1;j<4;j++)
	if(a1[i]>a1[j])
	{
		int t=a1[i];a1[i]=a1[j];a1[j]=t;
	}
	if(count==1)
	{
		for(int i=0;i<4;i++)
		fout2<<a1[i]<<" ";fout2<<e<<" ";
	}
	else
	{
		for(int i=0;i<4;i++)
		fout1<<a1[i]<<" ";fout1<<e<<" ";
	}
	fin1.close();fout1.close();fout2.close();
		while(s<no)
	{
		count=1;
	    s=0;
	    if(cnt++%2==1)
	    {
	    fin1.open("data1.txt");
	    fin2.open("data2.txt");
	    fout1.open("data3.txt");
	    fout2.open("data4.txt");
	    }
	    else
	    {
	    fin1.open("data3.txt");
	    fin2.open("data4.txt");
	    fout1.open("data1.txt");
	    fout2.open("data2.txt");
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
			            fout1<<b<<" ";
			            s++;
			        }
	    		    if(b!=-1&&!fin2.eof())
		    	    fin2>>b;
			        else
			        {
				        while(a!=-1&&!fin1.eof())
				        {
				    	    fout1<<a<< " ";
    					    s++;
		    			    fin1>>a;
			    	    }
			    	    if(s!=no)
				         fout1<<"-1"<<endl;
    				     fin1>>a;fin2>>b;
	    			     count++;
		    	    }
		        }
    		    else if(s!=no)
	    	    {
	    	    	if(b!=-1)
		        	fout2<<b<<" ";
			        if(b!=-1&&!fin2.eof())
    			    fin2>>b;
	    		    else
		    	    {
			    	    while(a!=-1&&!fin1.eof())
				        {
				        	fout2<<a<< " ";
	    				    fin1>>a;
		    		    }
		    		    if(s!=no)
			    	     fout2<<"-1"<<endl;
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
			            fout1<<a<<" ";
			            s++;
			        }
	    		    if(a!=-1&&!fin1.eof())
		    	    fin1>>a;
			        else
			        {
    				    while(b!=-1&&!fin2.eof())
	    			    {
	    			    	s++;
		    		    	fout1<<b<< " ";
					        fin2>>b;
    				    }
						if(s!=no)    
		    		     fout1<<"-1"<<endl;
			    	     fin1>>a;fin2>>b;
				         count++;
    			    }    
	    	    }
		        else if(s!=no)
		        {
		        	if(a!=-1)
		    	    fout2<<a<<" ";
	    		    if(a!=-1&&!fin1.eof())
		    	    fin1>>a;
			        else
			        {
    				    while(b!=-1&&!fin2.eof())
	    			    {
		    		    	fout2<<b<< " ";
					        fin2>>b;
    				    }    
    				    if(s!=no)
	    			    fout2<<"-1"<<endl;
			      	     fin1>>a;fin2>>b;
				         count++;
    			    }
	    	    }
	        }
	    }
	    fout1.close();
	    fout2.close();
    	fin1.close();
	    fin2.close();
	}
	return 0;		
}
