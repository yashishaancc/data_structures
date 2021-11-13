#include<iostream>
using namespace std;
void merge(int* a, int l, int mid, int r){
	int i, b[r-l+1], p1 = l, p2 = mid+1;
	int k = 0;
	while(p1 <= mid && p2 <= r){
		if(a[p1] < a[p2]){
			b[k] = a[p1];
			p1++; k++;
		}
		else{
			b[k] = a[p2];
			p2++; k++;
		}
	}
	while(p1 <= mid){
		b[k] = a[p1];
		p1++; k++;
	}
	while(p2 <= r){
		b[k] = a[p2];
		p2++; k++;
	}
	for(i = 0; i < r-l+1; i++){
		a[l+i] = b[i];
	}
}
void mergeSort(int a[], int l, int r){
	int mid = (l+r)/2;
	if(l >= r)return;
	mergeSort(a, l, mid);
	mergeSort(a, mid+1, r);
	merge(a, l, mid, r);
}
void printArray(int* a, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d \n", a[i]);
	}
}
int main(){
	int i, n;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	mergeSort(a, 0, n-1);
	printArray(a, n);
	return 0;
}
// 10   3 7 4 9 1 6 2 10 5 8