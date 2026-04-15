#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <string.h>

const int NAMECARTA = 20;

const int NAMEPLAYER = 20;

const int CARTAS = 5;

const int JUGADORES = 10;

const int NUMEROCARTAS = 10;

struct Carta
{
    int cantidad = 0;
    int attack = 0;
    int defense = 0;
    char nombre[ NAMECARTA ] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
    short id = 0;
};

struct Player
{
    int index = 1;
    char playerName[ NAMEPLAYER ] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
    Carta cartas[ CARTAS ];
};

//Función 1
void menuPrimero();

//Función 2
void menuSegundo( std::string nombreJugador );

//Función 3
Player ingresarJugador( int numeroJugadores );

//Función 4
void guardarJugador( Player jugador, int numeroJugadores );

//Función 5
void leerJugadores( Player jugadores[ JUGADORES ], int numeroJugadores );

//Función 6
void imprimirJugadores( Player jugadores[ JUGADORES ], int numeroJugadores );

//Función 7
bool validarInicioSesion( Player jugadores[ JUGADORES ], int numeroJugadores, std::string nombreJugador );

//Función 8
void leerCartas( Carta cartas[ CARTAS ], int numeroCartas );

//Función 9
void imprimirCartas( Carta cartas[ CARTAS ], int numeroCartas );

//Función 10
int buscarJugador( Player jugadores[ JUGADORES ], int numeroJugadores, std::string nombreJugador );

//Función 11
int buscarCarta( Carta cartas[ CARTAS ], int numeroCartas, short idCarta );

//Función 12
bool validarExistenciaCarta( Carta cartas[ CARTAS ], int posicionCarta );

//Función 13
void comprarCarta( Player jugadores[ JUGADORES ], int posicionJugador, Carta cartas[ CARTAS ], int posicionCarta, int unidadesCartasComprar );

//Función 14
void eliminarCarta( Carta cartas[ CARTAS ], int numeroCartas, int posicionCarta );

//Función 15
void escribirCartas( Carta cartas[ CARTAS ], int numeroCartas );

//Función 16
void imprimirCartasJugador( Player jugadores[ JUGADORES ], int posicionJugador );

//Función 17
bool validarUnidadesDisponibles( Carta cartas[ CARTAS ], int posicionCarta, int unidadesCartasComprar );

//Función 18
bool validarCartasJugador( Player jugadores[ JUGADORES ], int posicionJugador );

//Función 19
void escribirJugadores( Player jugadores[ JUGADORES ], int numeroJugadores );

