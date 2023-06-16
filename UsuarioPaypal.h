#pragma once
#include <string>
#include <vector>
using namespace std;

class UsuarioPaypal{
private:
    string nombreUsuario;
    string numeroIdentidad;
    string contrasena;
    double saldo;
    vector<string> historial;

public:
    UsuarioPaypal(string nombreUsuario, string numeroIdentidad, string contrasena) {
        this->nombreUsuario = nombreUsuario;
        this->numeroIdentidad = numeroIdentidad;
        this->contrasena = contrasena;
        this->saldo = 0.0;
    }
};

