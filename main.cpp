#include <iostream>
#include "Logger.hpp"
#include "CeasarCipher.hpp"
#include "RailFenceCipher.hpp"
#include "BreakSubstitionCipher.hpp"
#include "BreakTranspositionCipher.hpp"
using namespace std;

void do_command(string option) {
    string text;
    if(option=="1A") {
        CeasarCipher ceasarCipher;
        Logger::print_string("Type text to be encrypted:");
        getline(cin >> ws, text);
        Logger::print_string("Cipher text resulted from encryptation:");
        Logger::print_string(ceasarCipher.encrypt(text));
    } else if(option == "1B") {
        CeasarCipher ceasarCipher;
        Logger::print_string("Type text to be decrypted:");
        getline(cin >> ws, text);
        Logger::print_string("Cipher text resulted from decryptation:");
        Logger::print_string(ceasarCipher.decrypt(text));
    } else if(option == "1C") {
        BreakSubstitutionCipher crack;
        Logger::print_string("Type text to be broked using brute force:");
        getline(cin >> ws, text);
        Logger::print_string("Brute force generated the following texts:");
        Logger::print_vector(crack.brute_force(text));
    }  else if(option == "1D") {
        BreakSubstitutionCipher crack;
        Logger::print_string("Type text to be broked using frequency distribution:");
        getline(cin >> ws, text);
        Logger::print_string("Frequency distribution generated the following texts:");
        Logger::print_vector(crack.frequency_distribution(text));
    } else if(option == "2A") {
        Logger::print_string("Type text to be encrypted:");
        getline(cin>> ws, text);
        RailFenceCipher railsFenceChiper(3);
        Logger::print_string("Cipher text resulted from encryptation:");
        Logger::print_string(railsFenceChiper.encrypt(text)); 
    } else if(option == "2B") {
        Logger::print_string("Type text to be decrypted:");
        getline(cin>> ws, text);
        RailFenceCipher railsFenceChiper(3);
        Logger::print_string("Cipher text resulted from decryptation:");
        Logger::print_string(railsFenceChiper.decrypt(text)); 
    } else if (option == "2C") {
        BreakTranspositionCipher crack;
        Logger::print_string("Type text to be broked using crackforce:");
        getline(cin >> ws, text);
        Logger::print_string("Brute force generated the following texts:");
        Logger::print_vector(crack.brute_force(text));
    } else if (option == "2D") {
        BreakTranspositionCipher crack;
        Logger::print_string("Type text to be broked using frequency distribution:");
        getline(cin >> ws, text);
        Logger::print_string("Frequency distribution generated the following texts:");
        Logger::print_vector(crack.frequency_distribution(text));
    } else {
        Logger::print_string("Option not found :(");
    }
    Logger::print_string("Type Y to continue");
    getline(cin >>ws, text);
}

signed main() {
    string option;
    
    do{
        system("cls");
        Logger::start();
        cin >> option;
        
        system("cls");
        if(option == "0") break;
        do_command(option);
    } while(option!= "0");

    return 0;
}