#include "AdministradoraArchivos.h"
#include <fstream>
#include <iostream>
#include "UsuarioPaypal.h"
#include "Paypal.h"

AdministradoraArchivos::AdministradoraArchivos() {}

//void AdministradoraArchivos::crearArchivoBinario(Paypal* paypal) {
//    ofstream archivo("paypal.dat", ios::binary);
//    if (archivo.is_open()) {
//        size_t numUsuarios = paypal->getUsuarios().size();
//        archivo.write(reinterpret_cast<char*>(&numUsuarios), sizeof(numUsuarios));
//        for (auto& usuario : paypal->getUsuarios()) {
//            // Escribir los miembros individuales del usuario
//            string nombreUsuario = usuario->getNombreUsuario();
//            string numeroIdentidad = usuario->getNumeroIdentidad();
//            string contrasena = usuario->getContrasena();
//            double saldo = usuario->getSaldo();
//            vector<string> historial = usuario->getHistorial();
//
//            size_t nombreUsuarioSize = nombreUsuario.size();
//            archivo.write(reinterpret_cast<char*>(&nombreUsuarioSize), sizeof(nombreUsuarioSize));
//            archivo.write(nombreUsuario.c_str(), nombreUsuarioSize);
//
//            size_t numeroIdentidadSize = numeroIdentidad.size();
//            archivo.write(reinterpret_cast<char*>(&numeroIdentidadSize), sizeof(numeroIdentidadSize));
//            archivo.write(numeroIdentidad.c_str(), numeroIdentidadSize);
//
//            size_t contrasenaSize = contrasena.size();
//            archivo.write(reinterpret_cast<char*>(&contrasenaSize), sizeof(contrasenaSize));
//            archivo.write(contrasena.c_str(), contrasenaSize);
//
//            archivo.write(reinterpret_cast<char*>(&saldo), sizeof(saldo));
//
//            size_t historialSize = historial.size();
//            archivo.write(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));
//            for (const auto& transaccion : historial) {
//                size_t transaccionSize = transaccion.size();
//                archivo.write(reinterpret_cast<char*>(&transaccionSize), sizeof(transaccionSize));
//                archivo.write(transaccion.c_str(), transaccionSize);
//            }
//        }
//        archivo.close();
//        cout << "Archivo binario creado exitosamente." << endl;
//    }
//    else {
//        cout << "Error al crear el archivo binario." << endl;
//    }
//}
void AdministradoraArchivos::crearArchivoBinario(Paypal* paypal) {
    for (const auto& usuario : paypal->getUsuarios()) {
        std::string id = usuario->getNumeroIdentidad();
        std::string nombreArchivo = id + ".lab";
        std::ofstream archivo(nombreArchivo, std::ios::binary);
        if (archivo.is_open()) {
            // Escribir los datos del usuario en el archivo
            std::string nombreUsuario = usuario->getNombreUsuario();
            std::string numeroIdentidad = usuario->getNumeroIdentidad();
            std::string contrasena = usuario->getContrasena();
            double saldo = usuario->getSaldo();
            std::vector<std::string> historial = usuario->getHistorial();

            size_t nombreUsuarioSize = nombreUsuario.size();
            archivo.write(reinterpret_cast<char*>(&nombreUsuarioSize), sizeof(nombreUsuarioSize));
            archivo.write(nombreUsuario.c_str(), nombreUsuarioSize);

            size_t numeroIdentidadSize = numeroIdentidad.size();
            archivo.write(reinterpret_cast<char*>(&numeroIdentidadSize), sizeof(numeroIdentidadSize));
            archivo.write(numeroIdentidad.c_str(), numeroIdentidadSize);

            size_t contrasenaSize = contrasena.size();
            archivo.write(reinterpret_cast<char*>(&contrasenaSize), sizeof(contrasenaSize));
            archivo.write(contrasena.c_str(), contrasenaSize);

            archivo.write(reinterpret_cast<char*>(&saldo), sizeof(saldo));

            size_t historialSize = historial.size();
            archivo.write(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));
            for (const auto& transaccion : historial) {
                size_t transaccionSize = transaccion.size();
                archivo.write(reinterpret_cast<char*>(&transaccionSize), sizeof(transaccionSize));
                archivo.write(transaccion.c_str(), transaccionSize);
            }

            archivo.close();
            std::cout << "Archivo binario creado exitosamente: " << nombreArchivo << std::endl;
        }
        else {
            std::cout << "Error al crear el archivo binario: " << nombreArchivo << std::endl;
        }
    }
}


