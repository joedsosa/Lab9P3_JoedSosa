#pragma once
#include <string>
#include <vector>
#include "Wallet.h"
using namespace std;
class UsuarioPaypal {
public:
    UsuarioPaypal(const string& nombreUsuario, const string& numeroIdentidad, const string& contrasena);

    string getNombreUsuario();
    string getNumeroIdentidad();
    string getContrasena();
    double getSaldo();
    vector<string> getHistorial();
    bool validarContrasena(const string& contrasena);
    void setSaldo(double saldo);
    void setHistorial(vector<string>& historial);
    Wallet* getWallet();
    void setWallet(Wallet* wallet);
    void agregarTransaccion(string& transaccion);

private:
    string nombreUsuario;
    string numeroIdentidad;
    string contrasena;
    double saldo;
    vector<string> historial;
    Wallet* wallet;
    
};
