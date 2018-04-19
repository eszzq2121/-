#include<stdio.h>
using namespace std;
#define nodes
class Node
{
    public:
    Node() : value(0), next(NULL){}
    Node(int data) : value(data), next(NULL){}
    int value;
    Node *next;
};

class Stack
{
public:
    Node *tail;
    void push(Node Value);
    void pop(Node *pvalue);
    bool IsEmpty();
    Stack():tail(NULL){};
};

void Stack::push(Node Value){
    Node *newdata = NULL;
    newdata = new Node(Value.value);
    newdata->next=tail;
    tail=newdata;
}

void Stack::pop(Node *data){
    if(IsEmpty()){
        return;
    }
    data->value=tail->value;
    Node *p=tail;
    tail=tail->next;
}

bool Stack::IsEmpty(){
    return(NULL==tail);
}

class Queue{
public:
    void enqueue(Node Value);
    void dequeue(Node &data);
    bool IsEmpty();
private:
    Stack s1;
    Stack s2;
};

void Queue::enqueue(Node Value){
    s1.push(Value);
}

void Queue::dequeue(Node &data){
    Node temp(0);
    if(s2.IsEmpty()){
        while(!s1.IsEmpty()){
            s1.pop(&temp);
            s2.push(temp);
        }
    }
    if(!s2.IsEmpty()){
        s2.pop(&data);
    }
}

bool Queue::IsEmpty(){
    return(s1.IsEmpty()&& s2.IsEmpty());
}

int main(){
    int n,i;
    scanf("%d",&n);
    int A[n];
    for (i=0;i<=n-1;i++){
        scanf("%d",&A[i]);
    }

    Queue q;
    Node data(0);
    for (i=0;i<=n-1;i++){
        if (A[i]>=0){
            q.enqueue(Node(A[i]));
        }
        if(A[i]==-1){
            q.dequeue(data);
            printf("%d %d\n",i+1,data.value);
        }
    }

}


