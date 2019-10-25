#ifndef OPCIONESPASIENTES_H_INCLUDED
#define OPCIONESPASIENTES_H_INCLUDED


///Ingresar informacion de paciente.

struct paciente Ingresar_paciente(){

    struct paciente suport;
    bool key = true;

    struct tm actual;

    bool error;

    ///Ingresar DNI

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el DNI del paciente:"<< endl;
        gotoxy(35,6);
        cin>> suport.dni;

        system("cls");

        error = Repeticion_dni(suport.dni);

        if(suport.dni <= 0){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El DNI debe ser positivo."<< endl;
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
                cout<< "El DNI ya esta registrado en el sistema."<< endl;
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
        cout<< "Ingresa el nombre del paciente."<< endl;
        cin.ignore();
        gotoxy(35,6);
        cin.getline(suport.nombre, 50);

        system("cls");

        if(suport.nombre[0] == '\0'){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Es necesario el nombre del paciente para el registro."<< endl;
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
        cout<< "Ingresa el apellido del paciente."<< endl;
        gotoxy(35,6);
        cin.getline(suport.apellido, 50);

        system("cls");

        if(suport.apellido[0] == '\0'){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Es necesario el apellido del paciente para el registro."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    ///Ingresar genero

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el genero del paciente ( 'M' masculino, 'F' femenino, 'O' otros ):"<< endl;
        gotoxy(35,6);
        cin>> suport.genero;

        system("cls");

        if(!(suport.genero == 'M' || suport.genero == 'F' || suport.genero == 'O')){
            setColor(RED);
            gotoxy(35,5);
            cout<< "La opcion es invalida."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;
        }
    }

    ///Ingresar dia

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el dia de la fecha de nacimiento:"<< endl;
        gotoxy(35,6);
        cin>> suport.fecha.dia;

        system("cls");

        if(suport.fecha.dia < 1 || suport.fecha.dia > 31){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El dia ingresado es invalido."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    ///Ingresar mes

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el mes de la fecha de nacimiento:"<< endl;
        gotoxy(35,6);
        cin>> suport.fecha.mes;

        system("cls");

        if(suport.fecha.mes < 1 || suport.fecha.mes > 12){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El mes ingresado es invalido."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    ///Ingresar año

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el ano de la fecha de nacimiento:"<< endl;
        gotoxy(35,6);
        cin>> suport.fecha.ano;

        system("cls");

        ///                                                Año actual
        if(suport.fecha.ano < 1900 || suport.fecha.ano > 2019/*(1900 + actual.tm_year)*/){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El ano ingresado es invalido."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    ///Ingresar obra social

    key = true;

    while(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el numero de la obra social (Del 1 al 50):"<< endl;
        gotoxy(35,6);
        cin>> suport.obra_socila;

        system("cls");

        if(suport.obra_socila < 1 || suport.obra_socila > 50){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El valor es invalido."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }
    }

    suport.estado = true;

    return suport;

}

///Leer informacion de paciente.

void leer_paciente(struct paciente suport){

    if(suport.estado){

        cout<< "\t\t\t\tDNI: "<< suport.dni<< endl;
        cout<< "\t\t\t\tNombre: "<<suport.nombre<< " "<< suport.apellido<< endl;
        cout<< "\t\t\t\tGenero: "<< suport.genero<< endl;
        cout<< "\t\t\t\tFecha: "<< suport.fecha.dia<< " / "<< suport.fecha.mes<< " / "<< suport.fecha.ano<< endl;
        cout<< "\t\t\t\tObra social: "<< suport.obra_socila<<endl;
        setColor(CYAN);
        cout<< endl<< endl<< "\t\t\t\t---------------------------------------"<< endl<< endl;
        setColor(WHITE);
    }

}

///Pocicion del paciente en el archivo.

int Pocicion_paciente_en_archivo(int dni_buscado){

    int cont = 0;

    FILE *apertur;
    struct paciente suport;

    apertur = fopen("ArchivoPacientes.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Pocicion_datos_en_archivo'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){

        if(suport.dni == dni_buscado){

            fclose(apertur);
            return cont;

        }

        cont++;
    }

    fclose(apertur);
    return -1;
}

///Rescribir obra social del paciente.

void Rescrivir_obra_social(int pocicion, int nueva_obra_social){

    FILE *apertur;
    struct paciente suport;

    apertur = fopen("ArchivoPacientes.dat", "rb+");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Rescrivir_obra_social'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    fseek(apertur,pocicion * sizeof suport, 0);

    fread(&suport, sizeof suport, 1, apertur);

    suport.obra_socila = nueva_obra_social;

    fseek(apertur,pocicion * sizeof suport, 0);

    fwrite(&suport, sizeof suport, 1, apertur);

    fclose(apertur);
}

///Baja logica de un paciente.

void Eliminacion_de_paciente(int pocicion){

    FILE *apertur;
    struct paciente suport;

    apertur = fopen("ArchivoPacientes.dat", "rb+");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Rescrivir_obra_social'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    fseek(apertur,pocicion * sizeof suport, 0);

    fread(&suport, sizeof suport, 1, apertur);

    suport.estado = false;

    fseek(apertur,pocicion * sizeof suport, 0);

    fwrite(&suport, sizeof suport, 1, apertur);

    fclose(apertur);
}

///1) NUEVO PACIENTE

void Nuevo_pasiente(){

    FILE *apertur;
    struct paciente suport;

    apertur = fopen("ArchivoPacientes.dat", "ab");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Nuevo_pasiente'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    suport = Ingresar_paciente();

    fwrite(&suport, sizeof suport, 1, apertur);

    fclose(apertur);

    setColor(CYAN);
    gotoxy(35,5);
    cout<< "Se a ingresado exitosamente los datos del nuevo paciente."<< endl;
    setColor(WHITE);
    gotoxy(35,6);
    system("pause>>NULL");
    system("cls");

}

///2) MODIFICAR PACIENTE*

void Modificar_paciente(){

    int pasiente_buscado; ///DNI del paciente al que se le modificara el numero de obra social.
    int nueva_obra_social;
    bool key = true;

    int pocicion;

    gotoxy(35,5);
    cout<< "Ingresa el numero de DNI del paciente que deseas modificar:"<< endl;
    gotoxy(35,6);
    cin>> pasiente_buscado;

    system("cls");

    pocicion = Pocicion_paciente_en_archivo(pasiente_buscado);

    if(pocicion != -1){
        while(key){

            key = false;

            gotoxy(35,5);
            cout<< "Ingresa la calve de la nueva obra social (Del 1 al 50):"<< endl;
            gotoxy(35,6);
            cin>> nueva_obra_social;
            system("cls");

            if(nueva_obra_social < 1 || nueva_obra_social > 50){
                setColor(RED);
                gotoxy(35,5);
                cout<< "El valor es invalido."<< endl;
                setColor(WHITE);
                gotoxy(35,6);
                system("pause>>NULL");
                system("cls");
                key = true;
            }
        }

        Rescrivir_obra_social(pocicion, nueva_obra_social);

        return ;

    }
    else{
        setColor(RED);
        gotoxy(35,5);
        cout<< "El DNI ingresado no pertenece a ninguno de los pacientes ingresados en el sistema."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");

        return ;
    }

}

///3) LISTAR PACIENTE POR DNI*

void Listar_paciente_x_dni(){

    int pocicion;

    FILE *apertur;
    struct paciente suport;

    int paciente_buscado; ///Numero de DNI a buscar.

    gotoxy(35,5);
    cout<< "Ingresa el numero de DNI del paciente a buscar:"<< endl;
    gotoxy(35,6);
    cin>> paciente_buscado;

    system("cls");

    pocicion = Pocicion_paciente_en_archivo(paciente_buscado);

    if(pocicion != -1){

        apertur = fopen("ArchivoPacientes.dat", "rb");
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

        leer_paciente(suport);
        system("pause>>NULL");
        system("cls");
        fclose(apertur);
    }
    else{
        setColor(RED);
        gotoxy(35,5);
        cout<< "El DNI ingresado no pertenece a ninguno de los pacientes ingresados en el sistema."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }
}

///4) LISTAR TODOS LOS PACIENTES*

void Listar_todos_los_pacientes(){

    FILE *apertur;
    struct paciente suport;

    apertur = fopen("ArchivoPacientes.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Listar_todos_los_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){

        leer_paciente(suport);

    }
    system("pause>>NULL");
    system("cls");

    fclose(apertur);

}

///5) ELIMINAR PACIENTE*

void Eliminar_paciente(){

    int pocicion;

    int pasiente_buscado; ///DNI del paciente al que se desea darle una baja logica.
    bool key = true;

    gotoxy(35,5);
    cout<< "Ingresa el numero de DNI del paciente que deseas dar de baja:"<< endl;
    gotoxy(35,6);
    cin>> pasiente_buscado;

    system("cls");

    pocicion = Pocicion_paciente_en_archivo(pasiente_buscado);

    if(pocicion != -1){

        Eliminacion_de_paciente(pocicion);

        gotoxy(35,5);
        cout<< "El paciente fue eliminado exitosamente."<< endl;
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }
    else{
        setColor(RED);
        gotoxy(35,5);
        cout<< "El Nro de matricula ingresado no pertenece a ninguno de los doctores ingresados en el sistema."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }

}


#endif // OPCIONESPASIENTES_H_INCLUDED
