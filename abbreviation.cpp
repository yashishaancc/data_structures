#include<iostream>
#include<string>
using namespace std;
string abbreviation(string a, string b) {
    int i = 0, j = 0, n1 = a.size(), n2 = b.size();
    bool grid[n1+1][n2+1];
    for(i = 0; i <= n1; i++){
        for(j = 0; j <= n2; j++){
            if(i == 0 && j == 0)grid[i][j] = true;
            else if(i == 0)grid[i][j] = false;
            else if(j == 0 && a[i] >= 'a' && a[i] <= 'z')
                grid[i][j] = grid[i-1][j];
            else if(j == 0)grid[i][j] = false;
            else if(a[i-1] == b[j-1])grid[i][j] = grid[i-1][j-1];
            else if(a[i-1] >= 'A' && a[i-1] <= 'Z')grid[i][j] = false;
            else if(a[i-1] >= 'a' && a[i-1] <= 'z' && a[i-1]+'A'-'a' == b[j-1])
                grid[i][j] = grid[i-1][j-1] || grid[i-1][j];
            else if(a[i-1] >= 'a' && a[i-1] <= 'z')grid[i][j] = grid[i-1][j];
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    if(grid[n1][n2])return "YES";
    return "NO";
}
int main(){
    string s1, s2;
    cout << "\x1b[33mEnter 1st string(a-z + A-Z): \x1b[0m";
    cin >> s1;
    cout << "\x1b[33mEnter 2nd string(A-Z): \x1b[0m";
    cin >> s2;
    string result = abbreviation(s1, s2);
    cout << "Answer of whether 1st string can be converted into 2nd string by: "
         << "\nCapitalize zero or more of 1st string's lowercase letters."
         << "\nDelete all of the remaining lowercase letters in 1st string "
         << "is: \n" << result << endl;
}