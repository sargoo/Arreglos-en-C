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
int insertarOrdenado(char a[], int v, char caracter);
void mostrarChar (char arreglo[], int valid);
char encontrarMayor (char a[], int valid);
int capicua (char a[], int v);
void invertirArreglo (char a[], int v);
void ordenarXseleccion(char a[], int v);
void ordenarXinsercion (char a[], int v);


int main()
{
    srand(time(NULL));
    int array[DIM];
    int flag = 0;
    char arrayCaracteresOrdenado [DIM];
    char arrayCaracteres [DIM];
    char otroArray [DIM];
    char arrayCapicua [DIM];
    float arrayFloat [100];
    int validos = 0;
    float validosFloat = 0;
    int validosCaracteres = 0;
    Pila pila;
    inicpila(&pila);

    /*validos = cargarArreglo (array, validos);
    printf("Validos : %i\n", validos);
    mostrarArreglo (array, validos);
    sumaElementos ( array, validos);
    copiarElementos(array, validos, &pila);
    validosFloat = cargarRandom(arrayFloat, 100, validos);
    mostrarFloat(arrayFloat, validosFloat);

    validosCaracteres = cargarArregloCaracter (arrayCaracteresOrdenado, validosCaracteres);
    printf("\n Indique que caracter quiere buscar en el arreglo: ");
    fflush(stdin);
    scanf("%c", &buscar);
    system("cls");
    flag = encontrarCaracter(arrayCaracteresOrdenado, validosCaracteres, buscar);

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

    system("pause");
    system("cls");
    system("color 07");

    printf("\n Indique que caracter quiere insertar en el arreglo: ");
    fflush(stdin);
    scanf("%c", &buscar);
    system("cls");

    validos = 0;
    validos = cargarArregloCaracter (arrayCaracteres, validos);
    validos = insertarOrdenado(arrayCaracteres, validos, buscar);
    mostrarChar (arrayCaracteres, validos);
    system("pause");

    validos = 0;
    validos = cargarArregloCaracter (otroArray, validos);
    mayor = encontrarMayor (otroArray, validos);
    mostrarChar (otroArray, validos);
    printf("El caracter mayor es: %c", mayor);

    validos = cargarArregloCaracter(arrayCapicua, validos);
    flag = capicua(arrayCapicua, validos);
    printf("VALIDOS: %i", validos);
    if(flag == 0)
    {
        printf("El arreglo %s SI es capicua.", arrayCapicua);
    }
    else
    {
        printf("El arreglo %s NO es capicua.", arrayCapicua);
    }

    validos = cargarArregloCaracter(arrayCaracteres, validos);
    mostrarChar(arrayCaracteres, validos);
    printf("\n");
    invertirArreglo(arrayCaracteres,validos);
    mostrarChar(arrayCaracteres, validos);

    validos = cargarArregloCaracter(arrayCaracteres, validos);
    ordenarXseleccion(arrayCaracteres,validos);
    mostrarChar(arrayCaracteres,validos);*/

    validos = cargarArregloCaracter(arrayCaracteres, validos);
    ordenarXseleccion(arrayCaracteres, validos);
    mostrarChar(arrayCaracteres, validos);
    system("pause");

    printf("INGRESE UN ELEMENTO PARA INSERTAR EN EL ARREGLO DE CARACARTERES: \n");
    fflush(stdin);
    scanf("%c", &arrayCaracteres[validos +1]);
    mostrarChar(arrayCaracteres, validos);
    printf("ARRAY CON ELEMENTO A INSERTAR: \n");
    ordenarXinsercion(arrayCaracteres, validos);
    mostrarChar(arrayCaracteres, validos);



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
        printf("\n Ingrese un valor al arreglo de caracteres: \n");
        fflush(stdin);
        scanf("%c", &arreglo[valid]);
        valid ++;
        printf("Seguir cargando datos?\n Cualq. tecla: SI\n Esc: NO");
        opcion = getch();
        system("cls");
    }
    return valid;
}

int insertarOrdenado(char a[], int v, char caracter)
{
    int i = v - 1;
    while(i >= 0 && a[i] > caracter)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=caracter;

    return v+1;
}

void mostrarChar (char arreglo[], int valid)
{
    int i = 0;
    while (i < valid )
    {
        printf("|%c|", arreglo[i]);
        i++;
    }
}


///Realizar una función que obtenga el máximo carácter de un arreglo dado.

char encontrarMayor (char a[], int valid)
{
    int i = valid -1;
    char m = a[i];

    while (i >= 0)
    {
        if (m < a[i] )
        {
            m = a[i];
            i--;
        }
        else
        {
            i--;
        }
    }

    return m;
}


///Realizar una función que determine si un arreglo es capicúa.

int capicua (char a[], int v)
{

    int i = 0;
    int flag = 0;
    v = v -1;

    while(v > 0 && i < v && flag == 0)
    {
        if(a[i] == a[v])
        {
            i++;
            v--;
        }
        else
        {

            flag = 1;
        }
    }

    return flag;
}

///Realizar una función que invierta los elementos de un arreglo.

void invertirArreglo (char a[], int v)
{

    int i = 0;
    v = v -1;
    char aux;

    while(v > i)
    {
        aux = a[v];
        a[v] = a[i];
        a[i] = aux;
        v--;
        i++;
    }
}

/// Ordenar un arreglo según los siguientes métodos: A)Selección B)Inserción

void ordenarXseleccion(char a[], int v)

{
    int i = 0;
    char aux;

    while (i < v-1 )
    {
        while(a[i] > a[i+1])
        {
            aux = a[i+1];
            a[i+1] = a[i];
            a[i] = aux;

            while(i > 0 && a[i] < a[i-1])
            {
                aux = a[i-1];
                a[i-1] = a[i];
                a[i] = aux;
                i--;
            }
        }
        i++;
    }
}


void ordenarXinsercion (char a[], int v)
{
    int i = v;
    char aux;

    while(i >= 0)
    {
        while(a[i] < a[i-1])
        {
            aux = a[i-1];
            a[i-1] = a[i];
            a[i] = aux;
        }
        i--;
    }
}


