//
//  string.hpp
//  String
//
//  Created by Кирилл Зинкин on 14.05.2020.
//  Copyright © 2020 Кирилл Зинкин. All rights reserved.
//

#ifndef string_hpp
#define string_hpp

#include <iostream>
#include <cstring>
using namespace std;

class String{
    unsigned long size;
    char* str;
public:
    String();
    String(const char* str);
    String(char str, unsigned long size);
    String(String& a);
    char* GetStr();
    unsigned long GetSize();
    void SetStrSize(const char* ch);
    String operator+ (const String& a);
    String& operator= (const String& a);
    bool operator== (const String& a);
    bool operator< (const String& a);
    bool operator> (const String& a);
    char& operator[] (int index);
    friend ostream& operator<< (ostream& os, const String& a);
    friend istream& operator>> (istream& is, String& a);
    ~String();
    char* FirstFind(const char* ch);
    String* Getline(const char* ch);
    String Rep(int k);
    String AllFind(const char* ch);
};
#endif /* string_hpp */
