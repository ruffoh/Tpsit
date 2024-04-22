

































































































































































































#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int a=fork();
    int ritorno1=0;
    int ritorno2=0;
    int b=-1;
    if (a==0){
        int ai=0;
        printf("Sono il figlio 1, inserisci pure un'intero: ");
        scanf("%d",&ai);
        ai=ai*3;
        exit(ai);
    }
    if(a>0){
        b=fork();
    }
    if (b==0){
        int bi=0;
        printf("Sono il figlio 2, inserisci pure un'intero: ");
        scanf("%d",&bi);
        bi=bi*3;
        exit(bi);
    }

    waitpid(a,&ritorno1,0);
    waitpid(b,&ritorno2,0);

    printf("Il padre fa la somma dei 2 valori dei figli e il risultato è di : %d",(ritorno1+ritorno2)/256);


return 0;
}
