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
class Stack{
	Node* head;
public:
	Stack(){
		head = NULL;
	}
	void push(int val){
		if(head == NULL){
			head = getNewNode(val);
		}else{
			Node* node = getNewNode(val);
			node->next = head;
			head = node;
		}
	}
	int pop(){
		if(head == NULL)return -1;
		Node* tmp = head;
		head = head->next;
		int r = tmp->val;
		free(tmp);
		return r;
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
	Stack s1, s2[2];
	while(1){
		string str;
		cout << "\x1b[33mPossible commands are: push x, pop, isEmpty\x1b[0m\n";
		cin >> str;
		int x;
		if(str == "push"){
			cin >> x;
			s1.push(x);
		}
		if(str == "pop"){
			cout << "Popped: " << s1.pop() << endl;
		}
		if(str == "isEmpty"){
			cout << boolalpha << s1.isEmpty() << endl;
		}
		s1.print();
	}
}