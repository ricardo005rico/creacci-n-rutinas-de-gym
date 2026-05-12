#ifndef GESTOR_EJERCICIOS_H
#define GESTOR_EJERCICIOS_H

#include "Ejercicio.h"
#include "EjercicioCardiovascular.h"
#include "EjercicioFuerza.h"
#include "Rutina.h"
#include <vector>
#include <string>

class GestorEjercicios {
private:
    std::vector<Ejercicio*> ejercicios;
    int proximoCodigo;

    // Metodo privado auxiliar
    int buscarIndicePorCodigo(int codigo) const;

public:
    GestorEjercicios();
    ~GestorEjercicios();

    // CRUD
    void crearEjercicioCardiovascular();
    void crearEjercicioFuerza();
    void actualizarEjercicio();
    void eliminarEjercicio();
    void consultarEjercicio() const;
    void listarTodos() const;

    // Busqueda por nivel
    void buscarPorNivel() const;

    // Generacion de rutina
    Rutina* generarRutina(int semanaActual);
};

#endif
