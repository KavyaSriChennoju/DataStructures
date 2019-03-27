#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct reg
{
	int index,roll,course;
};
struct stud
{
	int index,roll;
	char name[10];
};
struct sub
{
	int course,index;
};
ifstream & operator >> (ifstream &t,stud &s)
{
   t>>s.roll;t>>s.name;return t;	
}
ifstream & operator >> (ifstream &t,sub &s)
{
	t>>s.course;return t;
};
ifstream & operator >> (ifstream &t,reg &s)
{
	t>>s.index;t>>s.roll;t>>s.course;return t;
};
int main()
{
	ofstream out1,out2,out3;ifstream in1,in2;int a1=0,a2=0,a3=0,k1=0,k2=0;
	stud s1,t1;sub s2,t2;reg s3;
	cout<<"enter the rollno\n";
	cin>>s1.roll;
	out1.open("stud.txt");out2.open("course.txt");out3.open("register.txt");
	while(s1.roll!=-1)
	{
		in1.open("stud.txt",ios::app);in2.open("course.txt",ios::app);
		if(a1==0)
		{
		   	cout<<"enter the name\n";
			cin>>s1.name;
			out1<<s1.roll<<" "<<s1.name<<" ";a1++;
		}
		else
		{
		in1>>t1;
		while(!in1.eof())
		{
			if(t1.roll==s1.roll)
			{
				k1++;break;
			}
			in1>>t1;
		}
		if(k1==0)
		{
			cout<<"enter the name\n";
			cin>>s1.name;
			out1<<s1.roll<<" "<<s1.name<<" ";
		}
		else k1=0;
	    }
	    if(a2==0)
	    {
	      cout<<"enter the courseno\n";
		  cin>>s2.course; a2++;
		  out2<<s2.course<<" ";     	
	    }
	    else
	    {
		cout<<"enter the courseno\n";
		cin>>s2.course;
		in2>>t2;
		while(!in2.eof())
		{
			if(t2.course==s2.course)
			{
				k1++;break;
			}
			in2>>t2;
		}
		if(k1==0)
		{
			out2<<s2.course<<" ";
		}
		else k1=0;
	    }
		out3<<a3++<<" "<<s1.roll<<" "<<s2.course<<" ";
		cout<<"enter the rollno\n";
		cin>>s1.roll;
		in1.close();in2.close();out1.close();out2.close();out3.close();
		out1.open("stud.txt",ios::app);out2.open("course.txt",ios::app);out3.open("register.txt",ios::app);
	}
	in1.close();in2.close();out1.close();out2.close();out3.close();
	out1.open("inverted.txt");
	in1.open("stud.txt");in2.open("register.txt");
	in1>>s1;
	while(!in1.eof())
	{
		out1<<s1.roll<<" ";
		in2>>s3;
		while(!in2.eof())
		{
			if(s3.roll==s1.roll)
			out1<<s3.index<<" ";
			in2>>s3;
		}
		out1<<endl;
		in2.close();
		in2.open("register.txt");
		in1>>s1;
	}
	in1.close();out1.close();in2.close();
	return 0;
}
