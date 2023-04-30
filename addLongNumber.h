#ifndef SUMMNUMBERS_ADDLONGNUMBER_H
#define SUMMNUMBERS_ADDLONGNUMBER_H

using namespace std;

struct longNumberElement {
    longNumberElement *next, *prev;
    short data;
};

using namespace std;
using longNumber = longNumberElement*;

class addLongNumber {
private:
    longNumber operand, last;
public:
    addLongNumber();
    addLongNumber(const string& numberPerLine);

    longNumber getLastElement();

    void addDigital(short digit);
    void initializeFirstElement(short digit);
};


#endif
