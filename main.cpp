#include <iostream>

#include "automataID.h"
#include "automataNumEntero.h"
#include "automataNumReal.h"
#include "recorrer_arch.h"

using namespace std;
using namespace recorrer;
using namespace autoEntero;
using namespace autoReal;
using namespace autoID;



int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string inputFileName = "C:\\Users\\Oswaldo\\CLionProjects\\untitled\\entrada.txt"; // Archivo original
    std::string processedFileName = "salida.txt"; // Archivo preprocesado

    recorrer_arch recorrer;
    automataID autoID;
    automataNumEntero autoNumEntero;
    automataNumReal autoNumReal;

    //recorrer.RecorrerArchivo(inputFileName, processedFileName);
    /*if (    autoID.esIdentificador("$")) {
        std::cout << " es un identificador válido.\n";
    } else {
        std::cout  << " NO es un identificador válido.\n";
    }*/

    /*if (autoNumEntero.esNumeroEntero("123456789")) {
        std::cout  << " es un número entero válido.\n";
    } else {
        std::cout << " NO es un número entero válido.\n";
    }*/

    /*if (autoNumReal.esNumeroReal("123.123456789")) {
        std::cout  << " es un número real válido.\n";
    } else {
        std::cout << " NO es un número real válido.\n";
    }*/
    return 0;
}
