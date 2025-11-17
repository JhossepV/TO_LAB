#pragma once

#include <string>

class Configuracion {
public:
    static Configuracion &instancia(const std::string &idioma = "es",
                                    const std::string &zonaHoraria = "UTC");

    void actualizar(const std::string &nuevoIdioma,
                    const std::string &nuevaZonaHoraria);
    void mostrarConfiguracion() const;

    Configuracion(const Configuracion &) = delete;
    Configuracion &operator=(const Configuracion &) = delete;

private:
    Configuracion(std::string idioma, std::string zonaHoraria);

    std::string idioma_;
    std::string zonaHoraria_;
};
