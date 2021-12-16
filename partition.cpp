#include<stdio.h>
int main(){
  int n, p, i, j;
  printf("Enter a number(0 to 405) to find partitions: ");
  scanf("%d", &n);
  long a[n+1][n+1];
  a[0][1] = 1;
  for(p = 1; p <= n; p++){
      for(i = 1; i <= p; i++){
          a[p][i] = 0;
          for(j = 1; j <= i; j++){
              if(p-i >= j){
                a[p][i] += a[p-i][j];
              }
          }
          if(a[p][i] == 0)a[p][i] = 1;
      }
  }
  long s[n+1];
  for(p = 1; p <= n; p++){
      s[p] = 0;
      for(i = 1; i <= p; i++){
          s[p] += a[p][i];
      }
      printf("Number of partitions of %d are %ld\n", p, s[p]);
  }
  return 0;
}