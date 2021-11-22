#include<iostream>
using namespace std;
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
void mergeSort(int a[], int l, int r){
	int mid = (l+r)/2;
	if(l >= r)return;
	mergeSort(a, l, mid);
	mergeSort(a, mid+1, r);
	merge(a, l, mid, r);
}
bool is_two_sum_x(int* arr, int n, int x){
	mergeSort(arr, 0, n-1);
	int l = 0, r = n-1;
	while(l < r){
		if(arr[l]+arr[r] == x){
			cout << arr[l] << " " << arr[r] << endl;
			return true;
		}
		if(arr[l]+arr[r] < x)l++;
		if(arr[l]+arr[r] > x)r--;
	}
	return false;
}
int main(){
	int i, n, x;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements: ";
	for(i = 0; i < n; i++)cin >> arr[i];
	cout << "Enter x to find whether there exist 2 elements in arr "
		 << "whose sum is exactly x: ";
	cin >> x;
	cout << boolalpha << "\x1b[33m" << is_two_sum_x(arr, n, x) << endl;
	return 0;
}
// 10   2 4 6 8 0 9 7 5 3 1   18