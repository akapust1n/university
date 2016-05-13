#ifndef DATAREAD_H
#define DATAREAD_H
#include <fstream>
#include <string>
using namespace std;
class DataRead {
public:
    virtual void ReadData(string name_source) = 0;

protected:
    string SourceName;
};

class FileStreamDataRead : public DataRead {
public:
    FileStreamDataRead(string fileName) { SourceName = fileName; }
    virtual void ReadData() final;

private:
    ifstream model1;
};

#endif // DATAREAD_H
