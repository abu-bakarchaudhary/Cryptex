#pragma once
#include <string>

class SharedData {
public:
    static std::string message;
    static int p;
    static int q;
};

// Initialize static members
std::string SharedData::message = "";
int SharedData::p = 0;
int SharedData::q = 0;
