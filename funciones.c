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

void buscarporNombre(char peliculas[][4][40]) {
    char pelicula[40];
    printf("\nIngrese el nombre de la pelicula que desea buscar: \n");
    scanf("%s", pelicula);
    printf("Numero\t\tPelicula\t\t\tHora\t\tGenero\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], pelicula) == 0) {
            printf("%s\t\t%s\t\t\t%s\t\t%s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
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
            printf("\n%s\t\t%s\t\t\t%s\t\t%s\n",peliculas[i][0],peliculas[i][1],peliculas[i][2],peliculas[i][3]);
        }
    }
}


void comprarTicket(char (*peliculas)[4][40], double *precio, char (*clientes)[2][40], int (*reserva)[4]) {
    char cedula[40];
    int NumPelicula, cantidad, tipoEntrada;
    int clienteIndex = -1;

    printf("Ingrese su cedula: ");
    scanf("%s", cedula);

    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            clienteIndex = i;
            break;
        }
    }

    if (clienteIndex == -1) {
        printf("Cedula no encontrada.\n");
        return;
    }

    printf("Ingrese el numero de la pelicula: ");
    scanf("%d", &NumPelicula);

    if (NumPelicula < 1 || NumPelicula > 10) {
        printf("El numero de la pelicula no es el correcto.\n");
        return;
    }

    printf("Ingrese la cantidad de entradas: ");
    scanf("%d", &cantidad);

    printf("Tipos de entrada: 0 - Normal ($7), 1 - Ninos ($3.5), 2- Adulto mayor ($3)\n");
    printf("Ingrese el tipo de entrada: ");
    scanf("%d", &tipoEntrada);

    if (tipoEntrada < 0 || tipoEntrada > 2) {
        printf("Tipo de entrada invalido.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < 4; j++) {
            if (reserva[NumPelicula-1][j] == -1) {
                reserva[NumPelicula-1][j] = clienteIndex;
                break;
            }
        }
    }

    double total = cantidad * precio[tipoEntrada];
    printf("Compra realizada exitosamente. Total: $%.2f\n", total);
}

    printf("No hay espacios disponibles para nuevas reservas.\n");
}
