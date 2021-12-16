#include<iostream>
#include<cstring>
// #include<graphics.h>
using namespace std;
void print(int l, int m, int n, int* grid){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < n; k++)cout << grid[i*m*n+j*n+k] << " ";
			cout << endl;
		}
		cout << endl;
	}
}
int main(){
	int i, j, k, l, m, n;
	cout << "Enter dimensions of 3d array: ";
	cin >> l >> m >> n;
	// int** grid = (int**)malloc(m*sizeof(int*));
	// for(i = 0; i < m; i++){
	// 	grid[i] = (int*)malloc(n*sizeof(int));
	// 	for(j = 0; j < n; j++)grid[i][j] = i;
	// }
	// int** newgrid = (int**)malloc(m*sizeof(int*));
	// for(i = 0; i < m; i++){
	// 	newgrid[i] = (int*)malloc(n*sizeof(int));
	// 	memcpy(newgrid[i], grid[i], m*sizeof(int));
	// }
	// print(m, n, grid);
	// print(m, n, newgrid);
	// int* grid = (int*)malloc(m*n*sizeof(int));
	// for(int i = 0; i < m; i++){
	// 	for(int j = 0; j < n; j++){
	// 		grid[i*n+j] = i;
	// 	}
	// }
	// int* newgrid = (int*)malloc(m*n*sizeof(int));
	// memcpy(newgrid, grid, m*n*sizeof(int));
	// print(m, n, grid);
	// print(m, n, newgrid);
	int* grid = (int*)malloc(l*m*n*sizeof(int));
	for(i = 0; i < l; i++)
		for(j = 0; j < m; j++)
			for(k = 0; k < n; k++)
				grid[i*m*n+j*n+k] = i;
	int* newgrid = (int*)malloc(l*m*n*sizeof(int));
	memcpy(newgrid, grid, l*m*n*sizeof(int));
	print(l, m, n, grid);
	print(l, m, n, newgrid);
	return 0;
}