//void AdministradoraArchivos::cargarInformacion(Paypal* paypal) {
//    ifstream archivo("paypal.dat", ios::binary);
//    if (archivo.is_open()) {
//        size_t numUsuarios;
//        archivo.read(reinterpret_cast<char*>(&numUsuarios), sizeof(numUsuarios));
//        for (size_t i = 0; i < numUsuarios; i++) {
//            string nombreUsuario;
//            string numeroIdentidad;
//            string contrasena;
//            double saldo;
//            vector<string> historial;
//
//            size_t nombreUsuarioSize;
//            archivo.read(reinterpret_cast<char*>(&nombreUsuarioSize), sizeof(nombreUsuarioSize));
//            nombreUsuario.resize(nombreUsuarioSize);
//            archivo.read(&nombreUsuario[0], nombreUsuarioSize);
//
//            size_t numeroIdentidadSize;
//            archivo.read(reinterpret_cast<char*>(&numeroIdentidadSize), sizeof(numeroIdentidadSize));
//            numeroIdentidad.resize(numeroIdentidadSize);
//            archivo.read(&numeroIdentidad[0], numeroIdentidadSize);
//
//            size_t contrasenaSize;
//            archivo.read(reinterpret_cast<char*>(&contrasenaSize), sizeof(contrasenaSize));
//            contrasena.resize(contrasenaSize);
//            archivo.read(&contrasena[0], contrasenaSize);
//
//            archivo.read(reinterpret_cast<char*>(&saldo), sizeof(saldo));
//
//            size_t historialSize;
//            archivo.read(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));
//            for (size_t j = 0; j < historialSize; j++) {
//                size_t transaccionSize;
//                archivo.read(reinterpret_cast<char*>(&transaccionSize), sizeof(transaccionSize));
//                std::string transaccion;
//                transaccion.resize(transaccionSize);
//                archivo.read(&transaccion[0], transaccionSize);
//                historial.push_back(transaccion);
//            }
//
//            UsuarioPaypal* usuario = new UsuarioPaypal(nombreUsuario, numeroIdentidad, contrasena);
//            usuario->setSaldo(saldo);
//            usuario->setHistorial(historial);
//            paypal->agregarUsuario(usuario);
//        }
//        archivo.close();
//        std::cout << "Información cargada exitosamente." << std::endl;
//    }
//    else {
//        std::cout << "Error al cargar la información." << std::endl;
//    }
//}
void AdministradoraArchivos::cargarInformacion(Paypal* paypal) {
    std::vector<std::string> archivos;
    std::string extension = ".lab";
    std::string nombreArchivo;
    DIR* directorio;
    struct dirent* archivo;
    if ((directorio = opendir(".")) != nullptr) {
        while ((archivo = readdir(directorio)) != nullptr) {
            nombreArchivo = archivo->d_name;
            if (nombreArchivo.length() > extension.length() &&
                nombreArchivo.substr(nombreArchivo.length() - extension.length()) == extension) {
                archivos.push_back(nombreArchivo);
            }
        }
        closedir(directorio);

        for (const auto& nombreArchivo : archivos) {
            std::ifstream archivo(nombreArchivo, std::ios::binary);
            if (archivo.is_open()) {
                // Leer los datos del archivo
                std::string nombreUsuario;
                std::string numeroIdentidad;
                std::string contrasena;
                double saldo;
                std::vector<std::string> historial;

                size_t nombreUsuarioSize;
                archivo.read(reinterpret_cast<char*>(&nombreUsuarioSize), sizeof(nombreUsuarioSize));
                nombreUsuario.resize(nombreUsuarioSize);
                archivo.read(&nombreUsuario[0], nombreUsuarioSize);

                size_t numeroIdentidadSize;
                archivo.read(reinterpret_cast<char*>(&numeroIdentidadSize), sizeof(numeroIdentidadSize));
                numeroIdentidad.resize(numeroIdentidadSize);
                archivo.read(&numeroIdentidad[0], numeroIdentidadSize);

                size_t contrasenaSize;
                archivo.read(reinterpret_cast<char*>(&contrasenaSize), sizeof(contrasenaSize));
                contrasena.resize(contrasenaSize);
                archivo.read(&contrasena[0], contrasenaSize);

                archivo.read(reinterpret_cast<char*>(&saldo), sizeof(saldo));

                size_t historialSize;
                archivo.read(reinterpret_cast<char*>(&historialSize), sizeof(historialSize));
                for (size_t i = 0; i < historialSize; i++) {
                    size_t transaccionSize;
                    archivo.read(reinterpret_cast<char*>(&transaccionSize), sizeof(transaccionSize));
                    std::string transaccion;
                    transaccion.resize(transaccionSize);
                    archivo.read(&transaccion[0], transaccionSize);
                    historial.push_back(transaccion);
                }

                archivo.close();

                UsuarioPaypal* usuario = new UsuarioPaypal(nombreUsuario, numeroIdentidad, contrasena);
                usuario->setSaldo(saldo);
                usuario->setHistorial(historial);
                paypal->agregarUsuario(usuario);

                std::cout << "Archivo binario cargado exitosamente: " << nombreArchivo << std::endl;
            }
            else {
                std::cout << "Error al cargar el archivo binario: " << nombreArchivo << std::endl;
            }
        }
    }
    else {
        std::cout << "Error al abrir el directorio." << std::endl;
    }
}


