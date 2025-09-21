#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class BruteForceAttack
{
    // a variable that will store the message
    string encryptmessage, Result = "";

    //function to calculate the a inverse for the decryption
    int modularInverse(int a, int m)
    {
        a = a % m;
        //for loop to check all the possible value
        for (int x = 1; x < m; x++)
        {
            if ((a * x) % m == 1)
            {
                return x;
            }
        }
        return -1;
    }

public:
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
    // assign the encrypt message
    void setEncryptedMessage(string encryptedMessage)
    {
        encryptmessage = encryptedMessage;
    }
    //return the updated message
    string getResult()
    {
        return Result;
    }
    //main logic to crack the encrypt message
    void bruteForceDecrypt()
    {
        //for loop to check all 26 shift
        for (int a = 1; a < 26; a++)
        {
            if (gcd(a, 26) != 1)
                continue;
            for (int b = 0; b < 26; b++)
            {
                string decryptedMessage = "";
                int inverse_a = modularInverse(a, 26);
                if (inverse_a == -1)
                {
                    continue;
                }
                // for loop to convert the message back to original message
                for (char value : encryptmessage)
                {
                    char newalphabet = value;
                    if (isalpha(value))
                    {
                        char base = islower(value) ? 'a' : 'A';
                        int temp = (value - base - b + 26) % 26;
                        newalphabet = (inverse_a * temp) % 26 + base;
                    }
                    decryptedMessage += newalphabet;
                }
                //value the all value into one variable
                Result += "Trying a = " + to_string(a) + ", b = " + to_string(b) + " -> " + decryptedMessage + "\r\n";
            }
        }
    }
};