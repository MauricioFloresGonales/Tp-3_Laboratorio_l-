#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "Inputs.h"
#include "funcionesAux.h"

#define BIN "binario"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int texto = 0;
    int binario = 0;
    int validador = 0;

    do{
            printf("1. Cargar los datos (modo texto).\n");
            printf("2. Cargar los datos (modo binario).\n");
            printf("3. Alta\n");
            printf("4. Modificar datos\n");
            printf("5. Baja\n");
            printf("6. Listar \n");
            printf("7. Ordenar\n");
            printf("8. Guardar los datos (modo texto).\n");
            printf("9. Guardar los datos (modo binario).\n");
            printf("10. Salir\n");
        while(getInt(&option,"Ingrese su opcion: ","Error,solo puedes ingresar del [1] al [10]",1,10)!=0);
        switch(option)
        {
            case 1:
                texto = controller_loadFromText("data.csv",listaEmpleados);
                if(texto == 0 && binario != 1)
                {
                    printf("los datos fueron cargados en modo Texto\n");
                    texto = 1;
                }else if(binario==1)
                {
                     printf("El archivo ya fue cargado en modo Binario\n");
                }else{
                    printf("El archivo no existe\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                binario = controller_loadFromBinary("databin",listaEmpleados);
                if(binario == 0 && texto != 1)
                {
                    printf("los datos fueron cargados en modo Binario\n");
                    binario = 1;
                }else if(texto==1)
                {
                     printf("El archivo ya fue cargado en modo Texto\n");
                }else{
                    printf("El archivo no existe\n");
                }
                system("pause");
                system("cls");
                //controller_loadFromBinaryAux("data.csv",listaEmpleados);<--- Esta funcion me ayudo a crear el archivo binario
                break;
            case 3:
                validador = controller_addEmployee(listaEmpleados);
                if(validador == 0)
                {
                    printf("Agregado con exito\n");
                }else{
                    printf("Empleado no agregado\n");
                }
                system("pause");
                system("cls");
                break;
            case 4:
                validador = controller_editEmployee(listaEmpleados);
                if(validador == 0)
                {
                    printf("Modificacion exitosa\n");
                }else{
                    printf("\nNo se a encontrado el Id ingresado\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                validador = controller_removeEmployee(listaEmpleados);
                if(validador == 0)
                {
                    printf("EL empleado fue borrado\n\n");
                }else if(validador==1)
                {
                    printf("La accion fue cancelada\n\n");
                }else{
                    printf("\nNo se encontro el ID ingresado\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 6:
                validador = controller_ListEmployee(listaEmpleados);
                if(validador == 0)
                {
                    printf("Todos los empleados fueron mostrados\n");
                }else{
                    printf("No hay nada que mostrar\n");
                }
                system("pause");
                system("cls");
                break;
            case 7:
                validador = controller_sortEmployee(listaEmpleados);
                if(validador == 0)
                {
                    printf("Ordenados con exito\n");
                }
                system("pause");
                system("cls");
                break;
            case 8:
                validador = controller_saveAsText("data.csv",listaEmpleados);
                if(validador == 0)
                {
                    printf("los datos fueron guardados en modo Texto\n");
                }else{
                    printf("El archivo no existe\n");
                }
                system("pause");
                system("cls");
                break;
            case 9:
                validador = controller_saveAsBinary("databin",listaEmpleados);
                if(validador == 0)
                {
                    printf("los datos guardados en modo Binario\n");
                }else{
                    printf("El archivo no existe\n");
                }
                system("pause");
                system("cls");
                break;
            default:
                printf("\n USTED ACABA DE SALIR\n");
                break;
        }
    }while(option != 10);
    return 0;
}
