#include <stdio.h>

#define NUM_ESTUDIANTES 6

typedef struct {
    int codigo;
    float nota;
} Estudiante;

Estudiante estudiantes[NUM_ESTUDIANTES] = {
    {101, 14.5},
    {102, 16.0},
    {103, 12.0},
    {104, 18.7},
    {105, 15.3},
    {106, 13.2}
};

void mostrarEstudiantes(int idx) {
    if (idx >= NUM_ESTUDIANTES) return;
    printf("Codigo: %d, Nota: %.2f\n", estudiantes[idx].codigo, estudiantes[idx].nota);
    mostrarEstudiantes(idx + 1);
}

int buscarEstudiante(int codigo, int idx) {
    if (idx >= NUM_ESTUDIANTES) return -1;
    if (estudiantes[idx].codigo == codigo) return idx;
    return buscarEstudiante(codigo, idx + 1);
}

double sumarNotas(int idx) {
    if (idx >= NUM_ESTUDIANTES) return 0.0;
    return estudiantes[idx].nota + sumarNotas(idx + 1);
}

void menu() {
    int opcion;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Mostrar estudiantes\n");
        printf("2. Buscar estudiante por codigo\n");
        printf("3. Calcular promedio de notas\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nLista de estudiantes:\n");
                mostrarEstudiantes(0);
                break;
            case 2: {
                int codigo, pos;
                printf("Ingrese codigo del estudiante a buscar: ");
                scanf("%d", &codigo);
                pos = buscarEstudiante(codigo, 0);
                if (pos == -1)
                    printf("Estudiante no encontrado.\n");
                else
                    printf("Estudiante encontrado: Codigo %d, Nota %.2f\n", estudiantes[pos].codigo, estudiantes[pos].nota);
                break;
            }
            case 3: {
                double promedio = sumarNotas(0) / NUM_ESTUDIANTES;
                printf("Promedio de notas: %.2f\n", promedio);
                break;
            }
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

int main() {
    menu();
    return 0;
}
