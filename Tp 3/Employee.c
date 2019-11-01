#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"



int employee_setId(Employee* this,int id)
{

    int todoOk = 0;

    if( this != NULL && id > 0)
    {

        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{

    int todoOk = 0;

    if( this != NULL && id != NULL )
    {

        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}


int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL && strlen(nombre) > 3)
    {

        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;

}
int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}

int employee_setSueldo(Employee* this,float sueldo)
{

    int todoOk = 0;

    if( this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;

}
int employee_getSueldo(Employee* this,float* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* this;

        if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
        {
            this  = employee_new();

            if( this != NULL){

            if( !employee_setId(this, atoi(idStr))||

                !employee_setNombre(this, nombreStr) ||

                !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||

                !employee_setSueldo(this, atof(sueldoStr)))
                       {
                            free(this);
                            this = NULL;
                       }
            }
        }

    return this;
}


void mostrarEmpleado(Employee* emp){
    if(emp != NULL){
    printf("%d  %5s  %5d  %5f\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
}

int compararPorLegajo(void* empleadoUno,void* empleadoDos)
{
    int compara = -1;
    int idUno;
    int idDos;

    Employee* empleado1= (Employee*)empleadoUno;
    Employee* empleado2 = (Employee*)empleadoDos;

    employee_getId(empleado1,&idUno);
    employee_getId(empleado2,&idDos);

    if(empleadoUno > empleadoDos)
    {
        compara = 1;
    }else{
        if(empleadoUno==empleadoDos)
        {
            compara = 0;
        }
    }

    return compara;
}


int compararPorSueldo(void* empleadoUno,void* empleadoDos)
{
    int compara = -1;
    float sueldoUno;
    float sueldoDos;

    Employee* empleado1= (Employee*)empleadoUno;
    Employee* empleado2 = (Employee*)empleadoDos;

    employee_getSueldo(empleado1,&sueldoUno);
    employee_getSueldo(empleado2,&sueldoDos);

    if(sueldoUno > sueldoDos)
    {
        compara = 1;
    }else{
        if(sueldoUno==sueldoDos)
        {
            compara = 0;
        }
    }
    return compara;
}


int compararPorNombre(void*empleadoUno,void*empleadoDos)
{
    int compara;

    Employee* empleado1= (Employee*)empleadoUno;
    Employee* empleado2 = (Employee*)empleadoDos;

    char nombreUno[50];
    char nombreDos[50];
    employee_getNombre(empleado1,nombreUno);
    employee_getNombre(empleado2,nombreDos);

    compara = stricmp(nombreUno,nombreDos);

    return compara;

}


