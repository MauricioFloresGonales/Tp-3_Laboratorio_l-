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
        int i;
        int len;

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
        len = ll_len(pArrayListEmployee);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);

            empleado = ll_newLinkedList();

            empleado->id = atoi(idAux);
            strcpy(empleado->nombre,nombreAux);
            empleado->horasTrabajadas = atoi(horasTrabajadasAux);
            empleado->sueldo = atof(sueldoAux);

            empleado = empleado+(i*sizeof(Employee));
            i++;
        }

        while(!feof(pFile))
        {
            i=0;
            //fprintf(pFile,"%d,%s,%d,%f\n",*(empleado+i)->id,*(empleado+i)->nombre,*(empleado+i)->horasTrabajadas,*(empleado+i)->sueldo);
            fread(empleado,sizeof(Employee),len,pFile);
            i++;
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
    int retorno = -1;
    Employee* empleado;
    char id[51];
    char nombre[51];
    char horasTrabajadas[51];
    char sueldo[51];
    int len;

    if(pFile!=NULL)
    {
        len = ll_len(pArrayListEmployee);
        while(!feof(pFile))
        {
            empleado = ll_newLinkedList();
            empleado->id = atoi(id);
            strcpy(empleado->nombre,nombre);
            empleado->horasTrabajadas = atoi(horasTrabajadas);
            empleado->sueldo = atof(sueldo);
            fwrite(&empleado,sizeof(Employee),1,pFile);
        }


        while(!feof(pFile))
        {
            fread(empleado,sizeof(Employee),len,pFile);
        }

        retorno = 0;
    }


    return retorno;

    return 1;
}
