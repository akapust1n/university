#ifndef SUPERFILE_H
#define SUPERFILE_H
#include <vector>
#include <QSharedPointer>
#include <QtDebug>
using namespace std;
struct info{
    double start;
    double end;
    double step;
};

class Method
{
protected:
  QSharedPointer<info> info2;
  vector<double> x_values;
  vector<double> y_values;
public:
   vector<double> getXvalues();
   Method(decltype(info2) info1);
   virtual ~Method(){}
   virtual vector<double> getValues() = 0;

};

class Pickar1: public Method
{
public:
   Pickar1(decltype(info2) info1):Method(info1){qDebug()<<"into Pickar1"; }
   vector<double> getValues() override ;

};


class Pickar2: public Method
{
public:
   Pickar2(decltype(info2) info1):Method(info1){ }
    vector<double> getValues() override;
};

class Pickar3: public Method
{
public:
   Pickar3(decltype(info2) info1):Method(info1){ }
    vector<double> getValues()override ;
};

class Pickar4: public Method
{
public:
   Pickar4(decltype(info2) info1):Method(info1){ }
    vector<double> getValues()override ;
};
class ExplicitMethod: public Method
{
public:
   ExplicitMethod(decltype(info2) info1):Method(info1){ }
   vector<double> getValues() override;
};

class NotExplicitMethod: public Method
{
public:
   NotExplicitMethod(decltype(info2) info1):Method(info1){ }
   vector<double> getValues() ;
};

class RungeKutt: public Method
{
public:
   RungeKutt(decltype(info2) info1, double alpha);
   vector<double> getValues() override;
private:
   double alpha;
};


#endif // SUPERFILE_H
