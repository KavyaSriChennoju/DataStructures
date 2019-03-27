#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct reg
{
	int index,roll,rf,rb,course,cf,cb;
};
struct stud
{
	int roll, index;char name[10];
};
struct sub
{
	int index,course;char name[10];
};
ifstream & operator >> (ifstream &t,stud &s)
{
	t>>s.roll;t>>s.name;t>>s.index;return t;
};
ifstream & operator >> (ifstream &t,sub &s)
{
	t>>s.course;t>>s.name;t>>s.index;return t;
}
ifstream & operator >> (ifstream &t,reg &s)
{
	t>>s.index;t>>s.roll;t>>s.rf;t>>s.rb;t>>s.course;t>>s.cf;t>>s.cb;return t;
}
int main()
{
	ifstream in1,in2,in3;ofstream out1,out2,out3;stud s1,t1;sub s2,t2;reg s3,t3;int a1=0,a2=0,a3=0,k1=0,k3=0,k2=-1;
	out1.open("student.txt");
	out2.open("sub.txt");
	out3.open("reg.txt");
	for(int i=0;i<20;i++)
	for(int j=0;j<20;j++)
	out3<<" ";
	cout<<"enter the rollno\n";
	cin>>s1.roll;
	while(s1.roll!=-1)
	{
	   in1.open("student.txt");
	   in2.open("sub.txt");
	   in3.open("reg.txt");
	   if(a1==0)
	   {
	   	cout<<"enter the name\n";
	   	cin>>s1.name;
	   	s1.index=a3;
	   	a1++;
	   	out1<<s1.roll<<" "<<s1.name<<" "<<s1.index<<" ";
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
	   	 	s1.index=a3;
	   	 	out1<<s1.roll<<" "<<s1.name<<" "<<s1.index<<" ";
	   	 }
	   	 else k1=0;
	   }
	   cout<<"enter the course no\n";
	   cin>>s2.course;
	   	if(a2==0)
	   {
	   	cout<<"enter the course name\n";
	   	cin>>s2.name;
	   	s2.index=a3;
	   	a2++;
	   	out2<<s2.course<<" "<<s2.name<<" "<<s2.index<<" ";
	   }
	   else
	   {
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
	   	 	cout<<"enter the course name\n";
	   	 	cin>>s2.name;
	   	 	s2.index=a3;
	   	 	out2<<s2.course<<" "<<s2.name<<" "<<s2.index<<" ";
	   	 }
	   	 else k1=0;
	   }
	   if(a3==0)
	   {
	   	out3<<a3<<" "<<s1.roll<<" "<<k2<<" "<<k2<<" "<<s2.course<<" "<<k2<<" "<<k2<<" ";
	   	a3++;
	   }
	   else
	   {
	   	s3.index=a3;s3.roll=s1.roll;s3.rf=-1;s3.rb=-1;s3.course=s2.course;s3.cf=-1;s3.cb=-1;
	   	 in3>>t3;
	   	 while(!in3.eof())
	   	 {
	   	 	if(t3.roll==s1.roll)
	   	 	{
	   	 		k3++;break;
	   	 	}
	   	 	else
	   	 	{
	   	 		k1++;
	   	 		in3.seekg(20*k1,ios::beg);
	   	 		in3>>t3;
	   	 	}
	   	 }
	   	 if(k3==0)
	   	 {
	   	 	out3.seekp(20*a3,ios::beg);
	   	 	out3<<s3.index<<" "<<s3.roll<<" "<<s3.rf<<" "<<s3.rb<<" "<<s3.course<<" "<<s3.cf<<" "<<s3.cb<<" ";
	   	 }
	   	 else
	   	 {
	   	 	k3=0;
	   	 	while(t3.rf!=-1)
	   	 	{
	   	 		in3.seekg(t3.rf*20,ios::beg);
	   	 		in3>>t3;
	   	 	}
	   	 	out3.seekp(t3.index*20,ios::beg);
	   	 	out3<<t3.index<<" "<<a3<<" "<<t3.rb<<" "<<t3.course<<" "<<t3.cf<<" "<<t3.cb<<" ";
	   	 	s3.rb=t3.index;
	   	 }
	   	 in3.close();
	   	 in3.open("reg.txt");
	   	  in3>>t3;
	   	 while(!in3.eof())
	   	 {
	   	 	if(t3.course==s2.course)
	   	 	{
	   	 		k3++;break;
	   	 	}
	   	 	else
	   	 	{
	   	 		k1++;
	   	 		in3.seekg(20*k1,ios::beg);
	   	 		in3>>t3;
	   	 	}
	   	 }
	   	 if(k3==0)
	   	 {
	   	 	out3.seekp(20*a3,ios::beg);
	   	 	out3<<s3.index<<" "<<s3.roll<<" "<<s3.rf<<" "<<s3.rb<<" "<<s3.course<<" "<<s3.cf<<" "<<s3.cb<<" ";
	   	 }
	   	 else
	   	 {
	   	 	k3=0;
	   	 	while(t3.rf!=-1)
	   	 	{
	   	 		in3.seekg(t3.rf*20,ios::beg);
	   	 		in3>>t3;
	   	 	}
	   	 	out3.seekp(t3.index*20,ios::beg);
	   	 	out3<<t3.index<<" "<<t3.rf<<" "<<t3.rb<<" "<<t3.course<<" "<<a3<<" "<<t3.cb<<" ";
	   	 	s3.cb=t3.index;
	   	 }
	   	 out3<<s3.index<<" "<<s3.roll<<" "<<s3.rf<<" "<<s3.rb<<" "<<s3.course<<" "<<s3.cf<<" "<<s3.cb<<" ";a3++;
	   }
	   in1.close();in2.close();in3.close();out1.close();out2.close();out3.close();
	    out1.open("student.txt",ios::app);out2.open("sub.txt",ios::app);out3.open("reg.txt",ios::app);
	    cout<<"enter the rollno\n";
	    cin>>s1.roll;
	}
}
