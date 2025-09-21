#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class CasarCipher {
    //declaring varible to stare value
    string message, decryptmessage, encryptmessage=" ";
    int a, b, inverse_a;
public:
    //function to calculate the a inverse for the decryption
    int modularInverse(int a, int m) {
        a = a % m;
        //for loop to check all the possible value
        for (int x = 1; x < m; x++) {
            if ((a * x) % m == 1) {
                return x;
            }
        }
        return -1;
    }
    //checking the enter key is correct or not
    bool checkkey(int keya, int keyb) {
        if (keya == a && keyb == b) {
            return true;
        }
        else
            return false;
    }
    //function to calculate the greater common divider
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    //return the updated message
    string getEncryptedMessage() {
        return encryptmessage;
    }
    //return the updated message
    string getDecryptMessage() {
        return decryptmessage;
    }
    //function to calculate the encrypt message
    void encryption(string m, int key1, int key2) {
        message = m;
        a = key1;
        b = key2;
        encryptmessage = "";
        //for loop to shift every character
        for (char value : message) {
            char newalphabet = value;
            if (isalpha(value)) {
                //formula for the shift and handly the space and special character
                char base = islower(value) ? 'a' : 'A';
                newalphabet = (a * (value - base) + b) % 26 + base;
            }
            encryptmessage += newalphabet;
        }
    }
    //function to calculate the decrypt message
    void decryption(int key1, int key2) {
        decryptmessage = "";
        // calculating the a inverse
        inverse_a = modularInverse(a, 26);
        //for loop to shift every character
        for (char value : encryptmessage) {
            char newalphabet = value;
            if (isalpha(value)) {
                //formula for the shift and handly the space and special character
                char base = islower(value) ? 'a' : 'A';
                int temp = (value - base - (b % 26) + 26) % 26;
                newalphabet = (inverse_a * temp) % 26 + base;
            }
            decryptmessage += newalphabet;
        }
    }
};