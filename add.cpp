#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	cin >> s1 >> s2;
	// cout << s1 << endl << s2 << endl;
	// cout << s1[0] << endl;
	int n1 = s1.size(),n2 = s2.size();
	int n = (n1 >= n2) ? n1 : n2;
	n = n+1;
	char s3[n];
	cout << " n1: " << n1 << " n2: " << n2 << " n: " << n << endl;
	int carry = 0,sum;
	// cout << "Hi" <<endl;
	for(int i = n; i >= 0; i--){
		if((i-n+n1-1) >= 0 && (i-n+n2-1) >= 0)
			//both strings are available
			sum = s1[i-n+n1-1]+s2[i-n+n2-1]+carry-'0'-'0';
		else if((i-n+n1-1) >= 0)
			sum = s1[i-n+n1-1]+carry-'0';
		else if((i-n+n2-1) >= 0)
			sum = s2[i-n+n2-1]+carry-'0';
		else sum = carry;
		// cout << sum << endl;
		s3[i] = '0'+(sum)%10;
		carry = sum/10;
	}
	// cout << "Hello" << endl;
	int flag = 0;
	for(int i = 0; i <= n; i++){
		if(s3[i] > '0' || i == n)flag = 1;
		if(flag == 1)cout << s3[i];
	}
	cout << endl;
	// cout << max(2,3);
	return 0;
}