#ifndef MY_MAP_DICT_H
#define MY_MAP_DICT_H
#include <stdlib.h>
//--------реализация структуры для хранения
template <typename MyMapType, typename MyMapType2>
struct dict {
    dict();
    ~dict();
    dict(dict&& item);
    dict(const dict& item);

    MyMapType first;

    bool operator==(const dict& dict_temp) const;
    bool operator!=(const dict& dict_temp) const;
    dict& operator=(const dict& item);
    void grow();
    size_t getsize() const { return size; }
    size_t getcurrentMeaning() const { return currentMeaning; }
    MyMapType getSecond() { return second[currentMeaning]; }
    const MyMapType cgetSecond() const { return second[currentMeaning]; }
    void setSecond(MyMapType2 temp) { second[currentMeaning] = temp; }

    void setcurrentMeaning(size_t i);

private:
    MyMapType2* second;
    size_t size = 1;
    size_t currentMeaning = 0;
    size_t grow_size = 1;
};

#endif // MY_MAP_DICT_H
