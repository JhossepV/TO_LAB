#include "Configuracion.h"

#include <iostream>
#include <utility>

Configuracion &Configuracion::instancia(const std::string &idioma, const std::string &zonaHoraria)
{
  static Configuracion unicaInstancia(idioma, zonaHoraria);
  return unicaInstancia;
}

Configuracion::Configuracion(std::string idioma, std::string zonaHoraria)
    : idioma_(std::move(idioma)), zonaHoraria_(std::move(zonaHoraria)) {}

void Configuracion::actualizar(const std::string &nuevoIdioma, const std::string &nuevaZonaHoraria)
{
  if (!nuevoIdioma.empty())
  {
    idioma_ = nuevoIdioma;
  }
  if (!nuevaZonaHoraria.empty())
  {
    zonaHoraria_ = nuevaZonaHoraria;
  }
}

void Configuracion::mostrarConfiguracion() const
{
  std::cout << "Idioma: " << idioma_ << '\n';
  std::cout << "Zona horaria: " << zonaHoraria_ << '\n';
}
