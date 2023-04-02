#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <wchar.h>
#include <math.h>

using namespace std;

struct datos
{
	int ID = 0;
	float preUnitario;
	string nombre, descripcion, genero, clasificacion, consola;
};

float precio(float x);

int main()
{
	datos articulo[3];
	int opcion;

	do
	{
		printf("Ingrese la opción deseada \n");
		printf("1.- Alta de articulos \n");
		printf("2.- Mod. articulos \n");
		printf("3.- Baja de articulos \n");
		printf("4.- Lista de articulos \n");
		printf("5.- Limpiar pantalla \n");
		printf("6.- Salir \n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1: //Alta
			for (int i = 0; i < 3; i++)
			{
				printf("Ingrese los datos del articulo \n");
				printf("ID del articulo: ");
				scanf_s("%d", &articulo[i].ID);
				while ((i > 0 && articulo[i].ID == articulo[0].ID) || (i == 2 && articulo[i].ID == articulo[1].ID))
				{
					printf("Este ID no se encuentra disponible, vuelva a ingresar \nID del articulo: ");
					scanf_s("%d", &articulo[i].ID);
				}
				printf("Nombre del articulo: ");
				cin.ignore();
				getline(cin, articulo[i].nombre);
				printf("Genero: ");
				getline(cin, articulo[i].genero);
				printf("Clasificacion: ");
				getline(cin, articulo[i].clasificacion);
				printf("Descripcion: \n");
				getline(cin, articulo[i].descripcion);
				printf("Consola: ");
				getline(cin, articulo[i].consola);
				printf("Precio Unitario: ");
				scanf_s("%f", &articulo[i].preUnitario);
				printf("\n");//Se salta el scanf
			}
			break;
		case 2: //Modificacion
			break;
		case 3: //Baja
			break;
		case 4: //Lista
			for (int i = 0; i < 3; i++) // No imprime los datos correctamente
			{
				printf("ID del articulo: %d \n", articulo[i].ID);
				printf("Nombre del articulo: %s \n", articulo[i].nombre.c_str());
				printf("Genero: %s \n", articulo[i].genero.c_str());
				printf("Clasificacion: %s \n", articulo[i].clasificacion.c_str());
				printf("Descripcion: \n%s \n", articulo[i].descripcion.c_str());
				printf("Consola: %s \n", articulo[i].consola.c_str());
				printf("Precio: %f \n", precio(articulo[i].preUnitario));
			}
			break;
		case 5: //Limpiar pantalla
			system("cls");
		case 6: //Salir
			exit(1);
			break;
		}

		system("pause");
	} while (opcion != 6);
}

float precio(float x)
{
	float total;
	total = x * 1.16;
	return total;
}