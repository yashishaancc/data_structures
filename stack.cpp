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
Node* push(Node* head, int x){
	if(head == NULL){
		Node* Head = getNewNode(x);
		return Head;
	}
	Node* node = getNewNode(x);
	node->next = head;
	head = node;
	return head;
}
Node* pop(Node* head){
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
void printStack(Node* head){
	if(head == NULL)return;
	cout << "Printing Stack: ";
	while(head != NULL){
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}
int main(){
	Node* head = NULL;
	while(1){
		string str;
		cin >> str;
		int x;
		if(str == "push"){
			cin >> x;
			head = push(head, x);
		}
		if(str == "pop"){
			head = pop(head);
		}
		if(str == "isEmpty"){
			cout << isEmpty(head) << endl;
		}
		printStack(head);
	}
	return 0;
}