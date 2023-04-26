#include "dynamic_array.hpp"
#include <iostream>
#include <fstream>
#include <string>

DynamicArray::DynamicArray(){
    size = 0;
    array = new int [size];
}

DynamicArray::~DynamicArray(){
    delete [] array;
}

unsigned int DynamicArray::getSize()
{
    return size;
}

void DynamicArray::addToBeginning(int value){
    int* tempArray = new int[size + 1];
    for(int i = 0; i < size; i++){
        tempArray[i + 1] = array[i];
    }
    //std::copy(array + 1, array + size, tempArray);
    tempArray[0] = value;
    size++;
    delete [] array;    // usuwanie starego miejsca w pamięci arraya
    array = tempArray;  // nowe miejsce w pamięci arraya (to są wskaźniki!!!)
}

void DynamicArray::addToEnd(int value){
    int * tempArray = new int[size + 1];
    std::copy(array, array + size, tempArray);  // skopiowanie array do tempArray
    tempArray[size++] = value;
    delete [] array;
    array = tempArray;
    //array = tempArray;
    //delete [] tempArray;    // usunięcie tempArray po jego wykorzystaniu
}

bool DynamicArray::addToIndex(int index, int value){
    if(index <= size && index >= 0){
        int * tempArray = new int[size + 1];
        for(int i = 0; i < index; i++){
            tempArray[i] = array[i];
        }
        tempArray[index] = value;
        for(int j = index; j < size; j++){
            tempArray[j + 1] = array[j];
        }
        size++;
        delete [] array;
        array = tempArray;

        return true;
    }

    else return false;

}

void DynamicArray::deleteBeginning(){
    if(size > 0){
        int* tempArray = new int[--size];   // od razu zmniejszamy rozmiar tablicy
        for(int i = 0; i < size; i++){
            tempArray[i] = array[i + 1];
        }
        delete [] array;    // usuwanie starego miejsca w pamięci arraya
        array = tempArray;  // nowe miejsce w pamięci arraya (to są wskaźniki!!!)
    }
    else{
        std::cout << "Dynamic array is empty!" << std::endl;
        return;
    }
}

void DynamicArray::deleteEnd(){
    if(size > 0){
        int* tempArray = new int[--size];   // od razu zmniejszamy rozmiar tablicy
        for(int i = 0; i < size; i++){
            tempArray[i] = array[i];
        }
        delete [] array;    // usuwanie starego miejsca w pamięci arraya
        array = tempArray;  // nowe miejsce w pamięci arraya (to są wskaźniki!!!)
    }
    else{
        std::cout << "Dynamic array is empty!" << std::endl;
        return;
    }
}

bool DynamicArray::deleteAtIndex(int index){
    if(index < size && size > 0){
        int * tempArray = new int[--size];
        for(int i = 0; i < index; i++){
            tempArray[i] = array[i];
        }

        for(int j = index; j < size; j++){
            tempArray[j] = array[j + 1];
        }

        delete [] array;
        array = tempArray;

        return true;
    }

    else return false;
}

int DynamicArray::search(int value){
    for(int i = 0; i < size; i++){
        if(array[i] == value){
            // std::cout << "Element has been found!" << std::endl;
            return i;
        }
    }

    // std::cout << "Element has not been found!" << std::endl;
    return -1;
}

void DynamicArray::fillRandom(int quantity, int range){
    srand(time(NULL));
    for(int i = 0; i < quantity; i++){
        int randomNumber = rand() % range;
        addToEnd(randomNumber);
    }
}

void DynamicArray::print(){
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

bool DynamicArray::fileRead(std::string filename){
    std::string line;
    std::ifstream file;
    file.open(filename);
    if(file.is_open()){
        while(std::getline(file, line)){
            addToEnd(std::stoi(line));
        }
        file.close();
        
        return true;
    }

    return false;
}