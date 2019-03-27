# include<iostream>
# include<cstring>
using namespace std;
class queue
{
	public:
	int size;
	int size1;
	char ele[50];
	int front;
	int rear;
	queue();
	queue(int);
	bool isqfull();
	bool isqempty();
	void enqueue(char);
	char dequeue();
};
queue :: queue()
{
	size=50;
	front=-1;
	rear=-1;
	size1=0;
}
queue :: queue(int s)
{
	size=s;
	front=-1;
	rear=-1;
	size1=0;
}
bool queue:: isqfull()
{
	if((rear+1)%size==front)
	return true;
	else
	return false;
}
void queue :: enqueue(char c)
{
	if(isqfull())
	cout<<"queue is full\n";
	else
	{
		rear=(rear+1)%size;
		ele[rear]=c;
		if(front==-1)
		front++;
		size1++;
	}
}
bool queue :: isqempty()
{
		if(front==-1)
	return true;
	else
	return false;
}
char queue :: dequeue()
{
	if (isqempty())
	{
		cout<<"queue is empty\n";
	}
	else
	{

		int temp=front;
		if(front!=rear)
		{
			front=(front+1)%size;
		}
		else
		{
			rear=-1;
			front=-1;
		}
			size1--;
		return(ele[temp]);
}
	}

int main()
{
      queue q;
	  char a[10];
    int x,l,i,j,p,m,k,t;
	cout<<"enter no of chars in exp\n";
	cin>>x;
	cout<<"enter the postfix expression\n";
		for(i=0;i<x;i++)
	{
		cin>>a[i];
	}
		for(i=0;i<x;i++)
		{
			if(a[i]=='0')
			q.enqueue(0);
			else if(a[i]=='1')
			q.enqueue(1);
				else if(a[i]=='2')
			q.enqueue(2);
				else if(a[i]=='3')
			q.enqueue(3);
				else if(a[i]=='4')
			q.enqueue(4);
				else if(a[i]=='5')
			q.enqueue(5);
				else if(a[i]=='6')
			q.enqueue(6);
			else if(a[i]=='7')
			q.enqueue(7);
			else if(a[i]=='8')
			q.enqueue(8);
			else if(a[i]=='9')
			q.enqueue(9);
		else if ( a[i]=='*' || a[i]=='+' || a[i]=='-' || a[i]=='/')
			{l=q.size1;
			for(j=0;j<(l-2);j++)
			{
				k=q.dequeue();
				q.enqueue(k);
			}
				m=q.dequeue();
				p=q.dequeue();
		
		if(a[i]=='*')
	    {k=(m*p);}
		else if(a[i]=='+')
		{k=(m+p);}
		else if(a[i]=='-')
		{
		k=(m-p);}
		else if(a[i]=='/')
		{
		k=(m/p);}
		q.enqueue(k);
			}		
}
	
	t=q.dequeue();
	cout<<t;
}

