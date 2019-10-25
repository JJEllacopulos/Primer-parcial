#ifndef RESTRICCIONES_H_INCLUDED
#define RESTRICCIONES_H_INCLUDED

///Restricciones de pacientes

bool Repeticion_dni(int comparacion){

    FILE *apertur;
    struct paciente suport;

    apertur = fopen("ArchivoPacientes.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Repeticion_dni'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){

        if(suport.dni == comparacion){
            fclose(apertur);
            return true;
        }
    }

    fclose(apertur);
    return false;
}

bool Repeticion_num_maticula(int comparacion){

    FILE *apertur;
    struct medico suport;

    apertur = fopen("ArchivoMedico.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Repeticion_num_maticula'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){

        if(suport.num_maticula == comparacion){
            fclose(apertur);
            return true;
        }
    }

    fclose(apertur);
    return false;
}

#endif // RESTRICCIONES_H_INCLUDED