int main()
{
    bool menuUnoCerrado = false;
    int menuUno;
    bool menuDosCerrado = false;
    int menuDos;
    bool menuTresCerrado = false;
    Player jugadoresRegistrados[ JUGADORES ];
    Player registros[ JUGADORES ];
    Carta bancoCartas[ CARTAS ];
    int cantidadJugadores = 0;
    int cantidadCartas = 10;
    Player nuevoJugador;
    std::string jugadorNombre;
    bool registroJugador = false;
    short cartaId;
    int cartasUnidadesComprar;
    int jugadorPosicion;
    int cartaPosicion;
    bool existenciaCarta = false;
    bool disponibilidadCarta = false;
    bool cartasOcupadas = false;

    while( menuUnoCerrado == false )
    {
        menuPrimero();
        std::cin >> menuUno;
        std::cout << std::endl;
        system("cls");
        switch( menuUno )
        {
        case 1:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

            nuevoJugador = ingresarJugador( cantidadJugadores );

            guardarJugador( nuevoJugador, cantidadJugadores );

            cantidadJugadores++;

            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            system("pause");
            system("cls");
            break;
        case 2:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

            leerJugadores( jugadoresRegistrados, cantidadJugadores );
            imprimirJugadores( jugadoresRegistrados, cantidadJugadores );
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "Digite su nombre: ";
            std::cin >> jugadorNombre;
            std::cout << std::endl;
            registroJugador = validarInicioSesion( jugadoresRegistrados, cantidadJugadores, jugadorNombre );

            switch( registroJugador )
            {
            case 1:
                std::cout << "Si esta registrado" << std::endl;
                std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                system("pause");
                system("cls");
                menuTresCerrado = false;
                while( menuTresCerrado == false )
                {
                    menuSegundo( jugadorNombre );
                    std::cin >> menuDos;
                    std::cout << std::endl;
                    system("cls");
                    std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                    imprimirJugadores( jugadoresRegistrados, cantidadJugadores );
                    jugadorPosicion = buscarJugador( jugadoresRegistrados, cantidadJugadores, jugadorNombre );
                    std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                    imprimirJugadores( jugadoresRegistrados, cantidadJugadores );
                    switch( menuDos )
                    {
                    case 1:
                        std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        std::cout << "ESTOY DENTRO DEL SWITCH ANTES DE LEER CARTAS" << std::endl << std::endl;
                        imprimirJugadores( jugadoresRegistrados, cantidadJugadores );
                        for( int i = 0; i < JUGADORES; i++ )
                        {
                            strcpy( registros[ i ].playerName, jugadoresRegistrados[ i ].playerName  );
                            jugadoresRegistrados[ i ].index = registros[ i ].index;
                        }
                        std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        leerCartas( bancoCartas, cantidadCartas );
                        imprimirCartas( bancoCartas, cantidadCartas);
                        std::cout << "ESTOY DENTRO DEL SWITCH DESPUES DE LEER CARTAS" << std::endl << std::endl;
                        std::cout << "ARREGLO ORIGINAL" << std::endl << std::endl;
                        imprimirJugadores( jugadoresRegistrados, cantidadJugadores );
                        std::cout << "ARREGLO COPIA" << std::endl << std::endl;
                        imprimirJugadores( registros, cantidadJugadores );
                        std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        std::cout << "Digite el id de la carta que quiere comprar: ";
                        std::cin >> cartaId;
                        cartaPosicion = buscarCarta( bancoCartas, cantidadCartas, cartaId );
                        existenciaCarta = validarExistenciaCarta( bancoCartas, cartaPosicion );
                        if( existenciaCarta == true )
                        {
                            std::cout << std::endl << "Digite cuantas unidades quieres de la carta con el id " << cartaId << ": ";
                            std::cin >> cartasUnidadesComprar;
                            disponibilidadCarta = validarUnidadesDisponibles( bancoCartas, cartaPosicion, cartasUnidadesComprar );
                            if( disponibilidadCarta == true )
                            {
                                cartasOcupadas = validarCartasJugador( jugadoresRegistrados, jugadorPosicion );
                                if( cartasOcupadas == false )
                                {
                                    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                                    std::cout << "ARREGLO DE JUGADORES Y CARTAS ANTES DE COMPRAR CARTA" << std::endl << std::endl;
                                    imprimirJugadores( jugadoresRegistrados, cantidadJugadores );
                                    imprimirCartas( bancoCartas, cantidadCartas );
                                    std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                                    std::cout << "COMPRANDO CARTA" << std::endl << std::endl;
                                    comprarCarta( jugadoresRegistrados, jugadorPosicion, bancoCartas, cartaPosicion, cartasUnidadesComprar );
                                    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                                    std::cout << "ARREGLO DE JUGADORES Y CARTAS DESPUES DE COMPRAR CARTA" << std::endl << std::endl;
                                    imprimirJugadores( jugadoresRegistrados, cantidadJugadores );
                                    imprimirCartas( bancoCartas, cantidadCartas );
                                    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                                    std::cout << "PROCEDIMIENTO DE ESCRITURA DE ARREGLO DE JUGADORES Y CARTAS" << std::endl << std::endl;
                                    existenciaCarta = validarExistenciaCarta( bancoCartas, cartaPosicion );
                                    if( existenciaCarta == false )
                                    {
                                        eliminarCarta( bancoCartas, cantidadCartas, cartaPosicion );
                                        cantidadCartas--;

                                    }
                                    escribirCartas( bancoCartas, cantidadCartas );
                                    escribirJugadores( jugadoresRegistrados, cantidadJugadores );
                                }
                                else if( cartasOcupadas == true )
                                {
                                    std::cout << std::endl << "Error, ya tiene cinco cartas, no puede agregar mas" << std::endl;
                                }
                            }
                            else if( disponibilidadCarta == false )
                            {
                                std::cout << std::endl << "Error, ingreso mas cartas de las que existen" << std::endl;
                            }
                        }
                        else if( existenciaCarta == false )
                        {
                            std::cout << std::endl << "Error, no hay unidades disponibles de la carta" << std::endl;
                        }
                        std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        imprimirCartasJugador( jugadoresRegistrados, jugadorPosicion );
                        std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        menuTresCerrado = true;
                        break;
                    default:
                        std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        std::cout << "El numero ingresado no corresponde a ninguna de las opciones permitidas" << std::endl;
                        std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                }
                break;
            case 0:
                std::cout << "No esta registrado" << std::endl;
                std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                system("pause");
                system("cls");
                break;
            }
            break;
        case 3:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "Gracias por su atencion, vuelva pronto" << std::endl;
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            return 0;
        default:
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "El numero ingresado no corresponde a ninguna de las opciones permitidas" << std::endl;
            std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

//Función 1
void menuPrimero()
{
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw (65) << "Menu Principal" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << "Digite la opcion que quiere ejecutar: " << std::endl << std::endl;
    std::cout << "\t" << "(1) Registrar jugador" << std::endl;
    std::cout << "\t" << "(2) Log-in" << std::endl;
    std::cout << "\t" << "(3) Salir" << std::endl << std::endl;
    std::cout << "Eleccion: ";
}

//Función 2
void menuSegundo( std::string nombreJugador )
{
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw (55) << "Cuenta de " << nombreJugador << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << "Digite la opcion que quiere ejecutar: " << std::endl << std::endl;
    std::cout << "\t" << "(1) Comprar cartas" << std::endl;
    std::cout << "\t" << "(2) Ver mis cartas" << std::endl;
    std::cout << "\t" << "(3) Salir" << std::endl << std::endl;
    std::cout << "Eleccion: ";
}

//Función 3
Player ingresarJugador( int numeroJugadores )
{
    std::string nombreJugador;
    Player jugador;

    std::cout << "Digite el nombre del jugador: ";
    std::cin >> nombreJugador;
    strcpy( jugador.playerName, nombreJugador.c_str() );
    numeroJugadores += 1;
    jugador.index = numeroJugadores;

    return jugador;
}

//Función 4
void guardarJugador( Player jugador, int numeroJugadores )
{
    std::ofstream file;

    file.open( "jugadores.bin", std::ios::binary | std::ios::app );

    if( file.is_open() )
    {
        file.write( ( char * ) &jugador, sizeof( Player ) );
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 5
void leerJugadores( Player jugadores[ JUGADORES ], int numeroJugadores )
{
    std::ifstream file;

    file.open( "jugadores.bin", std::ios::binary );

    if( file.is_open() )
    {
        for( int i = 0; i < numeroJugadores; i++ )
        {
            file.read( ( char * ) &jugadores[ i ], sizeof( Player ) );
        }
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 6
void imprimirJugadores( Player jugadores[ JUGADORES ], int numeroJugadores )
{
    for( int i = 0; i < numeroJugadores; i++ )
    {
        std::cout << "Jugador " << i + 1 << std::endl;
        std::cout << "\t" << "Indice: " << jugadores[ i ].index << std::endl;
        std::cout << "\t" << "Nombre: " << jugadores[ i ].playerName << std::endl << std::endl;
        for( int j = 0; j < CARTAS; j++ )
        {
            std::cout << "\t" << "Carta " << j + 1 << std::endl;
            std::cout << "\t" << "Cantidad: " << jugadores[ i ].cartas[ j ].cantidad << std::endl;
            std::cout << "\t" << "Ataque: " << jugadores[ i ].cartas[ j ].attack << std::endl;
            std::cout << "\t" << "Defensa: "  << jugadores[ i ].cartas[ j ].defense << std::endl;
            std::cout << "\t" << "Nombre: "  << jugadores[ i ].cartas[ j ].nombre << std::endl;
            std::cout << "\t" << "Id: " << jugadores[ i ].cartas[ j ].id << std::endl << std::endl;
        }
    }
}

//Función 7
bool validarInicioSesion( Player jugadores[ JUGADORES ], int numeroJugadores, std::string nombreJugador )
{
    bool encontreRegistro = false;

    for( int i = 0; i < numeroJugadores; i++ )
    {
        if( jugadores[ i ].playerName == nombreJugador )
        {
            encontreRegistro = true;
        }
    }

    return encontreRegistro;
}

//Función 8
void leerCartas( Carta cartas[ CARTAS ], int numeroCartas )
{
    std::ifstream file;

    file.open( "banco.bin", std::ios::binary );

    if( file.is_open() )
    {
        for( int i = 0; i < numeroCartas; i++ )
        {
            file.read( ( char * ) &cartas[ i ], sizeof( Carta ) );
        }
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 9
void imprimirCartas( Carta cartas[ CARTAS ], int numeroCartas )
{
    for( int i = 0; i < numeroCartas; i++ )
    {
        std::cout << "Carta " << i + 1 << std::endl;
        std::cout << "\t" << "Cantidad: " << cartas[ i ].cantidad << std::endl;
        std::cout << "\t" << "Ataque: " << cartas[ i ].attack << std::endl;
        std::cout << "\t" << "Defensa: " << cartas[ i ].defense << std::endl;
        std::cout << "\t" << "Nombre: " << cartas[ i ].nombre << std::endl;
        std::cout << "\t" << "Id: " << cartas[ i ].id << std::endl << std::endl;
    }
}

//Función 10
int buscarJugador( Player jugadores[ JUGADORES ], int numeroJugadores, std::string nombreJugador )
{
    int posicion = -1;

    for( int i = 0; i < numeroJugadores; i++ )
    {
        if( jugadores[ i ].playerName == nombreJugador )
        {
            posicion = i;
        }
    }

    return posicion;
}

//Función 11
int buscarCarta( Carta cartas[ CARTAS ], int numeroCartas, short idCarta )
{
    int posicion = -1;

    for( int i = 0; i < numeroCartas; i++ )
    {
        if( cartas[ i ].id == idCarta )
        {
            posicion = i;
        }
    }

    return posicion;
}

//Función 12
bool validarExistenciaCarta( Carta cartas[ CARTAS ], int posicionCarta )
{
    bool existenciaCarta = true;

    if( cartas[ posicionCarta ].cantidad <= 0 )
    {
        existenciaCarta = false;
    }

    return existenciaCarta;
}

//Función 13
void comprarCarta( Player jugadores[ JUGADORES ], int posicionJugador, Carta cartas[ CARTAS ], int posicionCarta, int unidadesCartasComprar )
{
    for( int i = 0; i < unidadesCartasComprar; i++ )
    {
        if( jugadores[ posicionJugador ].cartas[ i ].id == 0 )
        {
            jugadores[ posicionJugador ].cartas[ i ].cantidad = cartas[ posicionCarta ].cantidad;
            jugadores[ posicionJugador ].cartas[ i ].attack = cartas[ posicionCarta ].attack;
            jugadores[ posicionJugador ].cartas[ i ].defense = cartas[ posicionCarta ].defense;
            strcpy( jugadores[ posicionJugador ].cartas[ i ].nombre, cartas[ posicionCarta ].nombre );
            jugadores[ posicionJugador ].cartas[ i ].id = cartas[ posicionCarta ].id;
        }
    }
    cartas[ posicionCarta ].cantidad -= unidadesCartasComprar;
}

//Función 14
void eliminarCarta( Carta cartas[ CARTAS ], int numeroCartas, int posicionCarta )
{
    for( int i = posicionCarta; i < numeroCartas; i++ )
    {
        cartas[ i ].cantidad = cartas[ i + 1 ].cantidad;
        cartas[ i ].attack = cartas[ i + 1 ].attack;
        cartas[ i ].defense = cartas[ i + 1 ].defense;
        strcpy( cartas[ i ].nombre, cartas[ i + 1 ].nombre );
        cartas[ i ].id = cartas[ i + 1 ].id;
    }

    //numeroCartas -= 1;
}

//Función 15
void escribirCartas( Carta cartas[ CARTAS ], int numeroCartas )
{
    std::ofstream file;

    file.open( "banco.bin", std::ios::binary | std::ios::out  );

    if( file.is_open() )
    {
        for( int i = 0; i < numeroCartas; i++ )
        {
            file.write( ( char * ) &cartas[ i ], sizeof( Carta ) );
        }
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}

//Función 16
void imprimirCartasJugador( Player jugadores[ JUGADORES ], int posicionJugador )
{
    std::cout << "\t" << "Nombre: " << jugadores[ posicionJugador ].playerName << std::endl;
    std::cout << "\t" << "Indice: " << jugadores[ posicionJugador ].index << std::endl << std::endl;
    for( int i = 0; i < CARTAS; i++ )
    {
        std::cout << "\t" << "Carta " << i + 1 << std::endl;
        std::cout << "\t" << "Cantidad: " << jugadores[ posicionJugador ].cartas[ i ].cantidad << std::endl;
        std::cout << "\t" << "Ataque: " <<  jugadores[ posicionJugador ].cartas[ i ].attack << std::endl;
        std::cout << "\t" << "Defensa: " << jugadores[ posicionJugador ].cartas[ i ].defense << std::endl;
        std::cout << "\t" << "Nombre: " << jugadores[ posicionJugador ].cartas[ i ].nombre << std::endl;
        std::cout << "\t" << "Id: " << jugadores[ posicionJugador ].cartas[ i ].id << std::endl << std::endl;

    }
}

//Función 17
bool validarUnidadesDisponibles( Carta cartas[ CARTAS ], int posicionCarta, int unidadesCartasComprar )
{
    bool unidadesDisponibles = true;

    if( unidadesCartasComprar > cartas[ posicionCarta ].cantidad )
    {
        unidadesDisponibles = false;
    }
    return unidadesDisponibles;
}

//Función 18
bool validarCartasJugador( Player jugadores[ JUGADORES ], int posicionJugador )
{
    bool cartasLlenas = false;
    int contador = 0;

    for( int i = 0; i < CARTAS; i++ )
    {
        if( jugadores[ posicionJugador ].cartas[ i ].id != 0 )
        {
            contador++;
        }
    }
    if( contador >= 5 )
    {
        cartasLlenas = true;
    }

    return cartasLlenas;
}

//Función 19
void escribirJugadores( Player jugadores[ JUGADORES ], int numeroJugadores )
{
    std::ofstream file;

    file.open( "jugadores.bin", std::ios::binary | std::ios::out );

    if( file.is_open() )
    {
        for( int i = 0; i < numeroJugadores; i++ )
        {
            file.write( ( char * ) &jugadores[ i ], sizeof( Player ) );
        }
    }
    else
    {
        std::cerr << "Error de apertura del archivo" << std::endl << std::endl;
    }

    file.close();
}