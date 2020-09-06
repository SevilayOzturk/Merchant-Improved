//
//  antique.cpp
//  asa
//
//  Created by Sevilay Ozturk on 3/4/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#include "antique.h"


Antique::Antique() {
    name = "";
    price = 0;
};
// Format:
// returnType classname::functionName()
string Antique::getName(){
    return name;
}

void Antique::setName(string nName){
    name = nName;
}

float Antique::getPrice(){
    return price;
}

void Antique::setPrice(float nPrice){
    price = nPrice;
}

string Antique::toString() {
    ostringstream oss;
    oss<<fixed;
    oss<<setprecision(2);
    oss<< price;
    
    return name + ": $"+ oss.str();
}
bool Antique:: operator ==(const Antique& comparision){
    if(name == comparision.name && price == comparision.price)
        return true;
    return false;
}

Antique Antique :: operator +(const Antique& together){
    Antique result;
    result.name = name + " and " + together.name;
    result.price = price + together.price;
    return result;
}

