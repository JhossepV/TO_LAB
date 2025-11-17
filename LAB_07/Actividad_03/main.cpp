#include "ConexionBD.h"

#include <iostream>

int main()
{
  auto &conexion1 = ConexionBD::instancia();
  conexion1.configurar("ServidorConsultas");
  conexion1.conectar();
  std::cout << "Estado actual: " << conexion1.estado() << std::endl;

  auto &conexion2 = ConexionBD::instancia();
  std::cout << "Ambas referencias son la misma instancia? "
            << (&conexion1 == &conexion2 ? "Si" : "No") << std::endl;

  conexion2.conectar();
  conexion2.desconectar();
  std::cout << "Estado final: " << conexion2.estado() << std::endl;

  return 0;
}
