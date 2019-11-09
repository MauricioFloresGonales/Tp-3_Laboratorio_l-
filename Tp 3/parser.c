#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pFile!=NULL)
    {
        Employee* empleado;
        char idAux[51];
        char nombreAux[51];
        char horasTrabajadasAux[51];
        char sueldoAux[51];

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
            empleado = employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
            ll_add(pArrayListEmployee,empleado);
        }

        retorno = 0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    int aux;
    int retorno = -1;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            empleado = employee_new();
            aux = fread(empleado,sizeof(Employee),1,pFile);
            if(aux == 1)
            {
                ll_add(pArrayListEmployee,empleado);
            }
        }

        retorno = 0;
    }
    return retorno;
}
