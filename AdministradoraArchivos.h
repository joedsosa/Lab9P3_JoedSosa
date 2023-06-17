#pragma once
#include "Paypal.h"

class AdministradoraArchivos {
public:
    AdministradoraArchivos();

    static void crearArchivoBinario(Paypal* paypal);
    static void cargarInformacion(Paypal* paypal);
};
