//
// Created by miguel on 21-10-2023.
//

#include "PmergeMe.hpp"

template <typename T>
void displayArr(T first, T last, const std::string msg);

std::vector<int> PmergeMe::mySortV(std::vector<int> arr) {
    std::vector<int> arr1(arr.begin(), arr.begin() + arr.size() / 2);
    std::vector<int> arr2(arr.begin() + arr.size() / 2, arr.end());
    if (arr.size() > 2) {
        arr1 = mySortV(arr1);
        arr2 = mySortV(arr2);

    }
    else {
        if (arr.size() == 2 && arr[0] > arr[1]){
            int temp = arr[1];
            arr[1] = arr[0];
            arr[0] = temp;
        }
        return arr;
    }
    std::vector<int> newArray;
    for (int i2 = 0, i1 = 0; i2 < (int)arr2.size() || i1 < (int)arr1.size();) {
        if (i1 == (int)arr1.size()) {
            newArray.push_back(arr2[i2]);
            i2++;
        } else if (i2 == (int)arr2.size()) {
            newArray.push_back(arr1[i1]);
            i1++;
        } else if (arr1[i1] < arr2[i2]) {
            newArray.push_back(arr1[i1]);
            i1++;
        }
        else {
            newArray.push_back(arr2[i2]);
            i2++;
        }
    }
    return newArray;
}

std::list<int> PmergeMe::mySortL(std::list<int> arr) {

    std::list<int> arr1;
    std::list<int> arr2;
    int size = arr.size();
	if (arr.size() > 2) {
		for (int i = 0; i < size / 2; i++) {
			arr1.push_back(arr.front());
			arr.pop_front();
		}
		for (int i = size / 2; i < size; i++) {
			arr2.push_back(arr.front());
			arr.pop_front();
		}
		arr1 = mySortL(arr1);
		arr2 = mySortL(arr2);
    }
    else {
        if (arr.size() == 2 && arr.front() > arr.back()){
            int temp = arr.front();
            arr.pop_front();
            arr.push_back(temp);
        }
        return arr;
    }
    std::list<int> newArray;
    for (; !arr2.empty() || !arr1.empty();) {
        if (arr1.empty()) {
            newArray.push_back(arr2.front());
            arr2.pop_front();
        } else if (arr2.empty()) {
            newArray.push_back(arr1.front());
            arr1.pop_front();
        } else if (arr1.front() < arr2.front()) {
            newArray.push_back(arr1.front());
            arr1.pop_front();
        }
        else {
            newArray.push_back(arr2.front());
            arr2.pop_front();
        }
    }
    return newArray;
}
