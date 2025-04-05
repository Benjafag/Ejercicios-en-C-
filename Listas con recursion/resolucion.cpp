#include <stdio.h>
#include "funcionesPrevias.h"

void imprimirRecursiva(Lista L){
  if (L == nullptr)
  {
    printf(" ");
  }
  else
  {
    printf("[%d]->", L->dato);
    imprimirRecursiva(L->siguiente);
  }
  
}


int main(){
  Lista miLista;
  miLista = crearLista();
  mostrarLista(miLista);
  miLista = insertar(miLista, 1);
  miLista = insertar(miLista, 2);
  miLista = insertar(miLista, 3);
  miLista = insertar(miLista, 4);
  imprimirRecursiva(miLista);
  return 0;
}