#include "ConexionBD.h"

#include <iostream>

ConexionBD &ConexionBD::instancia()
{
  static ConexionBD instancia;
  return instancia;
}

void ConexionBD::configurar(const std::string &cadenaConexion)
{
  if (conectada_)
  {
    std::cout << "No se puede reconfigurar una conexion activa" << std::endl;
    return;
  }

  cadenaConexion_ = cadenaConexion;
}

void ConexionBD::conectar()
{
  if (conectada_)
  {
    std::cout << "La conexion ya esta activa" << std::endl;
    return;
  }

  if (cadenaConexion_.empty())
  {
    cadenaConexion_ = "ServidorLocal";
  }

  conectada_ = true;
  std::cout << "Conexion a base de datos establecida en " << cadenaConexion_ << std::endl;
}

void ConexionBD::desconectar()
{
  if (!conectada_)
  {
    std::cout << "La conexion ya esta cerrada" << std::endl;
    return;
  }

  conectada_ = false;
  std::cout << "Conexion cerrada" << std::endl;
}

std::string ConexionBD::estado() const
{
  if (conectada_)
  {
    return "Conectado a " + cadenaConexion_;
  }
  return "Desconectado";
}
