
#ifndef Firts
#define Firts


#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std; 
/**
 * Clase que tiene como atributo una lista doblemente enlazada simple. 
 * Contiene dos métodos uno que añade(add) cadenas y otro que verifica(check) si la cadena ya fue añadida. 
 * Se tomarán los espacios como caracteres válidos, a menos que se encuentren en los extremos de la cedena. 
*/
class firstImplementation{
private:
    list<string> stringsList;
public:
    void add(string word);
    bool check(string& word);
    void convertToUpperCase(string& input); 
    void trimSpaces(string& input); 
    void print(); 

};
/** 
 * Recibe una cadena de caracteres a guardar en la lista de la clase. 
 * Método verifica si la cadena recibida tiene espacios no significativos al comienzo o al final de la cadena
 * Cambia a mayúsculas todos los caracteres. 
 * Verifica si la palabra ya fue guardada, sino la guarda. 
 * La función tiene una complejidad total lineal de O(m*n) donde m es el tamaño de la palabra y n el tamaño de la lista. 
*/
void firstImplementation::add(string word){
    if(check(word) == false){            // O(m*n)
        stringsList.push_back(word);    // O(1)
    }
}

/**
 * Recibe una cadena de caracteres que verifica si existe en la lista de la clase
 * retorna true si existe y false en caso contrario. 
 * Complejidad lineal O(m*n)
*/
bool firstImplementation::check(string& word){
    trimSpaces(word);                      // O(m)
    convertToUpperCase(word);             // O(m)
    for (const auto& element : stringsList) {      //O(n)
        if (element == word) {                    //O(m)
            return true; 
        }
    }
    return false; 
}

/**
 * Recibe una cadena de caracteres y la cambia sus caracteres a mayúsculas. 
*/
void firstImplementation::convertToUpperCase(string& input) {
    for (char& c : input) {
        c = toupper(c);
    }
}

/**
 * Recibe una cadena de caracteres y la cambia sus caracteres a mayúsculas. 
*/
void firstImplementation::trimSpaces(string& input){

    auto start = input.find_first_not_of(" \t\n\r\f\v");

    if (start != string::npos) {
        auto end = input.find_last_not_of(" \t\n\r\f\v");
        input = input.substr(start, end - start + 1);
    } else {
        input.clear();
    }
}

/**
 * Imprime la lista de cadenas. 
*/
void firstImplementation::print(){
    for (auto& element : stringsList) {
            cout << element << " - ";
        }
    cout << endl; 
}

#endif