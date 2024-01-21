#include <iostream>
using namespace std;
class dequeue{
	private:
	 	int *data;
		int front;
		int rear;
		int size;
	public:
		dequeue(){
			data=new int[10];
			size=10;
			front=rear=-1;
		}
		dequeue(int s){
			size=s;
			data=new int[size];
			front=rear=-1;
		}
		
		void insert_at_end(int i){
			if(front==-1){
				front=rear=0;
				data[front]=i;
			}
			else{
				rear=rear+1%size;
				data[rear]=i;
			}
		}
		
		void insert_at_start(int i){	
			if(front==-1){
				front=rear=0;
				data[front]=i;
			}
			else if(front==0){
				front=size-1;
				data[front]=i;	
			}
			else{
				data[--front]=i;
			}				
		}
		void remove_at_end(){
			if(!empty()){
				if(front==rear){
					front=rear=-1;
				}
				else if(rear==0){
					rear=size-1;
				}
				else{
					rear=rear-1;
				}
				cout<<"Order has removed"<<endl<<endl;
			}
			else{
				cout<<"Array is empty"<<endl<<endl;
			}
		}
		void remove_at_start(){
			if(!empty()){
				if(front==rear){
					front=rear=-1;
				}
				else{
					front=(front+1)%size;;
				}
				cout<<"Order has removed"<<endl<<endl;
			}
			else{
				cout<<"Array is empty"<<endl<<endl;
			}
		}
		void display(){
			cout<<"----------Records-----------"<<endl;
			if(empty()){
				cout<<"There is no order yet"<<endl;
			}
			else{
				if(front==rear){
					cout<<data[rear]<<endl;
				}
				else{
					int i=front;
					do{
						cout<<data[i]<<endl;
						i=(i+1)%size;	
					}while(i!=rear);
					cout<<data[rear];
				}
			}
			cout<<endl;			
		}
		bool empty(){
			if(front==-1){
				return true;
			}
			return false;
		}
		bool full(){
			if((rear+1)%size==front){
				return true;
			}
			return false;
		}
};
int main(){
	dequeue q1;
	int choice,order;
do{
	cout<<"Enter 1 to insert at start"<<endl<<"Enter 2 to insert at end"<<endl<<"Enter 3 to remove at start"<<endl;
	cout<<"Enter 4 to remove at end"<<endl<<"Enter 5 to display"<<endl<<"Enter 0 to exit"<<endl;
	cin>>choice;
	
		switch(choice){
			case 1:
				if(!q1.full()){
					cout<<"Enter order number"<<endl;
					cin>>order;
					q1.insert_at_start(order);
					cout<<"Order has placed"<<endl<<endl;
				}
				else{
					cout<<"Array is full"<<endl;
				}
				break;
			case 2:
				if(!q1.full()){
					cout<<"Enter order number"<<endl;
					cin>>order;
					q1.insert_at_end(order);
					cout<<"Order has placed"<<endl<<endl;
				}	
				else{
					cout<<"Array is full"<<endl;
				}
				break;
			case 3:
				q1.remove_at_start();
				break;
			case 4:
				q1.remove_at_end();
				break;
			case 5:
				q1.display();
				break;
			case 0:
				cout<<"you exit"<<endl;
				break;
			default:
				cout<<"INVALID INPUT, Try again"<<endl;
		}
	}while(choice!=0 );
}