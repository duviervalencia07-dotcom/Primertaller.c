#include <stdio.h>

// Prototipos
void llenarArray(int a[], int n);
void mostrarArray(int a[], int n);
void ordenarSelectionAscendente(int a[], int n);
void ordenarInsertionDescendente(int a[], int n);

int main() {
    int a[10];
    int opcion;
    int n = 10;
    int datosIngresados = 0; // Bandera para validar si ya se llenó el arreglo

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Registrar tiempos\n");
        printf("2. Mostrar arreglo original\n");
        printf("3. Ordenar con Selection Sort (ascendente)\n");
        printf("4. Ordenar con Insertion Sort (descendente)\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                llenarArray(a, n);
                datosIngresados = 1;
                break;
            case 2:
                if (datosIngresados)
                    mostrarArray(a, n);
                else
                    printf("Debe registrar primero los tiempos.\n");
                break;
            case 3:
                if (datosIngresados)
                    ordenarSelectionAscendente(a, n);
                else
                    printf("Debe registrar primero los tiempos.\n");
                break;
            case 4:
                if (datosIngresados)
                    ordenarInsertionDescendente(a, n);
                else
                    printf("Debe registrar primero los tiempos.\n");
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while(opcion != 0);

    return 0;
}


void llenarArray(int a[], int n) {
    int valor;
    for (int i = 0; i < n; i++) {
        do {
            printf("Ingrese tiempo %d (entero positivo): ", i + 1);
            scanf("%d", &valor);
            if (valor <= 0) {
                printf("El valor debe ser un entero positivo. Intente de nuevo.\n");
            }
        } while (valor <= 0);
        a[i] = valor;
    }
}


void mostrarArray(int a[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}


void ordenarSelectionAscendente(int a[], int n) {
    int i, j, min, temp;
    printf("\nProceso Selection Sort Ascendente:\n");
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        // Intercambio
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("Paso %d: ", i + 1);
        mostrarArray(a, n);
    }
    printf("\nResultado final (ascendente): ");
    mostrarArray(a, n);
}


void ordenarInsertionDescendente(int a[], int n) {
    int i, j, key;
    printf("\nProceso Insertion Sort Descendente:\n");
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        // Mover los elementos menores que key hacia adelante
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        printf("Paso %d: ", i);
        mostrarArray(a, n);
    }
    printf("\nResultado final (descendente): ");
    mostrarArray(a, n);
}

