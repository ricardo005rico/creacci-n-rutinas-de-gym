#ifndef EJERCICIO_CARDIOVASCULAR_H
#define EJERCICIO_CARDIOVASCULAR_H

#include "Ejercicio.h"

class EjercicioCardiovascular : public Ejercicio {
private:
    int frecuenciaCardiacaObjetivo; // pulsaciones por minuto

public:
    EjercicioCardiovascular(int codigo, const std::string& nombre,
                            NivelIntensidad nivel, int tiempoEstimado,
                            const std::string& descripcion,
                            int frecuenciaCardiacaObjetivo,
                            int semanaUso = 0);

    ~EjercicioCardiovascular();

    int getFrecuenciaCardiacaObjetivo() const;
    void setFrecuenciaCardiacaObjetivo(int frecuencia);

    // Implementacion del metodo virtual puro (polimorfismo)
    void mostrarInfo() const override;
};

#endif
