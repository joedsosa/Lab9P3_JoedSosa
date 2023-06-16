#pragma once
#ifndef ADMINISTRADORA_ARCHIVOS_H
#define ADMINISTRADORA_ARCHIVOS_H

class Paypal;

class AdministradoraArchivos {
public:
    void crearArchivoBinario(Paypal* paypal);
    void cargarInformacion(Paypal* paypal);
};

#endif  // ADMINISTRADORA_ARCHIVOS_H


