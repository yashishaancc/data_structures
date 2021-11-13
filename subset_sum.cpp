#include<iostream>
#include<vector>
using namespace std;
bool isSubsetSum(int* arr, int n, int sum){
	if(sum < 0)return false;
	if(sum == 0)return true;
	if(n == 0)return false;
	if(arr[n-1] > sum)return isSubsetSum(arr, n-1, sum);
	return isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}
bool isSubsetSumTopBottomDP(vector<vector<int>> grid, int* arr, int n, int sum){
	if(sum < 0)return false;
	if(sum == 0){
		grid[sum][n] = 1;
		return true;
	}
	if(n == 0){
		grid[sum][n] = 0;
		return false;
	}
	if(arr[n-1] > sum){
		grid[sum][n] = (grid[sum][n-1] != -1) ? 
						grid[sum][n-1] : 
	 					(isSubsetSumTopBottomDP(grid, arr, n-1, sum)) ? 1 : 0;
	 	return (grid[sum][n]) ? true : false;
	}
	int excl = (grid[sum][n-1] != -1) ? grid[sum][n-1] : 
				(isSubsetSumTopBottomDP(grid, arr, n-1, sum)) ? 1 : 0;
	int incl = (grid[sum-arr[n-1]][n-1] != -1) ? grid[sum-arr[n-1]][n-1] : 
				(isSubsetSumTopBottomDP(grid, arr, n-1, sum-arr[n-1])) ? 1 : 0;
	return (incl || excl) ? true : false;
}
bool isSubsetSumDP(int* arr, int n, int sum){
	bool grid[sum+1][n+1];
	int i, j;
	for(i = 0; i <= sum; i++){
		for(j = 0; j <= n; j++){
			if(i == 0)grid[i][j] = true;
			else if(j == 0)grid[i][j] = false;
			else if(arr[j-1] > i)grid[i][j] = grid[i][j-1];
			else grid[i][j] = grid[i][j-1] || grid[i-arr[j-1]][j-1];
			printf("%3d", grid[i][j]);
		}
		cout << endl;
	}
	return grid[sum][n];
}
int main(){
	int i, n, sum;
	cout << "Enter sum(non -ve) to be found: ";
	cin >> sum;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter elements(non -ve) separated by a space:\n";
	for(i = 0; i < n; i++)cin >> arr[i];
	vector<vector<int>> grid(int(sum+1), vector<int>(n+1, -1));
	// bool is = isSubsetSum(arr, n, sum);
	// bool is = isSubsetSumTopBottomDP(grid, arr, n, sum);
	bool is = isSubsetSumDP(arr, n, sum);
	if(is)cout << "Sum " << sum << " is found\n";
	else cout << "Sum " << sum << " is not found\n";
	return 0;
}