#include <iostream>

using namespace std;
class Q{
	private:
		int *data;;
		int size;
		int front;
		int rear;
	public:
		Q(){
			size=10;
			data=new int[size];
			front=rear=-1;
		}
		Q(int s){
			size=s;
			data=new int[size];
			front=rear=-1;
		}
		bool empty(){
			return(rear==-1);
		}
		bool full(){
			return((rear+1)%size==front);
		}
		void enque(int x){
				if(empty()){
					front=rear=0;
					data[front]=x;
				}
				else{
					rear=(rear+1)%size;
					data[rear]=x;
					if(front!=rear){
						sort();	
					}
				}	
		}
		void sort(){
			int temp;
			for(int i=front;i<=rear;i++){
				for(int j=front;j<=rear;j++){
					if(data[j]<data[i]){
						temp=data[i];
						data[i]=data[j];
						data[j]=temp;
					}
				}
			}
		}
		void deque(){
			if(empty()){
				cout<<"Queue is empty"<<endl;
			}
			else{
				if(front==rear){
					front=rear=-1;
				}
				else{
				front=(front+1)%size;
				}
			}
		}
		void display(){
			if(empty()){
				cout<<"Queue is empty"<<endl;
			}
			else{
				cout<<"---------Orders--------"<<endl;
				if(front==rear){
					cout<<data[rear]<<endl;
				}
				else{
					int i=front;
					do{
						cout<<"i "<<i<<" ";
						cout<<data[i]<<endl;
						i=(i+1)%size;
					}while(i!=rear);
					cout<<"i "<<rear<<" ";
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
				int n;
				if(!q1.full()){
					cout<<"Enter your age"<<endl;
					cin>>n;
					q1.enque(n);
					cout<<"Your order has placed"<<endl;
				}
				else{
					cout<<"Queue is full"<<endl<<endl;
				}
				break;
			case 2:
				q1.deque();
				break;
			case 3:
				q1.display();
				break;
		}
	}while(choice!=0);
	
}
