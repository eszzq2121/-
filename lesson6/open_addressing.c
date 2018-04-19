#include <stdio.h>
#include <stdlib.h>
#define N 10000

unsigned long hash(unsigned char (*str)[16])
{
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

int addressing(unsigned long key,int k)
{
    int newkey;
    newkey=(key%N+k*k)%N;
    return newkey;
}

int hash_insert(unsigned long *T,unsigned long key)
{
    int k=0;
    int New_key=0;
    do{
        New_key=addressing(key,k);
        if(T[New_key]==0){
            T[New_key]=key;
            return New_key;
        }
        k=k+1;
    }while(k!=N);

}


int hash_search(unsigned long *T,unsigned long key)
{
    int k=0;
    int New_key=0;
    do{
        New_key=addressing(key,k);
        if(T[New_key]==key){
            return New_key;
        }
        k=k+1;
    }while(k!=N||T[New_key]!=0);
    return -1;
}


int main()
{
    int n;
    int flag=-1;
    scanf("%d",&n);
    unsigned long key[n];
    unsigned char name[n][16];
    char op[n];
    int grade[n];
    int i,j,k;
    unsigned long hashtable_key[N];
    int hashtable_grade[N];
    for(i=0;i<n;i++){
        grade[i]=-1;
        scanf(" %c", &op[i]);
        if(op[i]=='i')scanf(" %s %d", &name[i], &grade[i]);
        else scanf(" %s", &name[i]);
        key[i]=hash(&name[i]);}
    for (i=0;i<n;i++){
        if(op[i]=='i'){
            int temp;
            temp=hash_insert(&hashtable_key,key[i]);
            hashtable_grade[temp]=grade[i];
            printf("%c %s %d\n",op[i],name[i],hashtable_grade[temp]);
        }
        if(op[i]=='s'){
            int temp;
            temp=hash_search(&hashtable_key,key[i]);
            if(temp==-1){
                printf("%c %s %d\n",op[i],name[i],flag);
            }
            else{
                printf("%c %s %d\n",op[i],name[i],hashtable_grade[temp]);
            }
        }
        if(op[i]=='d'){
            int temp;
            temp=hash_search(&hashtable_key,key[i]);
            if(temp==-1){
                printf("%c %s %d\n",op[i],name[i],flag);
            }
            else{
                printf("%c %s %d\n",op[i],name[i],hashtable_grade[temp]);
            hashtable_key[temp]=0;
            hashtable_grade[temp]=0;
            }
        }
    }
}

