//fecha: 19/06/24
////Autor:Lopez Quiroz Wagner
//tema: ejercicios con funciones recursivas
//Diseña la función recursiva que imprima la una tabla de multiplicar, de manera descendente desde el 10 al 1


#include <iostream>

void imprimirTablaDescendente(int tabla, int limite) {
    // Imprimir el resultado de la multiplicación
    std::cout << tabla << " x " << limite << " = " << tabla * limite << std::endl;
    
    // Caso base: si el limite es 1, no hay más números que imprimir
    if (limite == 1) {
        return;
    }
    
    // Llamada recursiva con el límite reducido en 1
    imprimirTablaDescendente(tabla, limite - 1);
}

int main() {
    int tabla;
    std::cout << "Ingrese la tabla de multiplicar: ";
    std::cin >> tabla;

    imprimirTablaDescendente(tabla, 10);

    return 0;
}

