#include <stdio.h>
#include "funciones.h"
#include <string.h>

void ingresarCliente(char clientes[][2][40]){
   
    for (int i = 0; i < 5; i++)
    {
        if(strcmp(clientes[i][0],"")==0){
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s",clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s",clientes[i][1]);
            break;
        }
    } 
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]){
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t\t%s\n",clientes[i][0],clientes[i][1]);
    }   
}

void listarPeliculas(char peliculas[][4][40]){

    printf("Numero\t\tPelicula\t\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\n%s\t\t%s\t\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
    }
    
}

void buscarporNombre(char peliculas[][4][40]){
    char nombre[40];
    printf("\nIngrese el nombre de la pelicula que desea buscar: \n");
    scanf("%s",nombre);
    printf("Numero\t\tPelicula\t\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(peliculas[i][1], nombre)==0)
        {
            printf("\n%s\t\t%s\t\t\t%s\t\t%s\n",i+1,peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }
}

void buscarporGenero(char peliculas[][4][40]){
    char genero[40];
    printf("\nIngrese el genero de la pelicula que desea buscar: \n");
    scanf("%s",genero);
    printf("Numero\t\tPelicula\t\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(peliculas[i][3], genero)==0)
        {
            printf("\n%s\t\t%s\t\t\t%s\t\t%s\n",i+1,peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }
}


