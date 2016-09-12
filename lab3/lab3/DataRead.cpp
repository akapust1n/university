#include "my_exception.h"
#include <DataRead.h>
#include <iostream>
#include <typeinfo>
FileStreamDataRead::FileStreamDataRead(string Filename)
{

    SourceName = Filename;
    model = new ConcreteModel1;
}

FileStreamDataRead::~FileStreamDataRead()
{

    if (!model->full) {
        if (!model->links)
            delete[] model->links;
        if (!model->x)
            delete[] model->x;
        if (!model->y)
            delete[] model->y;
        if (!model->z)
            delete[] model->z;
        delete model;
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
    model->vertices = z;
    return z;
}
int FileStreamDataRead::read_number_edges()
{
    int z = 0;
    if (!(model1 >> z) or z < 1)
        throw file_read_error();
    model->edge_num = z;
    return z;
}
template <class T>
void FileStreamDataRead::mem_allocation_type(T*& u, int size)
{
    u = new T[size]();
    if (!u)
        throw memory_alloc_error();
}

void FileStreamDataRead::model_mem_alocation()
{
    mem_allocation_type<double>(model->x, model->vertices);
    mem_allocation_type<double>(model->y, model->vertices);
    mem_allocation_type<double>(model->z, model->vertices);
    mem_allocation_type<int>(model->links, model->edge_num);
}
void FileStreamDataRead::read_params()
{
    //считываем модель
    for (int i = 0; i < model->vertices; i++) {
        if (!(model1 >> model->x[i]))
            throw file_read_error();
        if (!(model1 >> model->y[i]))
            throw file_read_error();
        if (!(model1 >> model->z[i]))
            throw file_read_error();
    }
    //считываем связи
    for (int i = 0; i < model->edge_num; i++) {
        if (!(model1 >> model->links[i]))
            throw file_read_error();
    }
}

void FileStreamDataRead::ReadData()
{
    open_file();

    read_number_vertices(); //считываем количество вершин
    read_number_edges(); // считываем количество ребер

    //выделяем память под ребра и вершины
    model_mem_alocation();

    //читаем параметры модели(ребра и вершины)
    read_params();

    model->full = true;
}
