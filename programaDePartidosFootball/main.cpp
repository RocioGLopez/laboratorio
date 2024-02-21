#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_EQUIPO = 6;

// Función para ingreso de nombres de los 6 equipos
void ingresoEquipos(string equipo[]) {
    for (int i = 0; i < NUM_EQUIPO; i++) {
        cout << "Ingrese el nombre del equipo No. " << i + 1 << ": ";
        cin >> equipo[i];
    }
}

// Función para generar los marcadores de partidos ida y vuelta
void llenarMarcadores(int marcador[][NUM_EQUIPO]) {
    for (int i = 0; i < NUM_EQUIPO; i++) {
        for (int j = 0; j < NUM_EQUIPO; j++) {
            if (i != j) {
                marcador[i][j] = marcadorAleatorio(0, 10);
                marcador[j][i] = marcadorAleatorio(0, 10);
            }
        }
    }
}

// Función para números aleatorios
int marcadorAleatorio(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

// Función para mostrar la tabla en pantalla
void mostrarTabla(string equipos[], int marcadores[][NUM_EQUIPO]) {
    cout << setw(10) << "EQUIPO" << setw(10) << "PARTIDOS" << setw(10) << "GANADOS"
         << setw(10) << "EMPATES" << setw(10) << "PERDIDOS" << endl;

    int puntos[NUM_EQUIPO] = {0};

    for (int i = 0; i < NUM_EQUIPO; i++) {
        int partidosJugados = 0, partidosGanados = 0, partidosEmpatados = 0, partidosPerdidos = 0;

        for (int j = 0; j < NUM_EQUIPO; j++) {
            if (i != j) {
                partidosJugados++;

                if (marcadores[i][j] > marcadores[j][i]) {
                    partidosGanados++;
                    puntos[i] += 3;
                } else if (marcadores[i][j] == marcadores[j][i]) {
                    partidosEmpatados++;
                    puntos[i]++;
                    puntos[j]++;
                } else {
                    partidosPerdidos++;
                    puntos[j] += 3;
                }
            }
        }

        cout << setw(10) << equipos[i] << setw(10) << partidosJugados << setw(10) << partidosGanados
             << setw(10) << partidosEmpatados << setw(10) << partidosPerdidos << endl;
    }

    cout << "\nTabla de Puntos:\n";
    for (int i = 0; i < NUM_EQUIPO; ++i) {
        cout << equipos[i] << ": " << puntos[i] << " puntos\n";
    }
}

// Función para determinar al ganador del campeonato y al equipo que desciende
void obtenerGanadorDescenso(const string equipos[], const int puntos[]) {
    int maxPuntos = 0, minPuntos = INT_MAX;
    int ganadorIdx, descensoIdx;

    for (int i = 0; i < NUM_EQUIPO; ++i) {
        if (puntos[i] > maxPuntos) {
            maxPuntos = puntos[i];
            ganadorIdx = i;
        }

        if (puntos[i] < minPuntos) {
            minPuntos = puntos[i];
            descensoIdx = i;
        }
    }

    cout << "\nEl equipo ganador del campeonato es: " << equipos[ganadorIdx] << " con " << maxPuntos << " puntos.\n";
    cout << "El equipo que desciende es: " << equipos[descensoIdx] << " con " << minPuntos << " puntos.\n";
}

int main() {
    string equipos[NUM_EQUIPO];
    int marcadores[NUM_EQUIPO][NUM_EQUIPO];

    char opcion;

    do {
        ingresoEquipos(equipos);
        llenarMarcadores(marcadores);
        mostrarTabla(equipos, marcadores);
        obtenerGanadorDescenso(equipos, marcadores);

        cout << "\n¿Desea generar otro campeonato? (S/N): ";
        cin >> opcion;

    } while (opcion == 'S' || opcion == 's');

    return 0;
}


