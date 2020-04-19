//
//  main.cpp
//  snpInfo
//
//  Created by Gang Peng on 4/18/20.
//  Copyright © 2020 Gang Peng. All rights reserved.
//

#include <iostream>

#include "SortSNP.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    if(argc !=3){
        cout<<"Order SNP according to rs number with information from a VCF file"<<endl;
        cout<<"Usage:"<<endl;
        cout<<"snpInfo vcfFile outdir"<<endl;
    }
    
    if(!sortSNP(argv[1], argv[2])){
        cerr << "Error during SNP sorting!"<<endl;
        return 1;
    }
    return 0;
}
