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
    char cedula[40];
    int NumPelicula, cantidad, tipoEntrada, totalEntradas = 0;
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

    double total = 0.0;
    for (int i = 0; i < 3; i++) {
        do {
            printf("Ingrese la cantidad de entradas para el tipo %d (0 - Normal 7.00, 1 - Ninos 3.50, 2 - Adulto mayor 3): ", i);
            scanf("%d", &cantidad);
        } while (cantidad < 0);

        if (cantidad > 0) {
            for (int j = 0; j < 10; j++) {
                if (reserva[j][0] == -1) {
                    reserva[j][0] = NumPelicula - 1;
                    reserva[j][1] = clienteIndex;
                    reserva[j][2] = cantidad;
                    reserva[j][3] = i;
                    total += cantidad * precio[i];
                    totalEntradas += cantidad;
                    break;
                }
            }
        }
    }

    if (totalEntradas == 0) {
        printf("No se ingresaron entradas.\n");
    } else {
        printf("Compra realizada exitosamente. Total: $%.2f\n", total);
    }
}

void verCompras(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    char cedula[40];
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

    printf("Compras realizadas por %s (Cedula: %s):\n", clientes[clienteIndex][0], clientes[clienteIndex][1]);
    double totalPrecio = 0;

    for (int i = 0; i < 10; i++) {
        if (reserva[i][1] == clienteIndex) {
            int peliculaIndex = reserva[i][0];
            int cantidad = reserva[i][2];
            int tipoEntrada = reserva[i][3];
            double precioEntrada = precio[tipoEntrada];
            double precioTotal = cantidad * precioEntrada;

            printf("  Pelicula: %s, Hora: %s, Genero: %s, Cantidad: %d, Precio de entrada: $%.2f, Precio Total: $%.2f\n",
                   peliculas[peliculaIndex][1], peliculas[peliculaIndex][2], peliculas[peliculaIndex][3],
                   cantidad, precioEntrada, precioTotal);

            totalPrecio += precioTotal;
        }
    }

    if (totalPrecio == 0) {
        printf("No tiene reservas.\n");
    } else {
        printf("Total a pagar: $%.2f\n", totalPrecio);
    }
}
