#include "Logger.h"
#include <exception>
#include <iostream>
#include <string>

void procesarUsuarios()
{
  auto &logger = Logger::instancia();
  logger.log("Iniciando procesamiento de usuarios");
  // Simulacion de trabajo
  logger.log("Procesamiento de usuarios finalizado");
}

void generarReporte(const std::string &nombre)
{
  auto &logger = Logger::instancia();
  logger.log("Generando reporte: " + nombre);
  logger.log("Reporte " + nombre + " generado");
}

int main()
{
  try
  {
    auto &logger = Logger::instancia();
    logger.log("Aplicacion iniciada");

    procesarUsuarios();
    generarReporte("ventas");

    logger.log("Aplicacion finalizada");
    std::cout << "Logs escritos en bitacora.log" << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << "No se pudo inicializar el logger: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
