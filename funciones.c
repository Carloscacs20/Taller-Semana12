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


void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    int numPelicula;
    char cedula[40];
    printf("\nIngrese el numero de la pelicula que desea ver: ");
    scanf("%d", &numPelicula);

    if (numPelicula < 1 || numPelicula > 10) {
        printf("Numero de pelicula inválido.\n");
        return;
    }

    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedula);

    int numCliente = -1;
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            numCliente = i;
            break;
        }
    }

    if (numCliente == -1) {
        printf("Cliente no encontrado o cédula inválida.\n");
        return;
    }

    printf("Escoja el tipo de asiento:\n1. VIP 7.00\n2. Normal 3.50\n3. Económico 3.00\n>> ");
    int tipoAsiento;
    scanf("%d", &tipoAsiento);

    if (tipoAsiento < 1 || tipoAsiento > 3) {
        printf("Tipo de asiento invalido.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] == -1) {
            reserva[i][0] = numPelicula - 1;
            reserva[i][1] = numCliente;
            reserva[i][2] = tipoAsiento;
            reserva[i][3] = 1; 
            printf("Ticket comprado exitosamente.\n");
            return;
        }
    }

    printf("No hay espacios disponibles para nuevas reservas.\n");
}
