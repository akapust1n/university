#include "DataManager.h"
#include <iostream>
ConcreteDataManager::ConcreteDataManager(string Filename)
    : file_stream_data_read(Filename)
{
  //  std::cout<<Filename;
}
ConcreteModel1*  ConcreteDataManager::getModel()
{
   file_stream_data_read.ReadData();
   //file_stream_data_read.getModel();
}
