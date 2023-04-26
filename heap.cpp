#include "heap.hpp"
#include <iostream>
#include <fstream>
#include <string>

Heap::Heap(){
    currentSize = 0;
    heapArray = new int [currentSize];
}

Heap::~Heap(){
    delete [] heapArray;
}

void Heap::heapify(int nodeIndex){
    int parentIndex = (nodeIndex - 1) / 2;
    if(heapArray[nodeIndex] > heapArray[parentIndex] && parentIndex >= 0){
        int temp = heapArray[parentIndex];
        heapArray[parentIndex] = heapArray[nodeIndex];
        heapArray[nodeIndex] = temp;
        heapify(parentIndex);
    }
}

void Heap::add(int value){
    int * tempArray = new int[currentSize + 1];
    tempArray[currentSize] = value;
    for(int i = 0; i < currentSize; i++){
        tempArray[i] = heapArray[i];
    }
    currentSize++;

    delete [] heapArray;
    heapArray = tempArray;

    heapify(currentSize - 1);
}

void Heap::deleteMax(){
    if(currentSize > 0){
        int * tempArray = new int[--currentSize];
        for(int i = 0; i < currentSize; i++){
            tempArray[i] = heapArray[i + 1];
        }

        delete [] heapArray;
        heapArray = tempArray;

        for(int i = 0; i < currentSize; i++){
            heapify(i);
        }
    }
    else{
        std::cout << "Heap is empty!" << std::endl;
        return;
    }
}

int Heap::search(int value){
    for(int i = 0; i < currentSize; i++){
        if(heapArray[i] == value){
            // std::cout << "Element has been found!" << std::endl;
            return i;
        }
    }

    // std::cout << "Element has not been found!" << std::endl;
    return -1;
}

void Heap::print(){
    for(int i = 0; i < currentSize; i++){
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::printHeapAsTree(int v, std::string sp, std::string sn) {
    
    std::string s;
    std::string cr = "  ";
    std::string cl = "  ";
    std::string cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    if (v < currentSize)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printHeapAsTree(2 * v + 2, s + cp, cr);

        s = s.substr(0, sp.length() - 2);

        std::cout << s << sn << heapArray[v] << std::endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printHeapAsTree(2 * v + 1, s + cp, cl);
    }
}

void Heap::fillRandom(int quantity, int range){
    srand(time(NULL));
    for(int i = 0; i < quantity; i++){
        int randomNumber = rand() % range;
        add(randomNumber);
    }
}

bool Heap::fileRead(std::string filename){
    std::string line;
    std::ifstream file;
    file.open(filename);
    if(file.is_open()){
        while(std::getline(file, line)){
            add(std::stoi(line));
        }
        file.close();
        
        return true;
    }

    return false;
}