#pragma once
#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;
class RSA
{
    //declaring varible to stare value
    int n, Qn, e, d;
    string message, encryptmessage = " ", decryptmessage = "";
public:
    //following are the getter function that return the spacific value from the class as per requirment
    string getprivatekey() {
        string value = "( " + to_string(e) + ", " + to_string(n) + " )";
        return value;
    }
    string getpublickey() {
        string value = "( " + to_string(d) + ", " + to_string(n) + " )";
        return value;
    }
    string getencryptmessage() {
        return encryptmessage;
    }
    string getdecryptmessage() {
        return decryptmessage;
    }
    //function to check the valid key
    bool checkkey(int keyd, int keyn) {
        if (d == keyd && n == keyn) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isPrime(long long num) {
        if (num <= 1) return false;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
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
    //function that calculate the value for every character for encryption and decryption
    int formula(int base, int exp, int mod)
    {
        int result = 1;
        base = base % mod;

        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * base) % mod;
            }
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }
    //function that calculate the value of basic varible from p and q
    void calculation(int p, int q)
    {
        n = p * q;
        Qn = (p - 1) * (q - 1);
        for (int i = 2; i < Qn; i++)
        {
            if (gcd(i, Qn) == 1)
            {
                e = i;
                break;
            }
        }
        for (int i = 1; i < Qn; i++)
        {
            if ((e * i) % Qn == 1)
            {
                d = i;
                break;
            }
        }
    }
    //function to encrypt the message
    void encryption(string m)
    {
        encryptmessage = " ";
        message = m;
        //for loop to convert every character
        for (char c : message)
        {
            int ascii = static_cast<int>(c);
            ascii = ascii - 65;
            ascii = formula(ascii, e, n);
            encryptmessage += to_string(ascii) + ",";

        }
    }
    //function to calculate the decrypt message
    void decryption(int key1, int key2)
    {
        decryptmessage = "";
        string temp = "";
        //for loop to convert every character
        for (char c : encryptmessage)
        {
            //comdition to handle the space
            if (c != ',')
            {
                temp += c;
            }
            else
            {
                if (!temp.empty())
                {
                    int ascii = stoi(temp);
                    ascii = formula(ascii, d, n);
                    decryptmessage += static_cast<char>(ascii+65);
                    temp = "";
                }
            }
        }
    }
};