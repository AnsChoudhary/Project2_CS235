/****************************************************************************************************************************
Title        : Garage.hpp
Authors      : Violent (captain), Khan, Yash, Nigel
Description  : header/interface file of a Garage class which borrows heavily from the ArrayBag ADT
****************************************************************************************************************************/

#ifndef GARAGE_
#define GARAGE_

#include <vector>

template <typename ItemType>
class Garage
{

public:
    /** default constructor **/
    Garage(size_t capacity = 12);

    /**
        @return spaces_occupied_ : the number of vehicles currently stored in the caller
    **/
    size_t getCurrentSize() const;

    /**
        @return true if spaces_occupied_ == 0, false otherwise
    **/
    bool isEmpty() const;

    /**
        @return true if to_add was successfully added to items_, false otherwise
    **/
    bool add(const ItemType &to_add);

    /**
        @return true if a single instance of an_entry was successfully removed from items_, false otherwise
    **/
    bool remove(const ItemType &to_remove);

    /**
        @return true if you manage to swap the given items, false otherwise.
    **/
    bool swap(ItemType in, ItemType out);

    /**
        @return the number of times an_entry is found in items_
    **/
    int getFrequencyOf(const ItemType &an_entry) const;

    /**
     @return a vector that has the same contents as items_
     **/
    std::vector<ItemType> toVector() const;

    /**
        @return true if spaces_occupied_ == capacity_, false otherwise
    **/
    bool isFull() const;

    /**
        @post spaces_occupied_ == 0
    **/
    void clear();

    /**
        @return true if an_entry is found in items_, false otherwise
    **/
    bool contains(const ItemType &an_entry) const;

    /**
      Outputs the names of the content in the Garage ADT.
      If there are multiple instances of an item in the Garage, you only output it once.

        Example Output:
                Item_1_Name Item_1_Manufacturer
                Item_2_Name Item_2_Manufacturer
                Item_3_Name Item_3_Manufacturer

    **/
    void display() const;

    /** implements Set Union over the caller and a_garage. The union of two sets A and B is the set of elements which are in A, in B, or in both A and B.
		@param a_garage to be combined with the contents of this (the calling) garage
        @post adds as many items from a_garage as space allows
	*/
    void operator+=(const Garage<ItemType> &a_garage);

    /** implements Set Difference over the caller and a_garage. The difference between two sets A and B is the set that consists of the elements of A which are not elements of B
		@param a_garage to be subtracted from this (the calling) garage
        @post removes all data from items_ that are also found in a_garage
	*/
    void operator-=(const Garage<ItemType> &a_garage);

    /** implements Set Intersection over the caller and a_garage.
     * The intersection of two sets A and B is the set that consists of the elements that are in both A and B
		@param a_garage to be intersected with this (the calling) garage
		@post items_ no longer contains data that is not found in a_garage
	*/
    void operator/=(const Garage<ItemType> &a_garage);

protected:
  ItemType* items_;           // Array of garage items
    size_t spaces_occupied_;    // Current count of garage items
    size_t capacity_;           // Size of items_


    /**
        @param target to be found in items_
        @return either the index target in the array items_ or -1,
        if the array does not contain the target.
    **/
    int getIndexOf(const ItemType &target) const;

}; // end Garage

#include "Garage.cpp"
#endif



