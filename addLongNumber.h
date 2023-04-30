#ifndef SUMMNUMBERS_ADDLONGNUMBER_H
#define SUMMNUMBERS_ADDLONGNUMBER_H

struct longNumberElement {
    longNumberElement *next, *prev;
    int data;
};

using namespace std;
using longNumber = longNumberElement*;

class addLongNumber {
private:
    longNumber firstNumber, secondNumber;
public:
    addLongNumber();
    addLongNumber(char numberPerLine);
};


#endif
