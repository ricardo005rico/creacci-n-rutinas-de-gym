#include <iostream>
#include <string>
#include "GestorEjercicios.h"
#include "Rutina.h"

void mostrarMenu() {
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "   SISTEMA DE RUTINAS DE ENTRENAMIENTO     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "  1. Crear ejercicio cardiovascular" << std::endl;
    std::cout << "  2. Crear ejercicio de fuerza" << std::endl;
    std::cout << "  3. Actualizar ejercicio" << std::endl;
    std::cout << "  4. Eliminar ejercicio" << std::endl;
    std::cout << "  5. Consultar ejercicio por codigo" << std::endl;
    std::cout << "  6. Listar todos los ejercicios" << std::endl;
    std::cout << "  7. Buscar ejercicios por nivel de intensidad" << std::endl;
    std::cout << "  8. Generar rutina de entrenamiento" << std::endl;
    std::cout << "  0. Salir" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "  Opcion: ";
}

int main() {
    GestorEjercicios gestor;
    int opcion;
    int semanaActual = 1;

    std::cout << "Bienvenido al Sistema de Gestion de Rutinas." << std::endl;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                gestor.crearEjercicioCardiovascular();
                break;
            case 2:
                gestor.crearEjercicioFuerza();
                break;
            case 3:
                gestor.actualizarEjercicio();
                break;
            case 4:
                gestor.eliminarEjercicio();
                break;
            case 5:
                gestor.consultarEjercicio();
                break;
            case 6:
                gestor.listarTodos();
                break;
            case 7:
                gestor.buscarPorNivel();
                break;
            case 8: {
                Rutina* rutina = gestor.generarRutina(semanaActual);
                if (rutina != NULL) {
                    rutina->mostrarRutina();
                    // Preguntar si avanzar a la siguiente semana
                    char avanzar;
                    std::cout << "Desea avanzar a la siguiente semana? (s/n): ";
                    std::cin >> avanzar;
                    if (avanzar == 's' || avanzar == 'S') {
                        semanaActual++;
                        std::cout << ">> Ahora en semana " << semanaActual << "." << std::endl;
                    }
                    delete rutina;
                }
                break;
            }
            case 0:
                std::cout << ">> Saliendo del sistema. Hasta luego!" << std::endl;
                break;
            default:
                std::cout << ">> Opcion invalida. Intente de nuevo." << std::endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}
