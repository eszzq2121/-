#include <stdio.h>
#include <stdlib.h>
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
    int n,i;
    scanf("%d",&n);
    int A[n];
    for (i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    stack s1;
    stack s2;
    init(&s1);
    init(&s2);
    int x,y;
    for (i=0;i<n;i++){
        if(A[i]>=0){
            s1.push(&s1,A[i]);
        }
        if(A[i]==-1){
            if(s2.isEmpty(&s2)){
                while(!s1.isEmpty(&s1)){
                    x=s1.pop(&s1);
                    s2.push(&s2,x);
                }
            }
            if (!s2.isEmpty(&s2)){
                y=s2.pop(&s2);
                printf("%d %d\n",i+1,y);
            }

        }
    }
    return 0;
}
