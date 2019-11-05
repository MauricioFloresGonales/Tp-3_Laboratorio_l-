#include "funcionesAux.h"

int idAuto(LinkedList* pArrayListEmployee,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayor(pArrayListEmployee,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

int idMayor(LinkedList* pArrayListEmployee,int valMenor)
{
    Employee* empleadoAux;
    int i;
    int mayor = valMenor-1;
    int len;

    len = ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        empleadoAux = ll_get(pArrayListEmployee,i);

        if(mayor<empleadoAux[i].id)
        {
            mayor = empleadoAux[i].id;
        }
    }
    return mayor;
}

int agregarEmpleado(LinkedList* pArrayListEmployee,Employee* empleado)
{
    int id;
    char nombreAux[51];
    int horasAux;
    float salarioAux;
    int retorno;

    id = idAuto(pArrayListEmployee,1);
    while(getString(nombreAux,"ingrese el Nombre: ","Error,solo puede ingresar [51] caracteres\n","Error,No puede ingresa numeros\n",1,51)!=0);
    while(getIntIlimit(&horasAux,"Ingrese las horas Trabajadas: ","Error,tiene que ser mayor a cero",0)!=0);
    while(getFloatIlimit(&salarioAux,"Ingrese el Salario: ","Error,no puede ingresar letras",1)!=0);

    printf("%d  %5s  %5d  %5f\n",id,nombreAux,horasAux,salarioAux);

    if(confirmar("Continuar","Cancelar")==0)
    {
        employee_setId(empleado,id);
        employee_setNombre(empleado,nombreAux);
        employee_setHorasTrabajadas(empleado,horasAux);
        employee_setSueldo(empleado,salarioAux);
        retorno = 0;
    }else{
        retorno = 1;
    }
    return retorno;
}

void mostrarTodosLosEmpleado(LinkedList* pArrayListEmployee)
{
    Employee* empleadosAux;
    int len;
    int i;

    len = ll_len(pArrayListEmployee);
    printf("\tId   Nombre\t  Horas    Salario\n");
    for(i=0;i<len;i++)
    {
        empleadosAux = ll_get(pArrayListEmployee,i);
        mostrarEmpleado(empleadosAux);
    }
}

int validaId(LinkedList* pArrayListEmployee,int id)
{
    Employee* empleados = employee_new();
    int retorno;

    employee_setId(empleados,id);

    retorno = ll_contains(pArrayListEmployee,(Employee*)empleados->id);

    free(empleados);

    return retorno;
}

void modicaficarEmpleado(LinkedList* pArrayListEmployee,Employee* empleado)
{
    char nombreAux[51];
    int horasAux;
    float sueldoAux;
    int opcion;

    do{
        getInt(&opcion,"Modificar:\n1-Nombre\n2-Horas Trabajadas\n3-Sueldo\n4-Salir\nOpcion: ","Solo puede ingresar los numeros que aparecen en el menu",1,4);
        switch(opcion)
        {
            case 1:
                while(getString(nombreAux,"Ingrese el Nombre: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    employee_setNombre(empleado,nombreAux);
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            case 2:
                while(getInt(&horasAux,"Ingrese las horas: ","Error,el dia tiene 24hs",0,24)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    employee_setHorasTrabajadas(empleado,horasAux);
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            case 3:
                while(getFloatIlimit(&sueldoAux,"Ingrese el sueldo a modificar: ","Error,no puedes ingresar letras",0)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    employee_setSueldo(empleado,sueldoAux);
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                    break;
            default:
                printf("salir");
            }

        }while(opcion != 4);
}
