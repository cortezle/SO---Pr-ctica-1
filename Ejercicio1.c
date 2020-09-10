#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


void * hola2(void *arg){
    char msg[90];
    char msg2[90];
    int i;
    printf("Ingrese Nombre " );
    scanf("%s",msg);
    printf("Ingrese Apellido ");
    scanf("%s",msg2);

    i = strlen(msg)+strlen(msg2);

    if( i > 25){
        printf("WILL TRUNCATE ");
        return NULL;
    }else{
        printf("NO Problem ");
        return NULL;
    }
    return NULL;
}
int main(int argc, char const *argv[]){
    pthread_t h1;
    pthread_t h2;
    pthread_t h3;


    pthread_create(&h1,NULL,hola2,NULL);
    pthread_join(h1,NULL);
    pthread_create(&h2,NULL,hola2,NULL);
    pthread_join(h2,NULL);
    pthread_create(&h3,NULL,hola2,NULL);
    pthread_join(h3,NULL);
    printf("\n Fin\n");
}