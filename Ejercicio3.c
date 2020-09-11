#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

struct persona
{
    char name[50];
    char DUI[10];
    char edad[3];
};

void* datos(void *args){
    struct persona *personArgs;
    personArgs = (struct persona *) args;
    printf("Datos de Persona\n Nombre: %s\n DUI: %s\n Edad: %s\n",(char *) personArgs->name, (char *) personArgs->DUI, (char *) personArgs->edad );
}

int main(int argc, char *argv []){
    pid_t pid;
    struct  persona p1;
    char nombre[70], DUI[9], edad[3];
    //int edad;

    printf("Ingrese su nombre:");
    scanf("%s", nombre);
    strcpy(p1.name, nombre); 

    printf("Ingrese su DUI:");
    scanf("%s", DUI); 
    strcpy(p1.DUI, DUI); 

    printf("Ingrese su edad:");

    scanf("%s", edad); 
    strcpy(p1.edad, edad); 

    pthread_t h1;
    pthread_create(&h1, NULL, datos, (void *)&p1);
    pthread_join(h1, NULL);

    return 0;
}