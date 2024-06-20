//fecha: 19/06/24
////Autor:Lopez Quiroz Wagner
//tema: ejercicios con funciones recursivas
//Diseñe el programa que permita generar 3 cartas aleatorias, con las siguientes consideraciones:
 //Se puede comenzar a jugar, si luego de generar las 3 cartas, las 3 son diferentes, es decir, si salen, por ejemplo dos cartas K de brillo, no se puede continuar. 
 //El jugador gana si la sumatoria de sus cartas es 21. La carta A se la considera como 1, las cartas J, Q, K se las considera como 10.
//Si al generar las 3 primeras cartas el jugador no ha ganado, tiene la posibilidad de cambiar hasta 2 cartas.
//Se debe preguntar al usuario: Cuántas cartas desea cambiar 1 o 2 ?
//Luego de este cambio se vuelven a sumar y si suman 21 , ya hay ganador. También gana cuando salen 3 cartas iguales. Por ejemplo  A de brillo, A de trébol, A de corazón.
 //Después de cada partida, debe preguntar al usuario: Desea seguir Jugando (S/N) ?

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Carta {
    int valor;
    string simbolo;
};

string obtenerSimbolo(int indice) {
    switch (indice) {
        case 0: return "corazones";
        case 1: return "diamantes";
        case 2: return "treboles";
        case 3: return "picas";
        default: return "?";
    }
}

string obtenerValorCarta(int valor) {
    if (valor == 1) return "A";
    if (valor == 11) return "J";
    if (valor == 12) return "Q";
    if (valor == 13) return "K";
    return to_string(valor);
}

int obtenerPuntosCarta(int valor) {
    if (valor == 1) return 1;
    if (valor >= 11 && valor <= 13) return 10;
    return valor;
}

void Imprimircarta(const Carta& carta) {
    string valor = obtenerValorCarta(carta.valor);
    string simbolo_char;

    if (carta.simbolo == "corazones") simbolo_char = "♥";
    else if (carta.simbolo == "diamantes") simbolo_char = "♦";
    else if (carta.simbolo == "treboles") simbolo_char = "♣";
    else if (carta.simbolo == "picas") simbolo_char = "♠";
    else simbolo_char = "?";

    cout << "╔════════════╗" << endl;
    cout << "║ " << valor;
    if (valor.length() == 1) cout << " ";
    cout << "         ║" << endl;
    cout << "║            ║" << endl;
    cout << "║            ║" << endl;
    cout << "║     " << simbolo_char << "      ║" << endl;
    cout << "║            ║" << endl;
    cout << "║            ║" << endl;
    cout << "║         " << valor;
    if (valor.length() == 1) cout << " ";
    cout << " ║" << endl;
    cout << "╚════════════╝" << endl;
}

Carta generarCartaAleatoria() {
    int valor = rand() % 13 + 1;
    string simbolo = obtenerSimbolo(rand() % 4);
    return {valor, simbolo};
}

bool cartasDiferentes(const vector<Carta>& cartas) {
    set<pair<int, string>> conjunto;
    for (const auto& carta : cartas) {
        if (conjunto.count({carta.valor, carta.simbolo}) > 0) {
            return false;
        }
        conjunto.insert({carta.valor, carta.simbolo});
    }
    return true;
}

int sumarPuntos(const vector<Carta>& cartas) {
    int suma = 0;
    for (const auto& carta : cartas) {
        suma += obtenerPuntosCarta(carta.valor);
    }
    return suma;
}

bool tresCartasIguales(const vector<Carta>& cartas) {
    return (cartas[0].valor == cartas[1].valor && cartas[1].valor == cartas[2].valor);
}

void imprimirCartas(const vector<Carta>& cartas) {
    for (const auto& carta : cartas) {
        Imprimircarta(carta);
    }
}

int main() {
    srand(time(0));
    char continuar = 'S';
    
    while (continuar == 'S' || continuar == 's') {
        vector<Carta> cartas(3);
        bool diferentes;
        
        do {
            for (int i = 0; i < 3; ++i) {
                cartas[i] = generarCartaAleatoria();
            }
            diferentes = cartasDiferentes(cartas);
        } while (!diferentes);
        
        cout << "Cartas generadas:" << endl;
        imprimirCartas(cartas);
        
        if (sumarPuntos(cartas) == 21) {
            cout << "¡Ganaste! La sumatoria de tus cartas es 21." << endl;
        } else if (tresCartasIguales(cartas)) {
            cout << "¡Ganaste! Tienes 3 cartas iguales." << endl;
        } else {
            int cambios;
            cout << "No ganaste. ¿Cuántas cartas deseas cambiar (1 o 2)? ";
            cin >> cambios;
            if (cambios == 1 || cambios == 2) {
                for (int i = 0; i < cambios; ++i) {
                    int indice;
                    cout << "¿Qué carta deseas cambiar (1, 2, o 3)? ";
                    cin >> indice;
                    cartas[indice - 1] = generarCartaAleatoria();
                }
                
                cout << "Nuevas cartas:" << endl;
                imprimirCartas(cartas);
                
                if (sumarPuntos(cartas) == 21) {
                    cout << "¡Ganaste! La sumatoria de tus cartas es 21." << endl;
                } else if (tresCartasIguales(cartas)) {
                    cout << "¡Ganaste! Tienes 3 cartas iguales." << endl;
                } else {
                    cout << "No ganaste. La sumatoria de tus cartas es " << sumarPuntos(cartas) << "." << endl;
                }
            }
        }
        
        cout << "¿Deseas seguir jugando (S/N)? ";
        cin >> continuar;
    }
    
    return 0;
}
