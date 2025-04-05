#include <stdio.h>

// Ejercicio 1: Implementar una función recursiva que calcule el factorial de un número.
int factorial(int n){
  if (n == 1) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
};
// Ejercicio 2: Implementar una función recursiva que calcule la suma de los primeros N números naturales.
int sumaNaturales(int n){
  if (n == 1) {
    return 1;
  } else {
    return n + sumaNaturales(n-1);
  }  
}
// Ejercicio 3: Implementar una función recursiva para calcular a^b.
int potencia(int a, int b){
  if (b == 1) {
    return a;
  } else {
    return (a * potencia(a,b-1));
  }
}
// Ejercicio 4: Implementar una función recursiva que devuelva el enésimo término de la secuencia de Fibonacci.
int terminoFibonnacci(int n){
  if (n == 1) {
    return 0;
  } else if (n == 2 || n == 3) {
    return 1;
  } else {
    return (terminoFibonnacci(n-1) + terminoFibonnacci(n-2));
  }
}
// Ejercicio 5: Implementar una función recursiva que invierta una cadena de caracteres.
void invertir(char* cadena){
  if (*cadena == '\0'){

  } 
  else {
    invertir(cadena+1);
    printf("%c", *cadena);
  } 
}
// Ejercicio 6: Implementar una función recursiva que sume los dígitos de un número entero positivo.
int sumarDigito(int n){
  if (n < 10)
  {
    return n % 10;
  }
  else
  {
    return (n % 10 + sumarDigito(n / 10));
  }
}
// Ejercicio 7: Implementar una función recursiva que cuente cuántos dígitos tiene un número.
int contarDigitos(int n){
  if (n < 10)
  {
    return 1;
  }
  else
  {
    return ( 1 + contarDigitos(n/10));
  }
}
// Ejercicio 8: Implementar una función recursiva para calcular el MCD de dos números usando el algoritmo de Euclides.

// Ejercicio 9: Implementar una función recursiva para calcular combinaciones C(n, r).



char cadena[] = "Hola, como estas?";
int main()
{
  // printf("%d",factorial(4));
  // printf("%d",sumaNaturales(10));
  // printf("%d",potencia(2,6));
  // printf("%d",terminoFibonnacci(7));
  // printf("%d",sumarDigito(7123000));
  // printf("%d",contarDigitos(7126003));
  invertir(cadena);

  
  return 0;
}
