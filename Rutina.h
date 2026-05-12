#ifndef RUTINA_H
#define RUTINA_H

#include "Ejercicio.h"
#include <string>
#include <vector>

class Rutina {
private:
    std::string nombreCliente;
    std::string objetivoFisico;
    int semana;
    std::vector<Ejercicio*> ejercicios;

public:
    Rutina(const std::string& nombreCliente, const std::string& objetivoFisico, int semana);
    ~Rutina();

    void agregarEjercicio(Ejercicio* ejercicio);
    std::string getNombreCliente() const;
    std::string getObjetivoFisico() const;
    int getSemana() const;
    int getTiempoTotal() const;

    void mostrarRutina() const;
};

#endif
