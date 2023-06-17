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
    // Verificar longitud mínima de 8 caracteres
    if (contrasena.length() < 8) {
        return false;
    }

    // Verificar presencia de al menos un carácter especial
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
