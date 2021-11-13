#include<iostream>
using namespace std;
void permute(int n, int* arr, int* vis, int s, int* count){
	int i,j;
	if(s == n){
		(*count)++;
		cout << *count << "\t: ";
		for(i = 1; i <= n; i++)cout << arr[i] << " ";
		cout << endl;
		return;
	}
	int viscopy[n+1];
	for(i = 0; i <= n; i++)viscopy[i] = vis[i];
	for(i = 1; i <= n; i++){
		if(viscopy[i] == 0){
			arr[s+1] = i;
			viscopy[i] = 1;
			permute(n,arr,viscopy,s+1,count);
		}
		for(j = 0; j <= n; j++)viscopy[j] = vis[j];
	}
}
int main(){
	int n, i, j, k;
	int* count = (int*)calloc(1, sizeof(int));
	*count = 0;
	cin >> n;
	int arr[n+1], vis[n+1];
	for(i = 0; i <= n; i++){
		arr[i] = 0;
		vis[i] = 0;
	}
	permute(n, arr, vis, 0, count);
	return 0;
}