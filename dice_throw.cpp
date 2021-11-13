#include<iostream>
using namespace std;
int numberOfWays(int n, int m, int sum){
	if(sum < 0)return 0;
	if(sum == 0 && n == 0)return 1;
	if(n == 0)return 0;
	int i, count = 0;
	for(i = 1; i <= m; i++){
		count += numberOfWays(n-1, m, sum-i);
	}
	return count;
}
int numberOfWaysDP(int n, int m, int sum){
	int i, j, k, grid[n+1][sum+1];
	for(i = 0; i <= n; i++){
		for(j = 0; j <= sum; j++){
			if(i == 0 && j == 0)grid[i][j] = 1;
			else if(i == 0 || j == 0)grid[i][j] = 0;
			else{
				grid[i][j] = 0;
				for(k = 1; k <= m && j-k >= 0; k++){
					grid[i][j] += grid[i-1][j-k];
				}
			}
		}
	}
	return grid[n][sum];
}
int main(){
	int n, m, sum;
	cout << "Enter number of dice: ";
	cin >> n;
	cout << "Enter number of faces on one die: ";
	cin >> m;
	cout << "Enter sum whose number of ways to get need to be found: ";
	cin >> sum;
	// int ways = numberOfWays(n, m, sum);
	int ways = numberOfWaysDP(n, m, sum);
	cout << "Number of ways to find " << sum << " on " << n << " dice are " 
		 << ways << endl;
	return 0;
}