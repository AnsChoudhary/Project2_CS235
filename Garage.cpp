//Ans Choudhary
//Title:Garage with different itemtypes
//3/10/21

#include <iostream>

using namespace std;

template<typename ItemType>
inline Garage<ItemType>::Garage(size_t capacity)
{
    capacity_ = capacity;
    items_ = new ItemType[capacity_]{};

}

template<typename ItemType>
inline size_t Garage<ItemType>::getCurrentSize() const
{
    return spaces_occupied_;
}

template<typename ItemType>
inline bool Garage<ItemType>::isEmpty() const
{
    return spaces_occupied_ == 0;
}

template<typename ItemType>
inline bool Garage<ItemType>::add(const ItemType& to_add)
{
    if (isFull() == true || (spaces_occupied_ + to_add.getSpaces() > capacity_))
        return false;

    for (size_t i = spaces_occupied_; i < spaces_occupied_ + to_add.getSpaces(); i++)
    {
        items_[i] = to_add;
    }

    spaces_occupied_ += to_add.getSpaces();

    return true;
}


template<typename ItemType>
inline bool Garage<ItemType>::remove(const ItemType & to_remove)
{
    if (spaces_occupied_ == 0)
        return false;

    for (size_t i = 0; i < spaces_occupied_; i++)
    {
        if (items_[i] == to_remove)
        {
            ItemType null;
            for (size_t j = i; j < i + to_remove.getSpaces(); j++)
            {
                items_[j] = null;
            }

            spaces_occupied_ -= to_remove.getSpaces();

            return true;
        }
    }

    return false;
}

template<typename ItemType>
inline bool Garage<ItemType>::swap(ItemType in, ItemType out)
{
    bool isSwapDone = false;

    if (remove(out) == true && add(in) == true)
        isSwapDone = true;

    return isSwapDone;
}

template<typename ItemType>
inline int Garage<ItemType>::getFrequencyOf(const ItemType & an_entry) const
{
    int freq = 0;
    for (size_t i = 0; i < spaces_occupied_; i++)
    {
        if (items_[i] == an_entry)
            freq++;
    }

    return freq;
}

template<typename ItemType>
inline std::vector<ItemType> Garage<ItemType>::toVector() const
{
    std::vector<ItemType> items;

    for (size_t i = 0; i < spaces_occupied_; i++)
        items.push_back(items_[i]);

    return items;
}

template<typename ItemType>
inline bool Garage<ItemType>::isFull() const
{
    return spaces_occupied_ == capacity_;
}

template<typename ItemType>
inline void Garage<ItemType>::clear()
{
    delete[] items_;

    items_ = new ItemType[capacity_];

    spaces_occupied_ = 0;
}

template<typename ItemType>
inline bool Garage<ItemType>::contains(const ItemType & an_entry) const
{
    return (getIndexOf(an_entry) != -1) ? true : false;
}

template<typename ItemType>
inline void Garage<ItemType>::display() const {
    //int numItems = getCurrentSize()
    string temp[20];
    int k=0, j=0;
    bool duplicate= false;  //flag boolean
    for (size_t i = 0; i < spaces_occupied_; i++) {
            // Print the manufacturer and name ONLY once
            if (i==0) {
                cout << items_[i].getManufacturer() << " " << items_[i].getName() << ::endl;
                temp[k] = items_[i].getName();
                k++;
            }
            if (i > 0) {
                for (j=0;j<k;j++) {
                    if (items_[i].getName() == temp[j])
                        duplicate = true;
                }
                if (duplicate != true) {
                    cout << items_[i].getManufacturer() << " " << items_[i].getName() << ::endl;
                    temp[k] = items_[i].getName();
                    k++;
                }
            }
            duplicate = false;
    }
}



template<typename ItemType>
void Garage<ItemType>::operator+=(const Garage<ItemType>& a_garage)
{
    int aSize = a_garage.getCurrentSize();
    //cout << "OP += called/" << " cap : " << capacity_ << "spaces " << spaces_occupied_ << " " << aSize <<  endl;
    // checking if current garage has space
    size_t i = spaces_occupied_;
    for (int j = 0; j < aSize; j++)
    {
         if (capacity_ >(spaces_occupied_) )
         {
                    if (contains(a_garage.items_[j]) != true) {
                        items_[i] = a_garage.items_[j];
                        spaces_occupied_ += items_[i].getSpaces();
                    }
                    i++;
                }
        }
}


template<typename ItemType>
void Garage<ItemType>::operator-=(const Garage<ItemType>& a_garage)
{
    int aSize = a_garage.getCurrentSize();
    for(int j = 0; j< aSize;j++)
    {
        if (a_garage.contains(items_[j]) == true) {
            remove(items_[j]);
            spaces_occupied_ -= items_[j].getSpaces();
        }
    }
}

template<typename ItemType>
void Garage<ItemType>::operator/=(const Garage<ItemType>& a_garage)
{
    int numItems = getCurrentSize() ;

    for (int i = 0; i < getCurrentSize(); i++) {
        if (a_garage.contains(items_[i]) == false) {
            remove(items_[i]);
        }
    }
}


 template<typename ItemType>
int Garage<ItemType>::getIndexOf(const ItemType & target) const
{
    for (size_t i = 0; i < spaces_occupied_; i++)
    {
        if (items_[i] == target)
            return i;
    }

    return -1;
}





