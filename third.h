
#ifndef Third
#define Third

#include <iostream>
#include <string>
#include<unordered_map>



using namespace std; 

/**
 * Clase que representa un nodo en la implementación de Trie.
 * Cada nodo contiene un mapa no ordenado (unordered_map) que asocia caracteres con nodos hijos.
 * El booleano isEndOfWord indica si este nodo marca el final de una palabra.
 */
class Node {
public:
    unordered_map<char, Node*> children;
    bool isEndOfWord;

    Node() : isEndOfWord(false) {}
};

/**
 * Clase que implementa la funcionalidad utilizando un Trie (árbol Trie).
 * Contiene dos métodos uno que añade(add) cadenas y otro que verifica(check) si la cadena ya fue añadida. 
 * Se tomarán los espacios como caracteres válidos, a menos que se encuentren en los extremos de la cedena. 
 */
class thirdImplementation{
    private:
    Node* root;

public:
    thirdImplementation() : root(new Node()) { }
    void add(string word);
    bool check(string& word);
    void convertToUpperCase(string& input); 
    void trimSpaces(string& input); 
    void print(); 
    
};
/**
 * Método para agregar una palabra al Trie.
 * Verifica si la palabra recibida ya existe en el Trie, sino existe la agrega.
 * crea un nuevo Nodo raiz(root), recorre caracter por caracter la palabra, 
 * buscando cada caracter en el Trie.Si ya existe continúa sino lo crea. 
 * Tiene una complejidad de O(m)
*/
void thirdImplementation::add(string word) {
        if(!check(word)){              //O(m)
            Node* current = root;     //O(1)
            for (char c : word) {    //O(m)
                if (current->children.find(c) == current->children.end()) {
                    current->children[c] = new Node();          //O(1)
                }
                current = current->children[c];                //O(1)
            }
            current->isEndOfWord = true;
        }
        
    }

/**
 *  Método para verificar si una palabra ya existe en el Trie.
 *  Elimina los espacios no significativos del comienzo y el final 
 *  Cambia la cadena de caracteres a mayúsculas 
 *  y recorre caracter por caracter en Trie para encontrar la palabra. 
 *  La complejidad es de O(m). siendo m el tamaño del a letra 
*/
bool thirdImplementation::check(string& word) {
        Node* current = root;
        trimSpaces(word);               //O(m)               
        convertToUpperCase(word);      //O(m)   
        for (char c : word) {         //O(m)
            if (current->children.find(c) == current->children.end()) {  //O(1)
                return false;
            }
            current = current->children[c];                              //O(1)
        }
        return current->isEndOfWord;
    }

/**
 * Recibe una cadena de caracteres y la cambia sus caracteres a mayúsculas. 
*/
void thirdImplementation::convertToUpperCase(string& input) {
    for (char& c : input) {
        c = toupper(c);
    }
}

/**
 * Evalúa si existen espacios no significativos al comienzo y final de la cadena. 
*/
void thirdImplementation::trimSpaces(string& input){

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
void printTrie(Node* node, string currentWord) {
        if (node->isEndOfWord) {
            cout << currentWord << " - ";
        }

        for (const auto& child : node->children) {
            printTrie(child.second, currentWord + child.first);
        }
    }

void thirdImplementation::print() {
        printTrie(root, " ");
    }

#endif