//
//  string.cpp
//  String
//
//  Created by Кирилл Зинкин on 14.05.2020.
//  Copyright © 2020 Кирилл Зинкин. All rights reserved.
//

#include "string.hpp"
String::String()
{
    str = nullptr;
    size = 0;
}
String::String(const char* str)
{
    size = strlen(str);
    this->str = new char[size + 1];
    for (int i = 0; i < size; i++)
        this->str[i] = str[i];
    this->str[size] = '\0';

}

String::String(char st, unsigned long size)
{
    this->size = size + 1;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
        str[i] = st;
    str[size] = '\0';

}

String::String(String& a)
{
    size = strlen(a.str);
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
        this->str[i] = a.str[i];
    this->str[size] = '\0';
}

char* String::GetStr()
{
    return str;
}
unsigned long String::GetSize()
{
    return size;
}

void String::SetStrSize(const char* ch)
{
    size = strlen(ch);
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
        str[i] = ch[i];
    str[size] = '\0';
}

String String::operator+ (const String& a)
{
    String NewStr;
    unsigned long thisSize = strlen(this->str);
    unsigned long aSize = strlen(a.str);
    NewStr.size = thisSize + aSize;
    NewStr.str = new char[thisSize + aSize + 1];
    int i = 0;
    for (; i < thisSize; i++)
        NewStr.str[i] = this->str[i];
    for (int j = 0; j < aSize; j++, i++)
        NewStr.str[i] = a.str[j];
    NewStr.str[thisSize + aSize] = '\0';
    return NewStr;
}

String& String::operator= (const String& a)
{
    if (this->str != nullptr)
    {
        delete[] str;
    }
    size = strlen(a.str);
    this->str = new char[size + 1];
    for (int i = 0; i < size; i++)
        this->str[i] = a.str[i];
    this->str[size] = '\0';
    return*this;
}

bool String::operator== (const String& a)
{
    if (this->size != a.size)
    {
        return false;
    }
    for (int i = 0; i < this->size; i++)
    {
        if (this->str[i] != a.str[i])
        {
            return false;
        }
    }
    return true;
}
bool String::operator< (const String& a)
{
    return size < a.size;

}

bool String::operator> (const String& a)
{
    return size > a.size;
}
char& String::operator[] (int index)
{
    return this->str[index];
}

ostream& operator<< (ostream& os, const String& a)
{
    for (int i = 0; i < a.size; i++)
        os << a.str[i];
    return os;
}

istream& operator>> (istream& is, String& a)
{
    char c[256];
    is.getline(c, 256);
    String tmp(c);
    a = tmp;
    return is;
}

String::~String()
{
    delete[] str;
}

char* String::FirstFind(const char* ch)
{
    char* c = strstr(str, ch);
    return c;
}

String* String::Getline(const char* ch)
{
    String tmp;
    tmp = str;
    int digit = 0;
    char* c = strtok(tmp.str, ch);
    while (c != NULL) {
        digit += 1;
        c = strtok(NULL, ch);
    }
    tmp = c;
    String* a = new String[digit];
    digit = 0;
    c = strtok(tmp.str, ch);
    while (c != NULL){
        a[digit] = c;
        digit += 1;
        c = strtok(NULL, c);
    }

    return a;
}

String String::Rep(int k)
{
    String tmp, y;
    tmp = str;
    y = tmp;
    for (int i = 1; i < k; i++)
    {
        y = y + tmp;
    }
    return y;
}

String String::AllFind(const char* ch)
{
    String a;
    String b;
    a = str;
    string r;
    int n = 0;
    unsigned long size = strlen(a.str);
    for(int i = 0; i < size; i++)
        {
            if(a[i] == 'S')
                {
                    for (int j = i; j < size; j++)
                    {
                        r += a[j];
                        n++;
                    }
                }
            for (int l = 0; l < size; l++)
            {
                a[1] = a[l+1];
            }
        }
    a.size = n;
    for(int i = 0; i < n; i++){
        a[i] = r[i];
    }
    return a;
}
