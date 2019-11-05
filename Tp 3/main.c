#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "Inputs.h"
#include "funcionesAux.h"

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
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:

                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                break;
            case 6:
                mostrarTodosLosEmpleado(listaEmpleados);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
            break;
            default:
                printf("SALIR\n");
                break;
        }
    }while(option != 10);
    return 0;
}
