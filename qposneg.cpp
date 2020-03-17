#include <iostream>

using namespace std;

class queue{
	public:
		queue();
		bool empty();
		void enqueue(int x);
		void dequeue();
		int peek();
		void print();
		int size();
		friend bool posneg(queue &pos,queue &neg);
		
		struct Qnode{
			int data;
			Qnode* next;
		};
	
		Qnode* front;
		Qnode* rear;		
};

//Queue Constructor
queue::queue(){
	front=rear=NULL;
}

int queue::size(){
	int size=0;
	Qnode* temp=front;
	while(temp!=NULL){
		size++;
		temp=temp->next;
	}
	return size;
}

//Adds Node in Queue
void queue::enqueue(int x){
	Qnode* temp=new Qnode;

	temp->data=x;
	temp->next=NULL;
	if(empty()){
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}

//Checks if Queue is empty
bool queue::empty(){
	if(rear==NULL){
		return true;
	}
	else{
		return false;
	}
}

//Removes Node from Queue
void queue::dequeue(){
	if(front==NULL){
		return;
	}
	Qnode* temp=front;
	front=front->next;
	
	if(front==NULL){
		rear=NULL;
	}
	delete(temp);
}

//Returns first Node of Queue
int queue::peek(){
	cout<<front->data;
}

void queue::print(){
	Qnode* temp=front;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

bool posneg(queue &pos,queue &neg){
	queue::Qnode* temp1;
	queue::Qnode* temp2;
	temp1=pos.front;
	temp2=neg.front;
	int possize=pos.size();
	int negsize=neg.size();
	cout<<"possize: "<<possize<<endl;
	cout<<"negsize: "<<negsize<<endl;
	if(possize!=negsize){
		return false;
	}
	else{
		while(temp1!=NULL&&temp2!=NULL){
			if(temp1->data!=-temp2->data){
				return false;
			}
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	return true;
}

int main(){
	queue positive;
	queue negative;
	
	int N;
	cin>>N;
	
	if(N>0){
			positive.enqueue(N);
		}
	else if(N<0){
			negative.enqueue(N);
		}
	while(getchar()!='\n'){
		cin>>N;
		if(N>0){
			positive.enqueue(N);
		}
		else if(N<0){
			negative.enqueue(N);
		}
	}

	if(posneg(positive,negative)){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
	cout<<"Positive Queue: ";
	positive.print();
	cout<<endl<<"Negative Queue: ";
	negative.print();
	}






