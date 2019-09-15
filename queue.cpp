#include<iostream>
using namespace std;

bool isEmpty();
bool isFull();


int arr[10];

	
void enqueue(int x)
{
	int front=-1;
	int rear=-1;
		
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		
	}
	else
	{
		front=front+1;
	}
	arr[front]=x;
	
}

/*bool isEmpty()
{
	if(rear==-1 && front==-1)
	return true;
	return false;
}
bool isFull()
{
	if(front==arr[10-1])
	cout<<"Queue is Full ! ";
	
}
*/
int main()
{

	enqueue(2);
	enqueue(4);
	enqueue(6);
	for(int i=0;i<10;i++)
		cout<<"\nprint: "<<arr[i];

}

