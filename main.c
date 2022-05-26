#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#include <time.h>

#define DIM 50
#define ESC 27


int cargarArreglo (int arreglo[], int valid);
void mostrarArreglo (int arreglo[], int valid);
void sumaElementos (int arreglo[], int valid);
void copiarElementos(int arreglo[], int valid, Pila *p);
int  cargarRandom(float arreglo[], int dimension, int valid);
void mostrarFloat (float arreglo[], int valid);
int encontrarCaracter (char arreglo[], int valid, char caracter);
int cargarArregloCaracter (char arreglo[], int valid);

int main()
{
    srand(time(NULL));
    int array[DIM];
    int flag = 0;
    char arrayCaracteres [DIM];
    float arrayFloat [100];
    int validos = 0;
    float validosFloat = 0;
    int validosCaracteres = 0;
    char buscar;
    Pila pila;
    inicpila(&pila);

    validos = cargarArreglo (array, validos);
    printf("Validos : %i\n", validos);
    mostrarArreglo (array, validos);
    sumaElementos ( array, validos);
    copiarElementos(array, validos, &pila);
    validosFloat = cargarRandom(arrayFloat, 100, validos);
    mostrarFloat(arrayFloat, validosFloat);

    validosCaracteres = cargarArregloCaracter (arrayCaracteres, validosCaracteres);
    printf("\n Indique que caracter quiere buscar en el arreglo: ");
    fflush(stdin);
    scanf("%c", &buscar);
    system("cls");
    flag = encontrarCaracter(arrayCaracteres, validosCaracteres, buscar);

    if(flag == 1)

    {
     system("color 27");
     printf("El caracter SI se encuentra en el arreglo.");
    }
    else
    {
        system("color 47");
        printf("El caracter NO se encuentra en el arreglo.");
    }

    return 0;
}

int cargarArreglo (int arreglo[], int valid)
{
    int opcion = 0;
    printf("1- Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos)\n");
    while (opcion != ESC &&  valid < DIM)
    {
        printf("Ingrese in valor al arreglo: \n");
        scanf("%i", &arreglo[valid]);
        valid ++;
        printf("Seguir cargando datos?\n Cualq. tecla: SI\n Esc: NO");
        opcion = getch();
        system("cls");
    }
    return valid;
}

void mostrarArreglo (int arreglo[], int valid)
{
    int i = 0;
    printf("2- Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.\n");
    while (i < valid )
    {
        printf("|%i|", arreglo[i]);
        i++;
    }
}

void sumaElementos (int arreglo[], int valid)
{
    printf("\n 3- Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila\n");
    int total = 0;

    for (int i = 0; i < valid; i++)
    {
        total = total + arreglo[i];
    }
    printf("la suma de todos los elementos del arreglo es: %i\n", total);
}

void copiarElementos(int arreglo[], int valid, Pila *p)
{
    printf("\n 4- Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.");
    int i = 0;

    while (i < valid)
    {
        apilar(p, arreglo[i]);
        i++;
    }
    mostrar(p);

}

void sumaElementosFloat (float arreglo [], int valid)
{
    printf("\n 5- Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)");
}

void mostrarFloat (float arreglo[], int valid)
{
    int i = 0;
    while (i < valid )
    {
        printf("|%.2f|", arreglo[i]);
        i++;
    }
}

int  cargarRandom(float arreglo[], int dimension, int valid)
{

    float valorRandom;
    int i = 0;

    for (i = 0; i < dimension; i++)
    {
        valorRandom = rand()%10 / 1.3 ;
        arreglo[i] = valorRandom;

    }
    return i;
}

/// Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.

int encontrarCaracter (char arreglo[], int valid, char caracter)
{
    int flag = 0;
    int i = 0;

    while(i < valid && flag == 0)
    {
        if (arreglo[i] == caracter)
        {
            flag = 1;
        }
        i ++;
    }
   return flag;
}

int cargarArregloCaracter (char arreglo[], int valid)
{
    int opcion = 0;
    system("cls");
    while (opcion != ESC &&  valid < DIM)
    {
        printf("\n Ingrese in valor al arreglo de caracteres: \n");
        fflush(stdin);
        scanf("%c", &arreglo[valid]);
        valid ++;
        printf("Seguir cargando datos?\n Cualq. tecla: SI\n Esc: NO");
        opcion = getch();
        system("cls");
    }
    return valid;
}
