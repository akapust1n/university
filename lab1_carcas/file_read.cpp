#include <QString>
#include <QtWidgets>
#include <cstring>
#include <file_read.h>
#include <fstream>
#include <redraw.h>

using namespace std;
//выделение памяти под плоскость
eCodeFile mem_allocation_double(double*& x, int number)
{
    x = new double[number];
    if (!(x))
        return cfOutOfMemory;
    return cfFine;
}
eCodeFile mem_allocation_int(int*& x, int number)
{
    x = new int[number];
    if (!(x))
        return cfOutOfMemory;
    return cfFine;
}
eCodeFile read_vertices(sModel& model, file_data& m, int vertices_read)
{
    eCodeFile error_code = cfFine;

    for (int i = 0; i < vertices_read && error_code == cfFine;
         i++) {
        error_code = read_3points(m, model, i);
    }
    return error_code;
}
eCodeFile read_edges(sModel& model, file_data& m, int edges_read)
{
    eCodeFile error_code = cfFine;

    for (int i = 0; i < edges_read && error_code == cfFine;
         i++) {
        error_code = read_2points(m, model, i);
    }
    return error_code;
}
eCodeFile model_vertices_alocation(sModel& model, int vertices)
{
    eCodeFile error_code = cfFine;
    model.vertices = vertices;
    error_code = mem_allocation_double(model.x, vertices);
    if (error_code != cfFine)
        return error_code;
    error_code = mem_allocation_double(model.y, vertices);
    if (error_code != cfFine)
        return error_code;
    error_code = mem_allocation_double(model.z, vertices);
    if (error_code != cfFine)
        return error_code;

    return error_code;
}
eCodeFile model_links_allocation(sModel& model, int edges)
{
    eCodeFile error_code = cfFine;
    model.edge_num = edges;
    error_code = mem_allocation_int(model.links, edges);
    if (error_code != cfFine)
        return error_code;
    return error_code;
}
eCodeFile model_mem_alocation(sModel& model_buffer, int vertices_read, int edges_read)
{
    eCodeFile error_code = cfFine;
    error_code = model_vertices_alocation(model_buffer, vertices_read); //выделяем память под вершины);
    if (error_code != cfFine)
        return error_code;
    error_code = model_links_allocation(model_buffer, edges_read); //выделяем память по вершины
    if (error_code != cfFine)
        return error_code;

    return error_code;
}

bool open_file(ifstream* model1, const char* filename)
{
    model1->open(filename);
    if (model1->fail())
        return false;
    return true;
}
int read_number_vertices(file_data& m)
{
    int z = 0;
    if (!(m.model1 >> z))
        return -1;
    return z;
}
int read_number_edges(file_data& m)
{
    int z = 0;
    if (!(m.model1 >> z))
        return -1;
    return z;
}
void clearOldModel(sModel& model)
{
    if (model.x)
        delete[] model.x;
    if (model.y)
        delete[] model.y;
    if (model.z)
        delete[] model.z;
    return;
}
eCodeFile read_params(sModel& model_buffer, file_data& m, int vertices_read, int edges_read)
{
    eCodeFile error_code = cfFine;
    error_code = read_vertices(model_buffer, m, vertices_read); //считываем ребра
    if (!error_code)
        error_code = cfCorrupted;
    error_code = read_edges(model_buffer, m, edges_read);
    if (!error_code)
        error_code = cfCorrupted;
    return error_code;
}
eCodeFile read_2points(file_data& m, sModel& model, int i)
{
    bool read_one = 1;
    bool read_two = 1;
    eCodeFile error_code = cfFine;
    read_one = m.model1 >> (model.links[i]);
    if (!read_one)
        error_code = cfCorrupted;
    read_two = m.model1 >> (model.links[i]);
    if (!read_two)
        error_code = cfCorrupted;
    return error_code;
}

eCodeFile read_3points(file_data& m, sModel& model, int i)
{
    bool read_x = 1;
    bool read_y = 1;
    bool read_z = 1;
    eCodeFile error_code = cfFine;
    read_x = m.model1 >> (model.x[i]);
    if (!read_x)
        error_code = cfCorrupted;
    read_y = m.model1 >> (model.y[i]);
    if (!read_y)
        error_code = cfCorrupted;
    read_z = m.model1 >> (model.z[i]);
    if (!read_z)
        error_code = cfCorrupted;
    return error_code;
}

eCodeFile read_model_info(sModel*& model_buffer, file_data& m)
{
    eCodeFile error_code = cfFine;
    int vertices_read = read_number_vertices(m); //считываем количество вершин
    int edges_read = read_number_edges(m);    // считываем количество ребер
    if (vertices_read == -1)
        return cfCorrupted;
     //выделяем память под ребра и вершины
    error_code = model_mem_alocation(*model_buffer, vertices_read, edges_read);
    if (error_code != cfFine) {
        return error_code;
    }
     //читаем параметры модели(ребра и вершины)
    error_code = read_params(*model_buffer, m, vertices_read, edges_read);
    if (error_code != cfFine) {
        clearOldModel(*model_buffer);
        return error_code;
    }

    return error_code;
}

sModel* initBufModel()
{
    sModel* m = new sModel;
    m->dx = 0;
    m->dy = 0;
    m->dz = 0;
    m->fx = 0;
    m->fy = 0;
    m->fz = 0;
    m->M = 1;
    m->vertices = 0;
    m->x = 0;
    m->y = 0;
    m->z = 0;
    m->links = 0;
    return m;
}
void close_file_struct(file_data& m)
{
    m.model1.close();
}

eCodeFile file_read(sModel& model, const char* filename)
{
    file_data m;

    if (!open_file(&m.model1, filename)) //открываем файл
        return cfNotFound;

    sModel* model_buffer = initBufModel(); //создаем буферную модель
    eCodeFile error_code = cfFine;
    error_code = read_model_info(model_buffer, m); //считываем информацию о модели
    close_file_struct(m); //закрываем поток

    if (error_code == cfFine) //загружаем буферную модель в модель
    {
        clearOldModel(model);
        model = *model_buffer;
    }

    return error_code;
}
