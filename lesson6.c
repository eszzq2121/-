#include <stdio.h>
#include <stdlib.h>
#define N 10000
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
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
    int hashtable_key[N];
    int hashtable_grade[N];
    for(i=0;i<n;i++){
        grade[i]=-1;
        scanf(" %c", &op[i]);
        if(op[i]=='i'){
                scanf(" %s %d", &name[i], &grade[i]);}
                else scanf(" %s", &name[i]);
        key[i]=hash(&name[i]);}
    int newkey;
    for (j=0;j<n;j++){
        if(op[j]=='i'){
                newkey=0;
                for(k=0;k<N;){
                    newkey=(key[j]%N+k)%N;
                    if(hashtable_key[newkey]==0){
                        hashtable_key[newkey]=key[j];
                        hashtable_grade[newkey]=grade[j];
                        printf("%c %s %d\n",op[j], name[j],hashtable_grade[newkey]);
                        break;

                    }
                    else{
                        k=k+1;
                    }

                }

        }
       if(op[j]=='s'){
            k=0;
            do{
                    newkey=(key[j]%N+k)%N;
                    if(hashtable_key[newkey]==key[j]){
                        printf("%c %s %d\n",op[j], name[j],hashtable_grade[newkey]);
                        break;
                    }
                    k=k+1;
            }while(hashtable_key[newkey]!=0||k!=N-1);
            if(hashtable_key[newkey]==0){
                printf("%c %s %d\n",op[j], name[j],flag);
            }


       }
    if(op[j]=='d'){
        k=0;
        do{
            newkey=(key[j]%N+k*k)%N;
            if(hashtable_key[newkey]==key[j]){
                printf("%c %s %d\n",op[j], name[j],hashtable_grade[newkey]);
                break;
            }
            k=k+1;
        }while(hashtable_key[newkey]!=0||k!=N-1);
        if(hashtable_key[newkey]==0){
                printf("%c %s %d\n",op[j], name[j],flag);}
        else{
            hashtable_key[newkey]=0;
            hashtable_grade[newkey]=0;
        }
    }

    }
    }



