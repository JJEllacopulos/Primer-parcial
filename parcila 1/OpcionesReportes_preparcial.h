#ifndef OPCIONESREPORTES_H_INCLUDED
#define OPCIONESREPORTES_H_INCLUDED

///CONTROLES POR CADA MES DE CADA MEDICO:

void Listar_controles(int controles_x_mes[12]){

    setColor(LIGHTCYAN);
    gotoxy(35,5);
    cout<< "\t ENERO      :"<< controles_x_mes[0]<< endl;
    gotoxy(35,6);
    cout<< "\t FEBRERO    :"<< controles_x_mes[1]<< endl;
    gotoxy(35,7);
    cout<< "\t MARZO      :"<< controles_x_mes[2]<< endl;
    gotoxy(35,8);
    cout<< "\t ABRIL      :"<< controles_x_mes[3]<< endl;
    gotoxy(35,9);
    cout<< "\t MAYO       :"<< controles_x_mes[4]<< endl;
    gotoxy(35,10);
    cout<< "\t JUNIO      :"<< controles_x_mes[5]<< endl;
    gotoxy(35,11);
    cout<< "\t JULIO      :"<< controles_x_mes[6]<< endl;
    gotoxy(35,12);
    cout<< "\t AGOSTO     :"<< controles_x_mes[7]<< endl;
    gotoxy(35,13);
    cout<< "\t SEPTIEMBRE :"<< controles_x_mes[8]<< endl;
    gotoxy(35,14);
    cout<< "\t OCTUBRE    :"<< controles_x_mes[9]<< endl;
    gotoxy(35,15);
    cout<< "\t NOVIEMBRE  :"<< controles_x_mes[10]<< endl;
    gotoxy(35,16);
    cout<< "\t DICIEMBRE  :"<< controles_x_mes[11]<< endl;
    setColor(WHITE);

}

void Cont_controles(int controles_x_mes[12], int doctor){

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
                controles_x_mes[suport.fecha.mes - 1]++;
            }
        }
    }

    fclose(apertur);
    return;

}

void Controles_x_medico(){

    int doctor;
    int controles_x_mes[12] = {0};

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

    Cont_controles(controles_x_mes, doctor);
    Listar_controles(controles_x_mes);
    system("pause>>NULL");
    system("cls");

    return;
}

///DOCTORES QUE GANAN MAS DE $80000 Y MENOS DE $ 50000:

void Cont_sueldos_medicos(){

    int medic_moyor_80k = 0;
    int medic_menor_50k = 0;

    FILE *apertur;
    struct medico suport;

    apertur = fopen("ArchivoMedico.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Cont_sueldos_medicos'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){
        if(suport.sueldo > 80000){
            medic_moyor_80k++;
        }
        else{
            if(suport.sueldo < 50000){
                medic_menor_50k++;
            }
        }
    }

    fclose(apertur);

    setColor(LIGHTCYAN);
    gotoxy(35,5);
    cout<< "LA CANTIDAD DE DOCTORES QUE GANAN MAS DE $80000 SON "<< medic_moyor_80k<< "."<< endl;
    gotoxy(35,6);
    cout<< "LA CANTIDAD DE DOCTORES QUE GANAN MENOS DE $50000 SON "<< medic_menor_50k<< "."<< endl;
    setColor(WHITE);
    system("pause>>NULL");
    system("cls");

}

///ERCAUDACION POR CADA ESPECIALIDAD:

int Buscar_especialidad_del_doctor(int doctor_buscado){

    FILE *apertur;
    struct medico suport;

    apertur = fopen("ArchivoMedico.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Buscar_especialidad_del_doctor'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){
        if(suport.num_maticula == doctor_buscado){
            fclose(apertur);
            return suport.especialidad - 1;
        }
    }


    fclose(apertur);
}

int Buscar_genero_del_paciente(int paciente_buscado){

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
        if(suport.dni == paciente_buscado){
            fclose(apertur);
            if(suport.genero == 'M'){
                return 0;
            }
            else{
                if(suport.genero == 'F'){
                    return 1;
                }
                else{
                    return 2;
                }
            }
        }
    }


    fclose(apertur);
}

void Listar_recaudacion(float racaud_x_especial_x_genero[3][20]){

    int x, y;

    for(x=0;x<3;x++){
        setColor(LIGHTCYAN);
        switch(x){
            case 0:
                cout<< "\t\t\t\tMUJERES:"<< endl<< endl;
            break;
            case 1:
                cout<< "\t\t\t\tHOMBRES:"<< endl<< endl;
            break;
            case 2:
                cout<< "\t\t\t\tOTROS:"<< endl<< endl;
            break;
        }
        for(y=0;y<20;y++){
            cout<< "\t\t\t\t\tESPECIALIDAD "<< y+1<< ": "<< racaud_x_especial_x_genero[x][y]<< endl;
        }
        setColor(WHITE);
        cout<< endl<< endl<< "\t\t\t\t-----------------*-----------------"<< endl<< endl;
    }

    system("pause>>NULL");
    system("cls");
}

void Recaudacion_x_especialidad_x_genero(){

    float racaud_x_especial_x_genero[3][20] = {0};

    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Recaudacion_x_especialidad_x_genero'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){
        if(suport.estado){
            racaud_x_especial_x_genero[Buscar_genero_del_paciente(suport.dni)][Buscar_especialidad_del_doctor(suport.num_matricula)] += suport.costo;
        }
    }

    Listar_recaudacion(racaud_x_especial_x_genero);
    fclose(apertur);
}


#endif // OPCIONESREPORTES_H_INCLUDED
