#ifndef EJERCICIO_FUERZA_H
#define EJERCICIO_FUERZA_H

#include "Ejercicio.h"

class EjercicioFuerza : public Ejercicio {
private:
    int series;
    int repeticiones;

public:
    EjercicioFuerza(int codigo, const std::string& nombre,
                    NivelIntensidad nivel, int tiempoEstimado,
                    const std::string& descripcion,
                    int series, int repeticiones,
                    int semanaUso = 0);

    ~EjercicioFuerza();

    int getSeries() const;
    int getRepeticiones() const;
    void setSeries(int series);
    void setRepeticiones(int repeticiones);

    // Implementacion del metodo virtual puro (polimorfismo)
    void mostrarInfo() const override;
};

#endif
