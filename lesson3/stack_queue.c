#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define N 1000

typedef struct stack{
    int S[N];
    int top;
} sta;

void initiate(sta *s){
    s->top = -1;
}

void push(sta *s, int x){
    (s->top)++;
    s->S[(s->top)]=x;
}

int pop(sta *s){
    (s->top)--;
    return s->S[(s->top)+1];
}

int main(){
    int n;
    int i,j,num;
    int x;
    sta s1;
    sta s2;
    scanf("%d",&n);
    initiate(&s1);
    initiate(&s2);
    num=0;
    for (i=1;i<=n;i++){
        scanf("%d",&x);
        if (x>=0){
            push(&s1,x);
            num++;
        }
        else if (x==-1){
            for (j=1;j<=num;j++){
                push(&s2,pop(&s1));
            }

            printf("%d %d\n",i,pop(&s2));

        }
    }

}
