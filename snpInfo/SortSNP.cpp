//
//  SortSNP.cpp
//  snpInfo
//
//  Created by Gang Peng on 4/18/20.
//  Copyright © 2020 Gang Peng. All rights reserved.
//

#include "SortSNP.hpp"
#include <iostream>
#include <fstream>
#include <set>

#include "normal.h"
#include "SNPInfo.hpp"

using namespace std;

string getInfo(string infoAll){
    size_t st = infoAll.find("GENEINFO");
    string gene = "";
    if(st != string::npos){
        size_t ed = infoAll.find(":", st);
        gene = infoAll.substr(st+9, ed - st - 9);
    }
    string rlt = gene + "\t";
    
    bool flag = false;
    if(infoAll.find("NSF") != string::npos){
        rlt = rlt + "NSF";
        flag = true;
    }
    
    if(infoAll.find("NSM") != string::npos){
        if(flag){
            rlt = rlt + ";" + "NSM";
        } else {
            rlt = rlt + "NSM";
        }
        flag = true;
        
    }
    
    if(infoAll.find("NSN") != string::npos){
        if(flag){
            rlt = rlt + ";" + "NSN";
        } else {
            rlt = rlt + "NSN";
        }
    }
    
    return rlt;
}

bool sortSNP(const char* vcfFile, const char* outDir){
    ifstream fin(vcfFile);
    if(!fin.is_open()){
        cerr << "Cannot open file " << vcfFile << endl;
        return false;
    }
    
    ofstream fout;
    string strOutDir(outDir);
    
    set<SNPInfo> snpInfo;
    
    string currentChr = "";
    while(!fin.eof()){
        string fline;
        getline(fin, fline);
        if(fline[0] == '#'){
            continue;
        }
        
        if(fline.size() < 2){
            // process the last record
            cout<<"Output "<<currentChr<<endl;
            cout<<"Total SNP: " << snpInfo.size() << endl;
            fout.open((strOutDir +  currentChr + ".txt").c_str()); //, std::ofstream::out | std::ofstream::app);
            fout<<"rs\tpos\tgene\tinfo"<<endl;
            for(set<SNPInfo>::iterator it = snpInfo.begin(); it != snpInfo.end(); it++){
                fout<<(*it).getRS()<<"\t"<<(*it).getInfo()<<endl;
            }
            fout.close();
            fout.clear();
            break;
        }
        
        vector<string> vsline = split(fline, "\t");
        if(currentChr != vsline[0]){
            if(currentChr != ""){
                cout<<"Output "<<currentChr<<endl;
                cout<<"Total SNP: " << snpInfo.size() << endl;
                fout.open((strOutDir +  currentChr + ".txt").c_str()); //, std::ofstream::out | std::ofstream::app);
                fout<<"rs\tpos\tgene\tinfo"<<endl;
                for(set<SNPInfo>::iterator it = snpInfo.begin(); it != snpInfo.end(); it++){
                    fout<<(*it).getRS()<<"\t"<<(*it).getInfo()<<endl;
                }
                fout.close();
                fout.clear();
                snpInfo.clear();
            }
            currentChr = vsline[0];
        }
        
        int rsTmp = stoi(vsline[2].substr(2));
        string info = vsline[1] + "\t" + getInfo(vsline[7]);
        snpInfo.insert(SNPInfo(rsTmp, info));
    }
    return  true;
}
