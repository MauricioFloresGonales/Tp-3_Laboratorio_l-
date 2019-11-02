/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas

LinkedList* ll_newLinkedList(void);
///reserva un espacio en el heap (hace un malloc en memoria)

//--------------------------------------------------------------------------------------
int ll_len(LinkedList* this);
///muetra la cantidad de elementos que tenemos dentro de la lista(cuenta cuantos hay)
Node* test_getNode(LinkedList* this, int nodeIndex);
//--------------------------------------------------------------------------------------
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
//--------------------------------------------------------------------------------------
int ll_add(LinkedList* this, void* pElement);
///Agrega un elemento(devuelvesi pudo agragarlo o no)
/// [o] si esta bien - [-1] si es puntero NULL
//--------------------------------------------------------------------------------------
void* ll_get(LinkedList* this, int index);
///pasamos una lista,un indice y el get me dice cual es el objeto que hay en ese indice
//--------------------------------------------------------------------------------------
int ll_set(LinkedList* this, int index,void* pElement);
///pone un elemento por encima de otro(?)
//--------------------------------------------------------------------------------------
int ll_remove(LinkedList* this,int index);
///le paso un elemento en particular y me lo saca
//--------------------------------------------------------------------------------------
int ll_clear(LinkedList* this);
///borra los elementos de la lista
//--------------------------------------------------------------------------------------
int ll_deleteLinkedList(LinkedList* this);
///borra la lista y lo que tenga dentro
//--------------------------------------------------------------------------------------
int ll_indexOf(LinkedList* this, void* pElement);
///le paso una referencia y me dice donde esta
//--------------------------------------------------------------------------------------
int ll_isEmpty(LinkedList* this);
///me dice si hay algo en la lista o no / la dif con len es: este me dice si hay el len dice cuantos hay
//--------------------------------------------------------------------------------------
int ll_push(LinkedList* this, int index, void* pElement);
///agrega un elemento a la lista (algo en el medio de la lista)/ la dif con set es:
//--------------------------------------------------------------------------------------
void* ll_pop(LinkedList* this,int index);
///elimina / dif con remove es: que pop devuelve el elemnto (lo saca de donde este y lo puedo mover hacia otra parte)
//--------------------------------------------------------------------------------------
int ll_contains(LinkedList* this, void* pElement);
///paso un elemento y me dice si esta o no en la lsita
//--------------------------------------------------------------------------------------
int ll_containsAll(LinkedList* this,LinkedList* this2);
///mustra que elementos tengo en la lista
//--------------------------------------------------------------------------------------
LinkedList* ll_subList(LinkedList* this,int from,int to);
///duvuelve una sublista de un elemento determinado a otro
//--------------------------------------------------------------------------------------
LinkedList* ll_clone(LinkedList* this);
///crea una copia de una lista(va a ser una lista en otro lado)
//--------------------------------------------------------------------------------------
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
/// ordena
///  recive una funcion como parametro(esta funcion seria la que tenga el criteriode ordenamiento)
///
//--------------------------------------------------------------------------------------
