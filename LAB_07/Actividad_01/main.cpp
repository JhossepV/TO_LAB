#include "Configuracion.h"
#include <iostream>

int main()
{
  auto &primera = Configuracion::instancia("es", "America/Lima");
  auto &segunda = Configuracion::instancia();
  auto &tercera = Configuracion::instancia();

  std::cout << "Configuracion inicial:\n";
  primera.mostrarConfiguracion();

  segunda.actualizar("en", "Europe/Madrid");
  std::cout << "\nConfiguracion tras actualizar desde otra referencia:\n";
  tercera.mostrarConfiguracion();

  const bool mismaInstancia = &primera == &segunda && &segunda == &tercera;
  std::cout << "\n¿Todas las referencias apuntan al mismo objeto?: "
            << (mismaInstancia ? "true" : "false") << '\n';
  return 0;
}