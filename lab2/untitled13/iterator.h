#ifndef ITERATOR_H
#define ITERATOR_H
template <typename VType>
class iteratorM {
public:
    explicit iteratorM(VType* init)
        : ptr(init)
    {
    }
    ~iteratorM() {}

    VType& value() { return *ptr; }

    void operator++()  { ++ptr; }
    void operator--()  { --ptr; }

    bool operator==(iteratorM<VType>& it) const { return ptr == it.ptr; }
    bool operator!=(iteratorM<VType>& it) const { return ptr != it.ptr; }
    bool operator>(iteratorM<VType>& it) const { return ptr > it.ptr; }
    bool operator<(iteratorM<VType>& it) const { return ptr < it.ptr; }
    bool operator>=(iteratorM<VType>& it) const { return ptr >= it.ptr; }
    bool operator<=(iteratorM<VType>& it) const { return ptr <= it.ptr; }

    VType& operator*() { return *ptr; }

private:
    VType* ptr;
};

template <typename VType>
class const_iteratorM {
public:
    explicit const_iteratorM(VType* init)
        : ptr(init)
    {
    }
    ~const_iteratorM() {}

    const VType& value() const { return *ptr; }

    void operator++() { ++ptr; }
    void operator--() { --ptr; }

    bool operator==(iteratorM<VType>& it) const { return ptr == it.ptr; }
    bool operator!=(iteratorM<VType>& it) const { return ptr != it.ptr; }
    bool operator>(iteratorM<VType>& it) const { return ptr > it.ptr; }
    bool operator<(iteratorM<VType>& it) const { return ptr < it.ptr; }
    bool operator>=(iteratorM<VType>& it) const { return ptr >= it.ptr; }
    bool operator<=(iteratorM<VType>& it) const { return ptr <= it.ptr; }

    const VType& operator*() const { return *ptr; }

private:
    VType* ptr;
};
#endif // ITERATOR_H
