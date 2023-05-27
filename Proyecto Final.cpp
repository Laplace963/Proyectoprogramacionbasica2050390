#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;
//declaracion de variables

struct datos
{
	int ID = 0;
	float preUnitario, preFinal;
	string nombre, descripcion, genero, clasificacion, consola, estado;
};

int alta;

datos *articulo;//punteros

//funciones con void
void Alta();
void Modificacion();
void Baja();
void Lista();
void Archivos();

int main()
{
	int opcion;

	printf("\t%c %c %c Ingrese la opcion deseada %c %c %c\n", 175, 175, 175, 174, 174, 174);
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
		Alta();
		return main();
		break;
	case 2: //Modificacion
		Modificacion();
		return main();
		break;
	case 3: //Baja
		Baja();
		return main();
		break;
	case 4: //Lista
		Lista();
		return main();
		break;
	case 5: //Limpiar pantalla
		system("cls");
		return main();
		break;
	case 6: //Salir
		Archivos();
		break;
	}
}

void Alta()
{
	printf("Cuantos articulos desea dar de alta? \n");
	scanf_s("%d", &alta);
	articulo = new datos[alta];

	for (int i = 0; i < alta; i++)
	{
		printf("Ingrese los datos del articulo \n");
		printf("ID del articulo: ");
		scanf_s("%d", &articulo[i].ID);
		for (int j = 0; j < alta; j++)
		{
			while (articulo[i].ID == articulo[j].ID && j != i)
			{
				printf("Ingrese otro ID: ");
				scanf_s("%d", &articulo[i].ID);
			}
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
		articulo[i].preFinal = articulo[i].preUnitario * 1.16;
		printf("\n");
	}
}

void Modificacion()
{
	int j, opcion, op2;
	do
	{
		printf("Ingrese el registro a modificar \n");
		scanf_s("%d", &j);
		j = j - 1;

		for (int i = j; i == j; i++)
		{
			if (articulo[i].estado == "EN BAJA")
			{
				printf("ARTICULO EN BAJA %d \nIngrese un registro valido \n", i + 1);
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);

	printf("Ingrese que desea modificar: \n1.-ID 2.-Nombre 3.-Descripcion 4.-Genero 5.-Clasificacion 6.-Consola 7.-Precio unitario \n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese ID: ");
			scanf_s("%d", &articulo[i].ID);
			for (int h = 0; h < alta; h++)
			{
				while (articulo[i].ID == articulo[h].ID && h != i)
				{
					printf("Ingrese otro ID: ");
					scanf_s("%d", &articulo[i].ID);
				}
			}
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese nombre: ");
			getline(cin, articulo[i].nombre);
		}
		break;
	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese descripcion: \n");
			getline(cin, articulo[i].descripcion);
		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese genero: ");
			getline(cin, articulo[i].genero);
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese clasificacion: ");
			getline(cin, articulo[i].clasificacion);
		}
		break;
	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("Ingrese consola: ");
			getline(cin, articulo[i].consola);
		}
		break;
	case 7:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese precio unitario: ");
			scanf_s("%f", &articulo[i].preUnitario);
			articulo[i].preFinal = articulo[i].preUnitario * 1.16;
		}
		break;
	}
}

void Baja() 
{
	int j;
	printf("Ingrese el registro a eliminar \n");
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando registro %d \n", j + 1);
		articulo[i].estado = "EN BAJA";
	}
}

void Lista()
{
	for (int i = 0; i < alta; i++)
	{
		if (articulo[i].estado == "EN BAJA")
		{
			printf("REGISTRO ELIMINADO %d \n \n", i + 1);
		}
		else
		{
			printf("ID del articulo: %d \n", articulo[i].ID);
			printf("Nombre del articulo: %s \n", articulo[i].nombre.c_str());
			printf("Genero: %s \n", articulo[i].genero.c_str());
			printf("Clasificacion: %s \n", articulo[i].clasificacion.c_str());
			printf("Descripcion: \n%s \n", articulo[i].descripcion.c_str());
			printf("Consola: %s \n", articulo[i].consola.c_str());
			printf("Precio total: %f \n \n", articulo[i].preFinal);
		}
	}
}

void Archivos()
{
	ofstream archivo; //crear archivo y escribir en él
	string nombrearchivo;
	int texto;
	string texto2;

	nombrearchivo = "ProyectoF.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("\n\nERROR NO SE PUDO CREAR EL ARCHIVO");
	}

	archivo << "ID" << "\t" << "\t";
	archivo << "NOMBRE" << "\t" << "\t";
	archivo << "GENERO" << "\t" << "\t";
	archivo << "CLASIFICACION" << "\t" << "\t";
	archivo << "DESCRIPCION" << "\t" << "\t";
	archivo << "CONSOLA" << "\t" << "\t";
	archivo << "PRECIO TOTAL" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (articulo[i].estado == "EN BAJA")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i + 1;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = articulo[i].ID;
			archivo << texto << "\t";
			texto2 = articulo[i].nombre;
			archivo << texto2 << "\t";
			texto2 = articulo[i].genero;
			archivo << texto2 << "\t";
			texto2 = articulo[i].clasificacion;
			archivo << texto2 << "\t";
			texto2 = articulo[i].descripcion;
			archivo << texto2 << "\t";
			texto2 = articulo[i].consola;
			archivo << texto2 << "\t";
			texto = articulo[i].preFinal;
			archivo << texto << "\n";
		}
	}

	archivo.close();
}