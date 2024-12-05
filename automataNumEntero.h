//
// Created by Oswaldo on 15/11/2024.
//

#ifndef AUTOMATANUMENTERO_H
#define AUTOMATANUMENTERO_H
#include <iostream>
#include <string>

namespace autoEntero {

class automataNumEntero {

public: static bool esNumeroEntero(const std::string& input) {
        enum Estado {
            INICIO,
            SIGNO,
            DIGITOS,
            ACEPTACION,
            ERROR
        };

        Estado estado = INICIO;
        int contadorDigitos = 0;  // Contador para los dígitos del número

        for (char c : input) {
            switch (estado) {
                case INICIO:
                    if (c == '+' || c == '-') {
                        estado = SIGNO;  // Aceptar un signo opcional
                    } else if (isdigit(c)) {
                        estado = DIGITOS;
                        contadorDigitos++;
                    } else {
                        estado = ERROR;
                    }
                break;

                case SIGNO:
                    if (isdigit(c)) {
                        estado = DIGITOS;
                        contadorDigitos++;
                    } else {
                        estado = ERROR;
                    }
                break;

                case DIGITOS:
                    if (isdigit(c)) {
                        contadorDigitos++;
                        if (contadorDigitos > 9) {
                            estado = ERROR; // Excede el límite de 9 dígitos
                        }
                    } else {
                        estado = ERROR;
                    }
                break;

                default:
                    estado = ERROR;
                break;
            }

            if (estado == ERROR) {
                return false;
            }
        }

        // El número es válido si termina en el estado DIGITOS y no excede 9 dígitos
        return estado == DIGITOS && contadorDigitos <= 9;
    }


};

} // autoEntero

#endif //AUTOMATANUMENTERO_H
