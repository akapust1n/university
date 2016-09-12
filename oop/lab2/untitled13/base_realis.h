#pragma once
//получение размера
size_t base::get_size() const
{
    return size;
}
//проверка на пустоту
bool base::is_empty() const
{
    return (size == 0) ? 1 : 0;
}
//получение максимального размера
size_t base::get_maxsize() const
{
    return max_size;
}
