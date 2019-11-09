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
        empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
        if(mayor<empleadoAux->id)
        {
            mayor = empleadoAux->id;
        }
    }
    //printf("%p\n\n",pArrayListEmployee);(con esto el profesor pudo encontrar el error
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
        empleadosAux =(Employee*) ll_get(pArrayListEmployee,i);
        mostrarEmpleado(empleadosAux);
    }
}

int validaId(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int id;
    int len;
    int i;
    int indice;

    mostrarTodosLosEmpleado(pArrayListEmployee);
    while(getIntIlimit(&id,"Ingrese el Id del empleado que quiera modificar: ","Error,el numero no puede ser menor a 1",1)!=0);

    len = ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        empleadoAux =(Employee*) ll_get(pArrayListEmployee,i);

        if(empleadoAux->id == id)
        {
            indice = ll_indexOf(pArrayListEmployee, empleadoAux);
            break;
        }

        indice = -1;
    }

    return indice;
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
                while(getIntIlimit(&horasAux,"Ingrese las horas: ","Error,el numero no puede se menor a cero",0)!=0);
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
                printf("\nSalio del menu de modificar\n");
            }

        }while(opcion != 4);
}

int menuSort(LinkedList* pArrayListEmployee)
{
    LinkedList* pArrayListEmployeeAux = ll_newLinkedList();
    int retorno = -1;
    int opcion;

    pArrayListEmployeeAux = ll_clone(pArrayListEmployee);

    do{
        while(getInt(&opcion,"1.Ord.Legajo\n2.Ord.Nombre\n3.Ord.Horas Trabajadas\n4.Ord.sueldo\n5.Salir\nIngresar opcion: ","Error,Solo puiede ingresar numeros de las opciones del menu",1,5)!=0);

        switch(opcion)
        {
            case 1:
                while(getInt(&opcion,"[0] mayor a menor\n[1] de menor a mayor\nIngrese la opcion: ","Error,Solo puiede ingresar [0] o [1]",0,1)!=0);
                if(opcion==0)
                {
                    printf("\nOrdenando...");
                    ll_sort(pArrayListEmployeeAux,compararPorLegajo,opcion);
                    printf("Listo\n\n");
                    retorno = 0;
                }
                mostrarTodosLosEmpleado(pArrayListEmployeeAux);
                break;
            case 2:
                while(getInt(&opcion,"[0] Z - A\n[1] A - Z\nIngrese la opcion: ","Error,Solo puiede ingresar [0] o [1]",0,1)!=0);
                if(opcion==0)
                {
                    printf("\nOrdenando...");
                    ll_sort(pArrayListEmployeeAux,compararPorNombre,opcion);
                    printf("Listo\n\n");
                    retorno = 0;
                }
                mostrarTodosLosEmpleado(pArrayListEmployeeAux);

                break;
            case 3:
                while(getInt(&opcion,"[0] mayor a menor\n[1] de menor a mayor\nIngrese la opcion: ","Error,Solo puiede ingresar [0] o [1]",0,1)!=0);
                if(opcion==0)
                {
                    printf("\nOrdenando...");
                    ll_sort(pArrayListEmployeeAux,compararPorHoras,opcion);
                    printf("Listo\n\n");
                    retorno = 0;
                }
                mostrarTodosLosEmpleado(pArrayListEmployeeAux);

                break;
            case 4:
                while(getInt(&opcion,"[0] mayor a menor\n[1] de menor a mayor\nIngrese la opcion: ","Error,Solo puiede ingresar [0] o [1]",0,1)!=0);
                if(opcion==0)
                {
                    printf("\nOrdenando...");
                   ll_sort(pArrayListEmployeeAux,compararPorSueldo,opcion);
                   printf("Listo\n\n");
                   retorno = 0;
                }
                mostrarTodosLosEmpleado(pArrayListEmployeeAux);

                break;
            default:
                printf("\nEsta saliendo del menu de ordenamiento\n\n");
                break;
        }
    }while(opcion!=5);
    return retorno;
}
