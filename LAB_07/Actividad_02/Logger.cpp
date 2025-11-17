#include "Logger.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

Logger &Logger::instancia(const std::string &rutaArchivo)
{
  static Logger unicaInstancia(rutaArchivo);
  return unicaInstancia;
}

Logger::Logger(const std::string &rutaArchivo) : archivo_(rutaArchivo, std::ios::app)
{
  if (!archivo_.is_open())
  {
    throw std::runtime_error("No se pudo abrir el archivo de log: " + rutaArchivo);
  }
}

Logger::~Logger()
{
  if (archivo_.is_open())
  {
    archivo_.flush();
    archivo_.close();
  }
}

void Logger::log(const std::string &mensaje)
{
  if (!archivo_.is_open())
  {
    std::cerr << "Archivo de log cerrado." << std::endl;
    return;
  }

  escribirMarcaDeTiempo(archivo_);
  archivo_ << " " << mensaje << '\n';
  archivo_.flush();
}

void Logger::escribirMarcaDeTiempo(std::ofstream &stream) const
{
  const auto ahora = std::chrono::system_clock::now();
  const std::time_t tiempo = std::chrono::system_clock::to_time_t(ahora);
  std::tm tm{};
#if defined(_WIN32)
  localtime_s(&tm, &tiempo);
#endif
  stream << '[' << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << ']';
}
