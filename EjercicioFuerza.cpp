#include "EjercicioFuerza.h"
#include <iostream>

EjercicioFuerza::EjercicioFuerza(int codigo, const std::string& nombre,
                                 NivelIntensidad nivel, int tiempoEstimado,
                                 const std::string& descripcion,
                                 int series, int repeticiones,
                                 int semanaUso)
    : Ejercicio(codigo, nombre, FUERZA, nivel, tiempoEstimado, descripcion, semanaUso),
      series(series), repeticiones(repeticiones) {}

EjercicioFuerza::~EjercicioFuerza() {}

int EjercicioFuerza::getSeries() const { return series; }
int EjercicioFuerza::getRepeticiones() const { return repeticiones; }
void EjercicioFuerza::setSeries(int series) { this->series = series; }
void EjercicioFuerza::setRepeticiones(int rep) { this->repeticiones = rep; }

void EjercicioFuerza::mostrarInfo() const {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "  [FUERZA]" << std::endl;
    std::cout << "  Codigo      : " << codigo << std::endl;
    std::cout << "  Nombre      : " << nombre << std::endl;
    std::cout << "  Nivel       : " << nivelToString(nivel) << std::endl;
    std::cout << "  Tiempo      : " << tiempoEstimado << " min" << std::endl;
    std::cout << "  Series      : " << series << std::endl;
    std::cout << "  Repeticiones: " << repeticiones << std::endl;
    std::cout << "  Descripcion : " << descripcion << std::endl;
    std::cout << "  Ultima semana de uso: " << (semanaUso == 0 ? "Nunca usado" : std::to_string(semanaUso)) << std::endl;
    std::cout << "------------------------------------" << std::endl;
}
