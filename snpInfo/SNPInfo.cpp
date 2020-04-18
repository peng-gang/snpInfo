//
//  SNPInfo.cpp
//  snpInfo
//
//  Created by Gang Peng on 4/18/20.
//  Copyright © 2020 Gang Peng. All rights reserved.
//

#include "SNPInfo.hpp"

using namespace std;

SNPInfo::SNPInfo(int rs, string info){
    this->rs = rs;
    this->info = info;
}

bool SNPInfo::setRS(int r){
    this->rs = r;
    return true;
}

bool SNPInfo::setInfo(string i){
    this->info = i;
    return true;
}

bool SNPInfo::operator<(const SNPInfo & other) const {
    return (rs < other.rs);
}
