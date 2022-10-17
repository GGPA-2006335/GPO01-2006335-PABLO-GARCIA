//https://github.com/GGPA-2006335/GPO01-2006335-PABLO-GARCIA
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

struct tienda {
    int numa;//numero de articulo
    float pun;//precio unitario
    float imp ;//impuesto
    float tot ;//total
    int a;//ano de lanzamiento
  
    string clas;//clasificacion
    string carac;//caracteristicas
    string desc;//descripcion
    string gen;//genero
    string nom;// nombre del videojuego
};

int main()
{
    tienda bd[3] = { 0 };
    int opc, busq, s;// para el switch 

    do {
        printf("        PARADISE GAMES        \n");
        printf("ingrese la opcion que desee\n");
        printf(" 1.-Agregar Articulo\n 2.-Modificar Articulo\n 3.-Eliminar Articulo\n 4.-Lista de Articulos vigentes\n 5.-Limpiar pantalla\n 6.-Salir\n");
        scanf_s("%d", &opc);

        switch (opc) {

        case 1://agregar articculo

            for (int i = 0; i < 3; i++) {
                do {
                    printf("ingresa el numero de articulo\n");
                    scanf_s("%d", &bd[i].numa);
                    if (bd[i].numa == bd[i - 1].numa || bd[i].numa == bd[i - 2].numa)
                    {
                        printf("el numero de articulo ya existe \n");

                    }
                    else
                    {
                        s = 2;
                    }
                } while (s == 1);
                printf("ingresa el nombre del videojuego\n");
                cin.ignore();
                getline(cin, bd[i].nom);
                printf("ingresa el A%co de lanzamiento\n",164);
                scanf_s("%d", &bd[i].a);
                printf("ingresa la clasificacion\n");
                cin.ignore();
                getline(cin, bd[i].clas);
                printf("ingresa las caracteristicas\n");
                getline(cin, bd[i].carac);
                printf("ingresa la descripcion\n");
                getline(cin, bd[i].desc);
                printf("ingresa el genero\n");
                getline(cin, bd[i].gen);
                printf("ingresa el precio unitario\n");
                scanf_s("%f", &bd[i].pun);
                bd[i].imp = bd[i].pun * .16;
                printf("El impuesto es de %f\n", bd[i].imp);

                bd[i].tot = bd[i].pun * 1.16;
                printf("El total es de %f\n", bd[i].tot);
            }

            break;
        case 2://modificar articulo
            printf("ingrese el numero de articulo que desea modificar\n");
            scanf_s("%d", &busq);

            for (int i = 0; i < 3; i++) {
                if (busq ==bd[i].numa) {
                    printf("ingresa el nombre del videojuego\n");
                    cin.ignore();
                    getline(cin, bd[i].nom);
                    printf("ingresa el A%co de lanzamiento\n", 164);
                    scanf_s("%d", &bd[i].a);
                    printf("ingresa la clasificacion\n");
                    cin.ignore();
                    getline(cin, bd[i].clas);
                    printf("ingresa las caracteristicas\n");
                    getline(cin, bd[i].carac);
                    printf("ingresa la descripcion\n");
                    getline(cin, bd[i].desc);
                    printf("ingresa el genero\n");
                    getline(cin, bd[i].gen);
                    printf("ingresa el precio unitario\n");
                    scanf_s("%f", &bd[i].pun);
                    bd[i].imp = bd[i].pun * .16;
                    printf("El impuesto es de %f\n", bd[i].imp);
                    bd[i].tot = bd[i].pun * 1.16;
                    printf("El total es de %f\n", bd[i].tot);
                }
            }
            break;
        case 3://eliminar articulo
            printf("ingrese el numero de articulo que deseea eliminar\n");
            scanf_s("%d", &busq);
            for (int i = 0; i < 3; i++) {
                if (busq == bd[i].numa) {
                    bd[i].numa = 0;
                }
            }
            break;
        case 4://lista de articulos
            for (int i = 0; i < 3; i++) {
                printf("el numero de articulo %d\t",bd[i].numa);
                printf("nombre del videojuego %s\t",bd[i].nom .c_str());
                printf("a%co de lanzamiento %d\t",164,bd[i].a);
                printf("la clasificacion %s\t", bd[i].clas.c_str());
                printf("la caracteristicas %s\t", bd[i].carac.c_str());
                printf("la descripcion %s\t", bd[i].desc.c_str());
                printf("el genero %s\t", bd[i].gen.c_str());
                printf("el precio unitario %f \t", bd[i].pun);
                printf("el impuesto es de %f \t", bd[i].imp);
                printf("el total es %f \n", bd[i].tot);
            }
            break;
        case 5://limpiar pantalla
            system("cls");
            break;
        case 6://salir
            printf("saiendo...");
            exit(1);
            break;
        default:
            printf("ingrese una opcion correcta\n");
            break;
        }
    } while (opc != 6);
    system("pause");
  
}