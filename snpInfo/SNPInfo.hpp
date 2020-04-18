//
//  SNPInfo.hpp
//  snpInfo
//
//  Created by Gang Peng on 4/18/20.
//  Copyright © 2020 Gang Peng. All rights reserved.
//

#ifndef SNPInfo_hpp
#define SNPInfo_hpp

#include <stdio.h>
#include <string>

class SNPInfo{
private:
    int rs;
    std::string info;
    
public:
    SNPInfo(int rs, std::string info);
    
    int getRS() const {return rs;}
    std::string getInfo() const {return info;} 
    
    bool setRS(int rs);
    bool setInfo(std::string info);
    
    bool operator < (const SNPInfo & other) const;
};

#endif /* SNPInfo_hpp */
