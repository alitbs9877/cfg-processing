//
// Created by alitbs on 1/29/19.
//

#ifndef CFG_CFG_H
#define CFG_CFG_H
#include <vector>

#include <iostream>



class cfg {
public:
    char S;
    std::vector < std::pair<char,std::vector<std::string > >  >Lambda;
    std::vector < char > V;
    std::vector<char > A;
    cfg(

            ){

    };

    void setA(std::vector<char> APrim){
        A=APrim;
    };
    void setV(std::vector<char> VPrim){
        V=VPrim;
    };
    void setS(char SPrim){
        S=SPrim;
    };
    void setLambda(std::vector < std::pair<char,std::vector<std::string > >  >LambdaPrim){
        Lambda=LambdaPrim;


    };



};

#endif //CFG_CFG_H
