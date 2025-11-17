#pragma once

#include <string>

class ConexionBD final
{
public:
  static ConexionBD &instancia();

  void configurar(const std::string &cadenaConexion);
  void conectar();
  void desconectar();
  std::string estado() const;

  ConexionBD(const ConexionBD &) = delete;
  ConexionBD &operator=(const ConexionBD &) = delete;

private:
  ConexionBD() = default;

  bool conectada_ = false;
  std::string cadenaConexion_ = "";
};
