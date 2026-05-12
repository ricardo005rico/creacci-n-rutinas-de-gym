#include "EjercicioCardiovascular.h"
#include <iostream>

EjercicioCardiovascular::EjercicioCardiovascular(int codigo, const std::string& nombre,
                                                 NivelIntensidad nivel, int tiempoEstimado,
                                                 const std::string& descripcion,
                                                 int frecuenciaCardiacaObjetivo,
                                                 int semanaUso)
    : Ejercicio(codigo, nombre, CARDIOVASCULAR, nivel, tiempoEstimado, descripcion, semanaUso),
      frecuenciaCardiacaObjetivo(frecuenciaCardiacaObjetivo) {}

EjercicioCardiovascular::~EjercicioCardiovascular() {}

int EjercicioCardiovascular::getFrecuenciaCardiacaObjetivo() const {
    return frecuenciaCardiacaObjetivo;
}

void EjercicioCardiovascular::setFrecuenciaCardiacaObjetivo(int frecuencia) {
    this->frecuenciaCardiacaObjetivo = frecuencia;
}

void EjercicioCardiovascular::mostrarInfo() const {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "  [CARDIOVASCULAR]" << std::endl;
    std::cout << "  Codigo      : " << codigo << std::endl;
    std::cout << "  Nombre      : " << nombre << std::endl;
    std::cout << "  Nivel       : " << nivelToString(nivel) << std::endl;
    std::cout << "  Tiempo      : " << tiempoEstimado << " min" << std::endl;
    std::cout << "  FC Objetivo : " << frecuenciaCardiacaObjetivo << " ppm" << std::endl;
    std::cout << "  Descripcion : " << descripcion << std::endl;
    std::cout << "  Ultima semana de uso: " << (semanaUso == 0 ? "Nunca usado" : std::to_string(semanaUso)) << std::endl;
    std::cout << "------------------------------------" << std::endl;
}
