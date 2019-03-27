#include<iostream>
#include<cstdlib>
using namespace std;
struct btnode
{
	btnode *left;
	char c;
	btnode *right;
};
class stack
{
	public:
	btnode *c1[100];
	int top;
	int size;
	void push(btnode*);
	btnode* pop();
	btnode* Top();
	bool isFull()
	{
		if(top>=size-1)
			return true;
		else 
			return false;	
	}
	bool isEmpty()
	{
		if(top<0)
			return true;
		else 
			return false;	
	}
	stack(int s)
	{
		size=s;
		top=-1;
	}	
	stack()
	{
		top=-1;
	}
};
	 void stack::push(btnode* c)
	{
		if(isFull())
			cout<<"Stack is Full"<<endl;
		else
			c1[++top]=c;
	}
	btnode* stack::pop()
	{
		if(isEmpty())
			cout<<"Stack is Empty"<<endl;
		else
			return(c1[top--]);
	}
	btnode* stack::Top()
	{
		if(isEmpty())
			cout<<"Stack is Empty"<<endl;
		else
			return(c1[top]);
	}
int x=0,ele=0;
int cu=0;
void insert(btnode * &T,char c)
{
	char d;
	if(T==NULL)
	{
		T=new(btnode);
		T->c=c;
		T->left=NULL;
		T-> right =NULL;
		ele++;
	}
	
	cout<<"Enter the left child of "<< c <<endl;
	cin>>d;
	if(d!='*')
		insert(T->left, d);
	cout<<"Enter the right child of "<< c <<endl;
	cin>>d;
	if(d!='*')
		insert(T->right,  d);
	return;
	
}
void postorder(btnode *); 
int main()
{	
	btnode *T=NULL;
	char c;
	cout<<"Enter the root "<<endl;
	cin>>c;
	insert(T,c);
	postorder(T);
	cout<<endl;
return 0;
}
void postorder(btnode *T)  
{
    stack s(50);
    btnode *prev=NULL;
    do
    { 
        while (T!=NULL)
        { 
            s.push(T);
            T=T->left;
        }
        if(!s.isEmpty())
        {
            while(T==NULL && !s.isEmpty())
            {
                T= s.Top();
                if(T->right!=NULL)
                {
                    if(T->right == prev)
                    {
                        cout << T->c  <<  " ";
                        s.pop();
                        prev = T;
                        T = NULL;
                    }
                    else
                        T = T->right;
                }
                else
                {
                    cout << T->c  <<  " ";
                    s.pop();
                    prev = T;
                    T = NULL;
                }
            }
        }    
    }while(!s.isEmpty());
}