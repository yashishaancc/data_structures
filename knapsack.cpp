#include<iostream>
#include<vector>
using namespace std;
int main(){
	int i, j, n, w;
	cout << "Enter total number of items: ";
	cin >> n;
	cout << "Enter maximum weight capacity: ";
	cin >> w;
	int wtval[n][2];
	cout << "Enter all items weight and their value:\n";
	for(i = 0; i < n; i++)cin >> wtval[i][0] >> wtval[i][1];
	int grid[n][w+1];
	for(i = 0; i < n; i++){
		for(j = 0; j <= w; j++){
			if(wtval[i][0] > j){
				if(i == 0)grid[i][j] = 0;
				else grid[i][j] = grid[i-1][j];
			}
			else{
				if(i == 0)grid[i][j] = wtval[i][1];
				else{
					int selected = wtval[i][1]+grid[i-1][j-wtval[i][0]];
					grid[i][j] = max(grid[i-1][j], selected);
				}
			}
		}
	}
	// cout << i << " " << j << endl;
	i--; j--;
	vector<int> picked;
	while(j){
		if(i == 0){
			if(grid[i][j] == 0)j = 0;
			else{
				picked.push_back(i);
				j = 0;
			}
		}
		else if(grid[i][j] == grid[i-1][j])i--;
		else{
			picked.push_back(i);
			j = j-wtval[i][0];
			i--;
		}
	}
	cout << "Items picked are:\n";
	cout << "Weight\tValue\n";
	for(i = picked.size()-1; i >= 0; i--)
		cout << wtval[picked[i]][0] << "\t" << wtval[picked[i]][1] << endl;
	cout << "Max value that can be stolen is: " << grid[n-1][w] << endl;
	return 0;
}