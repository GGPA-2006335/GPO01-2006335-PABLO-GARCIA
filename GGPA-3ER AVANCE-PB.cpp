#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>//new, delete punteros
#include <fstream>//archivos
using namespace std;
void alta();
void listas();
void elimin();
void modi();
void archi();
int* a, regi, * numa, sn, n = 1;
float* imp, * pun, * tot;
string* carac, * desc, * nom, * gen, * clas;

void alta() {
    sn = 0;//para limpiar la variable
    printf("ingresa la cantidad de registros\n");
    scanf_s("%d", &regi);
    a = new int[regi];
    numa = new int[regi];
    imp = new float[regi];
    pun = new float[regi];
    tot = new float[regi];
    carac = new string[regi];// se usa el operador new para asignarle memoria dinamica a los punteros
    desc = new string[regi];
    nom = new string[regi];
    gen = new string[regi];
    clas = new string[regi];
    for (int i = 0; i < regi; i++) {
        printf("ingresa el numero de articulo\n");
        scanf_s("%d", &numa[i]);
        if (i > 0) {//para que pueda funcionar de manera correcta el ciclo for
            do {
                if (numa[i] == numa[i - n]) {
                    printf("ingrese otro numero de articulo\n");
                    scanf_s("%d", &numa[i]);
                }
                else {
                    n = n + 1;
                }
            } while (n < regi);
        }
        printf("ingresa el A%co de lanzamiento\n", 164);
        scanf_s("%d", &a[i]);
        printf("ingresa el nombre del videojuego\n");
        cin.ignore();
        getline(cin, nom[i]);
        printf("ingresa la clasificacion *Mantenga un mismo formato al ingresar los datos*\n");
        getline(cin, clas[i]);
        printf("ingresa las caracteristicas\n");
        getline(cin, carac[i]);
        printf("ingresa la descripcion\n");
        getline(cin, desc[i]);
        printf("ingresa el genero *Mantenga un mismo formato al ingresar los datos*\n");
        getline(cin, gen[i]);
        printf("ingresa el precio unitario\n");
        scanf_s("%f", &pun[i]);
        imp[i] = pun[i] * .16;
        printf("El impuesto es de %f\n", imp[i]);
        tot[i] = pun[i] * 1.16;
        printf("El total es de %f\n", tot[i]);
        /*if ((regi - 1) == i) {
            do {
                printf("deseea agregar otro articulo 1.si 2.no\n");
                scanf_s("%d", &sn);
                switch (sn) {
                case 1:
                    regi = regi + 1;
                    break;
                case 2:
                    break;
                default:
                    printf("opcion no valida\n");
                }
            } while (sn != 1 && sn != 2);
        }*/
    }
}

void listas() {
    int op1;
    string bus;
    do {
        printf("1.Clasificacion\n 2.Genero\n 3.salir\n");
        scanf_s("%d", &op1);
        switch (op1) {
        case 1:
            printf("ingrese la clasificacion a buscar\n");
            cin.ignore();
            getline(cin, bus);
            for (int i = 0; i < regi; i++) {
                if (bus == clas[i] && numa[i] != 0) {
                    printf("el numero de articulo: %d\n", numa[i]);
                    printf("nombre del videojuego: %s\n", nom[i].c_str());
                    printf("a%co de lanzamiento: %d\n", 164, a[i]);
                    printf("la clasificacion: %s\n", clas[i].c_str());
                    printf("la caracteristicas: %s\n", carac[i].c_str());
                    printf("la descripcion: %s\n", desc[i].c_str());
                    printf("el genero: %s\n", gen[i].c_str());
                    printf("el precio unitario: %f \n", pun[i]);
                    printf("el impuesto es de: %f \n", imp[i]);
                    printf("el total es: %f \n", tot[i]);
                }
            }
            break;
        case 2:
            printf("ingrese el genero a buscar\n");
            cin.ignore();
            getline(cin, bus);
            for (int i = 0; i < regi; i++) {
                if (bus == gen[i] && numa[i] != 0) {
                    printf("el numero de articulo: %d\n", numa[i]);
                    printf("nombre del videojuego: %s\n", nom[i].c_str());
                    printf("a%co de lanzamiento: %d\n", 164, a[i]);
                    printf("la clasificacion: %s\n", clas[i].c_str());
                    printf("la caracteristicas: %s\n", carac[i].c_str());
                    printf("la descripcion: %s\n", desc[i].c_str());
                    printf("el genero: %s\n", gen[i].c_str());
                    printf("el precio unitario: %f \n", pun[i]);
                    printf("el impuesto es de: %f \n", imp[i]);
                    printf("el total es: %f \n", tot[i]);;
                }
            }
            break;
        case 3:
            break;
        default:
            printf("ingresa una opcion correta\n");
            break;
        }
    } while (op1 != 3);
}

