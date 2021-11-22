#include<iostream>
using namespace std;
int isValid(int i, int j, int n, int c[][4]){
	int k, l, c1 = 0, c2 = 0, k1 = 0, k2 = 0, cl1 = 0, cl2 = 0;
	for(k = 0; k < 4; k++){
		if(c[i][k] != 0){
			if(cl1 == 0)cl1 = c[i][k];
			if(c[i][k] == cl1)k1++;
			else cl1 = -1;
			c1++;
		}
		if(c[j][k] != 0){
			if(cl2 == 0)cl2 = c[j][k];
			if(c[j][k] == cl2)k2++;
			else cl2 = -1;
			c2++;
		}
	}
	if(c1 == 0 || c2 == 4)return 0;
	if(4-c2 >= k1 && ((c2 == 0 && k1 != c1) || 
	  (c2 != 0 && c[i][4-c1] == c[j][4-c2]))){
		int a = c[i][4-c1];
		for(k = 0; k < k1; k++){
			c[i][4-c1+k] = 0;
			c[j][4-c2-k-1] = a;
		}
		return 1;
	}
	return 0;
}
void print(int n, int c[][4], int arr[][2], int id, int* cnt){
	int i, j, t, co = 0;
	for(i = 0; i < n; i++){
		t = 0;
		for(j = 0; j < 4; j++){
			if(c[i][j] == c[i][0])t++;
		}
		if(t == 4)co++;
	}
	if(co == n){
		(*cnt)++;
		cout << "solved\n";
		cout << id << " steps:" << endl;
		for(i = 0; i < id; i++){
			cout << i+1 << "--->\tMove water from " << arr[i][0]+1 
				 << " to " << arr[i][1]+1 << endl;
		}
	}
}
void solve(int n, int c[][4], int arr[][2], int id, int* cnt){
	int i,j,k,l,count = 0,ccopy[n][4];
	for(k = 0; k < n; k++)for(l = 0; l < 4; l++)ccopy[k][l] = c[k][l];
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(j != i && isValid(i, j, n, ccopy)){
				arr[id][0] = i;
				arr[id][1] = j;
				count++;
				if((*cnt) == 0)
					solve(n, ccopy, arr, id+1, cnt);
			}
			for(k = 0; k < n; k++)for(l = 0; l < 4; l++)ccopy[k][l] = c[k][l];
		}
	}
	if(count == 0 && (*cnt) == 0)
	// if(count == 0)
		print(n, c, arr, id, cnt);
}
int main(){
	int i, j, n;
	cout << "Enter number of tubes: ";
	cin >> n;
	int c[n][4], arr[100][2];
	for(i = 0; i < 100; i++){
		arr[i][0] = 0;
		arr[i][1] = 0;
	}
	cout << "Enter colours(Enter 0 for empty colour):\n";
	for(i = 0; i < n; i++){
		for(j = 0; j < 4; j++){
			cin >> c[i][j];
		}
	}
	int* cnt = (int*)malloc(sizeof(int));
	*cnt = 0;
	solve(n, c, arr, 0, cnt);
	return 0;
}
// 11
// 1 2 3 4
// 5 3 2 1
// 6 7 8 6
// 4 7 4 5
// 1 4 9 8
// 6 9 7 1
// 8 3 6 8
// 3 2 2 5
// 5 9 9 7
// 0 0 0 0
// 0 0 0 0

// 14
// 1 1 2 3
// 4 5 6 7
// 8 7 8 9
// 2 9 10 10
// 4 8 6 11
// 12 6 5 11
// 11 4 8 9 
// 2 12 10 10
// 7 5 3 3
// 5 7 11 3
// 4 12 12 9 
// 6 1 2 1
// 0 0 0 0
// 0 0 0 0

// 11
// 1 2 3 2
// 4 5 3 1
// 6 7 8 5
// 7 3 9 2
// 8 7 6 4
// 6 1 7 9
// 6 2 8 4
// 9 4 1 8
// 5 9 3 5
// 0 0 0 0
// 0 0 0 0