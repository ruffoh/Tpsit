#include <stdio.h>
#include <unistd.h>
 char const *path = "sostituto.c";
int main (){
execlp(path,"exec.c",NULL);

}
