#include<iostream>
using namespace std;
int main(){
	int i, j, n = 20;
	cout << "First 21 terms (0 to 20 index) of fibonacci series are following: "
		 << endl;
	long arr[n];
	arr[0] = 0;
	arr[1] = 1;
	for(i = 2; i <= n; i++)arr[i] = arr[i-1]+arr[i-2];
	for(i = 0; i <= n; i++)cout << i << "\t21: " << arr[i] << endl;
	cout << endl;
	while(1){
		cout << "Enter index from 0 to 100000 in fibonacci series"
			 <<	"at which you want to find the fibonacci number: ";
		cin >> n;
		int a[n+1], b[n+1], c[n+1];
		for(i = 0; i <= n; i++)a[i] = 0;
		for(i = 0; i <= n; i++)b[i] = 0;
		for(i = 0; i <= n; i++)c[i] = 0;
		b[n] = 1;
		int counter = n;
		for(i = 2; i <= n; i++){
			int carry = 0;
			for(j = n; j >= counter-1 && j >= 0; j--){
				c[j] = (a[j]+b[j]+carry)%10;
				if(j == counter-1 && c[j] > 0)counter--;
				carry = (a[j]+b[j]+carry)/10;
			}
			for(j = n; j >= counter-1 && j >= 0; j--){
				a[j] = b[j];
				b[j] = c[j];
			}
		}
		if(n == 0)cout << 0 << endl;
		else if(n == 1)cout << 1 << endl;
		else if(n >= 2){
			int f = 0;
			for(i = 0; i <= n; i++){
				if(c[i] > 0)f = 1;
				if(f == 1)cout << c[i];
			}
			cout << endl;
		}
	}
	return 0;
}