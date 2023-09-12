#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Node.cpp"

using std::string, std::ifstream, std::stringstream, std::vector;

//read info from file
void parcer(string file){
    ifstream myFile(file);
    stringstream sstrm;
    string line;
     
    int s;
    int b;
    int m;

    getline(myFile, line);
    sstrm << line;
    sstrm >> s >> b >> m;
    
    if(sstrm.fail()){
        //first line doesn't work
        return;
    }
    vector<vector<char>> stackInitial(s);
    vector<vector<char>> stackFinal(s);
    // >>>>>>>>> line
    getline(myFile, line);

    //add all chars to initial stack representation
    for(int i = 0; i < s; i++){
        getline(myFile, line);
        char curr;
        sstrm.clear();
        sstrm << line;
        while(sstrm >> curr){
            stackInitial.at(i).push_back(curr);
        }
    }
    // >>>>>>>>>>>line
    getline(myFile, line);

    //add all chars to final stack representation
    for(int i = 0; i < s; i++){
        getline(myFile, line);
        char curr;
        sstrm.clear();
        sstrm << line;
        while(sstrm >> curr){
            stackFinal.at(i).push_back(curr);
        }
    }

    //Print to check
    std::cout << "S = " << s << ", B = " << b << ", M = " << m << std::endl;
    std::cout << "Initital" << std::endl;
    for(int i = 0; i < s; i++){
        for(char curr: stackInitial.at(i))
            std::cout << curr;
        std::cout << std::endl;
    }

    std::cout << "Final" << std::endl;
    for(int i = 0; i < s; i++){
        for(char curr: stackFinal.at(i))
            std::cout << curr;
        std::cout << std::endl;
    }



    
}

int main() {
    parcer("probs/probA03.bwp");
}