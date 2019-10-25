#ifndef OPCIONESREPORTES_H_INCLUDED
#define OPCIONESREPORTES_H_INCLUDED

///LISTAR A LOS PACIENTES POR RANGO DE EDAD:

int Pacientes_en_el_rango(int menor, int mayor){

    int cont = 0;

    FILE *apertur;
    struct paciente suport;

    apertur = fopen("ArchivoPacientes.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Buscar_genero_del_paciente'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){
        if(suport.estado){
            if((2019 - suport.fecha.ano) > menor && (2019 - suport.fecha.ano) <= mayor){
                cont++;
            }
        }

    }

    fclose(apertur);
    return cont;

}

void Paciente_x_rango_edad(){

    int Cont_pacientes;
    char opcion;

    while(true){

        gotoxy(35,5);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,6);
        cout<< "N) "; setColor(LIGHTCYAN); cout<< "Niños (hasta 12 años)"<< endl;
        setColor(WHITE);
        gotoxy(35,7);
        cout<< "A) "; setColor(LIGHTCYAN); cout<< "Adolescente (mayores a 12 y hasta 18)"<< endl;
        setColor(WHITE);
        gotoxy(35,8);
        cout<< "J) "; setColor(LIGHTCYAN); cout<< "Joven (mayores a 18 hasta  30)"<< endl;
        setColor(WHITE);
        gotoxy(35,9);
        cout<< "M) "; setColor(LIGHTCYAN); cout<< "Adulto (mayores a 30)"<< endl;
        setColor(WHITE);
        gotoxy(35,10);
        cout<< "-------------------------------------"<< endl;
        gotoxy(35,11);
        cout<< "0) "; setColor(DARKGREY); cout<< "VOLVER AL MENU PRINCIPAL"<< endl;
        setColor(WHITE);
        gotoxy(35,12);
        cout<< " > "; opcion = getch();

        system("cls");

        switch(opcion){
            case 'N':
                Cont_pacientes = Pacientes_en_el_rango(-1, 12);
                cout<< "Los pacientes registrados entre "<< Cont_pacientes<< "."<< endl;
                system("pause>>NULL");
                system("cls");
                return;
            break;
            case 'A':
                Cont_pacientes = Pacientes_en_el_rango(12,18);
                cout<< "Los pacientes registrados entre "<< Cont_pacientes<< "."<< endl;
                system("pause>>NULL");
                system("cls");
                return;
            break;
            case 'J':
                Cont_pacientes = Pacientes_en_el_rango(18,30);
                cout<< "Los pacientes registrados entre "<< Cont_pacientes<< "."<< endl;
                system("pause>>NULL");
                system("cls");
                return;
            break;
            case 'M':
                Cont_pacientes = Pacientes_en_el_rango(30,200);
                cout<< "Los pacientes registrados entre "<< Cont_pacientes<< "."<< endl;
                system("pause>>NULL");
                system("cls");
                return;
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

///ACTIVIDAD DE UN MEDICO EN EL PRIMER CUATRIMESTRE DEL 2019:

bool Acticidad_peimer_cuatrimestre(int doctor){

    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Controles_x_medico'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){
        if(suport.estado){
            if(suport.num_matricula == doctor){
                if(suport.fecha.mes <= 3){
                    if(suport.fecha.ano == 2019){

                        fclose(apertur);
                        return true;

                    }
                }
            }
        }
    }

    fclose(apertur);
    return false;

}

void Actividad_doctor(){

    int doctor;
    bool key = false;

    while(!key){
        setColor(LIGHTCYAN);
        gotoxy(35,5);
        cout<< "Ingresa el Nro de matricula del medico del que se desea el informe:"<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        cin>> doctor;

        system("cls");

        key = Repeticion_num_maticula(doctor);

        if(!key){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El Nro de matricula no esta registrado."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
        }
    }

    key = Acticidad_peimer_cuatrimestre(doctor);

    if(key){
        setColor(LIGHTCYAN);
        gotoxy(35,5);
        cout<< "El doctor a tenido actividad dentro del primer cuatrimestre del ano 2019."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }
    else{
        setColor(LIGHTCYAN);
        gotoxy(35,5);
        cout<< "El doctor no a tenido actividad dentro del primer cuatrimestre del ano 2019."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }

}

///CONTROL CON MAYOR DURACION:

void Control_mayor_duracion(){

    struct control mayor_control;
    mayor_control.duracion = -1;
    int pocicion;

    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Controles_x_medico'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof (struct control), 1, apertur) == 1){
        if(suport.estado){
            if(suport.duracion > mayor_control.duracion){
                fseek(apertur, pocicion, 0);
                fread(&mayor_control, sizeof (struct control), 1, apertur);
                fseek(apertur, pocicion + sizeof (struct control), 0);
            }
        }
        pocicion = ftell(apertur);
    }

    setColor(LIGHTCYAN);
    gotoxy(35,5);
    cout<< "El control con mayor duracion fue para el paciente "<< mayor_control.dni<< endl<< " atendido por el doctor "<< mayor_control.num_matricula<< "."<< endl;
    setColor(WHITE);
    gotoxy(35,6);
    system("pause>>NULL");
    system("cls");

    fclose(apertur);

}


#endif // OPCIONESREPORTES_H_INCLUDED
