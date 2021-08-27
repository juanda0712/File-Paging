#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Page{
private:
    int pageNumber;
    int arrayNumbers[256];
    int bit;

public:
    // Setters
    void setpageNumber(int pageNumber) {
        this->pageNumber = pageNumber;
    }
    void setarrayNumbers(int arrayPosition, int value) {
        this->arrayNumbers[arrayPosition] = value;
    }
    void setbit(int bit) {
        this->bit = bit;
    }

    // Getters
    int getpageNumber() {
        return pageNumber;
    }
    int getarrayNumbers(int arrayPosition) {
        return arrayNumbers[arrayPosition];
    }
    int getbit() {
        return bit;
    }
};