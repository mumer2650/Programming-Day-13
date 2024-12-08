#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char arr[100];  

void readFromFile(string f_name);
void appendInFile(string f_name);
main()
{
    readFromFile("data.txt");
    appendInFile("data.txt");
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
    ofstream file(f_name, ios::app);
    file << '\n';
    for (int k = 0; arr[k] != '\0'; k++)
    {
        if(arr[k] != '[' && arr[k] != ']')
            file << arr[k];
    }
    file.close();
}