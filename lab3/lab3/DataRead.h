#ifndef DATAREAD_H
#define DATAREAD_H
#include <fstream>
#include <string>
#include <SceneObjects.h>
using namespace std;
class DataRead {
public:
    virtual void ReadData() = 0;

protected:
    string SourceName;
};

class FileStreamDataRead : public DataRead {
public:
    FileStreamDataRead(string fileName) ;
    ~FileStreamDataRead();
    virtual void ReadData() final;
    void open_file();
    int  read_number_vertices();
    int read_number_edges();
    void set_model_type(PrototypeModel *obj1);
    template <class T>  void mem_allocation_type(T* u , int size);
    void mem_allocation();
private:
    ConcreteModel1 *model; //может не стоит прямо судя модель девать? - не знаю как переделать
    ifstream model1;
};

#endif // DATAREAD_H
