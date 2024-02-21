//Ejercicio de como hacer una tabla de resultados para un juego de football

#include <iostream>

using namespace std;
//variable costante

const int NUM_EQUIPO =6;



//funcion para ingreso de nombres de los 6 equipos
void ingresoEquipos (string equipo[])
{
    //uso de for para ingresar los diferentes equipos
    //se usa la costante 6
    for(int i = 0, i<= NUM_EQUIPO; i++)
    {
        cout << "Ingrese el nombre del equipo No. "<<i+1<< ":";
        //ingreso por teclado del nombre de los equipos
        cin >> equipo[i];
    }
}

//funcion para generar los marcadores de partidos ida y vuelta
//void no devulve datos
void llenarMarcadores (int marcador[][NUM_EQUIPO])
{
    //primer for que nos llenara o movera entre filas
    for(int i=0;i<NUM_EQUIPO;i++)
    {
        //for que nos movera entre las columnas
        for(int j=0;j<NUM_EQUIPO;i++)
        {
            if (i!=j)//si i es diferente de j hacer:
                marcador[i][j] = marcadorAleatorio(0,10);//llenado de matriz de marcador
                marcador[j][i]=marcadorAleatorio(0,10);
        }
    }
}

//funcion para numeros randoms
int marcadorAleatorio(int minimo, int maximo)
{
    return minimo + rand()/ (RAND_MAX / (maximo - minimo + 1) + 1);
}


//funcion void para mostrar la tabla en pantalla
void mostrarTabla(string equipos[],int marcadores[][NUM_EQUIPO])
{
    //ENCABEZADO
    count<<setw(10)<<"EQUIPO" << setw(10)<<"PARTIDOS"<<setw(10)<<"GANADOS" <<setw(10)<<"EMPATES"<<setw(10)<<"PERDIDOS"<<endl;

    //declaracion de variable vector inicializada
    int puntos [NUM_EQUIPO]={0};

    //uso de for para correr los partidos
    for(int i =0; i<= NUM_EQUIPO; i++)
    {
        //declaracion de variables inicializadas en cero
        int partidosJugados=0;
        int partidosGanados=0;
        int partidosEmpatados=0;
        int partidosPerdidos=0;

        for (int j = 0; j<=NUM_EQUIPO;i++)
        {
            if(i!=j)
            {   //contador para incrementar:
                partidosJugados++;

                //uso del if para saber si
                //los marcador primero es mayor al segundo y por ende si gano o perdio
                if(marcadores[i][j]>marcadores[j][i])
                {
                    partidosGanados++;
                    puntos[i]+=3;
                }
                else if ( marcadores[i][j]==marcadores[i])
                {//suma uno mas a partidos empatados
                    partidosEmpatados++;
                    puntos[i] = puntos[i]+1;
                    puntos[j] = puntos[j]+1;

                }else //POR SI NO ES NINGUNO DE LOS ANTERIORES
                {//ES POR QUE PERDIERON Y SE LES SUMA 3 A LOS PUNTOS
                    partidosPerdidos++;
                    puntos[j] += 3;
                }
            }
        }
//aqui saldra en pantalla los numeros de partidos jugados, ganados, empatados,perdidos
        cout <<setw(10)<<equipos[i]<<setw(10)<<partidosJugados<<setw(10)<<partidosGanados<<setw (10)partidosEmpatados<<setw(10)<<partidosPerdidos<<endl;




    }
    cout << "\nTabla de Puntos:\n";
    for (int i = 0; i < NUM_EQUIPO; ++i) {
        cout << equipos[i] << ": " << puntos[i] << " puntos\n";
    }



}





void obtenerGanadorDescenso(const std::string equipos[], const int puntos[]) {
    int maxPuntos = 0, minPuntos = INT_MAX;
    int ganadorIdx, descensoIdx;

    for (int i = 0; i < NUM_EQUIPOS; ++i) {
        if (puntos[i] > maxPuntos) {
            maxPuntos = puntos[i];
            ganadorIdx = i;
        }

        if (puntos[i] < minPuntos) {
            minPuntos = puntos[i];
            descensoIdx = i;
        }
    }

    std::cout << "\nEl equipo ganador del campeonato es: " << equipos[ganadorIdx] << " con " << maxPuntos << " puntos.\n";
    std::cout << "El equipo que desciende es: " << equipos[descensoIdx] << " con " << minPuntos << " puntos.\n";
}

int main() {
    std::string equipos[NUM_EQUIPOS];
    int marcadores[NUM_EQUIPOS][NUM_EQUIPOS];

    char opcion;

    do {
        ingresarEquipos(equipos);
        generarMarcadores(marcadores);
        mostrarTabla(equipos, marcadores);
        obtenerGanadorDescenso(equipos, marcadores);

        std::cout << "\n¿Desea generar otro campeonato? (S/N): ";
        std::cin >> opcion;

    } while (opcion == 'S' || opcion == 's');

    return 0;
}




