

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#define  n 120

int main(int argc,char* argv[]){
// dichiarazioni variabili pid
pid_t a = -1;
pid_t b = -1;
pid_t c = -1;
//generatore seme del rand
srand(time(NULL));
//variabili
int somma = 0;
int status1 = 0;
int status2 = 0;
int status3= 0;

//stampa del padre
printf("Il mio pid vale %d, e quello di mio padre: %d\n\n  ",getpid(),getppid() );
int v[n];
    for (int i = 0;i < n ; i++){                                                                            //dichiarazione e assegnazione del vettore
        v[i] = rand()%3 +1  ;                                                                               // aggiungo uno cosicchè la cella non valga 0
        printf("   %d\t",v[i]);

}
printf("\n");
a = fork();                                                                                                 //creazione figlio 1
    if( a >0)
        b = fork();                                                                                         //creazione figlio 2
    if(b >0 )
        c = fork();                                                                                         //creazione figlio 3

if (a ==  0){
    printf("\n Sono il figlio %d, il mio pid vale:%d e mio padre ha pid:%d\n",1,getpid(),getppid());        //figlio 1 conta le cifre pari a 1
    int q = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 1) q++;
    }
    exit(q);
}
if ( b == 0){
    printf("\n Sono il figlio %d, il mio pid vale:%d e mio padre ha pid:%d\n",2,getpid(),getppid());        //figlio 2 conta le cifre pari a 2
    int w = 0;
    for(int i = 0; i < n; i++){

        if(v[i] == 2) w++;
    }
    exit(w);
}   // figlio 3

if ( c == 0){
    printf("\n Sono il figlio %d, il mio pid vale:%d e mio padre ha pid:%d\n",3,getpid(),getppid());        //figlio 3 conta le cifre pari a 3
    int y= 0;
    for(int i = 0; i < n; i++){

        if(v[i] == 3) y++;
    }
    exit(y);
}   // figlio 3
printf("\n");

if (a >0 && b >0 && c >0){                                                                                   //ritorno dei valori del padre
    waitpid(a,&status1,0);
    somma+=(status1/256);
    printf("\n");
    printf("Il figlio 1 ha contato %d cifre 1\n",status1/256);
    waitpid(b,&status2,0);
    printf("Il figlio 2 ha contato %d cifre 2\n",status2/256);
    somma+=(status2/256);
    waitpid(c,&status3,0);
    printf("Il figlio 3 ha contato %d cifre 3\n",status3/256);
    somma+=(status3/256);

    printf("\n La somma vale %d",somma);                                                                      //stampa della somma

}

return 0;
}















































































