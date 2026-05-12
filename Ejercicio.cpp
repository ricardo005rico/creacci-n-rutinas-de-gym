#include "Ejercicio.h"
#include <iostream>

// Constructor
Ejercicio::Ejercicio(int codigo, const std::string& nombre, TipoEjercicio tipo,
                     NivelIntensidad nivel, int tiempoEstimado,
                     const std::string& descripcion, int semanaUso)
    : codigo(codigo), nombre(nombre), tipo(tipo), nivel(nivel),
      tiempoEstimado(tiempoEstimado), descripcion(descripcion), semanaUso(semanaUso) {}

// Destructor
Ejercicio::~Ejercicio() {}

// Getters
int Ejercicio::getCodigo() const { return codigo; }
std::string Ejercicio::getNombre() const { return nombre; }
TipoEjercicio Ejercicio::getTipo() const { return tipo; }
NivelIntensidad Ejercicio::getNivel() const { return nivel; }
int Ejercicio::getTiempoEstimado() const { return tiempoEstimado; }
std::string Ejercicio::getDescripcion() const { return descripcion; }
int Ejercicio::getSemanaUso() const { return semanaUso; }

// Setters
void Ejercicio::setNombre(const std::string& nombre) { this->nombre = nombre; }
void Ejercicio::setNivel(NivelIntensidad nivel) { this->nivel = nivel; }
void Ejercicio::setTiempoEstimado(int tiempo) { this->tiempoEstimado = tiempo; }
void Ejercicio::setDescripcion(const std::string& descripcion) { this->descripcion = descripcion; }
void Ejercicio::setSemanaUso(int semana) { this->semanaUso = semana; }

// Conversiones a string
std::string Ejercicio::nivelToString(NivelIntensidad nivel) {
    switch (nivel) {
        case BASICO:           return "Basico";
        case INTERMEDIO:       return "Intermedio";
        case AVANZADO:         return "Avanzado";
        case ALTO_RENDIMIENTO: return "Alto Rendimiento";
        default:               return "Desconocido";
    }
}

std::string Ejercicio::tipoToString(TipoEjercicio tipo) {
    switch (tipo) {
        case CARDIOVASCULAR: return "Cardiovascular";
        case FUERZA:         return "Fuerza";
        default:             return "Desconocido";
    }
}

NivelIntensidad Ejercicio::intToNivel(int n) {
    switch (n) {
        case 1: return BASICO;
        case 2: return INTERMEDIO;
        case 3: return AVANZADO;
        case 4: return ALTO_RENDIMIENTO;
        default: return BASICO;
    }
}
