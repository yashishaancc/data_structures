#include<iostream>
using namespace std;

typedef struct node{
	int val;
	struct node* next;
}Node;

Node* getNewNode(int val){
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	return node;
}

class Queue{
	Node* head, *tail;
public:
	Queue(){
		head = NULL;
		tail = NULL;
	}

	void push(int val){
		if(head == NULL){
			Node* node = getNewNode(val);
			head = node;
			tail = node;
		}else{
			Node* node = getNewNode(val);
			tail->next = node;
			tail = node;
		}
	}	

	int pop(){
		if(head == NULL)return -1;
		int to_return = head->val;
		Node* next = head->next;
		free(head);
		head = next;
		return to_return;
	}

	bool isEmpty(){
		return head == NULL;
	}

	void print(){
		Node* head = this->head;
		while(head != NULL){
			cout << head->val << ", ";
			head = head->next;
		}
		cout << endl;
	}

};

int main(){
	Queue q1, q2;
	while(1){
		string str;
		cout << "\x1b[33mPossible commands are: push x, pop, isEmpty\x1b[0m\n";
		cin >> str;
		int x;
		if(str == "push"){
			cin >> x;
			q1.push(x);
		}
		if(str == "pop"){
			cout << "Popped: " << q1.pop() << endl;
		}
		if(str == "isEmpty"){
			cout << boolalpha << q1.isEmpty() << endl;
		}
		q1.print();
	}
}