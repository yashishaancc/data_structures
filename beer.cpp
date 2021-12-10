#include<iostream>
using namespace std;
typedef struct state{
	int* water;
}State;
typedef struct node{
	State* state;
	struct node* next;
}Node;
int desired, jugs, n = 1;
int* cap;
int* filled;
bool* visited;
int* movement;
State** parents;
State* getNewState(int* filled){
	State* state = (State*)malloc(sizeof(State));
	state->water = (int*)malloc(jugs*sizeof(int));
	for(int i = 0; i < jugs; i++)state->water[i] = filled[i];
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
Node* popQueue(Node* head){
	if(head == NULL) return NULL;
	Node* next = head->next;
	free(head);
	head = next;
	return head;
}
Node* pushStack(Node* head, State* state){
	if(head == NULL){
		Node* Head = getNewNode(state);
		return Head;
	}
	Node* node = getNewNode(state);
	node->next = head;
	head = node;
	return head;
}
Node* popStack(Node* head){
	if(head == NULL)return head;
	Node* temp = head;
	head = head->next;
	free(temp);
	return head;
}
void print(State* state){
	for(int i = 0; i < jugs; i++){
		cout << state->water[i] << "\t";
	}
	cout << endl;
}
void print(Node* node){
	while(node != NULL){
		print(node->state);
		node = node->next;
	}
}
void print(int arr[][2], int grid[][100], int jugs, int itr){
	cout << "solved\n";
	cout << itr << " steps:\t\t\tjug1\tjug2\tjug3" << endl;
	for(int i = 0; i < itr; i++){
		cout << i+1 << "--->\tMove beer from " << arr[i][0]+1
			 << " to " << arr[i][1]+1;
		for(int k = 0; k < jugs; k++)cout << "\t" << grid[k][i+1];
		cout << endl;
	}
}
int is_valid(int jugs, int i, int j, int* cap, int* filled){
	if(filled[i] == 0)return 0;
	if(filled[j] == cap[j])return 0;
	if(filled[j]+filled[i] <= cap[j]){
		filled[j] = filled[i]+filled[j];
		filled[i] = 0;
		return 1;
	}
	else{
		int tmp = filled[j];
		filled[j] = cap[j];
		filled[i] -= cap[j]-tmp;
		return 1;
	}
	return 0;
}
State* isValid(State* state, int jugs, int i, int j, int* cap){
	for(int k = 0; k < jugs; k++)filled[k] = state->water[k];
	if(filled[i] == 0)return NULL;
	if(filled[j] == cap[j])return NULL;
	if(filled[j]+filled[i] <= cap[j]){
		filled[j] = filled[i]+filled[j];
		filled[i] = 0;
		State* state = getNewState(filled);
		return state;
	}
	else{
		int tmp = filled[j];
		filled[j] = cap[j];
		filled[i] -= cap[j]-tmp;
		State* state = getNewState(filled);
		return state;
	}
	return NULL;
}
int idx_to_int(int* a){
	int i, x = 0;
	for(i = 0; i < jugs; i++)x = x*(cap[i]+1)+a[i];
	return x;
}
int idx_to_int(State* state){
	int i, x = 0;
	for(i = 0; i < jugs; i++)x = x*(cap[i]+1)+state->water[i];
	return x;
}
int* int_to_idx(int x){
	int* a = (int*)malloc(jugs*sizeof(int));
	for(int i = jugs-1; i >= 0; i--){
		a[i] = x%(cap[i]+1);
		x /= (cap[i]+1);
	}
	return a;
}
Node* allValidUnvisitedNeighbours(State* state, int jugs, int* cap){
	int i, j;
	Node* head, *tail;
	head = NULL; tail = NULL;
	for(i = 0; i < jugs; i++){
		for(j = 0; j < jugs; j++){
			if(i != j){
				State* next_state = isValid(state, jugs, i, j, cap);
				if(next_state == NULL)continue;
				int offset = idx_to_int(next_state);
				if(visited[offset])continue;
				visited[offset] = true;
				parents[offset] = state;
				movement[offset] = i*jugs+j;
				if(head == NULL){
					tail = pushQueue(tail, next_state);
					head = tail;
				}
				else{
					tail = pushQueue(tail, next_state);
				}
			}
		}
	}
	Node* tmp = head;
	// cout << "allValidUnvisitedNeighbours returning:" << endl;
	// cout<< "curr_state: "; print(state);
	// cout << "Next states:" << endl;
	// while(tmp != NULL){
	// 	print(tmp->state);
		// cout << "parent: ";
		// print(parents[idx_to_int(tmp->state)]);
	// 	tmp = tmp->next;
	// }
	// cout << endl;
	return head;
}
bool is_destination(State* state){
	for(int i = 0; i < jugs; i++){
		if(state->water[i] == desired)return true;
	}
	return false;
}
void BFS(State *start_state, int jugs, int* cap){
	for(int i = 0; i < n; i++)visited[i] = false;
	for(int i = 0; i < n; i++)parents[i] = NULL;
	for(int i = 0; i < n; i++)movement[i] = 0;
	Node* head = NULL;
	Node* tail = NULL;
	tail = pushQueue(tail, start_state);
	head = tail;
	visited[idx_to_int(start_state)] = true;
	cout << "Solving using BFS:\n";
	while(head != NULL){
		Node* new_head = NULL;
		Node* new_tail = NULL;
		while(head != NULL){
			// cout << "printing head linked list: " << endl;
			// print(head);
			State* curr_state = head->state;
			head = popQueue(head);
			// head = head->next;
			// cout << "printing after pop head: \n";
			// print(head);
			// all neighbour of curr_state
			Node* neighbours = allValidUnvisitedNeighbours(curr_state, 
				jugs, cap);
			// cout << "printing after Neighbour head: \n";
			// print(head);
			while(neighbours != NULL){
				// cout << "printing neighbour head: \n";
				// print(head);
				// cout << "printing neighbours: ";
				// print(neighbours->state);
				if(is_destination(neighbours->state)){
					State* curr_state = neighbours->state;
					State* parent_state = curr_state;
					int c1 = 0, c2 = 0;
					Node* Head = NULL;
					while (parent_state != NULL){
						Head = pushStack(Head, parent_state);
						parent_state = parents[idx_to_int(parent_state)];
						c1++;
					}
					cout << "solved\n";
					cout << c1-1 << " steps:\t\t\tjug1\tjug2\tjug3\n";
					while(Head != NULL){
						State* child_state = Head->state;
						Head = popStack(Head);
						cout << c2 << "--->\tMove beer from "
							 << movement[idx_to_int(child_state)]/jugs+1
							 << " to "
							 << movement[idx_to_int(child_state)]%jugs+1
							 << "\t";
						print(child_state);
						c2++;
					}
					// print and return whatever needed
					return;
				}
				if(new_tail == NULL){
					new_tail = pushQueue(new_tail, neighbours->state);
					new_head = new_tail;
				}else{
					new_tail = pushQueue(new_tail, neighbours->state);
				}
				// cout << "printing new_head linked list: " << endl;
				// print(new_head);
				// cout << "printing Head: \n";
				// print(head);
				neighbours = neighbours->next;
			}
		}
		head = new_head;
		tail = new_tail;
	}
}
void solve(int desired, int jugs, int* cap, int* filled, int itr, int arr[][2], 
	int grid[][100], int* cnt){
	int i, j, k, l, filledcopy[jugs];
	for(i = 0; i < jugs; i++)filledcopy[i] = filled[i];
	for(i = 0; i < jugs; i++){
		if(filled[i] == desired){
			(*cnt)++;
			print(arr, grid, jugs, itr);
			break;
		}
	}
	for(i = 0; i < jugs; i++){
		for(j = 0; j < jugs; j++){
			if(i != j && is_valid(jugs, i, j, cap, filledcopy)){
				arr[itr][0] = i; arr[itr][1] = j;
				int flag = 1, c;
				for(k = 0; k <= itr; k++){
					c = 0;
					for(l = 0; l < jugs; l++)if(grid[l][k] == filledcopy[l])c++;
					if(c == jugs){
						flag = 0;
						break;
					}
				}
				if(flag && itr <= 12 && (*cnt) == 0){
					for(k = 0; k < jugs; k++)grid[k][itr+1] = filledcopy[k];
					solve(desired, jugs, cap, filledcopy, itr+1, arr, grid,
					 	cnt);
				}
			}
			for(k = 0; k < jugs; k++)filledcopy[k] = filled[k];
		}
	}
}
int main(){
	int i;
	cout << "Enter desired amount of beer(in l): ";
	cin >> desired;
	cout << "Enter number of jugs: ";
	cin >> jugs;
	cap = (int*)malloc(jugs*sizeof(int));
	filled = (int*)malloc(jugs*sizeof(int));
	int arr[1000][2], grid[jugs][100];
	cout << "Enter capacity of " << jugs << " jugs separated by a space: ";
	for(i = 0; i < jugs; i++)cin >> cap[i];
	cout << "Enter beer(in l) present in each jug: ";
	for(i = 0; i < jugs; i++)cin >> filled[i];
	for(i = 0; i < jugs; i++)grid[i][0] = filled[i];
	for(i = 0; i < jugs; i++)n *= cap[i]+1;
	visited = (bool*)malloc(n*sizeof(bool));
	movement = (int*)malloc(n*sizeof(int));
	parents = (State**)malloc(n*sizeof(State*));
	int cnt = 0;
	solve(desired, jugs, cap, filled, 0, arr, grid, &cnt);
	State* start_state = getNewState(filled);
	BFS(start_state, jugs, cap);
	return 0;
}
// 8   3   16 11 6   16 0 0

// 4   3   8 5 3   8 0 0

// 8   4   24 13 11 5   24 0 0 0