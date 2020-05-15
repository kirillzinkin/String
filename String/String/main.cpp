//
//  main.cpp
//  String
//
//  Created by Кирилл Зинкин on 14.05.2020.
//  Copyright © 2020 Кирилл Зинкин. All rights reserved.
//

#include "string.hpp"
int main()
{
    String str;
    String str2("PMI ");
    String str3(str2);
    cout << str2.GetStr() << endl;
    cout << str3.GetStr() << endl;
    str3.SetStrSize("SILA");
    cout << str3 << endl;
    String str4;
    str4.SetStrSize("!!!");
    cout << str4 << endl;
    String sum;
    sum = str2 + str3 + str4;
    cout << "operator + : " << sum << endl;
    bool simple(str2 == str3);
    cout << boolalpha;
    cout << "operator == : " << simple << endl;
    cout << str2.GetSize() << endl;
    cout << str3.GetSize() << endl;
    cout << sum.GetSize() << endl;
    String str5("StrohkiStrohki Stroki");
    String str6("StrokiStrohki Strohi");
    bool simpl2 = str5 == str6;
    cout << "operator == : " << simpl2 << endl;
    str6.SetStrSize("StrokiStroki");
    bool res(str5 < str6);
    cout << "operator < : " << res << endl;
    bool res2(str5 > str6);
    cout << "operator > : " << res2 << endl;
    cout << "operator [] : " << str5[6] << endl;
    cout << str5.FirstFind("hki ") << endl;
    cout << str5.FirstFind("hk") << endl;
    //str5.Getline(" ");
    cout << str5.Rep(3) << endl;
    cout << str5.AllFind("St") << endl;
    return 0;
}
