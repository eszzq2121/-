#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node
{
    struct node * next;
    int value;
}node;


typedef struct stack
{
    struct node * top;
    int (*pop)(struct stack *s);
    void (*push)(struct stack *s,int value);
    int (*isEmpty)(struct stack *s);
}stack;


int pop(struct stack *s)
{
   int value;
   node *temp = s->top;
   s->top = temp->next;
   value = temp->value;
   free (temp);
return value;
}

void push(struct stack *s ,int value)
{
    node *nd = (node*)malloc(sizeof(node));
    nd->value = value;
    nd->next = s->top;
    s->top = nd;
}

int isEmpty(struct stack *s)
{
    if(s->top == NULL) return 1;
    return 0;
}

void init(struct stack *s)
{
    s->top = NULL;
    s->pop = pop;
    s->push=push;
    s->isEmpty = isEmpty;
}






int main()
{
    srand((unsigned) time(NULL));
    int n=500000;
    int b[n];
    stack s1;
    stack s2;
    init(&s1);
    init(&s2);
    int x,y,z;
    int i;
    double timeen=0,timede=0;
    int encount=0,decount=0;
    for (i=0;i<n;i++){
        b[i] = rand()%3-1;
        z = b[i];
        if(z>=0){
            clock_t begin = clock();
            s1.push(&s1,z);
            clock_t end = clock();
            timeen = timeen + end- begin;
            encount ++;
        }
        if(z==-1){
            clock_t begin = clock();
            if(s2.isEmpty(&s2)){
                while(!s1.isEmpty(&s1)){
                    x=s1.pop(&s1);
                    s2.push(&s2,x);
                }
            }
            if (!s2.isEmpty(&s2)){
                y=s2.pop(&s2);
            }
            clock_t end = clock();
            timede = timede+end-begin;
            decount ++;

        }
    }
    printf("%f %d\n",timeen,encount);
    printf("%f %d\n",timede,decount);
    return 0;
}
