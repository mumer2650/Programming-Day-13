#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
void readFromFile(string f_name);
void enterInFile(string f_name,string total);
fstream file;
string arr[2];
main()

{
    string total;
    string cake1 = "###################", cake2 = "*******************";
    string cake;
    readFromFile("name.txt");
    int age = stoi(arr[1]);
    if (age % 2 == 0)
    {
        cake = "# " + arr[1] + " HB " + arr[0] + "! " + arr[1] + " #";
        cout << cake1 << endl;
        cout << cake << endl;
        cout << cake1 << endl;
        total = cake1 +"\n"+ cake +"\n"+ cake1; 
    }
    else
    {
        cake = "* " + arr[1] + " HB " + arr[0] + "! " + arr[1] + " *";
        cout << cake2 << endl;
        cout << cake << endl;
        cout << cake2 << endl;
        total = cake2 + "\n"+ cake +"\n"+ cake2;
    }
    enterInFile("add.txt",total);
}
void readFromFile(string f_name)
{
    string line;
    file.open(f_name, ios::in);
    int idx = 0;
    string st;
    while (!file.eof())
    {

        getline(file, line);
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ',')
            {
                arr[idx] = st;;
                idx++;
                st = "";
            }
            else
            {
                st += line[i];
            }
        }
    }
    arr[idx] = st;
    file.close();
}
void enterInFile(string f_name,string total)
{
    file.open(f_name, ios::out);
    file << total;
    file.close();
}
