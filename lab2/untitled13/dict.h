#ifndef MY_MAP_DICT_H
#define MY_MAP_DICT_H
//--------реализация структуры для хранения
template <typename MyMapType, typename MyMapType2>
struct dict {
    dict();
    // ~dict(){}
    MyMapType first;
    MyMapType2 *second;
    //dict & operator*() { return *ptr; }
    bool operator==(const dict& dict_temp);
    bool operator!=(const dict& dict_temp);
private:
    size_t size = 1;
};

#endif // MY_MAP_DICT_H
