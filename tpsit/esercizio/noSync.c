#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int dado=0;
int letto=-1;
int i=0,j=0,k=0,l=0;
int a[10]={0};
int a1[10]={0};
int a2[10]={0};

void *routine(void *arg){
    int app=0;
    srand(time(NULL));
    while(1){
    app++;
        if(letto==-1 || i==0){
            dado= 1+rand()%6;
            a[i]=dado;
            i++;
            letto=0;
        }
        if(i==10){
            break;
        }
    }
    int k=0;
    printf("valori ottenuti: \n");
    for(k=0;k<10;k++){
        printf("%d, ", a[k]);
    }
    printf("\ncicli effettuati: %d\n",app);
}

void *routine1(void *arg){
    int app=0;
    while(i!= 11){
        app++;
        if(letto==0 && dado%2==0){
            a1[j]=dado;
            j++;
            letto=-1;

        }
        if(i==10){
            i++;
        }
    }
    int k=0;
    printf("\nvalori ottenuti th2: \n");
    for(k=0;k<10;k++){
        printf("%d, ", a1[k]);
    }
    printf("\ncicli effettuati th2: %d\n",app);
}
void *routine2(void *arg){
    int app=0;
    while(i!= 12){
        app++;
        if(letto==0 && dado%2==1){
            a2[l]=dado;
            l++;
            letto=-1;
        }
        if(i==11){
            i++;
        }
    }
    int k=0;
    printf("\nvalori ottenuti th3: \n");
    for(k=0;k<10;k++){
        printf("%d, ", a2[k]);
    }
    printf("\ncicli effettuati th3: %d\n",app);
}


int main(){

    srand(time(NULL));
    pthread_t ID1;
    pthread_t ID2;
    pthread_t ID3;


    pthread_create(&ID1,NULL,&routine,NULL);
    pthread_create(&ID2,NULL,&routine1,NULL);
    pthread_create(&ID3,NULL,&routine2,NULL);

    pthread_join(ID1,NULL);
    pthread_join(ID2,NULL);
    pthread_join(ID3,NULL);



    return 0;
}
