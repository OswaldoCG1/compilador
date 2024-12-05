//
// Created by Oswaldo on 15/11/2024.
//

#ifndef AUTOMATANUMREAL_H
#define AUTOMATANUMREAL_H

#include <iostream>
#include <string>

namespace autoReal {

class automataNumReal {


public: static bool esNumeroReal(const std::string& input) {
    enum Estado {
        INICIO,
        SIGNO,
        ENTERO,
        PUNTO,
        DECIMAL,
        ACEPTACION,
        ERROR
    };

    Estado estado = INICIO;
    int contadorEntero = 0;  // Contador para los dígitos antes del punto decimal
    int contadorDecimal = 0; // Contador para los dígitos después del punto decimal

    for (char c : input) {
        switch (estado) {
            case INICIO:
                if (c == '+' || c == '-') {
                    estado = SIGNO;
                } else if (isdigit(c)) {
                    estado = ENTERO;
                    contadorEntero++;
                } else {
                    estado = ERROR;
                }
                break;

            case SIGNO:
                if (isdigit(c)) {
                    estado = ENTERO;
                    contadorEntero++;
                } else {
                    estado = ERROR;
                }
                break;

            case ENTERO:
                if (isdigit(c)) {
                    contadorEntero++;
                    if (contadorEntero > 9) {
                        estado = ERROR; // Excede el límite de 9 dígitos antes del punto
                    }
                } else if (c == '.') {
                    estado = PUNTO;
                } else {
                    estado = ERROR;
                }
                break;

            case PUNTO:
                if (isdigit(c)) {
                    estado = DECIMAL;
                    contadorDecimal++;
                } else {
                    estado = ERROR;
                }
                break;

            case DECIMAL:
                if (isdigit(c)) {
                    contadorDecimal++;
                    if (contadorDecimal > 9) {
                        estado = ERROR; // Excede el límite de 9 dígitos después del punto
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

    // Estado final válido
    return (estado == ENTERO || estado == DECIMAL) && contadorEntero <= 9 && contadorDecimal <= 9;
}

};

} // autoReal

#endif //AUTOMATANUMREAL_H
