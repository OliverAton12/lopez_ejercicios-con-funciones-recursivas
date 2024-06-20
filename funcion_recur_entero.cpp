//fecha: 19/06/24
////Autor:Lopez Quiroz Wagner
//tema: ejercicios con funciones recursivas
//Diseñe la función recursiva que cuenta el total de cifras que tiene un número entero.


#include <iostream>

int contarCifras(int numero) {
    // Caso base: si el número es menor que 10, tiene solo una cifra
    if (numero < 10) {
        return 1;
    } else {
        // Caso recursivo: dividir el número por 10 y sumar 1 al contador de cifras
        return 1 + contarCifras(numero / 10);
    }
}

int main() {
    int numero;
    std::cout << "Ingrese un número entero: ";
    std::cin >> numero;

    // Asegurar que el número es positivo para contar las cifras
    if (numero < 0) {
        numero = -numero;
    }

    int totalCifras = contarCifras(numero);
    std::cout << "El número " << numero << " tiene " << totalCifras << " cifras." << std::endl;

    return 0;
}