void elimin() {
    int eli, no = 0;
    do {
        printf("ingrese el numero de articulo a eliminar\n");
        scanf_s("%d", &eli);
        for (int i = 0; i < regi; i++) {
            if (eli == numa[i]) {
                numa[i] = 0;
                no = no + 1;
            }
        }
        if (no == 0) {
            printf("Numero de articulo no existe\n");
        }
    } while (no == 0);
}

void modi() {
    int modif, opcion;
    do {
        printf("ingrese el numero de articulo a modificar\n");
        scanf_s("%d", &modif);
    } while (modif < 0);
    do {
        printf("que desea modificar\n1.Numero de articulo\n2.Nombre del videojuego\n3.A%co de lanzamiento\n4.Clasificacion\n5.Caracteristicas\n6.Descripcion\n7.Genero\n8.Precio unitario\n9.Salir\n", 164);
        scanf_s("%d", &opcion);
        switch (opcion) {
        case 1:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    scanf_s("%d", &numa[i]);
                }
            }
            break;
        case 2:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, nom[i]);
                }
            }
            break;
        case 3:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    scanf_s("%d", &a[i]);
                }
            }
            break;
        case 4:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, clas[i]);
                }
            }
            break;
        case 5:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, carac[i]);
                }
            }
            break;
        case 6:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, desc[i]);
                }
            }
            break;
        case 7:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, gen[i]);
                }
            }
            break;
        case 8:
            for (int i = 0; i < regi; i++) {
                if (modif == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    scanf_s("%d", &pun[i]);
                    imp[i] = pun[i] * .16;
                    tot[i] = pun[i] * 1.16;
                }
            }
            break;
        case 9://salir
            break;
        default:
            printf("ingrese una opcion correcta\n");
            break;
        }
    } while (opcion != 9);

}

void archi() {
    ofstream archivo;
    string nombre;
    nombre = "LISTAS PARADISE GAMES";
    archivo.open(nombre.c_str(), ios::out);

    if (archivo.fail()) {
        printf("ERROR AL CREAR ARCHIVO\n");
        system("pause");
        exit(1);
    }
    archivo << "Se seguira este formato" << "\n";
    archivo << "Numero de articulo" << "\t";
    archivo << "Nombre del videojuego" << "\t";
    archivo << "Año de lanzamiento" << "\t";
    archivo << "Clasificacion" << "\t";
    archivo << "Caracteristicas" << "\t";
    archivo << "Descripcion" << "\t";
    archivo << "Genero" << "\t";
    archivo << "Precio unitario" << "\t";
    archivo << "Impuesto" << "\t";
    archivo << "Total" << "\n";
    for (int i = 0; i < regi; i++) {
        if (numa[i] != 0) {
            archivo << numa[i] << "\t";
            archivo << nom[i].c_str() << "\t";
            archivo << a[i] << "\t";
            archivo << clas[i].c_str() << "\t";
            archivo << carac[i].c_str() << "\t";
            archivo << desc[i].c_str() << "\t";
            archivo << gen[i].c_str() << "\t";
            archivo << pun[i] << "\t";
            archivo << imp[i] << "\t";
            archivo << tot[i] << "\n";
        }
    }
}

int main() {
    int opc;
    do {
        printf("        PARADISE GAMES        \n");
        printf("ingrese la opcion que desee\n");
        printf(" 1.-Agregar Articulo\n 2.-Modificar Articulo\n 3.-Eliminar Articulo\n 4.-Lista de Articulos vigentes\n 5.-Limpiar pantalla\n 6.-Salir\n");
        scanf_s("%d", &opc);

        switch (opc) {
        case 1:
            alta();
            system("pause");
            break;
        case 2:
            modi();
            system("pause");
            break;
        case 3:
            elimin();
            system("pause");
            break;
        case 4:
            listas();
            system("pause");
            break;
        case 5:
            system("pause");
            system("cls");
            break;
        case 6:
            archi();
            system("pause");
            exit(1);
            break;
        default:
            printf("ingrese una opcion correcta\n");
            system("pause");
            break;
        }
    } while (opc != 6);
}