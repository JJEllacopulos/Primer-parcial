#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <ctime>

using namespace std;

#include "rlutil.h"
using namespace rlutil;

struct tiempo{
    int dia;
    int mes;
    int ano;
};

struct paciente{
    int dni;
    char apellido[50];
    char nombre[50];
    char genero;
    struct tiempo fecha;
    int obra_socila;
    bool estado;
};

struct medico{
    int num_maticula;
    char apellido[50];
    char nombre[50];
    int especialidad;
    float sueldo;
};

struct control{
    int id;
    int dni;
    int num_matricula;
    float costo;
    struct tiempo fecha;
    int duracion;
    bool estado;
};

#include "restricciones.h"
#include "OpcionesPasientes.h"
#include "OpcionesMedicos.h"
#include "OpcionesControles.h"
#include "OpcionesConfiguraciones.h"
#include "OpcionesReportes.h"
#include "OpcionesReportes_preparcial.h"
#include "menues.h"

///Menu principal:

int main(){

    int opcion;

    while(true){

        gotoxy(35,5);
        cout<< "MENU PERINCIPAL"<< endl;
        gotoxy(35,6);
        cout<< "---------------"<< endl;
        gotoxy(35,7);
        cout<< "1) "; setColor(CYAN); cout<< "PACIENTES"<< endl;
        setColor(WHITE);
        gotoxy(35,8);
        cout<< "2) "; setColor(LIGHTGREEN);cout<< "MEDICOS"<< endl;
        setColor(WHITE);
        gotoxy(35,9);
        cout<< "3) "; setColor(LIGHTMAGENTA);cout<< "CONTROLES"<< endl;
        setColor(WHITE);
        gotoxy(35,10);
        cout<< "4) "; setColor(LIGHTCYAN);cout<< "REPORTES"<< endl;
        setColor(WHITE);
        gotoxy(35,11);
        cout<< "5) "; setColor(LIGHTRED);cout<< "CONFIGURACION"<< endl;
        setColor(WHITE);
        gotoxy(35,12);
        cout<< "------------------------"<< endl;
        gotoxy(35,13);
        cout<< "0) "; setColor(DARKGREY); cout<< "SALIR DEL PROGRAMA"<< endl;
        setColor(WHITE);
        gotoxy(35,14);
        cout<< " > ";
        opcion = getch();

        system("cls");

        opcion-=48;

        switch(opcion){
            case 1:
                Menu_pacientes();
            break;
            case 2:
                Menu_medicos();
            break;
            case 3:
                Menu_controles();
            break;
            case 4:
                Menu_reportes();
            break;
            case 5:
                Menu_configuracion();
            break;
            case 0:
                gotoxy(35,5);
                cout<< "Gracias por sus servicios."<< endl<< endl;
                return 0;
            break;
            default:
                setColor(RED);
                gotoxy(35,5);
                cout<< "Ingresa una opcion valida."<< endl;
                setColor(WHITE);
                gotoxy(35,6);
                system("pause>>NULL");
                system("cls");
            break;

        }

    }

}
