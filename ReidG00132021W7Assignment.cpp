#include <iostream>
using namespace std;

void displayChart(string seatingChar[14][7],string classType);
void whereCanYouSit(string seatingChart[14][7],int rowNum,int seatNum);
void getSeat(string seatingChart[14][7]);
string getClassType();

int rowNum,seatNum;
string classType;

void displayChart(string seatingChart[14][7],string classType) {

    cout << "Here is our seating chart, you may select from the (" << classType << ") seats." << "\n" <<
         "* = available\nX = not available\n" << endl;

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 7; j++) {
            cout << seatingChart[i][j] << "\t";
        }
        cout << '\n';
    }
    cout << endl;

}

void whereCanYouSit(string seatingChart[14][7],int rowNum,int seatNum) {

    bool seatSelect = true;

    while (seatSelect) {
        if (classType == "FC") {
            if (rowNum > 2) {
                cout << "You have First Class, please select from the 'FC' seats." << endl;
                getSeat(seatingChart);
                seatSelect = false;
            }
        } else if (classType == "BC") {
            if (rowNum <= 2 || rowNum > 7) {
                cout << "You have Business Class, please select from the 'BC' seats." << endl;
                getSeat(seatingChart);
                seatSelect = false;
            }
        } else if (classType == "EC") {
            if (rowNum < 8) {
                cout << "You have Economy Class, please select from the 'EC' seats." << endl;
                getSeat(seatingChart);
                seatSelect = false;
            }
        }
        if (seatingChart[rowNum][seatNum] == "X") {
            cout << "That seat is unavailable, please select again: " << endl;
            getSeat(seatingChart);
            seatSelect = false;
        } else if (seatingChart[rowNum][seatNum] == "*") {
            seatSelect = false;
        }
    }

}

void getSeat(string seatingChart[14][7]) {

    int row;
    char aisle;
    cout << "Please select seat using this format example( '1 A' ): ";
    cin >> row >> aisle;
    rowNum = row;
    seatNum = static_cast<int>(aisle)-64;

    whereCanYouSit(seatingChart,rowNum,seatNum);

}

string getClassType() {

    cout << "Welcome, please enter your ticket type (first class, business class, economy class): ";
    getline(cin,classType);

    if (classType == "first class") {
        classType = "FC";
    } else if (classType == "business class") {
        classType = "BC";
    } else {
        classType = "EC";
    }
    return classType;
}

int main() {

    string seatingChart[14][7] = {
            {"\t\t","A","B","C","D","E","F"},
            {"(FC)Row 1","*","*","X","*","X","X"},
            {"(FC)Row 2","*","X","*","X","*","X"},
            {"(BC)Row 3","*","*","X","X","*","X"},
            {"(BC)Row 4","X","*","X","*","X","X"},
            {"(BC)Row 5","*","X","*","X","*","*"},
            {"(BC)Row 6","*","X","*","*","*","X"},
            {"(BC)Row 7","X","*","*","*","X","X"},
            {"(EC)Row 8","*","X","*","X","X","*"},
            {"(EC)Row 9","X","*","X","X","*","X"},
            {"(EC)Row 10","*","X","*","X","X","X"},
            {"(EC)Row 11","*","*","X","*","X","*"},
            {"(EC)Row 12","*","*","X","X","*","X"},
            {"(EC)Row 13","*","*","*","*","X","*"},
    };

    displayChart(seatingChart,getClassType());

    getSeat(seatingChart);

    cout << "That seat is available, Safe Travels!" << endl;

}