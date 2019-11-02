#include "funcionesAux.h"


int idAuto(Employee listadoDeEmpleados[],int len,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayor(listadoDeEmpleados,len,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

int idMayor(Employee listadoDeEmpleados[],int len,int valMenor)
{
    int i;
    int mayor = valMenor-1;

    for(i=0;i<len;i++)
    {
        if(mayor<listadoDeEmpleados[i].legajo)
        {
            mayor = listadoDeEmpleados[i].legajo;
        }
    }
    return mayor;
}
