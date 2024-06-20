//fecha: 19/06/24
////Autor:Lopez Quiroz Wagner
//tema: ejercicios con funciones recursivas
// Diseñe la función recursiva que realice la sumatoria de : 1 -2 + 3 - 4 + 5  - 6 + 7 .... n. Donde es el límite de la serie




#include <iostream>

int sumatoria(int n) {
    // Caso base: si n es 1, la sumatoria es 1
    if (n == 1) {
        return 1;
    }
    // Si n es impar, se suma el valor
    if (n % 2 != 0) {
        return n + sumatoria(n - 1);
    }
    // Si n es par, se resta el valor
    else {
        return -n + sumatoria(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "El valor de n debe ser mayor o igual a 1." << std::endl;
        return 1;
    }

    int resultado = sumatoria(n);
    std::cout << "La sumatoria de la serie hasta " << n << " es: " << resultado << std::endl;

    return 0;
}
