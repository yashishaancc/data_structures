#include<iostream>
using namespace std;
// typedef struct state{
// 	int water[3];
// }State;
// typedef struct node{
// 	State* state;
// 	struct node* next;
// }Node;
// State* getNewState(int* fill, int jugs){
// 	State* state = (State*)malloc(sizeof(State));
// 	// state->visited = false;
// 	for(int i = 0; i < jugs; i++)state->water[i] = fill[i];
// 	return state;
// }
// Node* getNewNode(State* state){
// 	Node* node = (Node*)malloc(sizeof(Node));
// 	node->state = state;
// 	node->next = NULL;
// 	return node;
// }
// Node* pushQueue(Node* tail, State* state){
// 	if(tail == NULL){
// 		tail = getNewNode(state);
// 		return tail;
// 	}
// 	Node* node = getNewNode(state);
// 	tail->next = node;
// 	tail = node;
// 	return tail;
// }
// Node* popQueue(Node* head){
// 	if(head==NULL) return NULL;
// 	Node* next = head->next;
// 	head = next;
// 	free(head);
// 	return head;
// }
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
// Node* allValidUnvisitedNeighbours(State* state, int jugs, int* cap,
// 	int* fillcopy){
// 	// all mark them visited
// 	int i, j;
// 	Node* head, *tail;
// 	head = NULL; tail = NULL;
// 	for(i = 0; i < jugs; i++){
// 		for(j = 0; j < jugs; j++){
// 			if(i != j && isValid(jugs, i, j, cap, fillcopy)){
// 				// for(k = 0; k < jugs; k++)cout << fillcopy[k] << "\t";
// 				// cout << endl;
// 				// arr[itr][0] = i; arr[itr][1] = j;
// 				State* state = getNewState(fillcopy, jugs);
// 				if(head == NULL){
// 					tail = pushQueue(tail, state);
// 					head = tail;
// 				}
// 				else{
// 					tail = pushQueue(tail, state);	
// 				}
// 			}
// 		}
// 	}
// 	return head;
// }
// bool is_destination(State* state){
// 	return state->water[0] == 8;
// }
// void BFS(State *start_state, int jugs, int* cap, int* fill){
// 	bool visited[cap[0]+1][cap[1]+1][cap[2]+1];
// 	// initialize by false
// 	//step 1: push all unvisited, valid next states to queue
// 	Node* head = NULL;
// 	Node* tail = NULL;
// 	if(tail == NULL){
// 		head = pushQueue(tail, start_state);
// 		tail = head;
// 	}else{
// 		tail = pushQueue(tail, start_state);
// 	}
// 	int x = start_state->water[0];
// 	int y = start_state->water[1];
// 	int z = start_state->water[2];
// 	visited[x][y][z] = true;
// 	// while queue is not empty
// 		// pop, new queue, repeat step 1
// 		// if you reach a destination state, end.
// 	while(head != NULL){
// 		Node* new_head = NULL;
// 		Node* new_tail = NULL;
// 		while(head != NULL){
// 			State* curr_state = head->state;
// 			int x = start_state->water[0];
// 			int y = start_state->water[1];
// 			int z = start_state->water[2];
// 			head = popQueue(head);
// 			// all neighbour of curr_state
// 			Node* neighbours = allValidUnvisitedNeighbours(curr_state, 
// 				jugs, cap, fill);
// 			while(neighbours!=NULL){
// 				if(is_destination(neighbours->state)){
// 					// print and return whatever needed
// 				}
// 				if(tail == NULL){
// 					tail = pushQueue(new_tail, neighbours->state);
// 					head = tail;
// 				}else{
// 					tail = pushQueue(new_tail, neighbours->state);
// 				}
// 			}
// 		}
// 		head = new_head;
// 		tail = new_tail;
// 	}
// }
void solve(int desired, int jugs, int* cap, int* fill, int itr, int arr[][2], 
	int grid[][100], int* cnt){
	int i, j, k, l, fillcopy[jugs];
	for(i = 0; i < jugs; i++)fillcopy[i] = fill[i];
	for(i = 0; i < jugs; i++){
		if(fill[i] == desired){
			(*cnt)++;
			cout << "solved\n";
			cout << itr << " steps:\t\t\tjug1\tjug2\tjug3" << endl;
			for(i = 0; i < itr; i++){
				cout << i+1 << "--->\tMove beer from " << arr[i][0]+1
					 << " to " << arr[i][1]+1;
				for(k = 0; k < jugs; k++)cout << "\t" << grid[k][i+1];
				cout << endl;
			}
			break;
		}
	}
	// int c = 0;
	// for(i = 0; i < jugs; i++){
	// 	if(fill[i] == desired || fill[i] == 0)c++;
	// }
	// if(c == jugs){
	// 	(*cnt)++;
	// 	cout << "solved\n";
	// 	cout << itr << " steps:\t\t\tjug1\tjug2\tjug3" << endl;
	// 	for(i = 0; i < itr; i++){
	// 		cout << i+1 << "--->\tMove beer from " << arr[i][0]+1
	// 			 << " to " << arr[i][1]+1;
	// 		for(k = 0; k < jugs; k++)cout << "\t" << grid[k][i+1];
	// 		cout << endl;
	// 	}
	// 	// break;
	// }
	for(i = 0; i < jugs; i++){
		for(j = 0; j < jugs; j++){
			if(i != j && isValid(jugs, i, j, cap, fillcopy)){
				// for(k = 0; k < jugs; k++)cout << fillcopy[k] << "\t";
				// cout << endl;
				arr[itr][0] = i; arr[itr][1] = j;
				// State* state = getNewState(fillcopy, jugs);
				// Node* head, *tail;
				// if(head == NULL){
				// 	tail = pushQueue(tail, state);
				// 	head = tail;
				// }
				// else{
				// 	tail = pushQueue(tail, state);	
				// }
				int flag = 1, c;
				for(k = 0; k <= itr; k++){
					c = 0;
					for(l = 0; l < jugs; l++)if(grid[l][k] == fillcopy[l])c++;
					if(c == jugs){
						flag = 0;
						break;
					}
				}
				if(flag && itr <= 12 && (*cnt) == 0){
					for(k = 0; k < jugs; k++)grid[k][itr+1] = fillcopy[k];
					solve(desired, jugs, cap, fillcopy, itr+1, arr, grid, cnt);
				}
			}
			for(k = 0; k < jugs; k++)fillcopy[k] = fill[k];
		}
	}
}
int main(){
	int i, desired, jugs;
	cout << "Enter desired amount of beer(in l): ";
	cin >> desired;
	cout << "Enter number of jugs: ";
	cin >> jugs;
	int cap[jugs], fill[jugs], arr[1000][2], grid[jugs][100];
	cout << "Enter capacity of " << jugs << " jugs separated by a space: ";
	for(i = 0; i < jugs; i++)cin >> cap[i];
	cout << "Enter beer(in l) present in each jug: ";
	for(i = 0; i < jugs; i++)cin >> fill[i];
	for(i = 0; i < jugs; i++)grid[i][0] = fill[i];
	int cnt = 0;
	solve(desired, jugs, cap, fill, 0, arr, grid, &cnt);
	return 0;
}
// 8   3   16 11 6   16 0 0