#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int A[n];
    for (i=0;i<=n-1;i++){
        scanf("%d",&A[i]);
    }
    mergesort(A,0,n-1);
    for (i=0;i<=n-1;i++){
        printf("%d\ ",A[i]);
    }
}

void mergesort(int *A, int p, int q){
  if (p<q){
    int r=(p+q)/2;
    mergesort(A,p,r);
    mergesort(A,r+1,q);
    merge(A,p,r,q);
  }
}

void merge(int *A, int p, int r, int q){
  int num1=r-p+1;
  int num2=q-r;
  int *L1=(int *)malloc(sizeof(int)*(num1+1));
  int *L2=(int *)malloc(sizeof(int)*(num2+1));
  int f;
  for (f=0;f<num1;f++){
    L1[f]=A[p+f];
  }
  L1[f]=100000;

  for (f=0;f<num2;f++){
    L2[f]=A[r+1+f];
  }
  L2[f]=100000;
  int m=0;
  int n=0;
  int k;
  for (k=0;k<q-p+1;k++){
    if(L1[m]<=L2[n]){
        A[p+k]=L1[m];
        m++;
    }
    else{
        A[p+k]=L2[n];
        n++;
    }
  }
  free(L1);
  free(L2);
}


