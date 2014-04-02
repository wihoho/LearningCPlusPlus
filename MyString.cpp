//
//  test.cpp
//  LearningCPlusPlus
//
//  Created by Gong Li on 2/4/14.
//  Copyright (c) 2014 wihoho. All rights reserved.
//


/* Output
 1. abcd-efgh-abcd-
 2. abcd-
 3.
 4. abcd-efgh-
 5. efgh-
 6. c
 7. abcd-
 8. ijAl-
 9. ijAl-mnop
 10. qrst-abcd-
 11. abcd-qrst-abcd- uvw xyz
 about
 big
 me
 take
 abcd
 qrst-abcd-
 
 Requirements
 1. copy constructor
 2. << override
 3. = override
 4. + override
 5. []
 6. + " abc" + "cbd"
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class MyString: public string{
public:
    MyString(){};
    MyString(const char* c):string(c){};
    MyString(const string& c):string(c){};
    
    MyString operator()(int start, int length){
        return string::substr(start, length);
    };
    
};

int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )     return -1;
    else if( *s1 == *s2) return 0;
    else if( *s1 > *s2 ) return 1;
    
    return 0;
}

/*

int main()   {
    MyString s1("abcd-"), s2, s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    
    s2 = s1;    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
} */