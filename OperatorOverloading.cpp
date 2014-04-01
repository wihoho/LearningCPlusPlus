//
//  main.cpp
//  LearningCPlusPlus
//
//  Created by Gong Li on 28/3/14.
//  Copyright (c) 2014 wihoho. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


// Overload >> & <<
class Complex{
private:
    double real, image;
    
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), image(i){};
    
    friend ostream & operator<<(ostream & o, const Complex & complex);
    friend istream & operator>>(istream & i, Complex & complex);
};

ostream & operator<< (ostream & o, const Complex & complex){
    o << complex.real << "+" << complex.image <<"i";
    return o;
}

istream & operator >> (istream & i, Complex & c){
    string s;
    i >> s;
    
    int pos = s.find("+", 0);
    string sTemp = s.substr(0, pos);
    c.real = atof(sTemp.c_str());
    
    sTemp = s.substr(pos + 1, s.length() - pos - 2);
    c.image = atof(sTemp.c_str());
    
    return i;
}

// Overload ++ & --
class CDemo{
    
private:
    int n;
public:
    CDemo(int i = 0): n(i){};
    
    CDemo& operator++ (){
        this->n ++;
        return *this;
    }
    
    CDemo operator++(int k){
        CDemo temp(n);
        n ++;
        return temp;
    }
    
    CDemo& operator--(){
        n --;
        return *this;
    }
    
    CDemo operator--(int k){
        CDemo temp(n);
        n --;
        
        return temp;
    }
    
    friend ostream& operator<< (ostream& o, const CDemo & demo);
};


ostream& operator<< (ostream& o, const CDemo & demo){
    o << demo.n;
    return o;
}





/*
 13.4+12.5i 10000
 13.4+12.5i,10000
 
 5 6 7 7 7 6 5 5
 */
//int main() {
//    
//    //    Complex c;
//    //    int n;
//    //    cin >> c >> n;
//    //    cout << c << "," << n; return 0;
//    
//    CDemo d(5);
//    cout << (d++) << " ";
//    cout << d << " ";
//    
//    cout << (++d) << " ";
//    cout << d << " ";
//    
//    cout << (d--) << " ";
//    cout << d << " ";
//    
//    cout << (--d) << " ";
//    cout << d << " ";
//    
//}

