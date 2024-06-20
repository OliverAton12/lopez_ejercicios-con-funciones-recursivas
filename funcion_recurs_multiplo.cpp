//fecha: 19/06/24
////Autor:Lopez Quiroz Wagner
//tema: ejercicios con funciones recursivas
//Diseña la función recursiva que imprima la una tabla de multiplicar. La función debe recibir 2 parámetros: el primero representa la tabla, y el segundo representa el límite superior de esa tabla.




#include <iostream>

void imprimirTabla(int tabla, int limite) {
    // Caso base: si el limite es 0, no hay más números que imprimir
    if (limite == 0) {
        return;
    }
    
    // Llamada recursiva con el límite reducido en 1
    imprimirTabla(tabla, limite - 1);
    
    // Imprimir el resultado de la multiplicación
    std::cout << tabla << " x " << limite << " = " << tabla * limite << std::endl;
}

int main() {
    int tabla, limite;
    std::cout << "Ingrese la tabla de multiplicar: ";
    std::cin >> tabla;
    std::cout << "Ingrese el límite superior: ";
    std::cin >> limite;

    imprimirTabla(tabla, limite);

    return 0;
}
