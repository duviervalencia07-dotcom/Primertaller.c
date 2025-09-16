#include <stdio.h>

#define N 10

void llenarArray(int a[]);
void mostrarArray(int a[]);
void ordenarSelectionAscendente(int a[]);
void ordenarInsertionDescendente(int a[]);
void copiarArray(int origen[], int destino[]);

int main() {
    int opcion;
    int arreglo[N];
    int copia[N];
    int registrado = 0;

    do {
        printf("\n--- Menu de Opciones ---\n");
        printf("1. Registrar tiempos\n");
        printf("2. Mostrar arreglo original\n");
        printf("3. Ordenar ascendente (Selection Sort)\n");
        printf("4. Ordenar descendente (Insertion Sort)\n");
        printf("5. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                llenarArray(arreglo);
                registrado = 1;
                break;
            case 2:
                if (registrado) {
                    printf("Arreglo original: ");
                    mostrarArray(arreglo);
                } else {
                    printf("Primero registre los tiempos.\n");
                }
                break;
            case 3:
                if (registrado) {
                    copiarArray(arreglo, copia);
                    ordenarSelectionAscendente(copia);
                } else {
                    printf("Primero registre los tiempos.\n");
                }
                break;
            case 4:
                if (registrado) {
                    copiarArray(arreglo, copia);
                    ordenarInsertionDescendente(copia);
                } else {
                    printf("Primero registre los tiempos.\n");
                }
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 5);

    return 0;
}

void llenarArray(int a[]) {
    printf("Ingrese 10 tiempos enteros positivos:\n");
    for (int i = 0; i < N; i++) {
        do {
            printf("Tiempo %d: ", i + 1);
            scanf("%d", &a[i]);
            if (a[i] <= 0) {
                printf("Error: debe ser positivo. Intente de nuevo.\n");
            }
        } while (a[i] <= 0);
    }
}

void mostrarArray(int a[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void ordenarSelectionAscendente(int a[]) {
    printf("Ordenando con Selection Sort (ascendente):\n");
    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
        printf("Paso %d: ", i + 1);
        mostrarArray(a);
    }
    printf("Resultado final: ");
    mostrarArray(a);
}

void ordenarInsertionDescendente(int a[]) {
    printf("Ordenando con Insertion Sort (descendente):\n");
    for (int i = 1; i < N; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printf("Paso %d: ", i);
        mostrarArray(a);
    }
    printf("Resultado final: ");
    mostrarArray(a);
}

void copiarArray(int origen[], int destino[]) {
    for (int i = 0; i < N; i++) {
        destino[i] = origen[i];
    }
}
