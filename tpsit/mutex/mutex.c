#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

int f = 0;
void *thread_function2() {


    for (int j = 0; j <= 999; j++){
        for (int x = 0; x <= 999; x++){
                f++;

    }
    }



    pthread_exit(NULL);
}

int w = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function() {
    for (int j = 0; j <= 999; j++){
        for (int x = 0; x <= 999; x++){
               pthread_mutex_lock(&mutex);
                w++;
                pthread_mutex_unlock(&mutex);



    }
    }


    pthread_exit(NULL);
}



int main() {
    pthread_t threads[NUM_THREADS];
    pthread_t threads2[NUM_THREADS];


    // Creazione dei thread
    long int timer = 0;
    timer = clock();
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);

        }


    // Attendo il termine dei thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        }

    printf("Valore finale di w: %d\n", w);
    printf("tempo di esecuzione mutex %ld\n",(clock()-timer )/1000);


        timer= clock();

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads2[i], NULL, thread_function2, NULL);

        }


    // Attendo il termine dei thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads2[i], NULL);
        }



    printf("Valore finale di f: %d\n", f);
    printf("tempo di esecuzione NO mutex %ld\n",(clock()-timer )/1000);




    pthread_mutex_destroy(&mutex);

    return 0;
}
