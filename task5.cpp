#include <iostream>
#include <fstream>
using namespace std;
char alpha[27] {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '
};
string code[29] {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-.-.-.-"
    };
char arr[30];
void readFromFile(string f_name);
void appendInFile(string f_name);
main()
{
    readFromFile("test.txt");
    appendInFile("test.txt");
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
        file << code[k];
    }
    file.close();
    cout << "Missing letters appended successfully!" << endl;
}