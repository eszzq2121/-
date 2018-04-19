#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int A[n];
    for (i=0;i<=n-1;i++){
        scanf("%d",&A[i]);
    }
    int j,k,minj,minx;
    for (k=0;k<=n-1;k++){
        minj=k;
        minx=A[k];
        for (j=k+1;j<=n-1;j++){
            if (A[j]<minx){
                minx=A[j];
                minj=j;
            }
        }
        A[minj]=A[k];
        A[k]=minx;
    }
    for (i=0;i<=n-1;i++){
        printf("%d\ ",A[i]);
    }
}
