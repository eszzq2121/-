#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int A[n];
    for (i=0;i<=n-1;i++){
        scanf("%d",&A[i]);
    }

    int j,k,x;
    for (j=1;j<=n-1;j++){
        x=A[j];
        k=j-1;
        while(k>=0 && x<A[k]){
            A[k+1]=A[k];
            k=k-1;
        }
        A[k+1]=x;
    }
    for (i=0;i<=n-1;i++){
        printf("%d\ ",A[i]);
    }
}
