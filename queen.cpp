#include<iostream>
using namespace std;
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
int main(){
	int i, j, n = 8, cnt = 0;
	cout << "Enter side length of square board: ";
	cin >> n;
	int** grid = (int**)malloc(n*sizeof(int*));
	for(i = 0; i < n; i++)grid[i] = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)grid[i][j] = 0;
	solve(n, grid, 0, &cnt);
	return 0;
}