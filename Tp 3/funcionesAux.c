#include "funcionesAux.h"

int idAuto(LinkedList* pArrayListEmployee,Employee* empleado,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayor(pArrayListEmployee,empleado,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

int idMayor(LinkedList* pArrayListEmployee,Employee* empleado,int valMenor)
{
    int i;
    int mayor = valMenor-1;
    int len;

    len = ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        if(mayor<empleado[i].id)
        {
            mayor = empleado[i].id;
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

    id = idAuto(pArrayListEmployee,empleado,1);
    while(getString(nombreAux,"ingrese el Nombre: ","Error,solo puede ingresar [51] caracteres\n","Error,No puede ingresa numeros\n",1,51)!=0);
    while(getInt(&horasAux,"Ingrese las horas de trabajo: ","Error,el dia solo tiene 24hs",0,24)!=0);
    while(getFloatIlimit(&salarioAux,"Ingrese el Salario: ","Error,no puede ingresar letras",1))

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

void mostrarTodosLosEmpleado(LinkedList* pArrayListEmployee,Employee* empleados)
{
    int len;
    int i;

    len = ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        mostrarEmpleado(empleados);
    }
}

int validaId(LinkedList* pArrayListEmployee,Employee* empleados,int id)
{
    int i;
    int len;
    int retorno = -1;
    len = ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        if(id==empleados[i].id)
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

void modicficarEmpleado(LinkedList* pArrayListEmployee,Employee* empleado)
{
    /*Employee* empleadoAux;
    int index;
    int opcion;
    int id;
    getIntIlimit()
    index = validaId(pArrayListEmployee,empleado);

    do{
            getInt(&opcion,"Modificar:\n1-Nombre\n2-Horas Trabajadas\n3-Sueldo\n4-Salir\nOpcion: ","Solo puede ingresar los numeros que aparecen en el menu",1,4);
            switch(opcion)
            {
            case 1:
                while(getString(empleadoAux.nombre,"Ingrese el Nombre: ","El limite de caracteres fue pasado","No puede ingresar numeros",0,51)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    strcpy(empleado[index].nombre,empleadoAux.nombre);
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            case 2:
                while(getInt(&empleadoAux.horasTrabajadas,"Ingrese las horas: ","Error,el dia tiene 24hs",0,24)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    empleado[index].horasTrabajadas,empleadoAux.horasTrabajadas);
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            case 3:
                while(getFloatIlimit(&empleadoAux.sueldo,"Ingrese el sueldo a modificar: ","Error,no puedes ingresar letras",0)!=0);
                if(confirmar("Confirmar:","Canselar:")==0)
                {
                    empleado[index].sueldo = empleadoAux.sueldo;
                }else{
                    printf("La operecion fue cancelada.\n");
                }
                break;
            default:
                printf("salir");
            }

    }while(opcion != 4);*/
}
