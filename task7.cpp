#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Name[10];
int Prices[10][10];
int Order[10];
int count[10];

bool isEligible(int ord, int amount, int index);
void readFromFile(string f_name);
void enterInFile(string f_name, string nm);

int main() {
    int min_ord, min_prc;
    cout << "Enter the minimum Orders: ";
    cin >> min_ord;
    cout << "Enter the minimum Price: ";
    cin >> min_prc;

    readFromFile("Task7.txt");

    for (int i = 0; i < 10 && !Name[i].empty(); i++) {
        if (isEligible(min_ord, min_prc, i)) {
            enterInFile("pizzaPoint.txt", Name[i]);
        }
    }

    return 0;
}

void readFromFile(string f_name) {
    ifstream file(f_name);
    if (!file.is_open()) {
        cout << "Failed to open the file!" << endl;
        return;
    }

    int idx = 0;
    string line;

    while (getline(file, line) && idx < 10) {
        string name = "";
        int orders = 0;
        int prices[10];
        int priceCount = 0;

        int i = 0;
        while (line[i] != ' ') {
            name += line[i];
            i++;
        }
        i++;

        while (line[i] != ' ') {
            orders = orders * 10 + (line[i] - '0');
            i++;
        }
        i++;

        if (line[i] == '{') {
            i++;
            int price = 0;

            while (line[i] != '}') {
                if (line[i] == ',') {
                    prices[priceCount++] = price;
                    price = 0;
                } else {
                    price = price * 10 + (line[i] - '0');
                }
                i++;
            }
            prices[priceCount++] = price;
        }

        Name[idx] = name;
        Order[idx] = orders;
        for (int j = 0; j < priceCount; j++) {
            Prices[idx][j] = prices[j];
        }
        count[idx] = priceCount;
        idx++;
    }

    file.close();
}

bool isEligible(int ord, int amount, int index) {
    if (Order[index] < ord) {
        return false;
    }
    for (int i = 0; i < count[index]; i++) {
        if (Prices[index][i] >= amount) {
            return true;
        }
    }
    return false;
}

void enterInFile(string f_name, string nm) {
    fstream file;
    file.open(f_name, ios::out | ios::app);
    file << nm << endl;
    file.close();
}