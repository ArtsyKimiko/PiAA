#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadFile
{
    int size;
public:
    double *array;
    ReadFile(ifstream &input, int size_to_test=0)
    {
        array = nullptr;
        readData(input, size_to_test);
    }
    ~ReadFile()
    {
        delete[] array;
    }
    int fileSize()
    {
        return size;
    }
    void readData(ifstream &input, int size_to_test)
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

        if(size_to_test == 0)
            size_to_test=size;
        for (int i = 0; i < size_to_test; i++) 
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
};