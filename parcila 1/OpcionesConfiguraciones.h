#ifndef OPCIONESCONFIGURACIONES_H_INCLUDED
#define OPCIONESCONFIGURACIONES_H_INCLUDED
/*
void Borrar_archivo(char archivo[]){

    FILE *apertur;

    ///Aqui se encuentra el error.

    cout<< "aaa"<<endl;
    system("pause");
    apertur = fopen(archivo, "wb");
    cout<< "aaa"<<endl;
    system("pause");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Borrar_archivo'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    fclose(apertur);

}
*/
void Crear_archivo(char archivo[]){

    FILE *apertur;
    apertur = fopen(archivo, "ab");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Borrar_archivo'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    fclose(apertur);

}

///Pacientes:

int Contar_contenido_pasientes(char archivo_a_guardar[]){

    int tam_vec = 0;

    FILE *apertur;
    struct paciente aux;

    apertur = fopen(archivo_a_guardar, "rb");
    if(apertur == NULL){
        return tam_vec;
    }

    while(fread(&aux, sizeof aux, 1, apertur) == 1){
        tam_vec++;
    }

    fclose(apertur);
    return tam_vec;

}

void Copiar_archivo_pasientes(char archivo_a_guardar[], struct paciente aux[], int tam_vec){

    int x;

    FILE *apertur;

    apertur = fopen(archivo_a_guardar, "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Copiar_archivo_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    for(x=0 ; x<tam_vec ; x++){
        fread(&aux[x], sizeof aux[x], 1, apertur);
    }

    fclose(apertur);

}

void Pegar_archivo_pasientes(char archivo_donde_guardar[], struct paciente aux[], int tam_vec){

    int x;

    FILE *apertur;

    apertur = fopen(archivo_donde_guardar, "wb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Copiar_archivo_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    for(x=0 ; x<tam_vec ; x++){
        fwrite(&aux[x], sizeof aux[x], 1, apertur);
    }

    fclose(apertur);
}

void Transpasar_archivo_pasientes(char archivo_donde_guardar[], char archivo_a_guardar[]){

    struct paciente *aux;

    int tam_vec;
    tam_vec = Contar_contenido_pasientes(archivo_a_guardar);

    if(tam_vec != 0){
        aux = (struct paciente *) malloc(tam_vec * sizeof (struct paciente));

        if(aux == NULL){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Error en la asignacion dinamica de la funcion 'Transpasar_archivo_pasientes'."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            return;
        }

        Copiar_archivo_pasientes(archivo_a_guardar, aux, tam_vec);

        //Borrar_archivo(archivo_donde_guardar);

        Pegar_archivo_pasientes(archivo_donde_guardar, aux, tam_vec);

        free(aux);
    }

}

///Medicos:

int Contar_contenido_medicos(char archivo_a_guardar[]){

    int tam_vec = 0;

    FILE *apertur;
    struct medico aux;

    apertur = fopen(archivo_a_guardar, "rb");
    if(apertur == NULL){
        return tam_vec;
    }

    while(fread(&aux, sizeof aux, 1, apertur) == 1){
        tam_vec++;
    }

    fclose(apertur);
    return tam_vec;

}

void Copiar_archivo_medicos(char archivo_a_guardar[], struct medico aux[], int tam_vec){

    int x;

    FILE *apertur;

    apertur = fopen(archivo_a_guardar, "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Copiar_archivo_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    for(x=0 ; x<tam_vec ; x++){
        fread(&aux[x], sizeof aux[x], 1, apertur);
    }

    fclose(apertur);
}

void Pegar_archivo_medicos(char archivo_donde_guardar[], struct medico aux[], int tam_vec){

    int x;

    FILE *apertur;

    apertur = fopen(archivo_donde_guardar, "wb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Copiar_archivo_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    for(x=0 ; x<tam_vec ; x++){
        fwrite(&aux[x], sizeof aux[x], 1, apertur);
    }

    fclose(apertur);
}

void Transpasar_archivo_medicos(char archivo_donde_guardar[], char archivo_a_guardar[]){

    struct medico *aux;

    int tam_vec;
    tam_vec = Contar_contenido_pasientes(archivo_a_guardar);

    if(tam_vec != 0){
        aux = (struct medico *) malloc(tam_vec * sizeof (struct medico));
        if(aux == NULL){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Error en la asignacion dinamica de la funcion 'Transpasar_archivo_pasientes'."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            return;
        }

        Copiar_archivo_medicos(archivo_a_guardar, aux, tam_vec);

        //Borrar_archivo(archivo_donde_guardar);

        Pegar_archivo_medicos(archivo_donde_guardar, aux, tam_vec);

        free(aux);
    }
}

/// Controles:

int Contar_contenido_controles(char archivo_a_guardar[]){

    int tam_vec = 0;

    FILE *apertur;
    struct control aux;

    apertur = fopen(archivo_a_guardar, "rb");
    if(apertur == NULL){
        return tam_vec;
    }

    while(fread(&aux, sizeof aux, 1, apertur) == 1){
        tam_vec++;
    }

    fclose(apertur);
    return tam_vec;

}

void Copiar_archivo_controles(char archivo_a_guardar[], struct control aux[], int tam_vec){

    int x;

    FILE *apertur;

    apertur = fopen(archivo_a_guardar, "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Copiar_archivo_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    for(x=0 ; x<tam_vec ; x++){
        fread(&aux[x], sizeof aux[x], 1, apertur);
    }

    fclose(apertur);
}

void Pegar_archivo_controles(char archivo_donde_guardar[], struct control aux[], int tam_vec){

    int x;

    FILE *apertur;

    apertur = fopen(archivo_donde_guardar, "wb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Copiar_archivo_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    for(x=0 ; x<tam_vec ; x++){
        fwrite(&aux[x], sizeof aux[x], 1, apertur);
    }

    fclose(apertur);
}

void Transpasar_archivo_controles(char archivo_donde_guardar[], char archivo_a_guardar[]){

    struct control *aux;

    int tam_vec;
    tam_vec = Contar_contenido_pasientes(archivo_a_guardar);

    if(tam_vec != 0){
        aux = (struct control *) malloc(tam_vec * sizeof (struct control));
        if(aux == NULL){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Error en la asignacion dinamica de la funcion 'Transpasar_archivo_pasientes'."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            return;
        }

        Copiar_archivo_controles(archivo_a_guardar, aux, tam_vec);

        //Borrar_archivo(archivo_donde_guardar);

        Pegar_archivo_controles(archivo_donde_guardar, aux, tam_vec);

        free(aux);
    }

}

#endif // OPCIONESCONFIGURACIONES_H_INCLUDED
