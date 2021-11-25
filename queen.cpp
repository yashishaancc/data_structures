#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
void print(int n, int** grid){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)cout << grid[i][j] << " ";
		cout << endl;
	}
}
bool isValid(int n, int** grid, int c, int j){
	for(int i = 0; i < c; i++)if(grid[i][j] == 1)return false;
	for(int i = c-1, k = j-1; i >= 0 && k >= 0; i--, k--)
		if(grid[i][k] == 1)return false;
	for(int i = c-1, k = j+1; i >= 0 && k < n; i--, k++)
		if(grid[i][k] == 1)return false;
	return true;
}
void solve(int n, int** grid, int c, int* cnt){
	int i, j, k;
	int** newgrid = (int**)malloc(n*sizeof(int*));
	for(i = 0; i < n; i++)newgrid[i] = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)newgrid[i][j] = grid[i][j];
	for(j = 0; j < n; j++){
		if((*cnt) == 0 && c < n && isValid(n, newgrid, c, j)){
			newgrid[c][j] = 1;
			solve(n, newgrid, c+1, cnt);
		}
		for(i = 0; i < n; i++)for(k = 0; k < n; k++)newgrid[i][k] = grid[i][k];
	}
	if(c == n){
		(*cnt)++;
		cout << "Solved: " << endl;
		print(n, grid);
	}
}
int main(int argc, char *argv[]){
	int i, j, n = 8, cnt = 0;
	// n = strtol(argv[1], nullptr, 0);
	cout << "Enter side length of square board: ";
	cin >> n;
	int** grid = (int**)malloc(n*sizeof(int*));
	for(i = 0; i < n; i++)grid[i] = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)grid[i][j] = 0;
	auto start = high_resolution_clock::now();
	solve(n, grid, 0, &cnt);
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << n << " \x1b[33mTime taken by function: \x1b[0;34m"
    	 << duration.count() << " microseconds\x1b[0m" << endl;
	return 0;
}