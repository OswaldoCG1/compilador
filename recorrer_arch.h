//
// Created by Oswaldo on 15/11/2024.
//

#ifndef RECORRER_ARCH_H
#define RECORRER_ARCH_H
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

namespace recorrer {

class recorrer_arch {

// Función para eliminar espacios en blanco iniciales y finales
static string Trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == string::npos) return ""; // Línea vacía o solo espacios/tabulaciones
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

// Función para eliminar comentarios de una línea (//)
static string EliminarComentariosLinea(const string& line) {
    size_t pos = line.find("//");
    if (pos != string::npos) {
        return line.substr(0, pos); // Devolver contenido antes de "//"
    }
    return line; // Sin cambios si no hay comentarios
}

// Función para eliminar comentarios de bloque (/*...*/)
static string EliminarComentariosBloque(string& line, bool& dentroDeComentario) {
    size_t inicio = line.find("/*");
    size_t fin = line.find("*/");

    if (dentroDeComentario) {
        if (fin != string::npos) {
            dentroDeComentario = false; // Final del comentario bloque
            return line.substr(fin + 2); // Retornar contenido después del bloque
        }
        return ""; // Línea completa dentro del comentario bloque
    }

    if (inicio != string::npos) {
        dentroDeComentario = true; // Inicio de un comentario bloque
        if (fin != string::npos) {
            dentroDeComentario = false; // Bloque termina en la misma línea
            return line.substr(0, inicio) + line.substr(fin + 2);
        }
        return line.substr(0, inicio); // Retornar contenido antes del bloque
    }

    return line; // Sin cambios si no hay comentarios
}

    // Función para eliminar todos los espacios dentro de una línea
static string EliminarEspaciosEnLinea(const string& line) {
    string resultado;
    for (char c : line) {
        if (!isspace(c)) { // Ignorar cualquier tipo de espacio
            resultado += c;
        }
    }
    return resultado;
}



// Función para preprocesar un archivo
static void PreprocesarArchivo(const string& inputFileName, const string& outputFileName) {
    // Abrir archivo de entrada
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << inputFileName << endl;
        return;
    }

    // Archivo de salida
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: No se pudo crear el archivo " << outputFileName << endl;
        inputFile.close();
        return;
    }

    string line;
    bool dentroDeComentario = false;

    while (getline(inputFile, line)) {
        // Eliminar comentarios de bloque
        line = EliminarComentariosBloque(line, dentroDeComentario);
        if (dentroDeComentario) continue; // Si aún estamos dentro de un bloque, ignorar línea

        // Eliminar comentarios de una línea
        line = EliminarComentariosLinea(line);

        // Eliminar espacios iniciales y finales
        line = Trim(line);

        // Ignorar líneas vacías
        if (line.empty()) continue;

        // Escribir la línea procesada al archivo de salida
        outputFile << line << '\n';
    }

    // Cerrar archivos
    inputFile.close();
    outputFile.close();

    cout << "El archivo ha sido procesado y guardado en: " << outputFileName << endl;
}


// Función para recorrer el archivo procesado e imprimir sus caracteres
public:
static void RecorrerArchivo(const string& inputFileName, const string& processedFileName) {
    // Preprocesar el archivo
    PreprocesarArchivo(inputFileName, processedFileName);

    // Abrir archivo preprocesado
    ifstream inputFile(processedFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: No se pudo abrir el archivo procesado " << processedFileName << endl;
        return;
    }

    char character;
    cout << "Contenido del archivo preprocesado:\n";

    // Leer carácter por carácter
    while (inputFile.get(character)) {
        cout << character; // Imprimir el carácter leído
    }

    // Cerrar archivo
    inputFile.close();
    cout << "\nArchivo procesado y recorrido exitosamente." << endl;
}

/*int main() {
    string inputFileName = "entrada.txt"; // Archivo original
    string processedFileName = "salida.txt"; // Archivo preprocesado

    RecorrerArchivo(inputFileName, processedFileName);

    return 0;
}*/


};

} // recorrer

#endif //RECORRER_ARCH_H
