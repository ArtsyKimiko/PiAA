#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadFile
{
    int size;
public:
    double *array;
    
    ReadFile(ifstream &input);
    ~ReadFile();
    void readData(ifstream &input);
};
ReadFile::ReadFile(ifstream &input) 
{
    array = nullptr;
    readData(input);
}
ReadFile::~ReadFile() 
{
    delete[] array;
}
void ReadFile::readData(ifstream &input) 
{
    string line;
    size = 0;
    while (getline(input, line)) 
    {
        size_t pos = line.find_last_of(",");
        string value = line.substr(pos + 1);
        try 
        {
            stod(value);
            size++;
        } 
        catch (const invalid_argument &e) {}
    }
        
    input.clear();
    input.seekg(0, ios::beg);  

    array = new double[size];

    for (int i = 0; i < size; i++) 
    {
        getline(input, line);
        size_t pos = line.find_last_of(",");
        string value = line.substr(pos + 1);
        try 
        {
            stod(value);
            array[i] = stod(value);
        }
        catch (const invalid_argument &e) {}
    }
}
