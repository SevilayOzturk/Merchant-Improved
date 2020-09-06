//
//  merchant.cpp
//  asa
//
//  Created by Sevilay Ozturk on 3/4/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//

#include "merchant.h"

Merchant::Merchant(){
    numOfantq = 0;
    revenue = 0;
    quantities = nullptr;
    antiques = nullptr;
}

Merchant::Merchant(float newRevenue){
    numOfantq = 0;
    revenue = newRevenue;
    quantities = nullptr;
    antiques = nullptr;
}

Merchant::~Merchant(){
    delete[] antiques;
    delete[] quantities;
}

Merchant& Merchant::operator = (const Merchant& copy){
    if(this == &copy)
        return* this;
    revenue = copy.revenue;
    numOfantq = copy.numOfantq;
    delete[] antiques;
    delete[] quantities;
    antiques = new Antique[numOfantq];
    quantities = new int[numOfantq];
    
    for(int i=0; i<numOfantq ; i++){
        quantities[i] = copy.quantities[i];
        antiques[i] = copy.antiques[i];
    }
    return* this;
}

bool Merchant::operator == (const Merchant &copy){
    if(revenue == copy.revenue && numOfantq == copy.numOfantq){
        for(int x=0; x<numOfantq; x++)
            if(quantities[x] != copy.quantities[x])
                return false;
            
        for(int i=0; i<numOfantq; i++)
            if(!(antiques[i] == copy.antiques[i]))
               return false;
        return true;
    }
    return false;
            
}

Merchant::Merchant(const Merchant &copy){
       revenue = copy.revenue;
       numOfantq = copy.numOfantq;
       antiques = new Antique[numOfantq];
       quantities = new int[numOfantq];
       
       for(int i=0; i<numOfantq ; i++){
           quantities[i] = copy.quantities[i];
           antiques[i] = copy.antiques[i];
       }
   
}

void Merchant::addAntique(Antique newAntique, int quantitiy){
    Antique* temporary = new Antique[numOfantq + 1];
    int* temporary2 = new int[numOfantq + 1];
    for (int i = 0; i < numOfantq; i++) {
        temporary[i] = Antique(antiques[i]);
        temporary2[i] = quantities[i];
    }
    temporary[numOfantq] = Antique(newAntique);
    temporary2[numOfantq] = quantitiy;
    delete[] antiques;
    antiques = temporary;
    delete[] quantities;
    quantities = temporary2;
    numOfantq++;
    
}
//void Merchant::printMenu(){
//    cout << fixed << setprecision(2);
//    for(int i =0; i < 10; i++){
//        cout << i +1 << ") " << antiques[i].getName() << ": $" << antiques[i].getPrice() << endl;
//    }
//}
//
//void Merchant::selectAntique(float &budget) {
//    ofstream ofs("log2.txt", ios_base::app);
//
//    cout << "Enter item number:" <<endl;
//    int index;
//    cin >> index;
//
//    if(quantities[index-1] == 0)
//        cout << "Sorry! Antique is out of stock." << endl;
//    else if(antiques[index-1].getPrice() > budget)
//        cout << "Insufficient funds." << endl;
//    else{
//        revenue += antiques[index-1].getPrice();
//        budget -= antiques[index-1].getPrice();
//        cout << "Enjoy your " << antiques[index-1].getName() << endl;
//        ofs << fixed;
//        ofs << setprecision(2);
//        ofs << "Sold " << antiques[index-1].getName() << " for $" <<antiques[index-1].getPrice() << endl;
//    ofs.close();
//    }
//}
//
//void Merchant::leave(float budget){
//    ofstream ofs("log2.txt", ios_base::app);
//    ofs <<fixed;
//    ofs<< setprecision(2);
//    ofs << "Total revenue: $" << revenue << endl;
//    ofs << "Remaining budget: $" << budget;
//    ofs.close();
//    }
//
//
//Insufficient funds.
//Otherwise, if the sale was successful, decrease the user's budget to reflect the sale, add to revenue, and reduce the quantity of the item by one. Print the following to standard output:
//
//Enjoy your <Antique.name>!
//And append to a text file called "log2.txt" that acts as an itemized receipt like following:
//
//Sold <Antique.name> for $<price.2digits>
//leave: this function terminates the program, and appends the budget and revenue to a text file called "log2.txt" at the end:
//Total revenue: $<revenue.2digits>
//Remaining budget: $<budget.2digits>



//Enjoy your <Antique.name>!
//And append to a text file called "log2.txt" that acts as an itemized receipt like following:
//
//Sold <Antique.name> for $<price.2digits>
//leave: this function terminates the program, and appends the budget and revenue to a text file called "log2.txt" at the end:
//Total revenue: $<revenue.2digits>
//Remaining budget: $<budget.2digits>
//Merchant::Merchant(Antique nAntiques[], int nQuantities[]){
//    revenue = 0;
//    hasChanged = false;
//    for (int i =0; i < 10; i++) {
//        antiques[i].setName(nAntiques[i].getName());
//        antiques[i].setPrice(nAntiques[i].getPrice());
//        quantities[i] = nQuantities[i];
//    }
//}
//void Merchant::haggle() {
//    if(!hasChanged) {
//        for(int i = 0; i < 10; i++) {
//            float bdiscount = antiques[i].getPrice();
//            antiques[i].setPrice(bdiscount*0.90);
//        }
//
//        hasChanged= true;
//        cout<< "You have successfully haggled and everything is 10% off." << endl;
//    }
//    else{
//        cout << "Sorry, you have already haggled." << endl;
//        return;
//    }
//}
