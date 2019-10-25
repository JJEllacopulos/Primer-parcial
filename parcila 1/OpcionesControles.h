#ifndef OPCIONESCONTROLES_H_INCLUDED
#define OPCIONESCONTROLES_H_INCLUDED

///Total de controles

int Total_de_controles(){

    FILE *apertur;
    struct control suport;

    int cont = 0;

    apertur = fopen("ArchivoControl.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Total_de_pacientes'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){

        cont++;

    }

    fclose(apertur);
    return cont;
}

///Ingresar control

struct control Ingresar_control(){

    struct control suport;
    bool key;

    struct tm actual;

    bool error;

    /// Ingreso de ID

    suport.id = Total_de_controles();

    /// Ingreso del DNI del paciente

    key = true;

    if(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el DNI del paciente al que se le relealizara el control:"<< endl;
        gotoxy(35,6);
        cin>> suport.dni;

        system("cls");

        error = Repeticion_dni(suport.dni);

        if(error == false){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El DNI del paciente no esta registrado en el sistema."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;
        }

    }

    /// Ingreso del numero de maricula del doctor

    key = true;

    if(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el Nro de matricula del doctor que realizara el control:"<< endl;
        gotoxy(35,6);
        cin>> suport.num_matricula;

        system("cls");

        error = Repeticion_num_maticula(suport.num_matricula);

        if(error == false){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El Nro de matricula ingresado no esta registrado en el sistema."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;
        }

    }

    /// Ingreso del costo

    key = true;

    if(key){
        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el costo del control a realizar."<< endl;
        gotoxy(35,6);
        cin>> suport.costo;

        system("cls");

        if(suport.costo <= 0){
            setColor(RED);
            gotoxy(35,5);
            cout<< "El costo debe ser mayor a cero."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }

    }

    /// Ingreso del dia

    key = true;

    if(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el dia de la fecha del control:"<< endl;
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

    /// Ingreso del mes

    key = true;

    if(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el mes de la fecha del control:"<< endl;
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

    /// Ingreso del año

    key = true;

    if(key){

        key = false;

        gotoxy(35,5);
        cout<< "Ingresa el ano de la fecha del control:"<< endl;
        gotoxy(35,6);
        cin>> suport.fecha.ano;

        system("cls");

        ///                                                Año actual
        if(suport.fecha.ano < 1900 || suport.fecha.ano > 2020/*(1900 + actual.tm_year)*/){
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

    /// Ingreso de la duracion

    key = true;

    if(key){
        key = false;

        gotoxy(35,5);
        cout<< "Ingresa la duracion del control a realizar."<< endl;
        gotoxy(35,6);
        cin>> suport.duracion;

        system("cls");

        if(suport.duracion <= 0){
            setColor(RED);
            gotoxy(35,5);
            cout<< "La duracion del control debe ser mayor a cero."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            key = true;

        }

    }

    /// Ingreso del estado

    suport.estado = true;

    return suport;
}

///Pocicion de la id en el archivo.

int Pocicion_control_en_archivo(int id_buscado){

    int cont = 0;

    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "rb");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Pocicion_control_en_archivo'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    while(fread(&suport, sizeof suport, 1, apertur) == 1){

        if(suport.id == id_buscado){

            fclose(apertur);
            return cont;

        }

        cont++;
    }

    fclose(apertur);
    return -1;
}

///Rescribir la duracion del control.

void Rescrivir_duracion(int pocicion, int nueva_duracion){

    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "rb+");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Rescrivir_duracion'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    fseek(apertur,pocicion * sizeof suport, 0);

    fread(&suport, sizeof suport, 1, apertur);

    suport.duracion = nueva_duracion;

    fseek(apertur,pocicion * sizeof suport, 0);

    fwrite(&suport, sizeof suport, 1, apertur);

    fclose(apertur);
}

///Leer_control

void leer_control(struct control suport){

    if(suport.estado){
        cout<< "\t\t\t\tID : "<< suport.id<< endl;
        cout<< "\t\t\t\tDNI del paciente : "<<suport.dni<< endl;
        cout<< "\t\t\t\tNro de matricula del medico : "<< suport.num_matricula<< endl;
        cout<< "\t\t\t\tCosto : "<< suport.costo<< endl;
        cout<< "\t\t\t\tFecha : "<< suport.fecha.dia<< " / "<< suport.fecha.mes<< " / "<< suport.fecha.ano<< endl;
        cout<< "\t\t\t\tDuracion : "<< suport.duracion<<endl;
        setColor(LIGHTMAGENTA);
        cout<< endl<< endl<< "\t\t\t\t---------------------------------------"<< endl<< endl;
        setColor(WHITE);
    }

}

///Baja logica de un control.

void Eliminacion_del_control(int pocicion){

    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "rb+");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Eliminacion_del_control'."<< endl;
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

///1) Nuevo control

void Nuevo_control(){
    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "ab");
    if(apertur == NULL){
        setColor(RED);
        gotoxy(35,5);
        cout<< "Error de apertura del archivo en la funcion 'Nuevo_control'."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        exit(1);
    }

