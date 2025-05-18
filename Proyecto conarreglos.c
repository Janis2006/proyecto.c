//El progrma desplega un menú el cual tienes que seguir en ese orden (de preferencia), te pedira varios datos como número de pueblo del que deseas ingresar datos, número asignado a cada
bebida a la que quieras ingresar la cantidad de litros que consume el pueblo... así haste llegar a la opción de comparar que pueblo consume más alcohol//
//Janis Lizeth Salgado Pérez//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BEBIDAS 8
#define NUM_PUEBLOS 100

char* nombre[NUM_BEBIDAS] = {
    "Natural", "Refresco", "Vino", "Cerveza",
    "Whisky", "Licores", "Energeticos", "Combinados"
};

void capturarDatos(int arr[NUM_PUEBLOS][NUM_BEBIDAS]) {
    int i, j, var1, var2;

    do {
        printf("¿Qué pueblo deseas capturar? (0 a 99, o -1 para salir): ");
        if (scanf("%d", &i) != 1) {
            printf("Entrada no válida. Cancelando captura.\n");
            while(getchar() != '\n');
            break;
        }
        if(i >= 0 && i < NUM_PUEBLOS) {
            printf("Capturando datos para el pueblo %d\n", i);
            printf("Lista de bebidas:\n");
            for (j = 0; j < NUM_BEBIDAS; j++)
                printf("%d - %s\n", j, nombre[j]);

            printf("Ingresa la bebida (0 a 7) o -1 para terminar: ");
            if (scanf("%d", &var1) != 1) {
                printf("Entrada no válida.\n");
                while(getchar() != '\n');
                break;
            }

            while(var1 != -1) {
                if(var1 >= 0 && var1 < NUM_BEBIDAS) {
                    printf("Cantidad en litros para %s: ", nombre[var1]);
                    if (scanf("%d", &var2) != 1) {
                        printf("Entrada no válida. Se cancela esta bebida.\n");
                        while(getchar() != '\n');
                        break;
                    }
                    arr[i][var1] += var2;
                } else {
                    printf("Bebida no válida (debe estar entre 0 y 7).\n");
                }

                printf("Ingresa otra bebida o -1 para terminar: ");
                if (scanf("%d", &var1) != 1) {
                    printf("Entrada no válida.\n");
                    while(getchar() != '\n');
                    break;
                }
            }
        } else if(i != -1) {
            printf("Pueblo no válido.\n");
        }
    } while(i != -1);
}

void mostrarBebidaMasConsumida(int arr[NUM_PUEBLOS][NUM_BEBIDAS]) {
    int total[NUM_BEBIDAS] = {0};
    int i, j, max = 0, bebida = 0;

    for(j = 0; j < NUM_BEBIDAS; j++) {
        for(i = 0; i < NUM_PUEBLOS; i++) {
            total[j] += arr[i][j];
        }
        if(total[j] > max) {
            max = total[j];
            bebida = j;
        }
    }

    printf("La bebida más consumida es %s con %d litros.\n", nombre[bebida], max);
}

void mostrarBebidaAlcoholicaMasConsumida(int arr[NUM_PUEBLOS][NUM_BEBIDAS]) {
    int total2[NUM_BEBIDAS] = {0};
    int i, j, acum, max2 = 0, bebida2 = 0;

    for(i = 0; i < NUM_BEBIDAS; i++) {
        if(i != 1 && i != 6) { // Refresco y Energéticos no se consideran alcohólicas
            acum = 0;
            for(j = 0; j < NUM_PUEBLOS; j++) {
                acum += arr[j][i];
            }
            total2[i] = acum;
            if(acum > max2) {
                max2 = acum;
                bebida2 = i;
            }
        }
    }

    printf("La bebida alcohólica más consumida es %s con %d litros.\n", nombre[bebida2], max2);
}

void mostrarPuebloMasAlcohol(int arr[NUM_PUEBLOS][NUM_BEBIDAS]) {
    int total3[NUM_PUEBLOS] = {0};
    int i, j, acum2, max3 = 0, pueblo = 0;

    for(i = 0; i < NUM_PUEBLOS; i++) {
        acum2 = 0;
        for(j = 0; j < NUM_BEBIDAS; j++) {
            if(j != 1 && j != 6) {
                acum2 += arr[i][j];
            }
        }
        total3[i] = acum2;
        if(acum2 > max3) {
            max3 = acum2;
            pueblo = i;
        }
    }

    printf("El pueblo %d consume más alcohol con %d litros.\n", pueblo, max3);
}

int main() {
    int opcion;
    int arr[NUM_PUEBLOS][NUM_BEBIDAS] = {{0}};

    do {
        printf("\n------ MENÚ PRINCIPAL ------\n");
        printf("1. Capturar datos de bebidas por pueblo\n");
        printf("2. Mostrar bebida más consumida en total\n");
        printf("3. Mostrar bebida alcohólica más consumida\n");
        printf("4. Mostrar pueblo que consume más alcohol\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                capturarDatos(arr);
                break;
            case 2:
                mostrarBebidaMasConsumida(arr);
                break;
            case 3:
                mostrarBebidaAlcoholicaMasConsumida(arr);
                break;
            case 4:
                mostrarPuebloMasAlcohol(arr);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }

    } while(opcion != 5);

    return 0;
}
