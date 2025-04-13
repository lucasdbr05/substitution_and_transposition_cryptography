#include <iostream>
#include <Logger.hpp>
#include <CeasarCipher.hpp>
#include <RailFenceCipher.hpp>
#include <BruteForceSubstitution.hpp>
using namespace std;

void do_command(string option) {
    string text;
    if(option=="1A") {
        CeasarCipher ceasarCipher;
        Logger::print_string("Type text to be encrypted:");
        cin >> text;
        Logger::print_string("Cipher text resulted from encryptation:");
        Logger::print_string(ceasarCipher.encrypt(text));
    } else if(option == "1B") {
        CeasarCipher ceasarCipher;
        Logger::print_string("Type text to be decrypted:");
        cin >> text;
        Logger::print_string("Cipher text resulted from decryptation:");
        Logger::print_string(ceasarCipher.decrypt(text));
    } else if(option == "1C") {
        BruteForceSubtitution brute;
        Logger::print_string("Type text to be broked using brute force:");
        cin >> text;
        Logger::print_string("Brute force generated the following texts:");
        Logger::print_vector(brute.breakChipher(text));
    }  else if(option == "1D") {
        // TODO HEHE
    } else if(option == "2A") {
        Logger::print_string("Type text to be encrypted:");
        cin >> text;
        RailFenceCipher railsFenceChiper(3);
        Logger::print_string("Cipher text resulted from encryptation:");
        Logger::print_string(railsFenceChiper.encrypt(text)); 
    } else if(option == "2B") {
        Logger::print_string("Type text to be decrypted:");
        cin >> text;
        RailFenceCipher railsFenceChiper(3);
        Logger::print_string("Cipher text resulted from decryptation:");
        Logger::print_string(railsFenceChiper.decrypt(text)); 
    } else if (option == "2C") {

    } else if (option == "2D") {

    } else {
        Logger::print_string("Option not found :(");
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string option;
    Logger::start();

    do{
        cin >> option;
        if(option == "0") break;
        do_command(option);
        system("cls");
    } while(option!= "0");

    return 0;
}