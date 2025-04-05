#include <stdio.h>
typedef int item;
struct Nodo {
  item dato;
  Nodo* siguiente;
};
typedef Nodo* Lista;


// 1.
Lista crearLista(){
  return nullptr;
}

int longitud(Lista l){
  int suma = 0;
  while (l != nullptr)
  {
    suma++;
    l = l->siguiente;
  }
  return suma;
}
void agregarNodoAlFinal(Lista* l,item valor){
  Nodo* nuevoNodo;
  nuevoNodo = new Nodo;
  nuevoNodo->dato = valor;
  nuevoNodo->siguiente = nullptr;

  switch (longitud(*l))
  {
  case 0:
    *l = nuevoNodo;
    break;
  case 1:
    (*l)->siguiente = nuevoNodo;
    break;
  default:
    Nodo* aux = *l;
    while (aux->siguiente != nullptr)
    {
      aux = aux->siguiente;
    }
    
    aux->siguiente = nuevoNodo;

    break;
  }
}
void mostrarLista(Lista l){
  if (l == nullptr) puts("Lista vacia");
  while (l != nullptr)
  {
    printf("[%d]", l->dato);
    l = l->siguiente;
  }
  puts("");
}

// 2.
Lista insertarConIndice(Lista l, int indice, item valor){
  int longitudLista = longitud(l);
  if (indice == 0 || indice - 1 > longitudLista){
    printf("Ingrese un numero contenido en [1,%d]\n", longitud(l) + 1);
    return l;
  }
  Nodo *nuevoNodo;
  nuevoNodo = new Nodo;
  nuevoNodo->dato = valor;
  nuevoNodo->siguiente = nullptr;

  if (indice == 1)
  {
    nuevoNodo->siguiente = l;
    l = nuevoNodo;
    return l;
  }
  
  Nodo* anterior = l;
  Nodo* partida = l;
    for (int i = 0; i < indice - 1; i++)
    {
      anterior = l;
      l = l->siguiente;
    }
    nuevoNodo->siguiente = l;
    anterior->siguiente = nuevoNodo;
    l = partida;
    return l;

}

// 3. Eliminar por valor
Lista eliminarPorValor(Lista l, item valor){
  Nodo* auxiliar;
  if (l->dato==valor){
    auxiliar = l;
    l = l->siguiente;
    delete(auxiliar);
    return l;
  }
  Lista partida = l;
  //casos para 2 o mas
  while (l != nullptr)
  {
    if (l->siguiente != nullptr && l->siguiente->dato == valor){
      auxiliar = l->siguiente;
      l->siguiente = l->siguiente->siguiente;
      delete(auxiliar);
      return partida;
      break;
    }
    l = l->siguiente;
  }
  puts("No hubo coincidencias!");
  return partida;
  
}
// extra cambiar valor de un nodo
void cambiarValor(Lista l, int indice, item valor){
  if (indice == 0 || indice > longitud(l)){
    printf("Ingrese un numero contenido en [1,%d]\n", longitud(l));
  }
  for (int i = 1; i < indice; i++)  
  {
    l= l->siguiente;
  }
  l->dato = valor;
}

// 4. Buscar un elemento en la lista:
bool estaEnLaLista(Lista l, item valor){
  while (l->siguiente != nullptr)
  {
    if(l->dato ==valor) return true;
    l=l->siguiente;
  }
  if(l->dato ==valor) return true;
  return false;
}

//5. Invertir la lista enlazada:
Lista invertirLista(Lista l){
  Nodo* aux;
  Nodo* laux;
  aux = l->siguiente;
  laux = aux->siguiente;
  l->siguiente = nullptr;
  while (laux->siguiente != nullptr)
  {
    aux->siguiente = l;
    l = aux;
    aux=laux;
    laux = aux->siguiente;
    
  }
  aux->siguiente = l;
  laux->siguiente = aux;
  l = laux;
  return l;
  
}

// 6. Eliminar nodos duplicados:
void eliminarDuplicados(Lista l){
  // Lista partida = l;
  Nodo* i = l;
  Nodo* aux = nullptr;
  while (l->siguiente != nullptr)
  {
    while (i->siguiente != nullptr)
    {
      aux = i;
      i = i->siguiente;      
      if (l->dato == i->dato)
      {
        aux->siguiente = i->siguiente;
        delete(i);
        i = aux;
      }
    }
    l = l->siguiente;
    i = l;
  }
  
}

// 8. Dividir la lista en pares e impares:
Lista dividirLista(Lista l, Lista* P, Lista* I){
  Nodo* impares = nullptr;
  Nodo* pares = nullptr;
  while (l->siguiente != nullptr)
  {
    if (l->dato%2 == 0) // pares
    {
      pares = l;
      l = l->siguiente;
      pares->siguiente = *P;
      *P = pares;
      
    }
    else // impares
    {
      impares = l;
      l = l->siguiente;
      impares->siguiente = *I;
      *I = impares;
      
    }
    
  }
  if (l->dato%2 == 0) // pares
  {
    pares = l;
    l = l->siguiente;
    pares->siguiente = *P;
    *P = pares;
    
  }
  else // impares
  {
    impares = l;
    l = l->siguiente;
    impares->siguiente = *I;
    *I = impares;
    
  }
  return l;
}

// 10. Merge de dos listas ordenadas:
void mergearListas(Lista* l1, Lista* l2){
  Lista partida = *l1;
  while ((*l1)->siguiente != nullptr)
  {
    *l1 = (*l1)->siguiente;
  }
  (*l1)->siguiente = *l2;
  *l1 = partida;
}

// 11. Convertir una lista en una lista doblemente enlazada:
// ?

// 12. Implementar una lista circular:
Lista listaCircular(Lista l){
  Lista partida = l;
  while (l->siguiente!=nullptr)
  {
    l = l->siguiente;
  }
  l->siguiente = partida;
  return partida;
}

int main(){
  Lista l;
  l = crearLista();
  agregarNodoAlFinal(&l,1);
  agregarNodoAlFinal(&l,6);
  agregarNodoAlFinal(&l,3);
  agregarNodoAlFinal(&l,4);
  agregarNodoAlFinal(&l,5);
  agregarNodoAlFinal(&l,6);
  agregarNodoAlFinal(&l,6);
  agregarNodoAlFinal(&l,8);
  // agregarNodoAlFinal(&l,9);
  // printf("Longitud con 3 elementos: %d\n", longitud(l)); // 3
  // mostrarLista(l);
  // l = insertarConIndice(l,1,0);
  // mostrarLista(l);
  // l = eliminarPorValor(l,5);
  // cambiarValor(l,2,7);
  // int buscado = 5;
  // printf("%d %s esta en la lista\n", buscado, estaEnLaLista(l,buscado)?"SI":"NO");
  // mostrarLista(l);
  // mostrarLista(l);
  // l = invertirLista(l);
  // mostrarLista(l);
  // eliminarDuplicados(l);
  mostrarLista(l);
  Lista pares = crearLista(), impares = crearLista();
  l = dividirLista(l, &pares, &impares);
  puts("Original");
  mostrarLista(l);
  puts("Pares");
  mostrarLista(pares);
  puts("Impares");
  mostrarLista(impares);
  mergearListas(&pares,&impares);
  mostrarLista(pares);
  listaCircular(impares);
  mostrarLista(impares);
}