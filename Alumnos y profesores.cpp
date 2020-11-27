/*
	Nombre: POO (Inscripcion de alumnos y profesores)
	Autor: Esleiter Jose Fajardo Laya
	Fecha: 26/11/20
	Lugar: Venezuela
*/

#include <iostream>
#include <stdlib.h>

#define MAXCAD 50
#define MAX_V 100

using namespace std;

void menu()
{
	cout<<"\n\t\tRegistro del IUPSM \n\n";
	cout<<"1. Registrar profesor              "<<endl;
	cout<<"2. Registrar alumno                "<<endl;
	cout<<"3. Mostrar personas                "<<endl;
	cout<<"4. Mostrar datos de un profesor    "<<endl;
	cout<<"5. Mostrar datos de un estudiante  "<<endl;
	cout<<"6. Salir                           "<<endl;
	
	cout<<"\n Ingrese una opcion y presione enter: ";
}

struct Persona {
	char nombre[MAXCAD];
	char genero[MAXCAD];
	char direccion[MAXCAD];
	int ci;
	int edad;
};

struct Profesor: virtual Persona {
	char dedicacion[MAXCAD];
};

struct Profesor lista[MAX_V];
struct Profesor aux;

struct Estudiante: virtual Persona {
	char semestre[MAXCAD];
	char carrera[MAXCAD];
};

struct Estudiante lista2[MAX_V];
struct Estudiante aux2;

void registrarProf(int n) {
	for	(int i=0; i<n; i++)
	{
		cout<<"\nProfesor "<< i+1 <<"\n";
		cin.ignore(); cout << "Nombre: "; cin>> lista[i].nombre;
		cin.ignore(); cout << "Genero: "; cin>> lista[i].genero;
		cin.ignore(); cout << "Direcion: "; cin>> lista[i].direccion;
		cin.ignore(); cout << "CI: "; cin>> lista[i].ci;
		cin.ignore(); cout << "Edad: "; cin>> lista[i].edad;
		cin.ignore(); cout << "Dedicacion: "; cin>> lista[i].dedicacion;
	}
}

void registrarAlum(int n) {
	for	(int i=0; i<n; i++)
	{
		cout<<"\nAlumno "<< i+1 <<"\n";
		cin.ignore(); cout << "Nombre: "; cin>> lista2[i].nombre;
		cin.ignore(); cout << "Genero: "; cin>> lista2[i].genero;
		cin.ignore(); cout << "Direcion: "; cin>> lista2[i].direccion;
		cin.ignore(); cout << "CI: "; cin>> lista2[i].ci;
		cin.ignore(); cout << "Edad: "; cin>> lista2[i].edad;
		cin.ignore(); cout << "Semestre: "; cin>> lista2[i].semestre;
		cin.ignore(); cout << "Carrera: "; cin>> lista2[i].carrera;
	}
}

void datosProf(int x, int num)
{
	if(num>0){
		cout<<endl<<endl;
		cout << "\t"<< lista[x].nombre << endl;
		cout << "Genero: "<< lista[x].genero<< endl;
		cout << "Direccion: "<< lista[x].direccion<< endl;
		cout << "CI: "<< lista[x].ci<< endl;
		cout << "Edad: "<< lista[x].edad<< endl;
		cout << "Dedicacion: "<< lista[x].dedicacion<< endl;
	}
}

void datosAlum(int x, int num)
{
	if(num>0){
		cout<<endl<<endl;
		cout << "\t"<< lista2[x].nombre << endl;
		cout << "Genero: "<< lista2[x].genero<< endl;
		cout << "Direccion: "<< lista2[x].direccion<< endl;
		cout << "CI: "<< lista2[x].ci<< endl;
		cout << "Edad: "<< lista2[x].edad<< endl;
		cout << "Semestre: "<< lista2[x].semestre<< endl;
		cout << "Carrera: "<< lista2[x].carrera<< endl;
	}
}

void mostrar_personas(int num){
	if(num>0)
	{
		cout<<"\n\nLista de profesores";
		for(int i=0; i<num; i++){
			cout<<endl<<endl;
			cout<<i+1<<". "<< lista[i].nombre << endl;
			cout<<endl;
		}
	}
	else cout<<"\n\tRegistro vacio.";
	
	if(num>0)
	{
		cout<<"\n\nLista de alumnos";
		for(int i=0; i<num; i++){
			cout<<endl<<endl;
			cout<<i+1<<". "<< lista2[i].nombre << endl;
			cout<<endl;
		}
	}
	else cout<<"\n\tRegistro vacio.";
}

int main()
{
	int num=0;
	int op;
	int num_persona;
	
	system("color F0");
	printf("\n Desarrollado por Esleiter Fajardo \n\n");
	
	do
	{
		menu(); cin >> op;
		
		switch(op)
		{
			case 1:
				cout<<"\n Numeros de profesores a registrar: ";
				cin>> num;
				registrarProf(num); cout<<endl;
				break;
			
			case 2:
				cout<<"\n Numeros de alumnos a registrar: ";
				cin>> num;
				registrarAlum(num); cout<<endl;
				break;
			
			case 3:
				mostrar_personas(num);
				break;
				
			case 4:
				cout<<"\n Ingrese numero del profesor a buscar: ";
				cin>> num_persona;
				datosProf(num_persona-1, num);
				break;
			
			case 5:
				cout<<"\n Ingrese numero del alumno a buscar: ";
				cin>> num_persona;
				datosAlum(num_persona-1, num);
				break;
		}
		
		cout<<endl<<endl;
		
		system("PAUSE"); system("cls");
	} while(op != 6);
	
	return 0;
}

