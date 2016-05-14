#include "my_exception.h"
#include <DataRead.h>
#include <typeinfo>
 FileStreamDataRead::FileStreamDataRead(string Filename)
{
    SourceName = fileName;
    model1 = new ConcreteModel1;
}
FileStreamDataRead::~FileStreamDataRead()
{
if(!model->full)
{
   if(!model->links)
       delete[] model->links;
   if (!model->x)
       delete model->x;
   if (!model->y)
       delete model->y;
   if (!model->z)
       delete model->z;
}
}

void FileStreamDataRead::open_file()
{
    model1.open(SourceName);
    if (model1.fail())
        throw file_read_error();
}
int FileStreamDataRead::read_number_vertices()
{
    int z = 0;
    if (!(model1 >> z) or z < 1)
        throw file_read_error();
    model.vertices = z;
    return z;
}
int FileStreamDataRead::read_number_edges()
{
    int z = 0;
    if (!(model1 >> z) or z < 1)
        throw file_read_error();
    model.edge_num = z;
    return z;
}
template< class T>
void FileStreamDataRead::model_mem_alocation(T* u, int size)
{

}

void FileStreamDataRead::model_mem_alocation(int vertices,int edges){
    error_code = mem_allocation_double(model.x, vertices);
    if (error_code != cfFine)
        return error_code;
    error_code = mem_allocation_double(model.y, vertices);
    if (error_code != cfFine)
        return error_code;
    error_code = mem_allocation_double(model.z, vertices);
    if (error_code != cfFine)
        return error_code;



}

void FileStreamDataRead::ReadData()
{
    open_file();
    read_number_vertices();
    read_number_edges();

    int vertices_read = read_number_vertices(); //считываем количество вершин
    int edges_read = read_number_edges(); // считываем количество ребер

    //выделяем память под ребра и вершины
    model_mem_alocation(vertices_read, edges_read);

    //читаем параметры модели(ребра и вершины)
    error_code = read_params( vertices_read, edges_read);
}
