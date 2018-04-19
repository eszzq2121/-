#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//生成随机数,范围从1-100
int (*generator(int n)){
 srand((unsigned) time(NULL));
 int (*A)[n];
 int i;
 A=calloc(n,sizeof(int));
 for (i = 0; i < n; i ++){
        (*A)[i] = rand() % 100 + 1;
 }
 return A;
}

//定义selectionsort
void selectionsort(int *A,int n){
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
}

int main(){
    int n=50000;
    int (*b)[n];
    int repeat, repeat_times = 10;
    b=generator(n);
    clock_t begin = clock();
    for (repeat=0;repeat<repeat_times;repeat++){
        selectionsort(b,n);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC/repeat_times;
    printf("It took %f seconds to run selectionsort at n=%d \n", time_spent,n);
    return 0;
}
