#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>


void *routine(void *arg){
    int t= clock();
    int c= *(int *)arg;

    printf("sono th1, sono a riposo per %d secondi\n",c);
    sleep(c);
    printf("sono th1, finito di dormire,faccio rendez-vous\n",c);
    printf("sono th1, finito dopo %d\n",clock()-t);


}
void *routine1(void *arg){
    int t= clock();
    int c= *(int *)arg;

    printf("sono th2, sono a riposo per %d secondi\n",c);
    sleep(c);
    printf("sono th2, finito di dormire,faccio rendez-vous\n",c);

    printf("sono th2, finito dopo %d\n",clock()-t);

}


int main(){

    pthread_t ID1;
    pthread_t ID2;

    srand(time(NULL));
    int c1= 1+rand()%10;
    int c2= 1+rand()%10;
    pthread_create(&ID1,NULL,&routine,&c1);
    pthread_create(&ID2,NULL,&routine1,&c2);
    pthread_join(ID1,NULL);
    pthread_join(ID2,NULL);






    return 0;
}
