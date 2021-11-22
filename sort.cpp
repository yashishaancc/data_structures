#include<iostream>
using namespace std;
void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void printArray(int* a, int n){
	int i;
	for(i = 0; i < n; i++)printf("%d ", a[i]);
	printf("\n");
}
void merge(int* a, int l, int mid, int r){
	int i, s1 = mid-l+1, s2 = r-mid;
    int a1[s1], a2[s2], p1 = 0, p2 = 0;
    for(i = 0; i < s1; i++)a1[i] = a[l+i];
    for(i = 0; i < s2; i++)a2[i] = a[mid+1+i];
    for(i = l; i <= r; i++){
        if(p2 >= s2 || p1 < s1 && a1[p1] < a2[p2]){
            a[i] = a1[p1];
            p1++;
        }
        else{
            a[i] = a2[p2];
            p2++;
        }
    }
}
void maxHeapify(int* a, int i, int r){
	int max = i;
	if(2*i+1 <= r && a[2*i+1] > a[max])max = 2*i+1;
	if(2*i+2 <= r && a[2*i+2] > a[max])max = 2*i+2;
	if(max != i){
		swap(&a[i], &a[max]);
		maxHeapify(a, max, r);
	}
}
void insertionSort(int* a, int l, int r){
	if(l < r-1)insertionSort(a, l, r-1);
	int tmp = a[r], j = r-1;;
	while(j >= l){
		if(a[j] > tmp)a[j+1] = a[j];
		else break;
		j--;
	}
	a[j+1] = tmp;
}
void selectionSort(int* a, int l, int r){
	for(int i = l; i < r; i++){
		int min = i;
		for(int j = i+1; j <= r; j++){
			if(a[j] < a[min])min = j;
		}
		swap(&a[i], &a[min]);
	}
}
void bubbleSort(int* a, int l, int r){
	for(int i = r; i > l; i--){
		for(int j = l; j < i; j++){
			if(a[j+1] < a[j])swap(&a[j+1], &a[j]);
		}
	}
}
void mergeSort(int* a, int l, int r){
	int mid = (l+r)/2;
	if(l >= r)return;
	mergeSort(a, l, mid);
	mergeSort(a, mid+1, r);
	merge(a, l, mid, r);
}
void heapSort(int* a, int l, int r){
	for(int i = r; i >= l; i--)maxHeapify(a, i, r);
	for(int i = r; i > l; i--){
		swap(&a[l], &a[i]);
		maxHeapify(a, l, i-1);
	}
}
int main(){
	int i, n;
	cout << "Enter size of array: ";
	scanf("%d", &n);
	int a[n];
	cout << "Enter array elements: ";
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	// insertionSort(a, 0, n-1);
	// selectionSort(a,0, n-1);
	// bubbleSort(a, 0, n-1);
	// mergeSort(a, 0, n-1);
	heapSort(a, 0, n-1);
	printArray(a, n);
	return 0;
}
// 10   3 7 4 9 1 6 2 10 5 8