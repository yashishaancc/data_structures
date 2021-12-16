#include<iostream>
using namespace std;
void partition(int* str, int n, int len, int min, int* c){
	if(n == 0){
		for(int i = 0; i < len; i++){
			cout << str[i];
			if(i < len-1)cout << "+";
		}
		cout << endl;
		(*c)++;
		return;
	}
	for(int i = min; i <= n; i++){
		str[len] = i;
		partition(str, n-i, len+1, i, c);
	}
}
int main(){
	int n;
	cout << "Enter a number(0 to 100) to find partitions: ";
	cin >> n;
	int str[n];
	int* c;
	*c = 0;
	partition(str, n, 0, 1, c);
	cout << "Number of partitions of " << n << " are " << *c << endl;
	return 0;
}