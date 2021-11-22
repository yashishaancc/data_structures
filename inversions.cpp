#include<iostream>
using namespace std;
int merge_inversions(int* a, int l, int mid, int r){
	int i, s1=mid-l+1, s2=r-mid, c = 0;
    int a1[s1], a2[s2], p1=0, p2=0;
    for(i = 0; i < s1; i++)a1[i] = a[l+i];
    for(i = 0; i < s2; i++)a2[i] = a[mid+1+i];
    for(i = l; i <= r; i++){
        if(p2 >= s2 || p1 < s1 && a1[p1] < a2[p2]){
            a[i] = a1[p1];
            p1++;
        }
        else{
        	c += s1-p1;
            a[i] = a2[p2];
            p2++;
        }
    }
    return c;
}
int count_mergeSort_inversions(int a[], int l, int r){
	int mid = (l+r)/2, c = 0;
	if(l >= r)return 0;
	c += count_mergeSort_inversions(a, l, mid);
	c += count_mergeSort_inversions(a, mid+1, r);
	c += merge_inversions(a, l, mid, r);
	return c;
}
int main(){
	int i, n, x;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements: ";
	for(i = 0; i < n; i++)cin >> arr[i];
	cout << "Number of inversions in array are: " 
		 << count_mergeSort_inversions(arr, 0, n-1) << endl;
	return 0;
}
// 10   2 4 6 8 0 9 7 5 3 1