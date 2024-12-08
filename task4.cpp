#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char arr[100]; 
char arr1[30]; 
string alph = "abcdefghijklmnopqrstuvwxyz";

void readFromFile(string f_name);
void appendInFile(string f_name);

int main()
{
    readFromFile("alpha.txt");
    appendInFile("alpha.txt");
    return 0;
}

void readFromFile(string f_name)
{
    ifstream file(f_name);
    int idx = 0;
    string line;
    while (getline(file, line))
    {
        for (int i = 0; i < line.length() && idx < 100; i++)
        {
            arr[idx] = line[i];
            idx++;
        }
    }
    arr[idx] = '\0';
    file.close();
}

void appendInFile(string f_name)
{
    int idx = 0;
    for (int i = 0; i < alph.length(); i++)
    {
        bool found = false;
        for (int j = 0; arr[j] != '\0'; j++)
        {
            if (alph[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            arr1[idx] = alph[i];
            idx++;
        }
    }
    arr1[idx] = '\0';

    ofstream file(f_name, ios::app);
    file << '\n';
    for (int k = 0; arr1[k] != '\0'; k++)
    {
        file << arr1[k];
    }
    file.close();
}
