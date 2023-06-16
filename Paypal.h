#ifndef PAYPAL_H
#define PAYPAL_H

#include <vector>
#include <string>
using namespace std;
class UsuarioPaypal;

class Paypal {
private:
    vector<UsuarioPaypal*> usuarios;

public:
    void crearCuenta(std::string nombreUsuario, string numeroIdentidad, string contrasena);
    UsuarioPaypal* buscarUsuario(string nombreUsuario);
    vector<UsuarioPaypal*> getUsuarios();
};

#endif  // PAYPAL_H
