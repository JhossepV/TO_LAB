#pragma once

#include <fstream>
#include <string>

class Logger
{
public:
  static Logger &instancia(const std::string &rutaArchivo = "bitacora.log");

  void log(const std::string &mensaje);

  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

private:
  explicit Logger(const std::string &rutaArchivo);
  ~Logger();

  void escribirMarcaDeTiempo(std::ofstream &stream) const;

  std::ofstream archivo_;
};
