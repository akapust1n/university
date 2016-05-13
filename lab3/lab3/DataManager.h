#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <string>
using namespace std;
class DataManager
{
public:
    virtual void WriteData() = 0;


  protected:
    string DataName;
};

class ConcreteDataManager
{
public:
    ConcreteDataManager(string Filename);
     virtual void WriteData() final;



};

#endif // DATAMANAGER_H
