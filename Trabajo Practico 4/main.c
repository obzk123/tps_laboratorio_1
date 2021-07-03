#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "autos.h"

int main()
{
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaAux = NULL;
    LinkedList* listaClon = NULL;

    eAuto* auto1 = nuevoAutoParametros(0, "Honda", "CRV", 1998);
    eAuto* auto2 = nuevoAutoParametros(1, "Peugueot", "208", 2008);
    eAuto* auto3 = nuevoAutoParametros(2, "Chevrolet", "Onix", 2010);
    eAuto* auto4 = nuevoAutoParametros(3, "Volkswagen", "Gol", 2020);
    eAuto* auxAuto = NULL;

    //ll_add
    printf("Lista de autos\n");
    ll_add(lista, auto1);
    ll_add(lista, auto2);
    ll_add(lista, auto3);
    mostrarAutos(lista);

    //ll_len
    printf("\nLa longitud de la lista es: %d\n\n", ll_len(lista));

    //ll_get
    ll_add(lista, auto4);
    printf("Se agrego un auto\n");
    mostrarAuto( *((eAuto*) ll_get(lista, 3)));

    //ll_set
    printf("\nModificar auto:\nAntes\n");
    mostrarAuto( *((eAuto*) ll_get(lista, 3)));
    eAuto* auto5 = nuevoAutoParametros(4, "Volkswagen", "Gol", 2021);
    ll_set(lista, 3, auto5);
    printf("Despues\n");
    mostrarAuto( *((eAuto*) ll_get(lista, 3)));

    //ll_remove
    printf("\nEliminar un auto\n");
    mostrarAutos(lista);
    ll_remove(lista, 1);
    printf("\n");
    mostrarAutos(lista);

    //ll_indexOf
    printf("\nEl auto: ");
    mostrarAuto(*auto5);
    printf("Se encuentra en la posicion %d\n\n", ll_indexOf(lista, auto5));

    //ll_isEmpty
    if(ll_isEmpty(lista))
    {
        printf("La lista esta vacia\n");
    }else
    {
        printf("La lista no esta vacia\n");
    }

    //ll_push
    printf("\n\nInsertar un auto\n");
    ll_push(lista, 1, auto2);
    mostrarAutos(lista);

    //ll_pop
    printf("\nEliminar un auto pero guardar sus datos\n");
    auxAuto = (eAuto*) ll_pop(lista, 3);
    mostrarAutos(lista);
    printf("\nAuto guardado: ");
    mostrarAuto(*auxAuto);

    //ll_contains
    printf("\nBuscar auto especifico: ");
    mostrarAuto(*auto4);
    if(ll_contains(lista, auto4))
    {
        printf("Se encuentra en la lista\n");
    }else
    {
        printf("No se encuentra en la lista\n");
    }
    mostrarAutos(lista);

    //ll_subList
    listaAux = ll_subList(lista, 0, ll_len(lista));
    if(listaAux != NULL)
    {
        printf("\n\nSe creo una sub lista\n");
    }

    //ll_containsAll
    if(ll_containsAll(lista, listaAux))
    {
        printf("Los autos se encuentran en ambas listas");
    }
    else
    {
        printf("Los autos no se encuentran en ambas listas");
    }

    //ll_clone
    printf("\n\n");
    listaClon = ll_clone(lista);
    if(listaClon != NULL)
    {
        printf("Se clono la lista\n");
    }
    else
    {
        printf("No se pudo clonar la lista\n");
    }
    mostrarAutos(listaClon);

    //ll_clear
    printf("\nSe limpio la lista clonada");
    ll_clear(listaClon);

    //ll_deleteLinkedList
    printf("\n\nSe eliminaron la lista auxiliar y la clonada\n");
    ll_deleteLinkedList(listaAux);
    ll_deleteLinkedList(listaClon);

    //ll_sort
    printf("\nOrdenar lista por anio\n");
    ll_sort(lista, ordenarPorAnio, 0);
    mostrarAutos(lista);
    printf("\n\n");


    system("pause");
    return 0;
}
