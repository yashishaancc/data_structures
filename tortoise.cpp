#include<iostream>
using namespace std;
void print(int* arr, int itr){
	cout << "Solved\n" << itr << " steps:\n";
	for(int i = 0; i < itr; i++){
		cout << "Move ";
		if(arr[i] == 1)cout << "up";
		if(arr[i] == 2)cout << "right";
		if(arr[i] == 3)cout << "down";
		if(arr[i] == 4)cout << "left";
		cout << endl;
	}
}
void solve(int grid[][7], int* arr, int direction, int x, int y, int c,
	int itr){
	int i, j, k, l, newgrid[7][7];
	for(k = 0; k < 7; k++)for(l = 0; l < 7; l++)newgrid[k][l] = grid[k][l];
	j = y;
	for(i = x-1; i >= 0 && direction != 3; i--){
		if(newgrid[i][j]){
			newgrid[x][y] = 0;
			arr[itr] = 1;
			solve(newgrid, arr, 1, i, j, c-1, itr+1);
			break;
		}
	}
	for(k = 0; k < 7; k++)for(l = 0; l < 7; l++)newgrid[k][l] = grid[k][l];
	for(i = x+1; i < 7 && direction != 1; i++){
		if(newgrid[i][j]){
			newgrid[x][y] = 0;
			arr[itr] = 3;
			solve(newgrid, arr, 3, i, j, c-1, itr+1);
			break;
		}
	}
	for(k = 0; k < 7; k++)for(l = 0; l < 7; l++)newgrid[k][l] = grid[k][l];
	i = x;
	for(j = y-1; j >= 0 && direction != 2; j--){
		if(newgrid[i][j]){
			newgrid[x][y] = 0;
			arr[itr] = 4;
			solve(newgrid, arr, 4, i, j, c-1, itr+1);
			break;
		}
	}
	for(k = 0; k < 7; k++)for(l = 0; l < 7; l++)newgrid[k][l] = grid[k][l];
	for(j = y+1; j < 7 && direction != 4; j++){
		if(newgrid[i][j]){
			newgrid[x][y] = 0;
			arr[itr] = 2;
			solve(newgrid, arr, 2, i, j, c-1, itr+1);
			break;
		}
	}
	if(c == 1)print(arr, itr);
}
int main(){
	int grid[7][7] = {{0,0,0,1,1,0,0},
					  {0,0,0,1,1,0,0},
					  {1,1,1,0,0,1,1},
					  {0,1,0,1,0,0,0},
					  {0,1,0,0,1,1,1},
					  {0,0,1,0,0,1,1},
					  {0,0,1,1,0,1,0}};
	int arr[100];
	solve(grid, arr, 4, 3, 3, 21, 0);
	return 0;
}