
#include<iostream>
#include "first.h"
#include "second.h"
#include "third.h"

using namespace std; 

int main(){
    string words[]={"Tere", "Sam", "Ter",  "Juli", "Esteban ", "JuAn Fer", "Gabo", "Sebastian", 
    "Angelica", "alejo", "esteban ", "sergio ", "   MARIO   ", "  WeN  ", "Pipe"};

    int n = size(words); 
    string name  = "sa";

    firstImplementation list1 = firstImplementation(); 
    secondImplementation list2 = secondImplementation(); 
    thirdImplementation list3 = thirdImplementation(); 


    for(int i = 0; i < n; i++){
        list1.add(words[i]); 
    }

    for(int i = 0; i < n; i++){
        list2.add(words[i]); 
    }

    for(int i = 0; i < n; i++){
        list3.add(words[i]); 
    }

    list1.print(); 
    cout<< endl; 
    cout<< endl; 
    list2.print(); 
    cout<< endl; 
    cout<< endl;
    list3.print(); 


    cout << "exist: " << list3.check(name) << endl; 
}