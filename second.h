#ifndef Second
#define Second


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std; 

/**
 * Clase que tiene como atributo una lista doblemente enlazada ordenada simple. 
 * Contiene dos métodos uno que añade(add) cadenas y otro que verifica(check) si la cadena ya fue añadida. 
 * Se tomarán los espacios como caracteres válidos, a menos que se encuentren en los extremos de la cedena. 
*/
class secondImplementation{
private: 
    vector<string> stringList; 
public: 
    void add(string word);
    bool check(string& word);
    void convertToUpperCase(string& input); 
    void trimSpaces(string& input); 
    void print(); 
}; 

/** 
 * Recibe una cadena de caracteres a guardar en la lista de la clase.  
 * Busca por medio de búsqueda binaria si la palabra ya existe 
 * o si no ha sido guardada devuelve la posición en la que debería ir para mantener el orden
 * La función tiene una complejidad total de O(logn) donde m es el tamaño de la palabra y n el tamaño de la lista. 
*/
void secondImplementation::add(string word){    
    if (check(word)) {   //O(logn)
        auto it = lower_bound(stringList.begin(), stringList.end(), word); //  O(mlogn) búsqueda binaria en el rango first last, devuelve un iterador al primer elemento mayor que value 
        // Inserta solo si la cadena no existe
        stringList.insert(it, word); //O(n)
    }
} 

/**
 * Método verifica si la cadena recibida tiene espacios no significativos al comienzo o al final de la cadena
 * Cambia a mayúsculas todos los caracteres.
 * Crea un iterador en la posición donde debería estar la cadena que recibe, si ya existe
 * retorna true si existe y false en caso contrario. 
 * La complejidad de la función es logaritmica O(logn)
*/
bool secondImplementation::check(string& word){
    trimSpaces(word);       //O(m)               
    convertToUpperCase(word);     //O(m)     
    auto it = lower_bound(stringList.begin(), stringList.end(), word); //O(mlogn)
    // Verificar si se encontró la cadena
    return it == stringList.end() || *it != word; //O(1) 
}

/**
 * Recibe una cadena de caracteres y la cambia sus caracteres a mayúsculas. 
*/
void secondImplementation::convertToUpperCase(string& input) {
    for (char& c : input) {
        c = toupper(c);
    }
}

/**
 * Evalúa si existen espacios no significativos al comienzo y final de la cadena. 
*/
void secondImplementation::trimSpaces(string& input){

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
void secondImplementation::print(){
    for (auto& element : stringList) {
            cout << element << " - ";
        }
    cout << endl; 
}

#endif