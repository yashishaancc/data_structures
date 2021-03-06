#include<iostream>
#include<string>
using namespace std;
typedef struct node{
	int i;
	struct node *next;
}Node;
Node* getNewNode(int in){
	Node* node = (Node*)malloc(sizeof(Node));
	node->i = in;
	return node;
}
Node* insertAtHead(Node* head, int in){
	// Node* node=(Node*)malloc(sizeof(Node));
	// node->i=in;
	Node* node = getNewNode(in);
	node->next = head;
	head = node;
	return head;
}
Node* reverseLinkList(Node* head){
	Node* newHead = NULL;
	while(head != NULL){
		newHead = insertAtHead(newHead, head->i);
		head = head->next;
	}
	return newHead;
}
Node* ReverseLinkList(Node* head){
	Node* prev = NULL;
	Node* curr = head;
	Node* next = head->next;
	while(head->next != NULL){
		curr->next = prev;
		prev = curr;
		curr = next;
		next = next->next;
		head = curr;;
	}
	curr->next = prev;
	return curr;
}
void insert(Node* head, int x, int y){
	while(head != NULL){
		if(head->i == x){
			Node* node = head->next;
			Node* newNode = getNewNode(y);
			head->next = newNode;
			newNode->next = node;
			break;
		}
		head = head->next;
	}
}
Node* Delete(Node* head, int x){
	if(head->i == x){
		Node* node = head;
		head = head->next;
		free(node);
		return head;
	}
	Node* Head = head; 
	while(head != NULL){
		if(head->next->i == x){
			Node* headNext = head->next;
			head->next = head->next->next;
			free(headNext);
			break;
		}
		head = head->next;
	}
	return Head;
}
Node* deleteAll(Node* head, int x){
	while(head != NULL && head->i == x){
		Node* node = head;
		head = head->next;
		free(node);
	}
	Node* Head = head; 
	while(head != NULL){
		// if(head->i==x){
		// 	Node* node=head;
		// 	head=head->next;
		// 	free(node);
		// }
		if(head->next == NULL)break;
		if(head->next->i == x){
			Node* headNext = head->next;
			head->next = head->next->next;
			free(headNext);
		}
		else{
			head = head->next;
		}
	}
	return Head;
}
void printList(Node* head){
	while(head != NULL){
		cout << head->i << " ";
		head = head->next;
	}
	cout << endl;
	return;
}
int main(){
	// int a[3][4]={{2,3,4,5},{6,8,10,12},{7,6,4,1}};
	// cout<<a[1][2]<<endl;
	// cout<<*(*(a+1)+2)<<endl;
	Node* head = NULL;
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		int in;
		cin >> in;
		head = insertAtHead(head,in);
	}
	// printList(head);
	// printList(ReverseLinkList(head));
	head = ReverseLinkList(head);
	printList(head);
	for(int i = 0; i < q; i++){
		int x, y;
		string str;
		cin >> str;
		if(str == "add"){
			cin >> x >> y;
			insert(head, x, y);
		}
		else if(str == "del"){
			cin >> x;
			head = Delete(head, x);
		}
		else if(str == "delAll"){
			cin >> x;
			head = deleteAll(head, x);
		}
		printList(head);
	}
	return  0;
}
// 10 100    10 20 30 40 50 60 70 80 90 100