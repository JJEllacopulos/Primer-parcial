#ifndef OPCIONESMEDICOS_H_INCLUDED
#define OPCIONESMEDICOS_H_INCLUDED

///Pocicion del paciente en el archivo.

int Pocicion_medico_en_archivo(int matricula_buscado){

    int cont = 0;

    FILE *apertur;
    struct medico suport;

    apertur = fopen("ArchivoMedico.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Pocicion_medico_en_archivo'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){

        if(suport.num_maticula == matricula_buscado){

            fclose(apertur);
            return cont;

        }

        cont++;
    }

    fclose(apertur);
    return -1;
}

///Rescribir obra social del paciente.

void Rescrivir_salario(int pocicion, int nuevo_salario){

    FILE *apertur;
    struct medico suport;

    apertur = fopen("ArchivoMedico.dat", "rb+");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Rescrivir_salario'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    fseek(apertur,pocicion * sizeof suport, 0);

    fread(&suport, sizeof suport, 1, apertur);

    suport.sueldo = nuevo_salario;

    fseek(apertur,pocicion * sizeof suport, 0);

    fwrite(&suport, sizeof suport, 1, apertur);

    fclose(apertur);
}

///Ingresar informacion de medico

struct medico Ingresar_medico(){

    struct medico suport;
    bool key = true;

    bool error;

    ///Ingresar Nro de matricula

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el Nro de matricula del doctor:"<< endl;
        gotoxy(35,6);
        cin>> suport.num_maticula;

        system("cls");

        error = Repeticion_num_maticula(suport.num_maticula);

        if(suport.num_maticula <= 0){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El Nro de matricula debe ser positivo."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;
        }
        else{
            if(error == true){
                setColor(RED);
                gotoxy(35,5);
                cout<< "El Nro de matricula ya esta registrado en el sistema."<< endl;
                setColor(WHITE);
                gotoxy(35,6);
                system("pause>>NULL");
                system("cls");
                key = true;
            }
        }
    }

    ///Ingresar nombre

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el nombre del medico."<< endl;
        cin.ignore();
        gotoxy(35,6);
        cin.getline(suport.nombre, 50);

        system("cls");

        if(suport.nombre[0] == '\0'){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Es necesario el nombre del medico para el registro."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    ///Ingresar apellido

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el apellido del medico."<< endl;
        gotoxy(35,6);
        cin.getline(suport.apellido, 50);

        system("cls");

        if(suport.apellido[0] == '\0'){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Es necesario el apellido del medico para el registro."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    ///Ingresar especialidad

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el Nro clabe de la especialidad (1 al 20):"<< endl;
        gotoxy(35,6);
        cin>> suport.especialidad;

        system("cls");

        if(suport.especialidad < 1 || suport.especialidad > 20){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El numero de especialidad debe ser entre el 1 al 20."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    ///Ingresar sueldo

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el sueldo del medico."<< endl;
        gotoxy(35,6);
        cin>> suport.sueldo;

        system("cls");

        if(suport.sueldo <= 0){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El sueldo debe ser mayor a cero."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    return suport;
}

///Leer informacion de paciente

void Leer_medico(struct medico suport){

    cout<< "\t\t\t\tNro de matricula: "<< suport.num_maticula<< "."<< endl;
    cout<< "\t\t\t\tNombre: "<<suport.nombre<< " "<< suport.apellido<< endl;
    cout<< "\t\t\t\tEspecialidad: "<< suport.especialidad<< "."<< endl;
    cout<< "\t\t\t\tSueldo: "<< suport.sueldo<< "."<< endl;
    setColor(LIGHTGREEN);
    cout<< endl<< "\t\t\t\t---------------------------------------"<< endl<< endl;
    setColor(WHITE);
}

///1) NUEVO MEDICO

void Nuevo_medico(){

    FILE *apertur;
    struct medico suport;

    apertur = fopen("ArchivoMedico.dat", "ab");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Nuevo_medico'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    suport = Ingresar_medico();

    fwrite(&suport, sizeof suport, 1, apertur);

    fclose(apertur);

    gotoxy(35,5);
    cout<< "Se a ingresado exitosamente los datos del nuevo medico."<< endl;
    gotoxy(35,6);
    system("pause>>NULL");
    system("cls");

}

///2) MODIFICAR MEDICO

void Modificar_medico(){

    int pocicion;

    int doctor_buscado; ///Numero de matricula del medico que se modificara.
    float nuevo_salario;
    bool flag = true;

    gotoxy(35,5);
    cout<< "Ingresa el numero de maatricula del medico que deseas modificar:"<< endl;
    gotoxy(35,6);
    cin>> doctor_buscado;

    system("cls");

    pocicion = Pocicion_medico_en_archivo(doctor_buscado);

    if(pocicion != -1){
        while(flag){
            flag =  false;
            gotoxy(35,5);
            cout<< "Ingresa el nuevo salario del medico:"<< endl;
            gotoxy(35,6);
            cin>> nuevo_salario;
            system("cls");

            if(nuevo_salario <= 0){
                setColor(RED);
                gotoxy(35,5);
                cout<< "El salario no puede ser $0 o menor a $0."<< endl;
                setColor(WHITE);
                gotoxy(35,6);
                system("pause>>NULL");
                system("cls");
                flag =  true;
            }
        }

        Rescrivir_salario(pocicion, nuevo_salario);

        return ;
    }
    else{
        setColor(RED);
        gotoxy(35,5);
        cout<< "El Nro de matricula ingresado no pertenece a ninguno de los doctores ingresados en el sistema."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        return ;

    }

}

///3) LISTAR TODOS LOS MEDICOS

void Listar_todos_los_medicos(){

    FILE *apertur;
    struct medico suport;

    apertur = fopen("ArchivoMedico.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Listar_todos_los_medicos'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){
        Leer_medico(suport);
    }
    system("pause>>NULL");
    system("cls");

    fclose(apertur);

}

///4) LISTAR MEDICO POR NRO DE MATRICULA

void Listar_medicos_x_num_de_matricula(){

    int pocicion;

    FILE *apertur;
    struct medico suport;

    int doctor_buscado; ///Numero de matricula a buscar.

    gotoxy(35,5);
    cout<< "Ingresa el numero de matricula del doctor a buscar:"<< endl;
    gotoxy(35,6);
    cin>> doctor_buscado;
    system("cls");

    pocicion = Pocicion_medico_en_archivo(doctor_buscado);

    if(pocicion != -1){

        apertur = fopen("ArchivoMedico.dat", "rb");
        if(apertur == NULL){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Error de apertura del archivo en la funcion 'Listar_paciente_x_dni'."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            exit(1);
        }

        fseek(apertur,pocicion * sizeof suport, 0);
        fread(&suport, sizeof suport, 1, apertur);

        Leer_medico(suport);
        system("pause>>NULL");
        system("cls");
        fclose(apertur);
        return ;

    }

    setColor(RED);
    gotoxy(35,5);
    cout<< "El Nro de matricula ingresado no pertenece a ninguno de los doctores ingresados en el sistema."<< endl;
    setColor(WHITE);
    gotoxy(35,6);
    system("pause>>NULL");
    system("cls");
    return ;
}

#endif // OPCIONESMEDICOS_H_INCLUDED
