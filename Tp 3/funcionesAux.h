#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "Inputs.h"

int idAuto(LinkedList* pArrayListEmployee,Employee* ,int valMenor);
int idMayor(LinkedList* pArrayListEmployee,Employee* ,int valMenor);
int agregarEmpleado(LinkedList* pArrayListEmployee,Employee* );
void mostrarTodosLosEmpleado(LinkedList* pArrayListEmployee,Employee* empleados);
int validaId(LinkedList* pArrayListEmployee,Employee* empleados,int id);
