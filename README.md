# Sistema de Gestión de Rutinas de Entrenamiento Personalizadas

> Tarea 1 — Paradigmas de Programación  
> Universidad Andrés Bello — Facultad de Ingeniería

---

## Descripción

Sistema desarrollado en C++ que permite gestionar ejercicios y generar rutinas de entrenamiento personalizadas para clientes de un centro deportivo. Aplica los principios de la **Programación Orientada a Objetos**: abstracción, encapsulamiento, herencia y polimorfismo.

---

## Estructura del proyecto

```
tarea1PARADIGMAS/
├── Ejercicio.h                  # Clase base (declaración)
├── Ejercicio.cpp                # Clase base (implementación)
├── EjercicioCardiovascular.h    # Subclase cardiovascular (declaración)
├── EjercicioCardiovascular.cpp  # Subclase cardiovascular (implementación)
├── EjercicioFuerza.h            # Subclase fuerza (declaración)
├── EjercicioFuerza.cpp          # Subclase fuerza (implementación)
├── Rutina.h                     # Clase Rutina (declaración)
├── Rutina.cpp                   # Clase Rutina (implementación)
├── SistemaEntrenamiento.h       # Controlador principal (declaración)
├── SistemaEntrenamiento.cpp     # Controlador principal (implementación)
└── main.cpp                     # Punto de entrada del programa
```

---

## Diagrama de clases

```
                        ┌─────────────────────┐
                        │      Ejercicio       │
                        │─────────────────────│
                        │ #codigo: string      │
                        │ #nombre: string      │
                        │ #tipo: string        │
                        │ #nivelIntensidad     │
                        │ #tiempoMinutos: int  │
                        │ #descripcion: string │
                        │ #ultimaSemanaUsada   │
                        │─────────────────────│
                        │ + getters/setters    │
                        │ + mostrarInfo()      │
                        └──────────┬──────────┘
                                   │ herencia
               ┌───────────────────┴───────────────────┐
               │                                       │
┌──────────────────────────┐           ┌──────────────────────────┐
│  EjercicioCardiovascular │           │     EjercicioFuerza      │
│──────────────────────────│           │──────────────────────────│
│ (sin atributos propios)  │           │ (sin atributos propios)  │
│──────────────────────────│           │──────────────────────────│
│ + mostrarInfo() override │           │ + mostrarInfo() override │
└──────────────────────────┘           └──────────────────────────┘

┌──────────────────────────┐           ┌──────────────────────────┐
│         Rutina           │◄- - - - - │   SistemaEntrenamiento   │
│──────────────────────────│dependencia│──────────────────────────│
│ - cliente: string        │           │ - ejercicios: Ejercicio* │
│ - objetivo: string       │           │ - cantidad: int          │
│ - semanaActual: int      │           │──────────────────────────│
│ - ejercicios[50]         │           │ + crearEjercicio()       │
│──────────────────────────│           │ + actualizarEjercicio()  │
│ + agregarEjercicio()     │           │ + eliminarEjercicio()    │
│ + calcularTiempoTotal()  │           │ + generarRutina()        │
│ + mostrarRutina()        │           │ + menu()                 │
└──────────────────────────┘           └──────────────────────────┘
```

---

## Funcionalidades

- ✅ Crear ejercicios cardiovasculares y de fuerza
- ✅ Actualizar información de un ejercicio
- ✅ Eliminar ejercicios del sistema
- ✅ Consultar ejercicio por código
- ✅ Buscar ejercicios por nivel de intensidad
- ✅ Generar rutinas personalizadas por nivel
- ✅ Calcular tiempo total estimado de la rutina
- ✅ Restricción: no se repiten ejercicios en semanas consecutivas

---

## Niveles de intensidad

| Nivel | Descripción |
|---|---|
| Básico | Ejercicios de baja exigencia |
| Intermedio | Exigencia moderada |
| Avanzado | Alta exigencia |
| Alto Rendimiento | Máxima exigencia |

---

## Compilación y ejecución

### Requisitos
- Compilador g++ (MinGW en Windows, g++ en Linux/Mac)

### Compilar
```bash
g++ -o sistema.exe main.cpp Ejercicio.cpp EjercicioCardiovascular.cpp EjercicioFuerza.cpp Rutina.cpp SistemaEntrenamiento.cpp
```

### Ejecutar
```bash
# Windows
.\sistema.exe

# Linux / Mac
./sistema
```

---

## Uso del sistema

Al ejecutar el programa aparece el siguiente menú:

```
===== SISTEMA DE ENTRENAMIENTO =====
1. Crear ejercicio
2. Actualizar ejercicio
3. Eliminar ejercicio
4. Consultar ejercicio
5. Buscar ejercicios por intensidad
6. Generar rutina
7. Mostrar todos los ejercicios
0. Salir
```

---

## Principios OOP aplicados

| Principio | Aplicación |
|---|---|
| **Abstracción** | Clase base `Ejercicio` modela el concepto general de ejercicio |
| **Encapsulamiento** | Atributos `protected`/`private`, acceso mediante getters y setters |
| **Herencia** | `EjercicioCardiovascular` y `EjercicioFuerza` heredan de `Ejercicio` |
| **Polimorfismo** | `mostrarInformacion()` virtual permite comportamiento distinto según tipo |

---

## Integrantes

| Nombre | RUT |

| Ricardo Rico | 25.255.197-2 |


---

## Información académica

- **Asignatura:** Paradigmas de Programación  
- **Universidad:** Universidad Andrés Bello  
- **Facultad:** Ingeniería  
- **Fecha:** Abril 2026
