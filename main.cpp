#include <iostream>
#include <fstream>
#include "Logger.hpp"
#include "CeasarCipher.hpp"
#include "RailFenceCipher.hpp"
#include "BreakTranspositionCipher.hpp"
#include "BreakSubstitionCipher.hpp"
using namespace std;

string input(bool user_input, string file) {
    string res;
    if(user_input) {
        getline(cin >> ws, res);        
    } else {
        ifstream File(file);
        getline(File, res);        
    }

    return res;
}

void do_command(string option, bool& user_input) {
    string text;

    if(option=="1A") {
        CeasarCipher ceasar_cipher;
        Logger::print_string("Type text to be encrypted:");
        getline(cin >> ws, text);
        Logger::print_string("Cipher text resulted from encryptation:");
        Logger::print_string(ceasar_cipher.encrypt(text));
    } else if(option == "1B") {
        CeasarCipher ceasar_cipher;
        Logger::print_string("Type text to be decrypted:");
        getline(cin >> ws, text);
        Logger::print_string("Cipher text resulted from decryptation:");
        Logger::print_string(ceasar_cipher.decrypt(text));
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
        Logger::print_string(crack.frequency_distribution(text));
    } else if(option == "2A") {
        Logger::print_string("Type text to be encrypted:");
        getline(cin>> ws, text);
        RailFenceCipher rails_fence_cipher(3);
        Logger::print_string("Cipher text resulted from encryptation:");
        Logger::print_string(rails_fence_cipher.encrypt(text)); 
    } else if(option == "2B") {
        Logger::print_string("Type text to be decrypted:");
        getline(cin>> ws, text);
        RailFenceCipher rails_fence_cipher(3);
        Logger::print_string("Cipher text resulted from decryptation:");
        Logger::print_string(rails_fence_cipher.decrypt(text)); 
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
        Logger::print_string("Frequency distribution generated the following text:");
        Logger::print_string(crack.frequency_distribution(text));
    } else if(option == "T") {
        user_input = !user_input;
        return;
    } else {
        Logger::print_string("Option not found :(");
    }
    Logger::print_string("Type Y to continue");
    getline(cin >>ws, text);
}

signed main() {
    string option;
    bool user_input = false;
    do{
        system("cls");
        Logger::start(user_input);
        cin >> option;
        
        system("cls");
        if(option == "0") break;
        do_command(option, user_input);
    } while(option!= "0");

    return 0;
}