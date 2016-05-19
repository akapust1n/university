#ifndef DATAREAD_H
#define DATAREAD_H
#include <SceneObjects.h>
#include <fstream>
#include <string>
using namespace std;
class DataRead {
public:
    virtual void ReadData() = 0;

protected:
    string SourceName;
};

class FileStreamDataRead : public DataRead {
public:
    FileStreamDataRead(string fileName);
    ~FileStreamDataRead();
    virtual void ReadData();
    ConcreteModel1* getModel() { return model; }
private:
    void open_file();
    int read_number_vertices();
    int read_number_edges();
    template <class T>
    void mem_allocation_type(T*& u, int size);
    void model_mem_alocation();
    void read_params();
    ConcreteModel1* model;
    ifstream model1;
};

#endif // DATAREAD_H
