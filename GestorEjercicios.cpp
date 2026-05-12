#include "GestorEjercicios.h"
#include <iostream>
#include <string>

GestorEjercicios::GestorEjercicios() : proximoCodigo(1) {}

GestorEjercicios::~GestorEjercicios() {
    for (int i = 0; i < (int)ejercicios.size(); i++) {
        delete ejercicios[i];
    }
    ejercicios.clear();
}

int GestorEjercicios::buscarIndicePorCodigo(int codigo) const {
    for (int i = 0; i < (int)ejercicios.size(); i++) {
        if (ejercicios[i]->getCodigo() == codigo) return i;
    }
    return -1;
}

// -------------------------------------------------------
// CREAR ejercicio cardiovascular
// -------------------------------------------------------
void GestorEjercicios::crearEjercicioCardiovascular() {
    std::string nombre, descripcion;
    int nivelInt, tiempo, frecuencia;

    std::cout << "\n--- Nuevo Ejercicio Cardiovascular ---" << std::endl;
    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Nivel de intensidad (1=Basico, 2=Intermedio, 3=Avanzado, 4=Alto Rendimiento): ";
    std::cin >> nivelInt;

    std::cout << "Tiempo estimado (minutos): ";
    std::cin >> tiempo;

    std::cout << "Frecuencia cardiaca objetivo (ppm): ";
    std::cin >> frecuencia;

    std::cin.ignore();
    std::cout << "Descripcion de ejecucion: ";
    std::getline(std::cin, descripcion);

    NivelIntensidad nivel = Ejercicio::intToNivel(nivelInt);
    Ejercicio* nuevo = new EjercicioCardiovascular(proximoCodigo++, nombre, nivel,
                                                   tiempo, descripcion, frecuencia);
    ejercicios.push_back(nuevo);
    std::cout << ">> Ejercicio cardiovascular creado con codigo " << (proximoCodigo - 1) << "." << std::endl;
}

// -------------------------------------------------------
// CREAR ejercicio de fuerza
// -------------------------------------------------------
void GestorEjercicios::crearEjercicioFuerza() {
    std::string nombre, descripcion;
    int nivelInt, tiempo, series, repeticiones;

    std::cout << "\n--- Nuevo Ejercicio de Fuerza ---" << std::endl;
    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Nivel de intensidad (1=Basico, 2=Intermedio, 3=Avanzado, 4=Alto Rendimiento): ";
    std::cin >> nivelInt;

    std::cout << "Tiempo estimado (minutos): ";
    std::cin >> tiempo;

    std::cout << "Series: ";
    std::cin >> series;

    std::cout << "Repeticiones: ";
    std::cin >> repeticiones;

    std::cin.ignore();
    std::cout << "Descripcion de ejecucion: ";
    std::getline(std::cin, descripcion);

    NivelIntensidad nivel = Ejercicio::intToNivel(nivelInt);
    Ejercicio* nuevo = new EjercicioFuerza(proximoCodigo++, nombre, nivel,
                                           tiempo, descripcion, series, repeticiones);
    ejercicios.push_back(nuevo);
    std::cout << ">> Ejercicio de fuerza creado con codigo " << (proximoCodigo - 1) << "." << std::endl;
}

// -------------------------------------------------------
// ACTUALIZAR ejercicio (nombre, nivel, tiempo, descripcion)
// -------------------------------------------------------
void GestorEjercicios::actualizarEjercicio() {
    int codigo;
    std::cout << "\n--- Actualizar Ejercicio ---" << std::endl;
    std::cout << "Ingrese el codigo del ejercicio a actualizar: ";
    std::cin >> codigo;

    int idx = buscarIndicePorCodigo(codigo);
    if (idx == -1) {
        std::cout << ">> Error: No se encontro un ejercicio con codigo " << codigo << "." << std::endl;
        return;
    }

    Ejercicio* e = ejercicios[idx];
    int opcion;

    std::cout << "Que desea actualizar?" << std::endl;
    std::cout << "  1. Nombre" << std::endl;
    std::cout << "  2. Nivel de intensidad" << std::endl;
    std::cout << "  3. Tiempo estimado" << std::endl;
    std::cout << "  4. Descripcion" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opcion;

    if (opcion == 1) {
        std::string nuevoNombre;
        std::cin.ignore();
        std::cout << "Nuevo nombre: ";
        std::getline(std::cin, nuevoNombre);
        e->setNombre(nuevoNombre);
    } else if (opcion == 2) {
        int nivelInt;
        std::cout << "Nuevo nivel (1=Basico, 2=Intermedio, 3=Avanzado, 4=Alto Rendimiento): ";
        std::cin >> nivelInt;
        e->setNivel(Ejercicio::intToNivel(nivelInt));
    } else if (opcion == 3) {
        int tiempo;
        std::cout << "Nuevo tiempo estimado (minutos): ";
        std::cin >> tiempo;
        e->setTiempoEstimado(tiempo);
    } else if (opcion == 4) {
        std::string desc;
        std::cin.ignore();
        std::cout << "Nueva descripcion: ";
        std::getline(std::cin, desc);
        e->setDescripcion(desc);
    } else {
        std::cout << ">> Opcion invalida." << std::endl;
        return;
    }

    std::cout << ">> Ejercicio actualizado correctamente." << std::endl;
}

