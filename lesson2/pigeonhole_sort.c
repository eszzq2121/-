#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int A[n];
    for (i=0;i<=n-1;i++){
        scanf("%d",&A[i]);
    }

    int max=0,min=9999;
    for (i=0;i<=n-1;i++){
        if (A[i]>=max){
            max=A[i];
        }
    }
     for (i=0;i<=n-1;i++){
        if (A[i]<=min){
            min=A[i];
        }
    }

    int s,k;
    s=max;
    int U[s+1];

    for (k=0;k<=s;k++){
        U[k]=0;
    }

    for (i=0;i<=n-1;i++){
        k=A[i];
        U[k]=U[k]+1;
    }
    i=-1;
    for (k=0;k<=s;k++){
        while (U[k]!=0){
            i=i+1;
            A[i]=k;
            U[k]=U[k]-1;

        }
    }
    for (i=0;i<=n-1;i++){
        printf("%d\ ",A[i]);
    }
}
