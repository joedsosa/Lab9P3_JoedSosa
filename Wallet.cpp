#include "Wallet.h"
#include "UsuarioPaypal.h"
#include <iostream>

Wallet::Wallet(string nombreUsuario, UsuarioPaypal* cuentaPaypal, string contrasena) {
    this->nombreUsuario = nombreUsuario;
    this->cuentaPaypal = cuentaPaypal;
    this->contrasena = contrasena;
}


void Wallet::mostrarMenu() {
    int opcion;
    do {
        cout << "------Bienvenido!------" << endl;
        cout << "1. Ver Estado de cuenta" << endl;
        cout << "2. Comprar Cryptos" << endl;
        cout << "3. Vender Cryptos" << endl;
        cout << "4. Salir" <<endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            verEstadoCuenta();
            break;
        case 2:
            comprarCryptos();
            break;
        case 3:
            venderCryptos();
            break;
        case 4:
            cout << "Saliendo de la Wallet..." << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    } while (opcion != 4);
}

void Wallet::verEstadoCuenta() {
    cout << "-- Estado de cuenta --" << endl;
    cout << "Nombre de usuario: " << nombreUsuario << endl;
    cout << "Saldo en cuenta: $" << cuentaPaypal->getSaldo() << endl;
}

void Wallet::comprarCryptos() {
    cout << "--- Comprar Cryptos ---" << endl;
    cout << "Ingrese el tipo de criptomoneda a comprar:" << endl;
    cout << "1. Doge Coin = 0.6 $" << endl;
    cout << "2. Ethereum = 1000 $" << endl;
    cout << "3. WalterCoin = 5 &" << endl;

    int opcion;
    cin >> opcion;

    double monto;
    switch (opcion) {
    case 1:
        monto = 0.6;
        break;
    case 2:
        monto = 1000;
        break;
    case 3:
        monto = 5;
        break;
    default:
        cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
        return;
    }

    if (monto > cuentaPaypal->getSaldo()) {
        cout << "No tiene suficiente saldo en su cuenta para realizar la compra." << endl;
    }
    else {
        cuentaPaypal->setSaldo(cuentaPaypal->getSaldo() - monto);
        cout << "Se ha realizado la compra de la criptomoneda." << endl;
    }
}

void Wallet::venderCryptos() {
    cout << "--- Vender Cryptos ---" << endl;
    cout << "Ingrese el tipo de criptomoneda a vender:" << endl;
    cout << "1. Doge Coin = 0.6 $" << endl;
    cout << "2. Ethereum = 1000 $" << endl;
    cout << "3. WalterCoin = 5 &" << endl;

    int opcion;
    cin >> opcion;

    double monto;
    switch (opcion) {
    case 1:
        monto = 0.6;
        break;
    case 2:
        monto = 1000;
        break;
    case 3:
        monto = 5;
        break;
    default:
        cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
        return;
    }

    cuentaPaypal->setSaldo(cuentaPaypal->getSaldo() + monto);
    cout << "Se ha vendido la criptomoneda y se ha depositado el monto en su cuenta." << endl;
}

void Wallet::crearWallet(Paypal& paypal) {
    std::cout << "Ingrese el nombre de usuario de Paypal: ";
    std::string nombreUsuario;
    std::cin >> nombreUsuario;

    UsuarioPaypal* usuario = paypal.buscarUsuario(nombreUsuario);
    if (usuario != nullptr) {
        // Verificar si el usuario ya tiene una Wallet asociada
        if (usuario->getWallet() != nullptr) {
            std::cout << "El usuario ya tiene una Wallet asociada." << std::endl;
        }
        else {
            // Crear una nueva Wallet para el usuario
            Wallet* nuevaWallet = new Wallet(nombreUsuario, usuario, "");
            usuario->setWallet(nuevaWallet);
            std::cout << "Se ha creado una nueva Wallet para el usuario." << std::endl;
        }
    }
    else {
        std::cout << "El usuario no existe en Paypal." << std::endl;
    }
}