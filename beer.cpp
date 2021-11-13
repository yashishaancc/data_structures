#include<iostream>
using namespace std;
typedef struct state{
	int water[10];
	bool visited;
}State;
typedef struct node{
	State* state;
	struct node* next;
}Node;
State* getNewState(int* fill, int jugs){
	State* state = (State*)malloc(sizeof(State));
	state->visited = false;
	for(int i = 0; i < jugs; i++)state->water[i] = fill[i];
	return state;
}
Node* getNewNode(State* state){
	Node* node = (Node*)malloc(sizeof(Node));
	node->state = state;
	node->next = NULL;
	return node;
}
Node* pushQueue(Node* tail, State* state){
	if(tail == NULL){
		tail = getNewNode(state);
		return tail;
	}
	Node* node = getNewNode(state);
	tail->next = node;
	tail = node;
	return tail;
}
int isValid(int jugs, int i, int j, int* cap, int* fill){
	if(fill[i] == 0)return 0;
	if(fill[j] == cap[j])return 0;
	if(fill[j] + fill[i] <= cap[j]){
		fill[j] = fill[i]+fill[j];
		fill[i] = 0;
		return 1;
	}
	else{
		int tmp = fill[j];
		fill[j] = cap[j];
		fill[i] -= cap[j]-tmp;
		return 1;
	}
}

void BFS(State *start_state){
	//step 1: push all unvisited, valid next states to queue
	// while queue is not empty
		// pop, new queue, repeat step 1
		// if you reach a destination state, end.
}
void solve(int desired, int jugs, int* cap, int* fill, int itr, int arr[][2]){
	int i, j, k, fillcopy[jugs];
	for(i = 0; i < jugs; i++)fillcopy[i] = fill[i];
	for(i = 0; i < jugs; i++){
		if(fill[i] == desired){
			cout << "solved\n";
			cout << itr << " steps:" << endl;
			for(i = 0; i < itr; i++){
				cout << "Move water from " << arr[i][0]+1
					 << " to " << arr[i][1]+1 
					 << endl;
			}
			break;
		}
	}
	for(i = 0; i < jugs; i++){
		for(j = 0; j < jugs; j++){
			if(i != j && isValid(jugs, i, j, cap, fillcopy)){
				for(k = 0; k < jugs; k++)cout << fillcopy[k] << "\t";
				cout << endl;
				arr[itr][0] = i; arr[itr][1] = j;
				State* state = getNewState(fillcopy, jugs);
				Node* head, *tail;
				if(head == NULL){
					tail = pushQueue(tail, state);
					head = tail;
				}
				else{
					tail = pushQueue(tail, state);	
				}
				// solve(desired, jugs, cap, fillcopy, itr+1, arr);
			}
			for(k = 0; k < jugs; k++)fillcopy[k] = fill[k];
		}
	}
}
int main(){
	int i, desired, jugs;
	cout << "Enter desired amount of water(in l): ";
	cin >> desired;
	cout << "Enter number of jugs: ";
	cin >> jugs;
	int cap[jugs], fill[jugs], arr[1000][2];
	cout << "Enter capacity of " << jugs << " jugs separated by a space: ";
	for(i = 0; i < jugs; i++)cin >> cap[i];
	cout << "Enter beer(in l) present in each jug: ";
	for(i = 0; i < jugs; i++)cin >> fill[i];
	solve(desired, jugs, cap, fill, 0, arr);
	return 0;
}