// -------------------------------------------------------
// ELIMINAR ejercicio
// -------------------------------------------------------
void GestorEjercicios::eliminarEjercicio() {
    int codigo;
    std::cout << "\n--- Eliminar Ejercicio ---" << std::endl;
    std::cout << "Ingrese el codigo del ejercicio a eliminar: ";
    std::cin >> codigo;

    int idx = buscarIndicePorCodigo(codigo);
    if (idx == -1) {
        std::cout << ">> Error: No se encontro un ejercicio con codigo " << codigo << "." << std::endl;
        return;
    }

    delete ejercicios[idx];
    ejercicios.erase(ejercicios.begin() + idx);
    std::cout << ">> Ejercicio con codigo " << codigo << " eliminado." << std::endl;
}

// -------------------------------------------------------
// CONSULTAR un ejercicio especifico
// -------------------------------------------------------
void GestorEjercicios::consultarEjercicio() const {
    int codigo;
    std::cout << "\n--- Consultar Ejercicio ---" << std::endl;
    std::cout << "Ingrese el codigo del ejercicio: ";
    std::cin >> codigo;

    int idx = buscarIndicePorCodigo(codigo);
    if (idx == -1) {
        std::cout << ">> Error: No se encontro un ejercicio con codigo " << codigo << "." << std::endl;
        return;
    }

    ejercicios[idx]->mostrarInfo(); // POLIMORFISMO
}

// -------------------------------------------------------
// LISTAR todos los ejercicios
// -------------------------------------------------------
void GestorEjercicios::listarTodos() const {
    if (ejercicios.empty()) {
        std::cout << ">> No hay ejercicios registrados." << std::endl;
        return;
    }
    std::cout << "\n=== Listado de todos los ejercicios (" << ejercicios.size() << ") ===" << std::endl;
    for (int i = 0; i < (int)ejercicios.size(); i++) {
        ejercicios[i]->mostrarInfo(); // POLIMORFISMO
    }
}

// -------------------------------------------------------
// BUSCAR por nivel de intensidad
// -------------------------------------------------------
void GestorEjercicios::buscarPorNivel() const {
    int nivelInt;
    std::cout << "\n--- Buscar por Nivel de Intensidad ---" << std::endl;
    std::cout << "Nivel (1=Basico, 2=Intermedio, 3=Avanzado, 4=Alto Rendimiento): ";
    std::cin >> nivelInt;

    NivelIntensidad nivel = Ejercicio::intToNivel(nivelInt);
    bool encontrado = false;

    std::cout << "\n=== Ejercicios de nivel: " << Ejercicio::nivelToString(nivel) << " ===" << std::endl;
    for (int i = 0; i < (int)ejercicios.size(); i++) {
        if (ejercicios[i]->getNivel() == nivel) {
            ejercicios[i]->mostrarInfo(); // POLIMORFISMO
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << ">> No se encontraron ejercicios para ese nivel." << std::endl;
    }
}

// -------------------------------------------------------
// GENERAR RUTINA
// -------------------------------------------------------
Rutina* GestorEjercicios::generarRutina(int semanaActual) {
    std::string cliente, objetivo;
    int cantidad, nivelInt;

    std::cout << "\n--- Generar Rutina de Entrenamiento ---" << std::endl;
    std::cin.ignore();
    std::cout << "Nombre del cliente: ";
    std::getline(std::cin, cliente);

    std::cout << "Objetivo fisico: ";
    std::getline(std::cin, objetivo);

    std::cout << "Nivel de intensidad deseado (1=Basico, 2=Intermedio, 3=Avanzado, 4=Alto Rendimiento): ";
    std::cin >> nivelInt;

    std::cout << "Cantidad de ejercicios deseados: ";
    std::cin >> cantidad;

    NivelIntensidad nivelDeseado = Ejercicio::intToNivel(nivelInt);
    int semanaAnterior = semanaActual - 1; // semana consecutiva anterior

    // Filtrar ejercicios disponibles: mismo nivel y no usados la semana anterior
    std::vector<Ejercicio*> disponibles;
    for (int i = 0; i < (int)ejercicios.size(); i++) {
        Ejercicio* e = ejercicios[i];
        if (e->getNivel() == nivelDeseado && e->getSemanaUso() != semanaAnterior) {
            disponibles.push_back(e);
        }
    }

    if ((int)disponibles.size() < cantidad) {
        std::cout << ">> Error: No hay suficientes ejercicios disponibles para ese nivel." << std::endl;
        std::cout << "   Disponibles: " << disponibles.size() << ", Solicitados: " << cantidad << std::endl;
        return NULL;
    }

    Rutina* rutina = new Rutina(cliente, objetivo, semanaActual);

    // Agregar los primeros 'cantidad' ejercicios disponibles y actualizar semana de uso
    for (int i = 0; i < cantidad; i++) {
        disponibles[i]->setSemanaUso(semanaActual);
        rutina->agregarEjercicio(disponibles[i]);
    }

    return rutina;
}
