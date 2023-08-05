#include "sequential-list.h"

SequentialList::SequentialList(unsigned int cap) {
    capacity_ = cap;
    size_ = 0;
    data_ = new DataType[capacity_];
}


SequentialList::~SequentialList() {
    delete [] data_;
    data_ = nullptr;
}


unsigned int SequentialList::size() const {
    return size_;
}


unsigned int SequentialList::capacity() const {
    return capacity_;
}


bool SequentialList::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}


bool SequentialList::full() const {
    if (size_ == capacity_)
        return true;
    else
        return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const {
    if (index < size_) {
        return data_[index];
    } else {
        return data_[size_-1];
    }
}

unsigned int SequentialList::search(DataType val) const {
    for (unsigned int i = 0; i < size_; i++) {
        if (data_[i] == val) {
            return i; // Return the index if the value is found
        }
    }
    return size_; // Return size_ if the value is not found
}


void SequentialList::print() const {
    for (int i=0; i <= size_; i++)
        std::cout << data_[i] << " -> ";
}

bool SequentialList::insert(DataType val, unsigned int index) {
    if (size_ >= capacity_) {
        return false;
    }

    if (index > size_) {
        return false; // Invalid index
    }

    for (unsigned int i = size_; i > index; i--) {
        data_[i] = data_[i-1];
        //data_[i] == null (1 index past size_) = Null

    }

    data_[index] = val;
    size_++; // Increment the size of the list

    return true;
}

bool SequentialList::insert_front(DataType val) {
    return insert(val, 0);
}


bool SequentialList::insert_back(DataType val) {
    return insert(val,size_);
}

bool SequentialList::remove(unsigned int index) {
    if (index >= size_) {
        return false;
    }

    for (unsigned int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i + 1];
    }

    data_[size_ - 1] = DataType(NULL);
    size_--;

    return true;
}



bool SequentialList::remove_front() {
    return remove(0);
}


bool SequentialList::remove_back() {
    return remove((size_-1));

}


bool SequentialList::replace(unsigned int index, DataType val) {
    return remove(index), insert(val,index);
}
