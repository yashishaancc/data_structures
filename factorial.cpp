#include<iostream>
#include<string>
using namespace std;
int main(){
	int n1;
	while(1){
		cout << "Enter number from 0 to 100000 "
			 << "whose factorial you want to find: ";
		cin >> n1;
		int counter, tmp, i, n = 5*n1;
		int a[n];
		a[0] = 1;
		counter = 0;
		// calculate n factorial
		for(;n1 >= 2; n1--){
			// multiply with n1 and store in a[] from counter to 0 index
			tmp = 0;
			for(i = 0; i <= counter; i++){
				tmp = a[i]*n1+tmp;
				a[i] = tmp%10;
				tmp = tmp/10;
			}
			// store carry in higher index positions in a[]
			while(tmp > 0){
				a[++counter] = tmp%10;
				tmp = tmp/10;
			}
			if(n1%10000 == 0)cout << "calculating at " << n1 << endl;
		}
		// print n1 factorial stored in a[]
		for(i = counter; i >=0; i--)cout << a[i];
		cout << endl;
	}
	return 0;
}