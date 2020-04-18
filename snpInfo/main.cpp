//
//  main.cpp
//  snpInfo
//
//  Created by Gang Peng on 4/18/20.
//  Copyright © 2020 Gang Peng. All rights reserved.
//

#include <iostream>
#include <set>

#include "SNPInfo.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    if(argc !=3){
        cout<<"Order SNP according to rs number with information from a VCF file"<<endl;
        cout<<"Usage:"<<endl;
        cout<<"snpInfo vcfFile outdir"<<endl;
    }
    
    
    set<SNPInfo> test;
    
    test.insert(SNPInfo(1, "aa"));
    test.insert(SNPInfo(10, "bb"));
    test.insert(SNPInfo(7, "cc"));
    test.insert(SNPInfo(1, "dd"));
    
    for(set<SNPInfo>::iterator it = test.begin(); it != test.end(); it++){
        cout<<(*it).getRS()<<'\t'<<(*it).getInfo()<<endl;
    }
    return 0;
}
