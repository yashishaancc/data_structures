#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define INF 2147483647
typedef struct node{
	int vertex;
	int w;
	struct node* next;
}Node;
Node* getNewNode(int ve){
	Node* node = (Node*)malloc(sizeof(Node));
	node->vertex = ve;
	node->next = NULL;
	return node;
}
Node* pushStack(Node* head, int x){
	if(head == NULL){
		Node* Head = getNewNode(x);
		return Head;
	}
	Node* node = getNewNode(x);
	node->next = head;
	head = node;
	return head;
}
Node* pushQueue(Node* tail, int x){
	if(tail == NULL){
		tail = getNewNode(x);
		return tail;
	}
	Node* node = getNewNode(x);
	tail->next = node;
	tail = node;
	return tail;
}
Node* pop(Node* head){
	if(head == NULL)return head;
	Node* temp = head;
	head = head->next;
	cout << "Popped : " << temp->vertex << endl;
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
		cout << head->vertex << ", ";
		head = head->next;
	}
	cout << endl;
}
Node* insert(Node* head, int v2, int w){
	Node* Head = head;
	if(head == NULL){
		head = getNewNode(v2);
		head->w = w;
		return head;
	}
	Node* temp = getNewNode(v2);
	temp->w = w;
	temp->next = head;
	head = temp;
	return head;
}
void printDFS(vector<Node*> v, int s){
	cout << "printing DFS" << endl;
	Node* head = NULL;
	vector<bool> visited(v.size(), false);
	head = pushStack(head, s);
	visited[s] = true;
	cout << "visiting: " << s << endl;
	while(!isEmpty(head)){
		int currVertex = head->vertex;
		//visit all unvisited childs
		Node* list = v[currVertex];
		while(list != NULL){
			//if unvisited, visit it
			int nextVertex = list->vertex;
			if(!visited[nextVertex]){
				cout << "visiting: " << nextVertex << endl;
				visited[nextVertex] = true;
				head = pushStack(head, nextVertex);
				break;
			}
			list = list->next;
		}
		if(list == NULL){
			//means all children visited
			//pop
			head = pop(head);
		}
	}
}
void printBFS(vector<Node*> v, int s){
	cout << "Printing BFS" << endl;
	Node* head = NULL;
	Node* tail = NULL;
	vector<bool> visited(v.size(), false);
	tail = pushQueue(tail,s);
	head = tail;
	visited[s] = true;
	cout << "visiting: " << s << endl;
	int count = 1,newcount = 0;
	while(!isEmpty(head)){
		cout << "count: " << count << endl;
		for(int i = 0; i < count; i++){
			int currVertex = head->vertex;
			Node* list = v[currVertex];
			while(list != NULL){
				int nextVertex = list->vertex;
				if(!visited[nextVertex]){
					cout << "visiting: " << nextVertex << endl;
					visited[nextVertex] = true;
					tail = pushQueue(tail, nextVertex);
					newcount++;
				}
				list = list->next;
			}
			head = pop(head);
			if(head == NULL)tail = NULL;
		}
		count = newcount;
		newcount = 0;
	}
}
int findMin(vector<int> d, vector<bool> confirmed){
	int min = INF,minIndex = -1;
	for(int i = 1; i < d.size(); i++){
		if(!confirmed[i] && d[i] < min){
			min = d[i];
			minIndex = i;
		}
	}
	return minIndex;
}
int findDijkstra(vector<Node*> AdjList, int start, int end){
	vector<int> d(AdjList.size(), INF);
	vector<bool> confirmed(AdjList.size(), false);
	d[start] = 0;
	// confirmed[start]=true;
	int i = AdjList.size()-1;
	while(i){
		int vertex = findMin(d, confirmed);
		// cout << "findMin return: " << vertex << endl;
		confirmed[vertex] = true;
		Node* List = AdjList[vertex];
		while(List != NULL){
			if(d[vertex]+List->w < d[List->vertex]){
				d[List->vertex] = d[vertex]+List->w;
			}
			List = List->next;
		}
		i--;
	}
	// cout << d << endl;
	return d[end];
}
vector<Node*> minSpanningTree(vector<Node*> AdjList){
	vector<int> d(AdjList.size(),  INF);
	vector<bool> confirmed(AdjList.size(), false);
	vector<Node*> Adj(AdjList.size(), NULL);
	d[1] = 0;
	int i = AdjList.size()-1;
	while(i){
		int vertex = findMin(d, confirmed);
		confirmed[vertex] = true;
		Node* list = AdjList[vertex];
		while(!isEmpty(list)){
			if(list->w < d[list->vertex]){
				d[list->vertex] = list->w;
				Adj[list->vertex] = getNewNode(vertex);
				Adj[list->vertex]->w = list->w;
			}
			list = list->next;
		}
		i--;
	}
	return Adj;
}
void printLinkedList(Node* head){
	while(head != NULL){
		cout << head->vertex << "(" << head->w << ") ";
		head =  head->next;
	}
}
void printAdjList(vector<Node*> v){
	for(int i = 0; i < v.size(); i++){
		cout << i << ": ";
		printLinkedList(v[i]);
		cout << endl;
	}
}
int main(){
	int V, E, v1, v2, w;
	cin >> V >> E;
	int start = 1,end = V;
	vector<Node*> v(V+1, NULL);
	for(int i = 1; i <= E; i++){
		cin >> v1 >> v2 >> w;
		v[v1] = insert(v[v1], v2, w);
		v[v2] = insert(v[v2], v1, w);
		// printAdjList(v);
	}
	printAdjList(v);
	printDFS(v, 1);
	printBFS(v, 1);
	cout << "Shortest path length from " << start << " to " << end
		 << " is: " << endl;
	cout << findDijkstra(v, 1, V) << endl;
	vector<Node*> Adj = minSpanningTree(v);
	cout << "Printing parent nodes in minimum spanning tree: \n";
	printAdjList(Adj);
	cout << "Weight of minimun spanning tree is: ";
	int sum = 0;
	for(int i = 2; i < Adj.size(); i++)sum += Adj[i]->w;
	cout << sum << endl;
	return 0;
}
// 4 6   1 2 1   1 3 4   1 4 7   2 3 2   2 4 6   3 4 3
   //      2
   //  2------3
   //  |\6   /|
   //  | \  / |
   // 1|  \/  |3
   //  |  /\  |
   //  | /  \ |
   //  |/4   \|
   //  1------4
   //      7