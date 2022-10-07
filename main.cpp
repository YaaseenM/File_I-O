#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "extrafile.h"
#include <vector>
using namespace std;
void GetDataFromCSVFile (string filePath, vector<extrafile>& lego) {

    ifstream legoFile (filePath);

    if (legoFile.is_open()) {
        string lineFromFile;
        getline(legoFile, lineFromFile);

        while (getline(legoFile, lineFromFile)) {

            istringstream stream(lineFromFile);

            string tempNumber;
            string name;
            string theme;
            string tempMinifigs;
            string tempPieces;
            string tempPrice;
            int number;
            int minifigs;
            int pieces;
            double price;

            getline(stream, tempNumber, ',');
            getline(stream, theme, ',');
            getline(stream, name, ',');
            getline(stream, tempMinifigs, ',');
            getline(stream, tempPieces, ',');
            getline(stream, tempPrice, ',');
            number = stoi(tempNumber);
            minifigs = stoi(tempMinifigs);
            pieces = stoi(tempPieces);
            price = stod(tempPrice);


            extrafile l (number, theme, name, minifigs, pieces, price);
            lego.push_back(l);
        }
    } else {
        cout << "File not opened." << endl;
    }
}
void FindMostExpensiveSet(vector<extrafile>& lego) {
    double highestPrice = 0;
    int place = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        if (lego[i].GetPrice() > highestPrice) {
            highestPrice = lego[i].GetPrice();
            place = i;
        }
    }
    cout << "Name: " << lego[place].GetName() << endl;
    cout << "Number: " << lego[place].GetNumber() << endl;
    cout << "Theme: " << lego[place].GetTheme() << endl;
    cout << "Price: $" << lego[place].GetPrice() << endl;
    cout << "Minifigures: " << lego[place].GetMinifigs() << endl;
    cout << "Piece count: " << lego[place].GetPieces() << endl;

}

void FindMostMiniFiguresSet(vector<extrafile>& lego) {
    int highestMiniFigures = 0;
    int place = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        if (lego[i].GetMinifigs() > highestMiniFigures) {
            highestMiniFigures = lego[i].GetMinifigs();
            place = i;
        }
    }
    cout << "\nSet with the most minifigures: " << endl;
    cout << "Name: " << lego[place].GetName() << endl;
    cout << "Number: " << lego[place].GetNumber() << endl;
    cout << "Theme: " << lego[place].GetTheme() << endl;
    cout << "Price: $" << lego[place].GetPrice() << endl;
    cout << "Minifigures: " << lego[place].GetMinifigs() << endl;
    cout << "Piece count: " << lego[place].GetPieces() << endl;

}

void FindLeastExpensiveSet(vector<extrafile>& lego) {
    double lowestPrice;
    int place = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        if (i == 0) {
            lowestPrice = lego[i].GetPrice();
        }
        if (lego[i].GetPrice() < lowestPrice) {
            lowestPrice = lego[i].GetPrice();
            place = i;
        }
    }
    cout << "\nLeast expensive set: " << endl;
    cout << "Name: " << lego[place].GetName() << endl;
    cout << "Number: " << lego[place].GetNumber() << endl;
    cout << "Theme: " << lego[place].GetTheme() << endl;
    cout << "Price: $" << lego[place].GetPrice() << endl;
    cout << "Minifigures: " << lego[place].GetMinifigs() << endl;
    cout << "Piece count: " << lego[place].GetPieces() << endl;

}

void FindMostPartSet(vector<extrafile>& lego) {
    int highestPieces = 0;
    int place = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        if (lego[i].GetPieces() > highestPieces) {
            highestPieces = lego[i].GetPieces();
            place = i;
        }
    }
    cout << "The set with the highest parts count: " << endl;
    cout << "Name: " << lego[place].GetName() << endl;
    cout << "Number: " << lego[place].GetNumber() << endl;
    cout << "Theme: " << lego[place].GetTheme() << endl;
    cout << "Price: $" << lego[place].GetPrice() << endl;
    cout << "Minifigures: " << lego[place].GetMinifigs() << endl;
    cout << "Piece count: " << lego[place].GetPieces() << endl;

}

int FindAverageMinifigures(vector<extrafile>& lego) {
    int totalMinifigures = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        totalMinifigures += lego[i].GetMinifigs();
    }
    int averageMinifigures = totalMinifigures / lego.size();

    return averageMinifigures;
}

int FindAveragePart(vector<extrafile>& lego) {
    int totalParts = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        totalParts += lego[i].GetPieces();
    }
    int averageParts = totalParts / lego.size();

    return averageParts;
}

