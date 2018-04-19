#include<stdio.h>
void binarysearch(int a[],int head, int tail, int x){
    if(head==tail){
        if(a[head]==x)
            printf("%d\n",head+1);
        else
            printf("-1\n");

    }
    else if (head>tail)
        printf("-1\n");
    else{
        int mid=(head+tail)/2;
        if(a[mid]==x)
            printf("%d\n",mid+1);
        else if(a[mid]<x)
            binarysearch(a,mid+1,tail,x);
        else
            binarysearch(a,head,mid-1,x);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    int i;
    for (i=0;i<n;i++)
        scanf("%d",&A[i]);
    int x;
    scanf("%d",&x);
    binarysearch(A,0,n-1,x);
    return 0;
}
