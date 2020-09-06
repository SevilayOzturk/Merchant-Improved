//
//  merchant.hpp
//  asa
//
//  Created by Sevilay Ozturk on 3/4/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#ifndef merchant_h
#define merchant_h

#include "antique.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Merchant{
private:
    Antique* antiques;
    int* quantities;
    float revenue;
    int numOfantq;
public:
    Merchant();
    Merchant(float newRevenue);
    ~Merchant();
    Merchant& operator= (const Merchant &copy);
    bool operator == (const Merchant &copy);
    Merchant(const Merchant &copy);
    void addAntique(Antique newAntique, int quantity);
//    void haggle();
//    void printMenu();
//    void selectAntique(float &budget);
//    void leave(float budget);
    
};





#endif /* merchant_hpp */
