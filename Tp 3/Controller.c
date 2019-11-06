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
    puede = agregarEmpleado(pArrayListEmployee,empleado);
    if(puede == 0)
    {
        ll_add(pArrayListEmployee,empleado);

    }else{
        printf("Empleado no agregado\n");
    }

    return 1;
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
        printf("\nNo se a encontrado el Id ingresado\n\n");
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
            printf("EL empleado fue borrado\n\n");
            retorno = 0;
        }else{
            printf("La accion fue cancelada\n\n");
            retorno = -1;
        }

    }else{
        printf("\nNo se encontro el ID ingresado\n\n");
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
    return 1;
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
    return 1;
}

