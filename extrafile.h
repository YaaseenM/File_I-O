#ifndef O_EXTRAFILE_H
#define O_EXTRAFILE_H
#include <string>

using namespace std;

class extrafile {
    int number;
    string theme;
    string name;
    int minifigs;
    int pieces;
    double price;
public:
    extrafile(int number, string theme, string name, int minifigs, int pieces, double price);
    int GetNumber();
    string GetTheme();
    string GetName();
    int GetMinifigs();
    int GetPieces();
    double GetPrice();
};

extrafile::extrafile(int number, string theme, string name, int minifigs, int pieces, double price) {
    this->number = number;
    this->theme = theme;
    this->name = name;
    this->minifigs = minifigs;
    this->pieces = pieces;
    this->price = price;
}

int extrafile::GetNumber() {
    return number;
}

string extrafile::GetTheme() {
    return theme;
}

string extrafile::GetName() {
    return name;
}

int extrafile::GetMinifigs() {
    return minifigs;
}

int extrafile::GetPieces() {
    return pieces;
}

double extrafile::GetPrice() {
    return price;
}

#endif //O_EXTRAFILE_H
