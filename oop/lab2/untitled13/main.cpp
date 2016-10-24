#include "my_map_realis.h"
#include <iostream>
using namespace std;
int main()
{
    my_map<int, int> obj1;
    my_map<int, int> obj2;
    dict<int, int> word;
    word.first = 1;
    word.setSecond(10);
    obj2.insert(word);
    word.first = 2;
    word.setSecond(11);
    obj2.insert(word);
    word.first = 7;
    word.setSecond(15);
    obj1.insert(word);
    word.first = 4;
    word.setSecond(13);
    obj1.insert(word);
    word.first = 5;
    word.setSecond(14);
    obj1.insert(word);

    iteratorM<dict<int, int> > z1(obj1.begin());
    iteratorM<dict<int, int> > z1_end(obj1.end());
    iteratorM<dict<int, int> > z2(obj2.begin());
    iteratorM<dict<int, int> > z2_end(obj2.end());
    //test const iterator
    const my_map<int, int> obj3(1, word);

    const_iteratorM<const dict<int, int> > c_iter(obj3.cbegin());
    cout << c_iter.value().first << endl;

    cout << "Map 1:" << endl;
    for (; z1 <= z1_end; ++z1)
        cout << z1.value().first << " " << z1.value().getSecond() << endl;
    cout << "Map 2:" << endl;
    for (; z2 <= z2_end; ++z2)
        cout << z2.value().first << " " << z2.value().getSecond() << endl;

    cout << "Swap maps" << endl;

    obj1.swap(obj2);

    iteratorM<dict<int, int> > z1_1(obj1.begin());
    iteratorM<dict<int, int> > z1_1_end(obj1.end());
    iteratorM<dict<int, int> > z2_1(obj2.begin());
    iteratorM<dict<int, int> > z2_1_end(obj2.end());

    cout << "Map 1:" << endl;
    for (; z1_1 <= z1_1_end; ++z1_1)
        cout << z1_1.value().first << " " << z1_1.value().getSecond() << endl;
    cout << "Map 2:" << endl;
    for (; z2_1 <= z2_1_end; ++z2_1)
        cout << z2_1.value().first << " " << z2_1.value().getSecond() << endl;
    //------------пример много значений
    cout << "Two meanings example:" << endl;
    iteratorM<dict<int, int> > z6_1(obj2.begin());
    iteratorM<dict<int, int> > z6_1_end(obj2.end());
    word.first = 7;
    word.setSecond(48);
    obj2.insert(word);

    cout << "new Map 2:" << endl;

    for (; z6_1 <= z6_1_end; ++z6_1) {
        if (z6_1.value().getcurrentMeaning() != 0) {
            z6_1.value().setcurrentMeaning(1);
        }
        cout << z6_1.value().first << " " << z6_1.value().getSecond() << endl;
    }
    //--------поиск
    cout << endl
         << "Find value for map1 key: 2" << endl;

    iteratorM<dict<int, int> > z_find(obj1.find(2));
    cout << "value " << z_find.value().getSecond() << endl;
    cout << obj1.find_elem(2);
    cout << endl
         << "Erase two elements from map2:" << endl;
    iteratorM<dict<int, int> > z1_3(obj2.begin());
    iteratorM<dict<int, int> > z1_3_end(obj2.end());
    ++z1_3;
    obj2.erase(z1_3, z1_3_end);

    cout << "New map: " << endl;

    iteratorM<dict<int, int> > z1_4(obj2.begin());
    iteratorM<dict<int, int> > z1_4_end(obj2.end());

    for (; z1_4 <= z1_4_end; ++z1_4)
        cout << z1_4.value().first << " " << z1_4.value().getSecond() << endl;
    //ловим ошибку

    cout << "Catch the error, wrong indexes: " << endl;

    iteratorM<dict<int, int> > z1_5(obj1.begin());
    iteratorM<dict<int, int> > z1_5_end(obj1.end());
    try {
        obj2.erase(z1_5_end, z1_5);
    } catch (my_base_exception& err) {
        cout << err.what();
    }

    //iteratorM<const dict<int, int> > z1_6_end(obj2.end());
    return 0;
}
