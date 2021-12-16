#include<iostream>
using namespace std;
void print(int grid[][6]){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++)cout << grid[i][j] << " ";
		cout << endl;
	}
}
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
void solve2(int grid[][6], int tap[][6], int itr, int taps, int* cnt){
	if(itr == 36){
		int i, j, k, l, m, newgrid[6][6], c = 0, flag;
		for(i = 0; i < 6; i++)for(j = 0; j < 6; j++)newgrid[i][j] = grid[i][j];
		// cout << endl;
		// print(tap);
		for(k = 0; k < 6; k++){
			for(l = 0; l < 6; l++){
				if(tap[k][l]){
					newgrid[k][l] = newgrid[k][l] == 1 ? 0 : 1;
					for(i = 0; i < 6; i++)
						newgrid[i][l] = newgrid[i][l] == 1 ? 0 : 1;
					for(j = 0; j < 6; j++)
						newgrid[k][j] = newgrid[k][j] == 1 ? 0 : 1;
				}
			}
		}
		for(i = 0; i < 6; i++)for(j = 0; j < 6; j++)if(newgrid[i][j])c++;
		if(c == 36){
			(*cnt)++;
			cout << "solved\n";
			for(i = 0; i < 6; i++)
				for(j = 0; j < 6; j++)
					if(tap[i][j])cout << "Tap " << i+1 << " " << j+1 << endl;
		}
		return;
	}
	for(int i = 0; i <= 1; i++){
		tap[itr/6][itr%6] = i;
		if(i == 1)taps++;
		if(*cnt == 0 && taps <= 8 && taps >= 0)
			solve2(grid, tap, itr+1, taps, cnt);
	}
}
void solve3(int grid[][6], int tap[][6], int itr, int taps, int* cnt){
	if(itr == 36){
		int i, j, k, l, m, newgrid[6][6], c = 0, flag;
		for(i = 0; i < 6; i++)for(j = 0; j < 6; j++)newgrid[i][j] = grid[i][j];
		// cout << endl;
		// print(tap);
		for(k = 0; k < 6; k++){
			for(l = 0; l < 6; l++){
				if(tap[k][l]){
					newgrid[k][l] = newgrid[k][l] == 1 ? 0 : 1;
					i = k; j = l;
					while(i >= 0 && j >= 0){// north-west
						newgrid[i][j] = newgrid[i][j] == 1 ? 0 : 1;
						i--; j--;
					}
					i = k; j = l;
					while(i < 6 && j < 6){// south-east
						newgrid[i][j] = newgrid[i][j] == 1 ? 0 : 1;
						i++; j++;
					}
					i = k; j = l;
					while(i >= 0 && j < 6){// north-east
						newgrid[i][j] = newgrid[i][j] == 1 ? 0 : 1;
						i--; j++;
					}
					i = k; j = l;
					while(i < 6 && j >= 0){// south-west
						newgrid[i][j] = newgrid[i][j] == 1 ? 0 : 1;
						i++; j--;
					}
					// for(i = 0; i < 6; i++)
					// 	newgrid[i][l] = newgrid[i][l] == 1 ? 0 : 1;
					// for(j = 0; j < 6; j++)
					// 	newgrid[k][j] = newgrid[k][j] == 1 ? 0 : 1;
				}
			}
		}
		for(i = 0; i < 6; i++)for(j = 0; j < 6; j++)if(newgrid[i][j])c++;
		if(c == 36){
			(*cnt)++;
			cout << "solved\n";
			for(i = 0; i < 6; i++)
				for(j = 0; j < 6; j++)
					if(tap[i][j])cout << "Tap " << i+1 << " " << j+1 << endl;
		}
		return;
	}
	for(int i = 0; i <= 1; i++){
		tap[itr/6][itr%6] = i;
		if(i == 1)taps++;
		if(*cnt == 0 && taps <= 8 && taps >= 0)
			solve3(grid, tap, itr+1, taps, cnt);
	}
}
int main(){
	int i, j, n = 6, cnt = 0;
	int grid[6][6], arr[10000][2], g[10000][6][6], tap[6][6];
	cout << "Enter 6x6 grid(0 for green, 1 for yellow:\n";
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)cin >> grid[i][j];
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)g[0][i][j] = grid[i][j];
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)tap[i][j] = 0;
	// solve(grid, arr, g, 0, &cnt);
	// tap any finite number of coins and see if it works
	// every coin is tapped 0 or 1 times and then see if it works
	// easy levels can be solved in <= 8 taps
	solve2(grid, tap, 0, 0, &cnt);
	// solve3(grid, tap, 0, 0, &cnt);
	return 0;
}
// for solve 2

// 1 1 1 0 0 0
// 0 0 0 0 1 0
// 1 0 0 1 1 1
// 1 0 1 0 1 0
// 0 0 1 0 0 0
// 1 0 0 1 1 1

// 1 1 1 1 1 1
// 1 1 1 1 1 1
// 0 0 1 1 0 1
// 1 1 1 1 1 1
// 1 1 1 0 0 1
// 0 0 1 0 1 1

// 1 1 1 1 1 0
// 1 1 1 1 1 0
// 1 1 1 1 1 0
// 1 1 1 1 1 0
// 1 1 1 1 1 0
// 0 0 0 0 0 0

// for solve 3

// 0 1 1 0 0 1
// 0 1 1 1 1 0
// 0 0 0 0 0 1
// 0 1 0 1 1 1
// 1 1 0 1 1 0
// 1 0 1 0 0 0

// 0 1 1 1 1 1
// 1 0 1 1 1 1
// 1 1 0 1 1 1
// 1 1 1 0 1 1
// 1 1 1 1 0 1
// 1 1 1 1 1 0