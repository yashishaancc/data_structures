#include<iostream>
using namespace std;
int a[] = {4,5,6};
void fun(int* a){
	*a = 3;
}
int main(){
	cout << a << endl;
	fun(a);
	cout << *a << endl;
	cout << sizeof(a) << endl;
}