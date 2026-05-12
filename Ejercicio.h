#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <string>

// Enum para niveles de intensidad
enum NivelIntensidad {
    BASICO = 1,
    INTERMEDIO,
    AVANZADO,
    ALTO_RENDIMIENTO
};

// Enum para tipos de ejercicio
enum TipoEjercicio {
    CARDIOVASCULAR = 1,
    FUERZA
};

// Clase abstracta base
class Ejercicio {
protected:
    int codigo;
    std::string nombre;
    TipoEjercicio tipo;
    NivelIntensidad nivel;
    int tiempoEstimado; // en minutos
    std::string descripcion;
    int semanaUso; // semana en que fue usado por ultima vez (0 = nunca)

public:
    // Constructor
    Ejercicio(int codigo, const std::string& nombre, TipoEjercicio tipo,
              NivelIntensidad nivel, int tiempoEstimado,
              const std::string& descripcion, int semanaUso = 0);

    // Destructor virtual (polimorfismo)
    virtual ~Ejercicio();

    // Getters
    int getCodigo() const;
    std::string getNombre() const;
    TipoEjercicio getTipo() const;
    NivelIntensidad getNivel() const;
    int getTiempoEstimado() const;
    std::string getDescripcion() const;
    int getSemanaUso() const;

    // Setters
    void setNombre(const std::string& nombre);
    void setNivel(NivelIntensidad nivel);
    void setTiempoEstimado(int tiempo);
    void setDescripcion(const std::string& descripcion);
    void setSemanaUso(int semana);

    // Metodo virtual puro (abstraccion y polimorfismo)
    virtual void mostrarInfo() const = 0;

    // Metodos estaticos de utilidad
    static std::string nivelToString(NivelIntensidad nivel);
    static std::string tipoToString(TipoEjercicio tipo);
    static NivelIntensidad intToNivel(int n);
};

#endif
