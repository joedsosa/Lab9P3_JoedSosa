#include "Paypal.h"
#include "UsuarioPaypal.h"

void Paypal::crearCuenta(string nombreUsuario, string numeroIdentidad, string contrasena) {
    for ( auto& usuario : usuarios) {
        if (usuario->getNombreUsuario() == nombreUsuario) {
            cout << "El nombre de usuario ya existe. Introduce uno diferente." << endl;
            return;
        }
        if (usuario->getNumeroIdentidad() == numeroIdentidad) {
            cout << "El número de identidad ya existe. Introduce uno diferente." << endl;
            return;
        }
    }

    UsuarioPaypal* nuevoUsuario = new UsuarioPaypal(nombreUsuario, numeroIdentidad, contrasena);
    usuarios.push_back(nuevoUsuario);

    cout << "Cuenta de Paypal creada exitosamente." << endl;
}

UsuarioPaypal* Paypal::buscarUsuario(std::string nombreUsuario) {
    for (auto& usuario : usuarios) {
        if (usuario->getNombreUsuario() == nombreUsuario) {
            return usuario;
        }
    }

    return nullptr;  // Usuario no encontrado
}

vector<UsuarioPaypal*> Paypal::getUsuarios() {
    return usuarios;
}
void Paypal::agregarUsuario(UsuarioPaypal* usuario) {
    // Verificar si el usuario ya existe
    for (const auto& u : usuarios) {
        if (u->getNombreUsuario() == usuario->getNombreUsuario()) {
            cout << "El usuario ya existe en Paypal. No se puede agregar nuevamente." << endl;
            return;
        }
        if (u->getNumeroIdentidad() == usuario->getNumeroIdentidad()) {
            cout << "El número de identidad ya existe en Paypal. No se puede agregar nuevamente." << endl;
            return;
        }
    }

    if (!usuario->validarContrasena(usuario->getContrasena())) {
        cout << "La contraseña no cumple con los requisitos. Inténtelo nuevamente." << endl;
        return;
    }

    usuarios.push_back(usuario);
    cout << "Usuario agregado exitosamente a Paypal." << endl;
}



