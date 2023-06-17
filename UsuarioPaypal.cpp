#include "UsuarioPaypal.h"

UsuarioPaypal::UsuarioPaypal(const string& nombreUsuario, const string& numeroIdentidad, const string& contrasena) {
    this->nombreUsuario = nombreUsuario;
    this->numeroIdentidad = numeroIdentidad;
    this->contrasena = contrasena;
    this->saldo = 0.0;
    this->wallet = nullptr;
}
string UsuarioPaypal::getNombreUsuario() {
    return nombreUsuario;
}
string UsuarioPaypal::getNumeroIdentidad() {
    return numeroIdentidad;
}

string UsuarioPaypal::getContrasena(){
    return contrasena;
}

double UsuarioPaypal::getSaldo(){
    return saldo;
}

vector<string> UsuarioPaypal::getHistorial() {
    return historial;
}

void UsuarioPaypal::setSaldo(double saldo) {
    this->saldo = saldo;
}

void UsuarioPaypal::setHistorial(vector<string>& historial) {
    this->historial = historial;
}
bool UsuarioPaypal::validarContrasena(const string& contrasena) {
    // Verificar longitud m�nima de 8 caracteres
    if (contrasena.length() < 8) {
        return false;
    }

    // Verificar presencia de al menos un car�cter especial
    bool tieneCaracterEspecial = false;
    for (char c : contrasena) {
        if (!isalnum(c)) {
            tieneCaracterEspecial = true;
            break;
        }
    }

    return tieneCaracterEspecial;
}
void UsuarioPaypal::setWallet(Wallet* wallet) {
    this->wallet = wallet;
}
Wallet* UsuarioPaypal::getWallet() {
    return wallet;
}
void UsuarioPaypal::agregarTransaccion(string& transaccion) {
    historial.push_back(transaccion);
}
void UsuarioPaypal::depositar(double cantidad) {
    saldo += cantidad;
    std::string transaccion = "Dep�sito de $" + std::to_string(cantidad);
    historial.push_back(transaccion);
    std::cout << "Se ha depositado $" << cantidad << " en la cuenta." << std::endl;
}

bool UsuarioPaypal::retirar(double cantidad) {
    if (cantidad > saldo) {
        std::cout << "No tiene suficiente saldo en la cuenta." << std::endl;
        return false;
    }

    saldo -= cantidad;
    std::string transaccion = "Retiro de $" + std::to_string(cantidad);
    historial.push_back(transaccion);
    std::cout << "Se ha retirado $" << cantidad << " de la cuenta." << std::endl;
    return true;
}