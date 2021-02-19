#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class IntVector {
    public:
        IntVector();
        IntVector(unsigned size, int value);
        IntVector(unsigned size);
        ~IntVector();
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size1, int value);
        void resize(unsigned size1);
        void reserve(unsigned n);
        void assign(unsigned n, int value);
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
        int & at(unsigned index);
        int & front();
        int & back();
    private:
        void expand();
        void expand(unsigned amount);
        unsigned sz;
        unsigned cap;
        int *data;
};

#endif