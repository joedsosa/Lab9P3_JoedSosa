#ifndef PAYPAL_H
#define PAYPAL_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class UsuarioPaypal;

class Paypal {
private:
    vector<UsuarioPaypal*> usuarios;

public:
    void crearCuenta(string nombreUsuario, string numeroIdentidad, string contrasena);
    UsuarioPaypal* buscarUsuario(string nombreUsuario);
    vector<UsuarioPaypal*> getUsuarios();
    void agregarUsuario(UsuarioPaypal* usuario);

};

#endif  // PAYPAL_H
