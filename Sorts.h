/*
 * Name: Calvin Aduma
 * Date Submitted:
 * Lab Section: 002
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>
#include <random>

template <class T> std::vector<T> mergeSort(std::vector<T> lst);
template <class T> std::vector<T> quickSort(std::vector<T> lst);
template <class T> void quickSort(std::vector<T> &lst, size_t start, size_t end);

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    T temp;
    size_t vectorLength = lst.size();
    if (vectorLength <= 1) //base case
    {
        return lst;
    }
    size_t mid = vectorLength / 2;
    std::vector<T> left = mergeSort(std::vector<T>(lst.begin(),lst.begin()+mid));
    std::vector<T> right  = mergeSort(std::vector<T>(lst.begin()+mid,lst.end()));
    lst.clear();
    //size_t i = 0;
    // sorts the vector into ascending order
    /*while (i < vectorLength){
        if (lst[i] < lst[i+1]){
            i+=2;
        } else {
            temp = lst[i];
            lst[i] = lst[i+1];
            lst[i+1] = temp;
            i+=2;
        }
    }*/
    typename std::vector<T>::iterator leftPos = left.begin();
    typename std::vector<T>::iterator rightPos = right.begin();
    
    while (leftPos != left.end() && rightPos != right.end())
    {
        if (*leftPos <= *rightPos)
        {
            lst.push_back(*leftPos);
            leftPos++;
        }
        else
        {
            lst.push_back(*rightPos);
            rightPos++;
        }
    }
    while (leftPos != left.end())
    {
        lst.push_back(*leftPos);
        leftPos++;
    }
    while (rightPos != right.end())
    {
        lst.push_back(*rightPos);
        rightPos++;
    }
    return lst;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst)
{
    quickSort(lst, 0, lst.size()-1);
    return lst;
}

template <class T>
void quickSort(std::vector<T> &lst, size_t start, size_t end){
    if (end <= start)
    {
        return;
    }
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(start, end);
    
    int pivotIndex = dis(gen);
    //int firstIndex = (start+end+1)/2;     // gets a number in between start and end. 1 is added to offset for the start position at 0
    T pivotValue = lst[pivotIndex];
    T temp = lst[start];                    // switch of pivotValue and first element in sort
    lst[start] = pivotValue;
    lst[pivotIndex] = temp;
    pivotIndex = start;
    for (size_t i=start+1; i<=end; i++){
        if (lst[i]<pivotValue){
            pivotIndex++;
            temp = lst[pivotIndex];
            lst[pivotIndex] = lst[i];
            lst[i] = temp;
        }
        /*if (i==lst.size()-1){           // once last element has been checked for swap
            temp = lst[firstIndex];
            lst[firstIndex] = lst[pivotIndex];
            lst[pivotIndex] = temp;
        }*/
    }
    temp = lst[start];
    lst[start] = lst[pivotIndex];
    lst[pivotIndex] = temp;
    /*
    // constraint for recursion
    int sortedArrayCount = 0;
    for (int i=1; i<end; i++){
        if (lst[i] < lst[i-1]){
            sortedArrayCount++;
        }
    }*/
    // recursion
    quickSort(lst,start,pivotIndex-1);
    quickSort(lst,pivotIndex+1,end);
    /*if (sortedArrayCount != end){
        quickSort(lst,start,pivotIndex-1, sortedArrayCount);
        quickSort(lst,pivotIndex+1,end, sortedArrayCount);
    } else {
        return lst;
    }*/
}