    suport = Ingresar_control();

    fwrite(&suport, sizeof suport, 1, apertur);

    fclose(apertur);

    gotoxy(35,5);
    cout<< "Se a ingresado exitosamente los datos del control."<< endl;
    gotoxy(35,6);
    system("pause>>NULL");
    system("cls");

}

///2) Modificar control

void Modificar_control(){

    int pocicion;

    int control_buscado; ///Numero de ID que se modificara.
    int nueva_duracion;
    bool flag = true;

    gotoxy(35,5);
    cout<< "Ingresa el numero de ID del control que deseas modificar:"<< endl;
    gotoxy(35,6);
    cin>> control_buscado;

    system("cls");

    pocicion = Pocicion_control_en_archivo(control_buscado);

    if(pocicion != -1){
        while(flag){
            flag =  false;
            gotoxy(35,5);
            cout<< "Ingresa una nueva duracion para el control:"<< endl;
            gotoxy(35,6);
            cin>> nueva_duracion;
            system("cls");

            if(nueva_duracion <= 0){
                setColor(RED);
                gotoxy(35,5);
                cout<< "El control debe durar mas de 0 horas."<< endl;
                setColor(WHITE);
                gotoxy(35,6);
                system("pause>>NULL");
                system("cls");
                flag =  true;
            }
        }

        Rescrivir_duracion(pocicion, nueva_duracion);

        return ;
    }
    else{
        setColor(RED);
        gotoxy(35,5);
        cout<< "la ID ingresada no pertenece a ninguno de los controles ingresados en el sistema."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
        return ;

    }

}

///3) Listar control por ID

void Listar_control_x_id(){

    int pocicion;

    FILE *apertur;
    struct control suport;

    int id_buscado; ///Numero de ID a buscar.

    gotoxy(35,5);
    cout<< "Ingresa el numero de ID del control buscado:"<< endl;
    gotoxy(35,6);
    cin>> id_buscado;

    system("cls");

    pocicion = Pocicion_control_en_archivo(id_buscado);

    if(pocicion != -1){

        apertur = fopen("ArchivoControl.dat", "rb");
        if(apertur == NULL){
            setColor(RED);
            gotoxy(35,5);
            cout<< "Error de apertura del archivo en la funcion 'Listar_control_x_id'."<< endl;
            setColor(WHITE);
            gotoxy(35,6);
            system("pause>>NULL");
            system("cls");
            exit(1);
        }

        fseek(apertur,pocicion * sizeof suport, 0);
        fread(&suport, sizeof suport, 1, apertur);

        leer_control(suport);
        system("pause>>NULL");
        system("cls");
        fclose(apertur);
    }
    else{
        setColor(RED);
        gotoxy(35,5);
        cout<< "El ID ingresado no pertenece a ninguno de los controles ingresados en el sistema."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }

}

///4) Listar todos los controles

void Listar_todos_los_controles(){

    FILE *apertur;
    struct control suport;

    apertur = fopen("ArchivoControl.dat", "rb");
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

        leer_control(suport);

    }
    system("pause>>NULL");
    system("cls");

    fclose(apertur);


}

///5) Cancelar control

void Cancelar_control(){

    int pocicion;

    int id_buscado; ///ID del control al que se desea darle una baja logica.

    gotoxy(35,5);
    cout<< "Ingresa el numero de ID del control que deseas dar de baja:"<< endl;
    gotoxy(35,6);
    cin>> id_buscado;

    system("cls");

    pocicion = Pocicion_control_en_archivo(id_buscado);

    if(pocicion != -1){

        Eliminacion_del_control(pocicion);

        gotoxy(35,5);
        cout<< "El control fue eliminado exitosamente."<< endl;
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }
    else{
        setColor(RED);
        gotoxy(35,5);
        cout<< "El numero de ID ingresado no pertenece a ninguno de los controles ingresados en el sistema."<< endl;
        setColor(WHITE);
        gotoxy(35,6);
        system("pause>>NULL");
        system("cls");
    }

}


#endif // OPCIONESCONTROLES_H_INCLUDED
