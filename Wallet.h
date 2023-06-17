#pragma once
#include <string>
#include <vector>
#include "Paypal.h"
class UsuarioPaypal;
using namespace std;
class Wallet {

private:
    string nombreUsuario;
    UsuarioPaypal* cuentaPaypal;
    string contrasena;

public:
    Wallet(string nombreUsuario, UsuarioPaypal* cuentaPaypal, string contrasena);
    void mostrarMenu();
    void verEstadoCuenta();
    void comprarCryptos();
    void venderCryptos();
    void crearWallet(Paypal& paypal);
    Wallet() = default;

};

