#include <iostream>
#include <vector>
#include <fstream>
#include "Paypal.h"
#include "UsuarioPaypal.h"
#include "Wallet.h"
#include "AdministradoraArchivos.h"

#include <iostream>
using namespace std;
void menuPaypal(Paypal& paypal) {
    cout << "------Iniciar Sesion------" << endl;
    string nombreUsuario;
    string contrasena;
    cout << "Ingrese su Usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;

    bool usuarioEncontrado = false;
    for (UsuarioPaypal* usuario : paypal.getUsuarios()) {
        if (usuario->getNombreUsuario() == nombreUsuario && usuario->getContrasena() == contrasena) {
            usuarioEncontrado = true;
            cout << "----------Bienvenido!-----------" << endl;
            int opcion;
            do {
                cout << "1. Ver Estado de cuenta" << endl;
                cout << "2. Hacer deposito a mi propia cuenta" << endl;
                cout << "3. Hacer retiro de mi cuenta" << endl;
                cout << "4. Ver historial de cuenta" << endl;
                cout << "5. Salir" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch (opcion) {
                case 1: {
                    double saldo = usuario->getSaldo();
                    cout << "Su saldo actual es: $" << saldo << endl;
                    break;
                }
                case 2: {
                    double deposito;
                    cout << "Ingrese la cantidad a depositar: $";
                    cin >> deposito;
                    usuario->setSaldo(usuario->getSaldo() + deposito);
                    cout << "Se ha depositado $" << deposito << " en su cuenta. " << endl;
                    break;
                }
                case 3: {
                    double retiro;
                    cout << "Ingrese la cantidad a retirar: $";
                    cin >> retiro;
                    if (retiro > usuario->getSaldo()) {
                        cout << "No tiene suficiente saldo en su cuenta." << endl;
                    }
                    else {
                        usuario->setSaldo(usuario->getSaldo() - retiro);
                        cout << "Se ha retirado $" << retiro << " de su cuenta." << endl;
                    }
                    break;
                }
                case 4: {
                    cout << "Historial de cuenta: " << endl;
                    const vector<string>& historial = usuario->getHistorial();
                    for (const string& transaccion : historial) {
                        cout << "- " << transaccion << endl;
                    }
                    break;
                }
                case 5: {
                    AdministradoraArchivos::crearArchivoBinario(&paypal);
                    break;
                }
                default:
                    cout << "Opcion invalida. Por Favor, ingrese una opcion valida." << endl;
                    break;
                }
            } while (opcion != 5);
            break;
        }
    }

    if (!usuarioEncontrado) {
        cout << "Nombre de usuario o contrasena incorrectos. " << endl;
    }
}
void menuWallet(Paypal& paypal) {
    cout << "-- Iniciar sesión Wallet --" << endl;
    string nombreUsuario;
    string contrasena;
    cout << "Ingrese su usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    bool usuarioEncontrado = false;
    for (UsuarioPaypal* usuario : paypal.getUsuarios()) {
        if (usuario->getNombreUsuario() == nombreUsuario && usuario->getContrasena() == contrasena) {
            usuarioEncontrado = true;
            Wallet wallet(nombreUsuario, usuario, contrasena);
            wallet.mostrarMenu();
            break;
        }
    }

    if (!usuarioEncontrado) {
        cout << "Nombre de usuario o contraseña incorrectos." << endl;
    }
}
void Menu(Paypal* paypal, Wallet& wallet, AdministradoraArchivos& adminArchivos) {
    int opc;
    do{
    cout << "------------Menu-------------" << endl;
    cout << "1. Crear Cuenta de Paypal" << endl;
    cout << "2. Crear Wallet" << endl;
    cout << "3. Cargar Informacion" << endl;
    cout << "4. Acceder a paypal" << endl;
    cout << "5. Acceder a Wallet" << endl;
    cout << "6. Salir" << endl;
    cin >> opc;
    
    switch (opc) {
    case 1: {
        string nombreUsuario, numIdentidad, contrasena;
        cout << "Ingrese el nombre de usuario: ";
        cin >> nombreUsuario;
        cout << "Ingrese el numero de identidad: ";
        cin >> numIdentidad;
        cout << "Ingrese la contrasena: ";
        cin >> contrasena;
        UsuarioPaypal* usuario = new UsuarioPaypal(nombreUsuario, numIdentidad, contrasena);
        paypal->agregarUsuario(usuario);
        break;
        }
    case 2: {
        string nombreUsuario;
        cout << "Ingrese el nombre de usuario de Paypal: ";
        cin >> nombreUsuario;
        wallet.crearWallet(*paypal);
    }
    case 3: {
        adminArchivos.cargarInformacion(paypal);
        break;
    }
    case 4: {
        menuPaypal(*paypal);
        break;
    }
    case 5: {
        menuWallet(*paypal);
        break;
    }
    case 6: {
        adminArchivos.crearArchivoBinario(paypal);
        cout << "¡Hasta luego!" << endl;
        break;
    }
    default:
        cout << "Opción inválida. Inténtelo nuevamente." << endl;
        break;
    }
} while (opc != 6);

    }
  
int main(){
    Paypal paypal;
    Wallet wallet;
    AdministradoraArchivos adminArchivos;

    Menu(&paypal, wallet, adminArchivos);
    return 0;
}
