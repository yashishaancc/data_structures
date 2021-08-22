#include<iostream>
#include<string>
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
Node* push(Node* tail,int x){
	if(tail == NULL){
		tail = getNewNode(x);
		return tail;
	}
	Node* node = getNewNode(x);
	tail->next = node;
	tail = node;
	return tail;
}
Node* pop(Node* head,int x){
	if(head == NULL)return head;
	Node*temp = head;
	head = head->next;
	cout << "Popped : " << temp->val << endl;
	free(temp);
	return head;
}
bool isEmpty(Node* head){
	if(head == NULL)return true;
	return false;
}
void printQueue(Node* head){
	if(head == NULL)return;
	cout << "Printing Queue: ";
	while(head != NULL){
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}
int main(){
	Node* head = NULL;
	Node* tail = NULL;
	while(1){
		string str;
		cin >> str;
		int x;
		if(str == "push"){
			cin >> x;
			if(tail == NULL){
				tail = push(tail,x);
				head = tail;
			}
			else tail = push(tail,x);
		}
		if(str == "pop"){
			head = pop(head,x);
			if(head == NULL)tail = NULL;
		}
		if(str == "isEmpty"){
			cout << isEmpty(head) << endl;
		}
		printQueue(head);
	}
	return 0;
}