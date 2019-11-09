#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#include "Inputs.h"
#include "funcionesAux.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"r");
    int retorno = -1;

    if(pFile!=NULL)
    {

        retorno = parser_EmployeeFromText(pFile,pArrayListEmployee);

        fclose(pFile);

        retorno = 0;
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"rb");
    int retorno = -1;

    if(pFile!=NULL)
    {
        retorno = parser_EmployeeFromBinary(pFile,pArrayListEmployee);

        fclose(pFile);
    }else{
        printf("NO Existe\n");
    }
    return retorno;
}


int controller_loadFromBinaryAux(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"r");
    FILE* pFileBin = fopen("databin","wb");

    Employee* empleado;
    char idAux[51];
    char nombreAux[51];
    char horasTrabajadasAux[51];
    char sueldoAux[51];
    int retorno =-1;

    if(pFile!=NULL && pFileBin!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
            empleado = employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
            ll_add(pArrayListEmployee,empleado);
            fwrite(empleado,sizeof(Employee),1,pFileBin);
        }

        fclose(pFile);
        fclose(pFileBin);
        retorno = 0;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado = employee_new();
    int puede;
    int retorno;

    puede = agregarEmpleado(pArrayListEmployee,empleado);

    if(puede == 0)
    {
        ll_add(pArrayListEmployee,empleado);
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int indice;
    int retorno;

    indice = validaId(pArrayListEmployee);

    if(indice>1)
    {
        empleadoAux =(Employee*) ll_get(pArrayListEmployee,indice);
        modicaficarEmpleado(pArrayListEmployee,empleadoAux);
        ll_set(pArrayListEmployee, indice, empleadoAux);
        printf("El empleado modificado quedo asi:\n");
        mostrarEmpleado(empleadoAux);
        printf("\n");
        retorno = 0;

    }else{
        retorno = -1;
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int retorno;
    int index;

    index = validaId(pArrayListEmployee);

    if(index > 1)
    {
        empleadoAux = (Employee*)ll_get(pArrayListEmployee,index);
        mostrarEmpleado(empleadoAux);

        if(confirmar("Confirmar","Cancelar")==0)
        {
            ll_remove(pArrayListEmployee,index);
            retorno = 0;
        }else{
            retorno = 1;
        }

    }else{
        retorno = -1;
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;

    if(pArrayListEmployee!=NULL)
    {
        mostrarTodosLosEmpleado(pArrayListEmployee);
        retorno = 0;
    }else{
        retorno = -1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;

    retorno = menuSort(pArrayListEmployee);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"w");
    int len;
    int i;
    int retorno = -1;

    if(pFile!=NULL)
    {
        Employee* empleado;

        len = ll_len(pArrayListEmployee);

        fprintf(pFile,"id,nombre,HorasTrabajadas,sueldo\n");

        for(i=0;i<len;i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            fprintf(pFile,"%d,%s,%d,%f\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
        }

        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path,"wb");
    int len;
    int i;
    int retorno = -1;

    if(pFile!=NULL)
    {
        Employee* empleado;

        len = ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            fwrite(empleado,sizeof(Employee),1,pFile);
        }

        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

