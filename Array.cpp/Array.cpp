//Array.cpp
#include "Array.h"
#include <iostream>
using namespace std;

int Compare(void* one, void* other);

int main(int argc, char* argv[]) {
	Array<int> array(3);
	Long index;
	Long(*indexes);
	Long count;
	
	int i;
	int key;

	index = array.Store(0, 100);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;
	
	index = array.Store(1, 80);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.Store(2, 60);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.Insert(1, 90);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.AppendFromFront(80);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.AppendFromRear(70);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.Delete(1);
	if (index == -1) {
		cout << "지워졌습니다" << endl;
	}

	index = array.DeleteFromFront();
	if (index == -1) {
		cout << "지워졌습니다" << endl;
	}

	index = array.DeleteFromRear();
	if (index == -1) {
		cout << "지워졌습니다" << endl;
	}

	array.Clear();

	index = array.AppendFromFront(90);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.AppendFromRear(80);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.AppendFromRear(70);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;
	
	index = array.Modify(1, 100);
	cout << array[index] << endl;

	key = 90;
	index = array.LinearSearchUnique(&key, Compare);
	cout << array[index] << endl;
	cout << array.GetAt(index) << endl;

	index = array.Modify(0, 100);
	cout << array[index] << endl;


	key = 100;
	array.LinearSearchDuplicate(&key, &indexes, &count, Compare);
	i = 0;
	while (i < count) {
		cout << array.GetAt(indexes[i]) << endl;
		i++;
	}

	index = array.Modify(0, 80);
	cout << array[index] << endl;

	array.SelectionSort(Compare);

	index = 0;
	cout << array[index] << endl;

	key = 80;
	index = array.BinarySearchUnique(&key, Compare);
	cout << array[index] << endl;

	index = array.Modify(0, 100);
	cout << array[index] << endl;
	
	array.SelectionSort(Compare);

	key = 100;
	array.BinarySearchDuplicate(&key, &indexes, &count, Compare);
	i = 0;
	while (i < count) {
		cout << array[indexes[i]] << endl;
		i++;
	}

	Array<int>one(2);
	index = one.Store(0, 100);
	cout << one[index] << endl;

	index = one.Store(1, 90);
	cout << one[index] << endl;

	one.BubbleSort(Compare);

	Array<int>other(2);
	index = other.Store(0, 80);
	cout << other[index] << endl;

	index = other.Store(1, 70);
	cout << other[index] << endl;

	other.InsertionSort(Compare);

	array.Merge(one, other, Compare);

	Array<int>another(array);

	i = 0;
	while (i < another.GetLength()) {
		cout << another[i] << endl;
		i++;
	}

	Array<int>bad;

	bad = array;
	i = 0;
	while (i < bad.GetLength()) {
		cout << bad[i] << endl;
		i++;
	}
	return 0;
}

int Compare(void* one, void* other) {
	int* one_ = (int*)one;
	int* other_ = (int*)other;
	int ret;
	if (*one_ > *other_) {
		ret = 1;
	}
	else if (*one_ == *other_) {
		ret = 0;
	}
	else if (*one_ < *other_) {
		ret = -1;
	}
	return ret;
}