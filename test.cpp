#include<iostream>
#include<string>
#include<vector>
using namespace std;
void fun(int a[]){
	a[0] = 5;
}
void funV(vector<int>* a){
	(*a)[0] = 5;
}
int main(){
	cout << "\x1b[31m#include\x1b[0m\x1b[33m<iostream>\x1b[0m" << endl;
	cout << "\x1b[31musing namespace \x1b[0mstd;" << endl;
	cout << "\x1b[36mint \x1b[0m\x1b[32mmain\x1b[0m(){" << endl;
	cout << "    cout << \x1b[33m\"Hello World!\" \x1b[0m<< endl;" << endl;
	cout << "    \x1b[31mreturn \x1b[0m\x1b[34m0\x1b[0m;" << endl;
	cout << "}" << endl;
	// goto end;
	// int a[3] = {1, 2, 3};
	// vector<int> v = {1, 2, 3};
	// fun(a);
	// funV(&v);
	// string s;
	// s[0] = 's';
	// int arr[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
	// printf("%.0f\n", 3.5);
	// end: cout << "end" << endl;
	// cout << **(arr+1)  << *(*arr+1) << endl;
	// cout << "a" << a[0] << endl;
	// cout << "v" << v[0] << endl;
	// cout << "-1%10 = " << -1%10 << " -1/10 = " << -1/10 << endl;
	// cout << "1%-10 = " << 1%-10 << " 1/-10 = " << 1/-10 << endl;
	// cout << "-1%-10 = " << -1%-10 << " -1/-10 = " << -1/-10 << endl;
	// cout << s << endl;
	// cout << "hello"        " ""world" << endl;
	// cout << "He\tllo" << endl;
	// cout << "\7";
	// cout << 7/int(3.99) << endl;
	// cout << 7/(int)3.999 << endl;
	return 0;
}