double FindAveragePrice(vector<extrafile>& lego) {
    double totalPrice = 0.00f;
    for (unsigned int i = 0; i < lego.size(); i++) {
        totalPrice += lego[i].GetPrice();
    }
    double averagePrice = totalPrice / lego.size();

    return averagePrice;
}

double FindTotalPrice(vector<extrafile>& lego) {
    double totalPrice = 0.00f;
    for (unsigned int i = 0; i < lego.size(); i++) {
        totalPrice += lego[i].GetPrice();
    }

    return totalPrice;
}

int FindTotalPieces(vector<extrafile>& lego) {
    int totalPieces = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        totalPieces += lego[i].GetPieces();
    }

    return totalPieces;
}

int FindTotalMinifigures(vector<extrafile>& lego) {
    int totalMiniFigures = 0;
    for (unsigned int i = 0; i < lego.size(); i++) {
        totalMiniFigures += lego[i].GetMinifigs();
    }

    return totalMiniFigures;
}

void FindName(vector<extrafile>& lego, string searchName) {
    int works = 0;
    for(unsigned int i = 0; i < lego.size(); i++) {
        size_t found = lego[i].GetName().find(searchName);
        if(found != string::npos) {
            if (works == 0) {
                cout << "Sets matching \"" << searchName << "\":" << endl;
            }
            works++;
            cout << lego[i].GetNumber() << " " << lego[i].GetName() << " $" << lego[i].GetPrice() << endl;
        }
    }
    if (works == 0) {
        cout << "No sets found matching that search term" << endl;
    }
}

void FindTheme(vector<extrafile>& lego, string searchTheme) {
    int works = 0;
    for(unsigned int i = 0; i < lego.size(); i++) {
        size_t found = lego[i].GetTheme().find(searchTheme);
        if(found != string::npos) {
            if (works == 0) {
                cout << "Sets matching \"" << searchTheme << "\":" << endl;
                works++;
            }
            cout << lego[i].GetNumber() << " " << lego[i].GetName() << " $" << lego[i].GetPrice() << endl;
        }
    }
    if (works == 0) {
        cout << "No sets found matching that search term" << endl;
    }
}

int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

   /*======= Load data from file(s) =======*/
   vector<extrafile> lego;
    if(option == 1) {
        GetDataFromCSVFile("lego1.csv", lego);
    } else if (option == 2) {
        GetDataFromCSVFile("lego2.csv", lego);
    } else if (option == 3) {
        GetDataFromCSVFile("lego3.csv", lego);
    } else if (option == 4) {
        GetDataFromCSVFile("lego1.csv", lego);
        GetDataFromCSVFile("lego2.csv", lego);
        GetDataFromCSVFile("lego3.csv", lego);
    } else {
        cout << "Option not available." << endl;
    }

    cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
    cin.get();  // Clear newline character for any later input

   /*======= Print out how many sets were loaded =======*/
   cout << "\nTotal number of sets: " << lego.size() << endl << endl;
   /*======= Based on the choice, execute the appropriate task and show the results =======*/
    if (choice == 1) {
        cout << "\nThe most expensive set is: " << endl;
        FindMostExpensiveSet(lego);
    } else if (choice == 2) {
        FindMostPartSet(lego);
    } else if (choice == 3) {
        string nameSearch;
        getline(cin, nameSearch);
        FindName(lego, nameSearch);
    } else if (choice == 4) {
        string themeSearch;
        getline(cin, themeSearch);
        FindTheme(lego, themeSearch);
    } else if (choice == 5) {
        cout << "Average part count for " << lego.size() << " sets: " << FindAveragePart(lego) << endl;

    } else if (choice == 6) {
        cout << "Average price for " << lego.size() << " sets: $" << FindAveragePrice(lego) << endl;
        FindLeastExpensiveSet(lego);
        cout << "\nMost expensive set: " << endl;
        FindMostExpensiveSet(lego);
    } else if (choice == 7) {
        cout << "Average number of minifigures: " << FindAverageMinifigures(lego) << endl;
        FindMostMiniFiguresSet(lego);
    } else if (choice == 8) {
        cout << "If you bought one of everything..." << endl;
        cout << "It would cost: $" << FindTotalPrice(lego) << endl;
        cout << "You would have " << FindTotalPieces(lego) << " pieces in your collection" << endl;
        cout << "You would have an army of " << FindTotalMinifigures(lego) << " minifigures!" << endl;
    } else if (choice == 0) {
        return 0;
    } else {
        cout << "Invalid Choice;" << endl;
    }
	return 0;
}