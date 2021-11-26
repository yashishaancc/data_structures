#include<iostream>
using namespace std;
void solve(int grid[][6], int arr[][2], int g[][6][6], int itr, int* cnt){
	cout << itr << endl;
	int i, j, k, l, m, newgrid[6][6], c = 0, flag;
	for(i = 0; i < 6; i++)for(j = 0; j < 6; j++)newgrid[i][j] = grid[i][j];
	for(k = 0; k < 6; k++)for(l = 0; l < 6; l++)if(grid[k][l])c++;
	if(c == 36){
		(*cnt)++;
		cout << "solved\n" << itr << " steps:\n";
		for(i = 0; i < itr; i++)
			cout << i+1 << "-->\t" << "Click "
				 << arr[i][0]+1 << " " << arr[i][1]+1 << endl;
	}
	for(k = 0; k < 6; k++){
		for(l = 0; l < 6; l++){
			newgrid[k][l] = newgrid[k][l] == 1 ? 0 : 1;
			for(i = 0; i < 6; i++)newgrid[i][l] = newgrid[i][l] == 1 ? 0 : 1;
			for(j = 0; j < 6; j++)newgrid[k][j] = newgrid[k][j] == 1 ? 0 : 1;
			c = 0; flag = 0;
			for(m = 0; m <= itr; m++){
				c = 0;
				for(i = 0; i < 6; i++)
					for(j = 0; j < 6; j++)
						if(newgrid[i][j] == g[m][i][j])c++;
				if(c == 36){
					flag = 1;
					break;
				}
			}
			arr[itr][0] = k; arr[itr][1] = l;
			for(i = 0; i < 6; i++)
				for(j = 0; j < 6; j++)
					g[itr+1][i][j] = grid[i][j];
			if((*cnt) == 0 && flag == 0)
				solve(newgrid, arr, g, itr+1, cnt);
			for(i = 0; i < 6; i++)
				for(j = 0; j < 6; j++)
					newgrid[i][j] = grid[i][j];
		}
	}
}
int main(){
	int i, j, n = 6, cnt = 0;
	int grid[6][6], arr[10000][2], g[10000][6][6];
	cout << "Enter 6x6 grid(0 for green, 1 for yellow:\n";
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)cin >> grid[i][j];
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)g[0][i][j] = grid[i][j];
	solve(grid, arr, g, 0, &cnt);
	return 0;
}
// 1 1 1 0 0 0
// 0 0 0 0 1 0
// 1 0 0 1 1 1
// 1 0 1 0 1 0
// 0 0 1 0 0 0
// 1 0 0 1 1 1