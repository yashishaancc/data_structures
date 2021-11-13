#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string s1, s2;
	cout << "Enter 1st string: ";
	cin >> s1;
	cout << "Enter 2nd string: ";
	cin >> s2;									
	// cout << s1 << endl << s2 << endl;
	int i, j, n1 = s1.size(), n2 = s2.size();
	int grid[n1+1][n2+1];
	for(i = 0; i <= n1; i++)grid[i][0] = 0;
	for(i = 0; i <= n2; i++)grid[0][i] = 0;
	for(i = 1; i <= n1; i++){
		for(j = 1; j <= n2; j++){
			if(s1[i-1] == s2[j-1])grid[i][j] = grid[i-1][j-1]+1;
			else grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
		}
	}
	vector<char> s;
	// cout << i << " " << j << endl;
	i--; j--;
	while(i && j){
		if(s1[i-1] == s2[j-1]){
			s.push_back(s1[i-1]);
			i--; j--;
		}
		else{
			if(grid[i][j] == grid[i-1][j])i--;
			if(grid[i][j] == grid[i][j-1])j--;
		}
	}
	cout << "Longest common subsequence is: ";
	for(i = s.size()-1; i >= 0; i--)cout << s[i];
	cout << endl;
	cout << "Length of longest common subsequence is: "
		 << grid[n1][n2] << endl;
	return 0;
}