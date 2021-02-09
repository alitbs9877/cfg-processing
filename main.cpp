#include <iostream>
#include <vector>


#include "cfg.h"

cfg*   init(){
    cfg *cfg1=new cfg();
    char S='S';
    std::vector < std::pair<char,std::vector<std::string > >  >Lambda;
    std::vector < char > V;
    std::vector<char > A;
    A.push_back('a');

    A.push_back('b');
    V.push_back('S');
    V.push_back('B');

    V.push_back('W');
    V.push_back('A');
    std::vector<std::string> n2;
    std::string s1="";
//    n2.push_back(s1);
    s1="a";
    n2.push_back(s1);

    s1="W";

    n2.push_back(s1);

    std::pair<char,std::vector<std::string > >  m;
    m.first='A';
    m.second=n2;
    Lambda.push_back(m);

    n2.clear();
    s1="";
    n2.push_back(s1);
    m.first='W';
    m.second=n2;

    Lambda.push_back(m);
    n2.clear();
    s1="";
    s1="b";
    n2.push_back(s1);
    m.first='B';
    m.second=n2;

    Lambda.push_back(m);
    n2.clear();
    s1="A";
    n2.push_back(s1);
    s1="BaAA";
    n2.push_back(s1);

    s1="BWB";
    n2.push_back(s1);
    m.first=S;

    m.second=n2;

    Lambda.push_back(m);
    cfg1->setA(A);
    cfg1->setV(V);
    cfg1->setS(S);
    cfg1->setLambda(Lambda);



    return cfg1;
}

void print ( cfg *cfg1){

    std::cout << "its S="<< cfg1->S<< std::endl;

    std::cout << "its A =";
    for (int i = 0; i <cfg1->A.size() ; i++) {

        std::cout << cfg1->A.at(i) ;
    }

    std::cout <<  std::endl;

    std::cout << "its V =";
    for (int i = 0; i <cfg1->V.size() ; i++) {

        std::cout << cfg1->V.at(i) ;
    }

    std::cout <<  std::endl;


    std::cout << "its Lambdas rules =";
    for (int i = 0; i <cfg1->Lambda.size() ; i++) {

        std::cout <<  cfg1->Lambda.at(i).first<< "-----> ";
        for (int j = 0; j < cfg1->Lambda.at(i).second.size(); j++) {

            std::cout <<  cfg1->Lambda.at(i).second.at(j)<< " / ";


        }

        std::cout <<  std::endl;

    }

    std::cout <<  std::endl;





}
void recursive(char current ,std::string newStrin ,std::vector< std::string > *newVec,std::vector<int > CurrentCharInString){
    newVec->push_back(newStrin);
//
//    std::cout <<" **********its string   "<< newStrin<<  std::endl;
    if(CurrentCharInString.size()==0){
        return;
    }
    for (int i = 0; i < CurrentCharInString.size(); i++) {
        std::vector<int > CurrentCharInString2;

//        std::cout <<"w   "<< CurrentCharInString.at(i)<<newStrin <<  std::endl;
        for (int j = 0; j < CurrentCharInString.size(); j++) {
            if(i==j){
                continue;
            }
            if(j<i){
                CurrentCharInString2.push_back(CurrentCharInString.at(j));
            }else{
                CurrentCharInString2.push_back(CurrentCharInString.at(j)-1);
            }
        }

        unsigned long find_number =CurrentCharInString.at(i);
        std::string newString =newStrin;

//        std::cout <<find_number<<  std::endl;
        newString.erase(newString.begin() + find_number);

        std::cout <<newString<<  std::endl;
        recursive(current,newString,newVec,CurrentCharInString2);


    }
}

