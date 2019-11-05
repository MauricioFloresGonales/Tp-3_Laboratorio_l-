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
    FILE* pFile;
    int retorno = -1;

    if(pFile!=NULL)
    {
        pFile = fopen(path,"r");

        retorno = parser_EmployeeFromText(pFile,pArrayListEmployee);

        fclose(pFile);
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
    return 1;
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
    Employee* empleadoAux = employee_new();
    int modificar;

    mostrarTodosLosEmpleado(pArrayListEmployee);
    getIntIlimit(&empleadoAux->id,"Ingrese el Id del empleado que quiera modificar: ","Error,el numero no puede ser menor a 1",1);

    modificar =  ll_indexOf(pArrayListEmployee,(Employee*)empleadoAux->id);

    if(validaId(pArrayListEmployee,modificar)==0)
    {
        empleadoAux = ll_get(pArrayListEmployee,modificar);
        modicaficarEmpleado(pArrayListEmployee,empleadoAux);
        //int ll_set(LinkedList* this, int index,void* pElement);PODRIA USAR ESTA FUNCION PARA NO USAR LA FUNCION DE ARRIBA??
        ll_push(pArrayListEmployee,modificar,(Employee*)empleadoAux);//ESTA BIEN ?
    }




    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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

