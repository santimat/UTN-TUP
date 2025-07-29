#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarArray(int numeros[], int longitud);
int encontrarNumero(int numeros[], int longitud, int target);
void mostrarResultado(int res);
void mostrarNumeros(int numeros[], int longitud);

int main(){
    srand(time(NULL));
    int target = 0;
    int longitud = 10;
    int numeros[longitud];
    cargarArray(numeros, longitud);
    
    printf("Ingrese el numero que desea buscar\n");
    scanf("%d", &target);

    int res  = encontrarNumero(numeros, longitud, target);
    mostrarNumeros(numeros, longitud);

    mostrarResultado(res);

    return 0;
}

void cargarArray(int numeros[], int longitud)
{
    for(int i = 0; i < longitud; i++){
        int random = rand() % 100 + 1;
        numeros[i] = random;
    }
}

int encontrarNumero(int numeros[], int longitud, int target){
    int indice = -1;

    for(int i = 0; i < longitud; i++){
        if(numeros[i] == target){
            indice = i;
        }
    }
    return indice;
}

void mostrarResultado(int res)
{
    if (res != -1)
    {
        printf("El numero se encuentra en la posicion %d\n",res + 1);
    }else{
        printf("El numero ingresado no existe en el listado de numeros");
    }
}

void mostrarNumeros(int numeros[], int longitud)
{
    for(int i = 0; i < longitud; i++){
        printf(" %d |", numeros[i]);
    }
    printf("\n");
}