void search(char current,std::vector < std::pair<char,std::vector<std::string > >  > *v , int  condition){
    for ( int i =0 ; i <v->size(); i++){
        if(v->at(i).first==current){
            continue;
        }
        for ( int j = 0 ;j < v->at(i).second.size()  ; j++){
            if(condition==0) {
                unsigned long find_number = v->at(i).second.at(j).find(current);
                if (find_number >= v->at(i).second.at(j).size()) {
                    continue;
                }
                // TODO find out how to work with pointers in inner vector
                std::string newString = v->at(i).second.at(j);
                newString.erase(newString.begin() + find_number);

                v->at(i).second.erase(v->at(i).second.begin() + j);
                v->at(i).second.push_back(newString);
            }if(condition==1){
                std::string newString = v->at(i).second.at(j);

                 unsigned long find_number = 1;
                int numOfCurrentCharInStrin=0;
                std::vector<int > CurrentCharInString;
                bool conditions=false;
                while (!conditions){

                    find_number = newString.find(current);

                    if(find_number >= v->at(i).second.at(j).size()){

                        conditions=true;
                        break;
                    }

                    //std::cout <<v->at(i).second.at(j)<<find_number<<current<<  std::endl;
                    CurrentCharInString.push_back((int)find_number+numOfCurrentCharInStrin);
                    newString.erase(newString.begin() + find_number);
                    numOfCurrentCharInStrin++;
                }


                std::vector< std::string > newVec;
                for (int k = 0; k <CurrentCharInString.size() ; ++k) {

//                    std::cout <<v->at(i).second.at(j)<<k<<" its find   "<<CurrentCharInString.at(k)<< " its "<<current<<  std::endl;

                }
                if(CurrentCharInString.size()>0) {
                    recursive(current, v->at(i).second.at(j), &newVec, CurrentCharInString);

//                    std::cout <<" **********its string   "<< v->at(i).second.at(j)<<  std::endl;
                }

//                std::cout <<" //////////// "<<  std::endl;
                for (int l = 0; l <newVec.size() ; ++l) {
//                    std::cout <<" its string   "<< newVec.at(l)<<  std::endl;

                }

//TODO if there are the same Like B(after WB)
// refactoring

//
                for (int k =1 ; k <newVec.size() ; k++) {

//                    std::cout <<" its string  as the  "<< newVec.at(k)<<  std::endl;
                    v->at(i).second.push_back(newVec.at(k));

                }
            }


        }
    }



    // TODO removing abselon 0  from B

}
cfg  convert(cfg *cfg1){

    cfg *cfg12 = new cfg();
    cfg12->setA(cfg1->A);
    cfg12->setLambda(cfg1->Lambda);
    cfg12->setS(cfg1->S);
    cfg12->setV(cfg1->V);

    char S=cfg12->S;
    std::vector < std::pair<char,std::vector<std::string > >  >Lambda=cfg12->Lambda;
    std::vector < char > V=cfg12->V;
    std::vector<char > A=cfg1->A;


    //---------------------
    // adding s0
    // --------------------

    bool condition = false;
    int q = 150 ;
    char S0;
    S0=(char)q;
    while ( !condition) {
        //TODO convert q to string
        S0=(char)q;

        for ( int i  =0 ; i < cfg12->V.size() ; i++){
            if(cfg12->V[i]==S0){
                condition=false;

                break;
            }
            if(i == cfg12->V.size()-1){
                condition=true;
            }

        }
        q++;
    }


    std::vector<std::string> n2;
    std::string s1="";
    n2.clear();
    s1.operator+=(S0);
    std::vector <std::string> myStrings;
    int we;
    for (int j = 0; j <Lambda.size() ; j++) {
        if(Lambda.at(j).first==S){
            myStrings=Lambda.at(j).second;
            we=j;
        }

    }
    n2.push_back(s1);
    std::pair<char,std::vector<std::string > >  m;

    m.first=S;
    m.second=n2;
    Lambda.erase(Lambda.begin()+we);
    Lambda.push_back(m);


    m.first=S0;
    V.push_back(S0);
    m.second=myStrings;
    Lambda.push_back(m);


    // TODO try to put them in function and working with pointer of Class


    for ( int i =0 ; i<Lambda.size() ; i++) {
        char current = Lambda[i].first;

        for (int j = 0; j < Lambda.at(i).second.size(); ++j) {

        }
    }


    // --------------------
    //convert V's (changable) NULL in lambda's

    // --------------------
    for ( int i =0 ; i<Lambda.size() ; i++){
        char current=Lambda[i].first;


        for (int j = 0; j < Lambda.at(i).second.size(); ++j) {

//            std::cout << "its Laaaaaaaes =" << Lambda.at(i).second.at(j) << " :: "<< current << std::endl;
        }
//
        if (Lambda.at(i).second.size() ==1  && Lambda.at(i).second.at(0)=="" ){
            //TODO delete B from All

            search(current,&Lambda,0);


            //**************

//            std::cout << "its Lambdas rules =" << current<< std::endl;
            //TODO if there are the same Like B(after WB) or nothing

            int a;
            for (int qw = 0; qw <V.size() ; qw++) {
                if (current==V.at(qw)){
                    a=qw;
                }

            }

//            std::cout << "its Lambdas rules =" << current<<V.at(a) << std::endl;
            V.erase(V.begin() +a);

             Lambda.erase(Lambda.begin()+i);
             i--;

//TODO if there are the same Like B(after WB)
// refactoring


            continue;

         }
        int b=-5;
        for ( int j =0 ; j <Lambda.at(i).second.size() ; j++){
            if(Lambda.at(i).second.at(j)=="" ){
                b=j;


                search(current,&Lambda,1);


                break;
            }

        }
        if(b>-1){

            Lambda.at(i).second.erase(Lambda.at(i).second.begin()+ b);
        }




    }
    for (int i = 0; i <Lambda.size() ; i++) {
        for (int k = 0; k < Lambda.at(i).second.size(); k++) {
            for (int j = k+1; j < Lambda.at(i).second.size();j++) {
                if(Lambda.at(i).second.at(k)==Lambda.at(i).second.at(j)  ){


//            std::cout << "its Lambdas rules =" << Lambda.at(i).first<< "@"<<Lambda.at(i).second.at(k)<<"::"<<Lambda.at(i).second.at(j)<< std::endl;
                    Lambda.at(i).second.erase(Lambda.at(i).second.begin()+j);
                }


            }


        }

    }




    // --------------------
    //convert A's (terminals) in lambda's
    // --------------------

    for (int k = 0; k < Lambda.size(); k++) {
        for (int i = 0; i < Lambda.at(k ).second.size(); i++) {
            std::string currentString = Lambda.at(k).second.at(i);

            std::vector<std::pair<int, int> > myVec;
            if(currentString.size()>1 ) {

                unsigned long size = currentString.size();
                for (int j = 0; j < A.size(); j++) {
                    unsigned long find = currentString.find(A.at(j));
                    if (find < size) {
                        //TODO need to exploide
                     //     std::cout << "its Lambdas rules =" << Lambda.at(k).first<< "@"<<Lambda.at(k).second.at(i)<<"::"<<A.at(j)<< std::endl;
                        std::pair<int, unsigned long> pair1;
                        pair1.first = j;
                        pair1.second = find;
                        myVec.push_back(pair1);
                    }

                }
            }

            std::vector<std::pair<char, unsigned  long> > myNewVec;
            std::string nString=currentString;
            for (int l = 0; l <myVec.size() ; l++) {
                bool conditions =false;
                for (int j = 0; j <Lambda.size() ; j++) {
                    std::string string1 ="";
                    string1.operator+=(A.at(myVec.at(l).first));
                    if (Lambda.at(j).second.size()==1 && Lambda.at(j).second.at(0)==string1 ){

//                        std::cout << "its Lambdas rules =" <<  Lambda.at(j).first<< ":"<<string1<< "@@" << nString<<std::endl;

                        std::pair<char, unsigned long> pair1;
                        pair1.first = Lambda.at(j).first;
                        pair1.second =myVec.at(l).second ;
                        myNewVec.push_back(pair1);
                        break;
                    }
                    if(j==Lambda.size()-1){
                        conditions=true;
                        break;
                    }


                }
                if(conditions){


                    condition = false;
                    q = 200 ;
                    char V0;

                    while ( !condition) {

                        V0=(char)q;

                        for ( int i  =0 ; i < cfg12->V.size() ; i++){
                            if(cfg12->V[i]==V0){
                                condition=false;

                                break;
                            }
                            if(i == cfg12->V.size()-1){
                                condition=true;
                            }

                        }
                        q++;
                    }

                    std::string string1 ="";
                    string1.operator+=(A.at(myVec.at(l).first));
//
//                    std::cout << "its# conditions" << V0 <<" : " << string1<< std::endl;
                    std::vector<std::string> NewStrings;
                    NewStrings.push_back(string1);
                    std::pair<char,std::vector<std::string > > mypair;
                    mypair.first=V0;
                    mypair.second=NewStrings;
                    Lambda.push_back(mypair);
                    V.push_back(V0);


                    std::pair<char, unsigned long> pair1;
                    pair1.first =V0;
                    pair1.second =myVec.at(l).second ;
                    myNewVec.push_back(pair1);
                }

                /////
                //TODO erase last string and push new string that you have create from myNewVec
                ////

            }
            if(myNewVec.size()>0) {
                for (int n = 0; n < myNewVec.size(); n++) {
                    nString.replace(myNewVec.at(n).second, myNewVec.at(n).second, 1, myNewVec.at(n).first);
//
//                    std::cout << "its## =" << nString << std::endl;
                }


//                std::cout << "its#####rules =" << nString << std::endl;
            Lambda.at(k).second.erase(Lambda.at(k).second.begin()+i);
            Lambda.at(k).second.push_back(nString);
            }

        }

    }








    // --------------------
    //convert two V's changable and  search or create new changable
    // --------------------

    for (int i = 0; i <Lambda.size() ; i++) {
        for (int j = 0; j <Lambda.at(i).second.size() ; j++) {
            std::string currentString = Lambda.at(i).second.at(j);
            bool exsisting;

            while(currentString.size()>2){


                char  first = currentString.at(0);
                exsisting= false;
                char  second  = currentString.at(1);
                std::string newString = "";
                newString.operator+=(first);
                newString.operator+=(second);


                char V0=800;
                for (int k = 0; k <Lambda.size() ; k++) {
                    bool conditions= false;
                    for (int l = 0; l <Lambda.at(l).second.size() ; l++) {
                        if(Lambda.at(k).second.at(l)==newString){
                            V0=Lambda.at(k).first;
                            conditions=true;
                            exsisting=true;
                            break;
                        }

                    }
                    if ( conditions){
                        break;
                    }

                }

                if(!exsisting){


                    condition = false;
                    q = 200 ;

                    while ( !condition) {

                        V0=(char)q;

                        for ( int i  =0 ; i < cfg12->V.size() ; i++){
                            if(cfg12->V[i]==V0){
                                condition=false;

                                break;
                            }
                            if(i == cfg12->V.size()-1){
                                condition=true;
                            }

                        }
                        q++;
                    }

                    std::string string1 ="";
                    string1=newString;

                    std::cout << "its current string =" << currentString << std::endl;
                    std::cout << "its  newString =" <<  newString << std::endl;
                    std::vector<std::string> NewStrings;
                    NewStrings.push_back(string1);
                    std::pair<char,std::vector<std::string > > mypair;
                    mypair.first=V0;
                    mypair.second=NewStrings;
                    Lambda.push_back(mypair);
                    V.push_back(V0);
                }

                currentString.replace(0,2,1,V0);


            }

            Lambda.at(i).second.erase(Lambda.at(i).second.begin()+j);
            Lambda.at(i).second.push_back(currentString);


        }
    }


    cfg12->setA(A);
    cfg12->setLambda(Lambda);
    cfg12->setS(S);
    cfg12->setV(V);



    return *cfg12;

    // --------------------
    //convert one charecter rule -----
    // --------------------




}

int main() {
    //a
    cfg *cfg12 =init();
        print(cfg12);
   *cfg12=convert(cfg12);

    print(cfg12);
        std::string m="ali-";
//
//    std::cout << m.operator+=("al") << std::endl;
//    m.find('s');
//
//    std::cout <<m<< std::endl;
//    m.erase(m.begin()+1);
//    std::cout <<m<< std::endl;

    return 0;
}