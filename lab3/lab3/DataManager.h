#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <DataRead.h>
#include <SceneObjects.h>
#include <string>
using namespace std;

class DataManager {
public:
    virtual void WriteData() = 0;

protected:
    string DataName;
};
class FileStreamDataRead;
class ConcreteDataManager {
public:
    ~ConcreteDataManager() {}
    //virtual void WriteData() final {}

private:
    FileStreamDataRead file_stream_data_read;

    ConcreteModel1 model;

public:
    ConcreteDataManager(string Filename);
    ConcreteModel1* getModel();
};

#endif // DATAMANAGER_H
