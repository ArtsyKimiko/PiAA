#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// read file x; x.array[i] = 434556678;

class ReadFile
{
    int size;
    string line;
public:
    double *array;

    ReadFile(ifstream &input, int size_to_test)
    {
        array=nullptr;
        checkData(input);
    }
    ~ReadFile()
    {
        delete[] array;
    }
    int fileSize()
    {
        return size;
    }
    void checkData(ifstream &input)
    {
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
    }
    void readData(ifstream &input, int size_to_test)
    {
        if(size_to_test == 0 || size_to_test > size)
            size_to_test=size;  
        array = new double[size_to_test];
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