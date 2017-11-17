#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

bool read(int * array, unsigned int size){
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    for(unsigned int i=0; i<size; ++i){
        if(!(stream>>array[i])){
            cout<<"An error has occured while reading input data."<<endl;
            return false;
        }
    }
    return true;
}

void QuickSort(int * array, int left, int right){
	int i=left, j=right;
	int pivot=array[(left+right)/2];
	while(i<=j){
		while(array[i]<pivot){
			i++;
		}
		while(array[j]>pivot){
			j--;
		}
		if(i<=j){
			swap(array[i], array[j]);
			i++; j--;
		}
	}
	if(left<j){
		QuickSort(array, left, j);
	}
	if(i<right){
		QuickSort(array, i, right);
	}
}

int main(){
	int size;
	string number;
	getline(cin, number);
	istringstream num(number);
	if(!(num>>size)||(size<2)){
		cout<<"An error has occured while reading input data"<<endl;
		return -1;
	}
	int * array = new int[size];
	if(read(array, size)){
		QuickSort(array, 0, size - 1);
	}
	for(unsigned int i=0; i<size; ++i){
		cout<<array[i]<<" ";
	}
	return 0;
}
