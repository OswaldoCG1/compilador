//
// Created by Oswaldo on 15/11/2024.
//

#ifndef AUTOMATAID_H
#define AUTOMATAID_H
#include <iostream>
#include <string>

namespace autoID {

class automataID {
public: static bool esIdentificador(const std::string& input) {
        enum Estado {
            INICIO,
            SIMBOLO,
            LETRA_DIGITO_GUION,
            ERROR
        };

        Estado estado = INICIO;

        if (input.empty()) {
            return false;  // Un identificador no puede estar vacío
        }

        for (char c : input) {
            switch (estado) {
                case INICIO:
                    if (c == '$') {
                        estado = SIMBOLO;  // El identificador empieza con '$'
                    } else {
                        estado = ERROR;
                    }
                break;

                case SIMBOLO:
                    // Después del '$', el identificador puede contener letras, dígitos, guiones o guiones bajos
                        if (isalpha(c) || isdigit(c) || c == '_' || c == '-') {
                            estado = LETRA_DIGITO_GUION;
                        } else {
                            estado = ERROR;
                        }
                break;

                case LETRA_DIGITO_GUION:
                    // El identificador puede seguir con letras, dígitos, guiones o guiones bajos
                        if (isalpha(c) || isdigit(c) || c == '_' || c == '-') {
                            // Permanece en el estado LETRA_DIGITO_GUION
                        } else {
                            estado = ERROR;
                        }
                break;

                default:
                    estado = ERROR;
                break;
            }

            if (estado == ERROR) {
                return false;  // Si llegamos al estado ERROR, el identificador es inválido
            }
        }

        // El identificador es válido si terminamos en el estado LETRA_DIGITO_GUION
        return estado == LETRA_DIGITO_GUION;
    }

};

} // autoID

#endif //AUTOMATAID_H
