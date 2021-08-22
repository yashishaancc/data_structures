#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printVector(vector<int> vec){
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << ", ";
	}
	cout << endl;
}
int main(){
	int arr[] = {1, 2, 3, 4, 5};
	vector<int> v{1, 2, 3, 4};
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	printVector(v);
	return 0;
}