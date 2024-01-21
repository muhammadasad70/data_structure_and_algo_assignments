#include <iostream>
using namespace std;
class Q{
	private:
		string *data;
		int size;
		int front;
		int rear;
	public:
		Q(){
			size=10;
			data=new string[10];
			front=rear=-1;
		}
		Q(int s){
			size=s;
			data=new string[size];
			front=rear=-1;
		}
		bool empty(){
			return(front==-1);
		}
		bool full(){
			return((rear+1)%size==front);
		}
		void enque(string x){
			if(!full()){
				if(empty()){
					front=rear=0;
					data[front]=x;
				}
				else{
					rear=(rear+1)%size;
					data[rear]=x;
				}
				cout<<"Order has placed"<<endl<<endl;
			}
			else{
				cout<<"Queue is full"<<endl;
			}
		}
		void deque(){
			if(empty()){
				cout<<"Queue is empty"<<endl;
			}
			else{
				data[front].clear();
				if(front==rear){
					front=rear=-1;
				}
				else{
					front=(front+1)%size;
					cout<<"Order has delivered"<<endl<<endl;
				}
			}
		}
		void display(){
			if(empty()){
				cout<<"Queue is empty"<<endl;
			}
			else{
				cout<<"-------------Orders----------"<<endl;
				if(front==rear){
					cout<<data[front]<<endl;
				}
				else{
					int p=front;
					do{
						cout<<data[p]<<endl;
						p=(p+1)%size;			
					}while(p!=rear);
					cout<<data[rear]<<endl;	
				}
				}
		}
};

int main(){
	
	Q q1;
	
	int choice;
	do{
		cout<<"press 1 to order pizza"<<endl;
		cout<<"press 2 to deliver pizza"<<endl;
		cout<<"press 3 to display"<<endl;
		cout<<"press 0 to exit"<<endl;
		cin>>choice;
		switch(choice){
			case 0:
				cout<<"you exit"<<endl;
				break;
			case 1:
				q1.enque("booked");
				break;
			case 2:
				q1.deque();	
				break;
			case 3:
				q1.display();
				break;
			default:
				cout<<"Invalid input,try again"<<endl<<endl;
		}
	}while(choice!=0);
	
	
}
