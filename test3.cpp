#include<iostream>
using namespace std;
int jugs = 4;
int cap[] = {16,11,6};
int idx_to_int(int* a){
	int i, x = 0;
	for(i = 0; i < jugs; i++)x = x*(cap[i]+1)+a[i];
	return x;
}
int* int_to_idx(int x){
	int* a = (int*)malloc(jugs*sizeof(int));
	for(int i = jugs-1; i >= 0; i--){
		a[i] = x%(cap[i]+1);
		x /= (cap[i]+1);
	}
	return a;
}
int main(){
	jugs = 3;
	int a[] = {1,2,3};
	int x = 100;
	cout << idx_to_int(a) << endl;
	int* r = int_to_idx(x);
	for(int i = 0; i < jugs; i++)cout << r[i] << " ";
	cout << endl;
	return 0;
}