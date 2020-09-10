#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

struct timeval t0H , t1H;
double media = 0.0;

void * hilo(void *arg ) {
    gettimeofday(&t1H , NULL);
    unsigned int ut1 = t1H. tv_sec *1000000+ t1H. tv_usec ;
    unsigned int ut0 = t0H. tv_sec *1000000+ t0H. tv_usec ;
    media += (ut1 -ut0 );
}


struct timeval t0, t1;

int main(int argc, char const *argv[])
{
    int i;
    int id = -1;
    gettimeofday(&t0, NULL);
    for(i = 0; i < 100; i++){
        id = fork();
        if(id == 0)
        return 0;
    }
    if(id != 0){
        gettimeofday(&t1, NULL);
        unsigned int ut1 = t1.tv_sec*1000000+t1.tv_usec;
        unsigned int ut0 = t0.tv_sec*1000000+t0.tv_usec;
        printf("%f Process\n", (double)(ut1-ut0)/100);
    }


    ///
    int iH = 0;
    pthread_t h;
    for ( i = 0 ; i < 100 ; i++ ) {
    gettimeofday(&t0H , NULL);
    pthread_create(&h, NULL , hilo , NULL);
    pthread_join(h, NULL);
    }
    printf (" %f Threads\n", ( media /100.0) ); /* Tiempo medio en microsegundos */
    return 0;
}