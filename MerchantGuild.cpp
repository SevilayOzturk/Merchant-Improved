//
//  MerchantGuild.cpp
//  asa
//
//  Created by Sevilay Ozturk on 3/24/20.
//  Copyright © 2020 Sevilay Ozturk. All rights reserved.
//
#include "MerchantGuild.h"

    MerchantGuild::MerchantGuild(int size){
        
        numMem = 0;
        if(size<1)
            guildSize = 10;
        else
            guildSize = size;
        members = new Merchant[guildSize];
        
    }
   
    MerchantGuild::MerchantGuild(const MerchantGuild &copy){
        guildSize = copy.guildSize;
        numMem = copy.numMem;
        members = new Merchant[guildSize];
  
        for(int i=0; i<numMem ; i++){
            members[i] = copy.members[i];
        }
    }
    MerchantGuild::~MerchantGuild(){
        delete[] members;
    }
        
    MerchantGuild& MerchantGuild ::operator=(const MerchantGuild &other){
        if(this == &other)
            return* this;
        guildSize = other.guildSize;
        numMem = other.numMem;
        delete[] members;
        members = new Merchant[guildSize];
        
        for(int i=0; i<numMem ; i++){
           members[i] = other.members[i];

        }
        return* this;
    }

    void MerchantGuild :: addMember(Merchant newM){
        if(numMem< guildSize){
            members[numMem] = newM;
            numMem += 1;
        }
        else{
            cout<<"Guild is full" <<endl;
        }
    }

    Merchant* MerchantGuild :: getMembers(){
        return members;
    }
