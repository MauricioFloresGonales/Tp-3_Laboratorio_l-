#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "Inputs.h"

int idAuto(LinkedList* pArrayListEmployee,int valMenor);
int idMayor(LinkedList* pArrayListEmployee,int valMenor);
int agregarEmpleado(LinkedList* pArrayListEmployee,Employee*);
void mostrarTodosLosEmpleado(LinkedList* pArrayListEmployee);
int validaId(LinkedList* pArrayListEmployee);
void modicaficarEmpleado(LinkedList* pArrayListEmployee,Employee* );
int menuSort(LinkedList* pArrayListEmployee);
