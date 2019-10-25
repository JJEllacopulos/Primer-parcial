#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

///1) PACIENTES

void Menu_pacientes(){

    int opcion;

    while(true){

        setColor(CYAN);
        gotoxy(35,5);
        cout<< "MENU PACIENTES"<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        cout<< "-------------------"<< endl;
        gotoxy(35,7);
        cout<< "1) "; setColor(CYAN); cout<< "NUEVO PACIENTE"<< endl;
        setColor(WHITE);
        gotoxy(35,8);
        cout<< "2) "; setColor(CYAN); cout<< "MODIFICAR PACIENTE"<< endl;
        setColor(WHITE);
        gotoxy(35,9);
        cout<< "3) "; setColor(CYAN); cout<< "LISTAR PACIENTE POR DNI"<< endl;
        setColor(WHITE);
        gotoxy(35,10);
        cout<< "4) "; setColor(CYAN); cout<< "LISTAR TODOS LOS PACIENTES"<< endl;
        setColor(WHITE);
        gotoxy(35,11);
        cout<< "5) "; setColor(CYAN); cout<< "ELIMINAR PACIENTE"<< endl;
        setColor(WHITE);
        gotoxy(35,12);
        cout<< "-------------------------------"<< endl;
        gotoxy(35,13);
        cout<< "O) "; setColor(DARKGREY); cout<< "VOLVER AL MENU PRINCIPAL"<< endl;
        setColor(WHITE);
        gotoxy(35,14);
        cout<< " > "; opcion = getch();
        system("cls");

        opcion-=48;

        switch(opcion){
            case 1:
                Nuevo_pasiente();
            break;
            case 2:
                Modificar_paciente();
            break;
            case 3:
                Listar_paciente_x_dni();
            break;
            case 4:
                Listar_todos_los_pacientes();
            break;
            case 5:
                Eliminar_paciente();
            break;
            case 0:
                return;
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

///2) MEDICOS

void Menu_medicos(){

    int opcion;

    while(true){

        setColor(LIGHTGREEN);
        gotoxy(35,5);
        cout<< "MENU MEDICOS"<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,7);
        cout<< "1) "; setColor(LIGHTGREEN); cout<< "NUEVO MEDICO"<< endl;
        setColor(WHITE);
        gotoxy(35,8);
        cout<< "2) "; setColor(LIGHTGREEN); cout<< "MODIFICAR MEDICO"<< endl;
        setColor(WHITE);
        gotoxy(35,9);
        cout<< "3) "; setColor(LIGHTGREEN); cout<< "LISTAR TODOS LOS MEDICOS"<< endl;
        setColor(WHITE);
        gotoxy(35,10);
        cout<< "4) "; setColor(LIGHTGREEN); cout<< "LISTAR MEDICO POR NRO DE MATRICULA"<< endl;
        setColor(WHITE);
        gotoxy(35,11);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,12);
        cout<< "0) "; setColor(DARKGREY); cout<< "VOLVER AL MENU PRINCIPAL"<< endl;
        setColor(WHITE);
        gotoxy(35,13);
        cout<< " > "; opcion = getch();
        system("cls");

        opcion-=48;

        switch(opcion){
            case 1:
                Nuevo_medico();
            break;
            case 2:
                Modificar_medico();
            break;
            case 3:
                Listar_todos_los_medicos();
            break;
            case 4:
                Listar_medicos_x_num_de_matricula();
            break;
            case 0:
                return;
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

///3) CONTROLSE

void Menu_controles(){

    int opcion;

    while(true){

        setColor(LIGHTMAGENTA);
        gotoxy(35,5);
        cout<< "MENU CONTROLES"<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,7);
        cout<< "1) "; setColor(LIGHTMAGENTA); cout<< "NUEVO CONTROL"<< endl;
        setColor(WHITE);
        gotoxy(35,8);
        cout<< "2) "; setColor(LIGHTMAGENTA); cout<< "MODIFICAR CONTROL"<< endl;
        setColor(WHITE);
        gotoxy(35,9);
        cout<< "3) "; setColor(LIGHTMAGENTA); cout<< "LISTAR CONTROL POR ID"<< endl;
        setColor(WHITE);
        gotoxy(35,10);
        cout<< "4) "; setColor(LIGHTMAGENTA); cout<< "LISTAR TODOS LOS CONTROLES"<< endl;
        setColor(WHITE);
        gotoxy(35,11);
        cout<< "5) "; setColor(LIGHTMAGENTA); cout<< "CANCELAR CONTROLES"<< endl;
        setColor(WHITE);
        gotoxy(35,12);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,13);
        cout<< "0) "; setColor(DARKGREY); cout<< "VOLVER AL MENU PRINCIPAL"<< endl;
        setColor(WHITE);
        gotoxy(35,14);
        cout<< " > "; opcion = getch();

        system("cls");

        opcion-=48;

        switch(opcion){
            case 1:
                Nuevo_control();
            break;
            case 2:
                Modificar_control();
            break;
            case 3:
                Listar_control_x_id();
            break;
            case 4:
                Listar_todos_los_controles();
            break;
            case 5:
                Cancelar_control();
            break;
            case 0:
                return;
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

///4) REPORTES

void Menu_reportes(){

    int opcion;

    while(true){

        setColor(LIGHTCYAN);
        gotoxy(35,5);
        cout<< "MENU CONTROLES"<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,7);
        cout<< "1) "; setColor(LIGHTCYAN); cout<< "PACIENTES EN UN RANGO DE EDAD"<< endl;
        setColor(WHITE);
        gotoxy(35,8);
        cout<< "2) "; setColor(LIGHTCYAN); cout<< "ACTIVIDAD DE UN MEDICO EN EL PRIMER CUATRIMESTRE DEL 2019"<< endl;
        setColor(WHITE);
        gotoxy(35,9);
        cout<< "3) "; setColor(LIGHTCYAN); cout<< "CONTROL CON MAYOR DURACION"<< endl;
        setColor(WHITE);
        gotoxy(35,10);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,11);
        cout<< "0) "; setColor(DARKGREY); cout<< "VOLVER AL MENU PRINCIPAL"<< endl;
        setColor(WHITE);
        gotoxy(35,12);
        cout<< " > "; opcion = getch();

        system("cls");

        opcion-=48;

        switch(opcion){
            case 1:
                Paciente_x_rango_edad();
            break;
            case 2:
                Actividad_doctor();
            break;
            case 3:
                Control_mayor_duracion();
            break;
            case 0:
                return;
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

///5) CONFIGURACION

void Menu_configuracion(){

    int opcion;

    ///Parche a revicion:
    Crear_archivo("ArchivoPacientes.bak");
    Crear_archivo("ArchivoMedico.bak");
    Crear_archivo("ArchivoControl.bak");

    while(true){

        setColor(LIGHTRED);
        gotoxy(35,5);
        cout<< "MENU CONTROLES"<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,7);
        cout<< "1) "; setColor(LIGHTRED); cout<< "REALIZAR BACKUP"<< endl;
        setColor(WHITE);
        gotoxy(35,8);
        cout<< "2) "; setColor(LIGHTRED); cout<< "RESTAURAR BACKUP"<< endl;
        setColor(WHITE);
        gotoxy(35,9);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,10);
        cout<< "0) "; setColor(DARKGREY); cout<< "VOLVER AL MENU PRINCIPAL"<< endl;
        setColor(WHITE);
        gotoxy(35,11);
        cout<< " > "; opcion = getch();

        system("cls");

        opcion-=48;

        switch(opcion){
            case 1:
                Transpasar_archivo_pasientes("ArchivoPacientes.bak", "ArchivoPacientes.dat");
                Transpasar_archivo_medicos("ArchivoMedico.bak", "ArchivoMedico.dat");
                Transpasar_archivo_controles("ArchivoControl.bak", "ArchivoControl.dat");
                setColor(LIGHTRED);
                gotoxy(35,5);
                cout<< "El backup se a realisado exitosamente."<< endl;
                setColor(WHITE);
                gotoxy(35,6);
                system("pause>>NULL");
                system("cls");
            break;
            case 2:
                Transpasar_archivo_pasientes("ArchivoPacientes.dat", "ArchivoPacientes.bak");
                Transpasar_archivo_medicos("ArchivoMedico.dat", "ArchivoMedico.bak");
                Transpasar_archivo_controles("ArchivoControl.dat", "ArchivoControl.bak");
                setColor(LIGHTRED);
                gotoxy(35,5);
                cout<< "Se a recuperado los datos exitosamente."<< endl;
                setColor(WHITE);
                gotoxy(35,6);
                system("pause>>NULL");
                system("cls");
            break;
            case 0:
                return;
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

#endif // MENUES_H_INCLUDED
