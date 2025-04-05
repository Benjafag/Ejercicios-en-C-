#include <stdio.h>
#include "funcionesPrevias.h"

void imprimirRecursiva(Lista L){
  if (L == nullptr)
  {
    printf("");
  }
  else
  {
    printf("[%d]->", L->dato);
    imprimirRecursiva(L->siguiente);
  }  
}

void imprimirRecursivaReversa(Lista L){
  if (L == nullptr)
  {
    printf("");
  } else {
    imprimirRecursivaReversa(L->siguiente);
    printf("[%d]->", L->dato);
  }
}

int longitudRecursiva(Lista L){
  if (L == nullptr)
  {
    return 0;
  }
  else
  {
    return (1+longitudRecursiva(L->siguiente));
  }
  
}

bool estaEnLaListaRecursiva(Lista L, item buscado){
  if (L == nullptr)
  {
    return false;
  }
  if (L->dato == buscado) return true;
  return false || estaEnLaListaRecursiva(L->siguiente, buscado);
  
}

int main(){
  Lista miLista;
  miLista = crearLista();
  mostrarLista(miLista);
  miLista = insertar(miLista, 1);
  miLista = insertar(miLista, 2);
  miLista = insertar(miLista, 3);
  miLista = insertar(miLista, 4);
  puts("IMPRIMIR NORMAL:");
  imprimirRecursiva(miLista);
  puts("\nIMPRIMIR EN REVERSA:");
  imprimirRecursivaReversa(miLista);
  printf("\nLONGITUD CON RECURSIVIDAD: %d\n", longitudRecursiva(miLista));
  item buscar = 0;
  printf("\nBUSCAR %d CON RECURSIVIDAD: %s ESTA\n", buscar, estaEnLaListaRecursiva(miLista, buscar) ? "SI": "NO");

  return 0;
}