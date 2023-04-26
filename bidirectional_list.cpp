#include "bidirectional_list.hpp"
#include <iostream>
#include <fstream>
#include <string>

BidirectionalList::BidirectionalList(){
    size = 0;
    start = NULL;
    end = NULL;
}

BidirectionalList::~BidirectionalList(){
    delete start;
    delete end;
}


void BidirectionalList::addToBeginning(int value){
    if(start == NULL){
        start = new listElement;
        start -> value = value;
        start -> previous = NULL;
        start -> next = NULL;
        end = start;
        size++;
    }
    else{
        listElement * tempElement = new listElement;    //stworzenie nowego elementu
        tempElement -> value = value;
        tempElement -> next = start;
        start -> previous = tempElement;
        start = tempElement;
        size++;
    }
}

void BidirectionalList::addToEnd(int value){
    if(start == NULL){
        start = new listElement;
        start -> value = value;
        start -> previous = NULL;
        start -> next = NULL;
        end = start;
        size++;
    }
    else{
        listElement * tempElement = new listElement;    //stworzenie nowego elementu
        end -> next = tempElement;
        tempElement -> value = value;
        tempElement -> previous = end;
        tempElement -> next = NULL;
        end = tempElement;
        size++;
    }
}

void BidirectionalList::addToIndex(int index, int value){
    if((!start && index != 0) || (index < 0 || index > size)){
        return;
    }
    else if(index == 0){
        addToBeginning(value);
    }
    else if(index == size){
        addToEnd(value);
    }
    else{
        listElement * temp;
        if(index < (size / 2)){
            temp = start;
            for(int i = 1; i < index; i++){
                temp = temp -> next;
            }
        }
        else{
            temp = end;
            for(int i = 1; i < index; i++){
                temp = temp -> previous;
            }
        }

        listElement * tempElement = new listElement;
        tempElement -> value = value;
        tempElement -> next = temp -> next;
        tempElement -> previous = temp;

        temp -> next -> previous = tempElement;
        temp -> next = tempElement;

        size++;
    }
}

void BidirectionalList::deleteBeginning(){
    if(size == 0){
        return;
    }

    listElement * temp = start -> next;

    if(size > 1){
        temp -> previous = NULL;
        start = temp;
    }
    else{   // jeśli size = 1
        start = NULL;
        end = NULL;
    }
    size--;
}

void BidirectionalList::deleteEnd(){
    if(size == 0){
        return;
    }

    listElement * temp = end -> previous;

    if(size > 1){
        temp -> next = NULL;
        end = temp;
    }
    else{   // jeśli size = 1
        start = NULL;
        end = NULL;
    }
    size--;
}

void BidirectionalList::deleteAtIndex(int index){
    if(index < 0 || index >= size){
        return;
    }
    else if(index == 0){
        deleteBeginning();
    }
    else if(index == size){
        deleteEnd();
    }
    else{
        listElement * temp = start;
        for(int i = 1; i < index; i++){
             temp = temp -> next;
        }

        listElement * tempElement = temp -> next;

        temp -> next = tempElement -> next;
        temp -> next -> previous = tempElement;

        size--;

        if(size == 0){
            start = new listElement;
            start -> next = NULL;
            start -> previous = NULL;
        }
    }
}

int BidirectionalList::search(int value){
    if(!start){
        return -1;
    }
    else{
        listElement * temp = start;
        int i = 0;
        while(temp -> next){
            if(temp -> value == value){
                return 1;
            }
            temp = temp -> next;
            i++;
        }
        if(temp -> value == value){
            return 1;
        }
    }
}

void BidirectionalList::printBeginning(){
    if(!start){
        std::cout << "Bidirectional List is empty!" << std::endl;
        return;
    }
    listElement * temp = start;
    while(temp -> next != NULL){
        std::cout << temp -> value << " ";
        temp = temp -> next;
    }
    std::cout << temp -> value << std::endl;
}

void BidirectionalList::printInverted(){
    if(!start){
        std::cout << "Bidirectional List is empty!" << std::endl;
        return;
    }
    listElement * temp = end;
    while(temp -> previous != NULL){
        std::cout << temp -> value << " ";
        temp = temp -> previous;
    }
    std::cout << temp -> value << std::endl;
}

void BidirectionalList::fillRandom(int quantity, int range){
    srand(time(NULL));
    for(int i = 0; i < quantity; i++){
        int randomNumber = rand() % range;
        addToEnd(randomNumber);
    }
}

bool BidirectionalList::fileRead(std::string filename){
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