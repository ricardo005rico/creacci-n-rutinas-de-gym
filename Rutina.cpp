#include "Rutina.h"
#include <iostream>

Rutina::Rutina(const std::string& nombreCliente, const std::string& objetivoFisico, int semana)
    : nombreCliente(nombreCliente), objetivoFisico(objetivoFisico), semana(semana) {}

Rutina::~Rutina() {
    // No eliminamos los ejercicios aqui porque son gestionados por GestorEjercicios
    ejercicios.clear();
}

void Rutina::agregarEjercicio(Ejercicio* ejercicio) {
    ejercicios.push_back(ejercicio);
}

std::string Rutina::getNombreCliente() const { return nombreCliente; }
std::string Rutina::getObjetivoFisico() const { return objetivoFisico; }
int Rutina::getSemana() const { return semana; }

int Rutina::getTiempoTotal() const {
    int total = 0;
    for (int i = 0; i < (int)ejercicios.size(); i++) {
        total += ejercicios[i]->getTiempoEstimado();
    }
    return total;
}

void Rutina::mostrarRutina() const {
    std::cout << "====================================" << std::endl;
    std::cout << "        RUTINA DE ENTRENAMIENTO     " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "  Cliente   : " << nombreCliente << std::endl;
    std::cout << "  Objetivo  : " << objetivoFisico << std::endl;
    std::cout << "  Semana    : " << semana << std::endl;
    std::cout << "  Ejercicios: " << ejercicios.size() << std::endl;
    std::cout << "====================================" << std::endl;

    for (int i = 0; i < (int)ejercicios.size(); i++) {
        std::cout << "  Ejercicio " << (i + 1) << ":" << std::endl;
        ejercicios[i]->mostrarInfo(); // POLIMORFISMO en accion
    }

    std::cout << "====================================" << std::endl;
    std::cout << "  TIEMPO TOTAL ESTIMADO: " << getTiempoTotal() << " minutos" << std::endl;
    std::cout << "====================================" << std::endl;
}
