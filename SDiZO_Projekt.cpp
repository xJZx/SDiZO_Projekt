// SDiZO_Projekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "dynamic_array.hpp"
#include "dynamic_array_benchmark.hpp"
#include "bidirectional_list.hpp"
#include "bidirectional_list_benchmark.hpp"
#include "heap.hpp"
#include "heap_benchmark.hpp"
#include "binary_search_tree.hpp"
#include "binary_search_tree_benchmark.hpp"
#include <iostream>

void testManually();
void testBenchmark();
void testDynamicArray();
void testBidirectionalList();
void testHeap();
void testBinarySearchTree();


int main() {
    int switcher = 1;

    while(switcher != 0){
        std::cout << "0 - Leave Programme" << std::endl;
        std::cout << "1 - Manual Testing" << std::endl;
        std::cout << "2 - Benchmarking" << std::endl;
        std::cin >> switcher;
        std::cout << std::endl;
        switch(switcher){
            case 1:
                testManually();
                break;

            case 2:
                testBenchmark();
                break;
        }
    }

}

void testManually(){
    int switcher = 1;

    while(switcher != 0){
        std::cout << "0 - Leave Testing" << std::endl;
        std::cout << "1 - Dynamic Array" << std::endl;
        std::cout << "2 - Bidirectional List" << std::endl;
        std::cout << "3 - Heap" << std::endl;
        std::cout << "4 - Binary Search Tree" << std::endl;
        std::cin >> switcher;
        std::cout << std::endl;
        switch(switcher){
            case 1:
                testDynamicArray();
                break;

            case 2:
                testBidirectionalList();
                break;

            case 3:
                testHeap();
                break;

            case 4:
                testBinarySearchTree();
                break;
        }
    }
}

void testBenchmark(){
    int switcher = 1;

    while(switcher != 0){
        int size;
        DynamicArrayBenchmark * dynamicArrayBenchmark;
        BidirectionalListBenchmark * bidirectionalListBenchmark;
        HeapBenchmark * heapBenchmark;
        BinarySearchTreeBenchmark * binarySearchTreeBenchmark;

        std::cout << "0 - Leave Testing" << std::endl;
        std::cout << "1 - Dynamic Array Benchmark" << std::endl;
        std::cout << "2 - Bidirectional List Benchmark" << std::endl;
        std::cout << "3 - Heap Benchmark" << std::endl;
        std::cout << "4 - Binary Search Tree Benchmark" << std::endl;
        std::cin >> switcher;
        std::cout << std::endl;
        switch(switcher){
            case 1:
                std::cout << "Pass the input size: ";
                std::cin >> size;
                dynamicArrayBenchmark = new DynamicArrayBenchmark(size);
                delete dynamicArrayBenchmark;
                break;

            case 2:
                std::cout << "Pass the input size: ";
                std::cin >> size;
                bidirectionalListBenchmark = new BidirectionalListBenchmark(size);
                delete bidirectionalListBenchmark;
                break;

            case 3:
                std::cout << "Pass the input size: ";
                std::cin >> size;
                heapBenchmark = new HeapBenchmark(size);
                delete heapBenchmark;
                break;

            case 4:
                std::cout << "Pass the input size: ";
                std::cin >> size;
                binarySearchTreeBenchmark = new BinarySearchTreeBenchmark(size);
                delete binarySearchTreeBenchmark;
                break;
        }
    }
}

void testDynamicArray(){
    DynamicArray dynamicArray;
    int switcher = 1;

    while(switcher != 0){
        int index, value, quantity, range;
        std::string filename;
        std::cout << "0 - Leave Testing" << std::endl;
        std::cout << "1 - Add To End" << std::endl;
        std::cout << "2 - Add To Beginning" << std::endl;
        std::cout << "3 - Add To Index" << std::endl;
        std::cout << "4 - Delete End" << std::endl;
        std::cout << "5 - Delete Beginning" << std::endl;
        std::cout << "6 - Delete At Index" << std::endl;
        std::cout << "7 - Search" << std::endl;
        std::cout << "8 - Fill Random" << std::endl;
        std::cout << "9 - Read From File" << std::endl;
        std::cout << "10 - Print" << std::endl;
        std::cin >> switcher;
        std::cout << std::endl;
        switch(switcher){
            case 1:
                std::cout << "Pass the value: ";
                std::cin >> value;
                dynamicArray.addToEnd(value);
                break;

            case 2:
                std::cout << "Pass the value: ";
                std::cin >> value;
                dynamicArray.addToBeginning(value);
                break;

            case 3:
                std::cout << "Pass the index and value: ";
                std::cin >> index >> value;
                dynamicArray.addToIndex(index, value);
                break;

            case 4:
                dynamicArray.deleteEnd();
                break;
            
            case 5:
                dynamicArray.deleteBeginning();
                break;

            case 6:
                std::cout << "Pass the index: ";
                std::cin >> index;
                dynamicArray.deleteAtIndex(index);
                break;

            case 7:
                std::cout << "Pass the value: ";
                std::cin >> value;
                dynamicArray.search(value);
                break;

            case 8:
                std::cout << "Pass the quantity and range: ";
                std::cin >> quantity >> range;
                dynamicArray.fillRandom(quantity, range);
                break;

            case 9:
                std::cout << "Insert filename: ";
                std::cin >> filename;
                dynamicArray.fileRead(filename);
                break;

            case 10:
                dynamicArray.print();
                break;
        }
        std::cout << std::endl;
    }
}

void testBidirectionalList(){
    BidirectionalList bidirectionalList;
    int switcher = 1;

    while(switcher != 0){
        int index, value, quantity, range;
        std::string filename;
        std::cout << "0 - Leave Testing" << std::endl;
        std::cout << "1 - Add To End" << std::endl;
        std::cout << "2 - Add To Beginning" << std::endl;
        std::cout << "3 - Add To Index" << std::endl;
        std::cout << "4 - Delete End" << std::endl;
        std::cout << "5 - Delete Beginning" << std::endl;
        std::cout << "6 - Delete At Index" << std::endl;
        std::cout << "7 - Search" << std::endl;
        std::cout << "8 - Fill Random" << std::endl;
        std::cout << "9 - Read From File" << std::endl;
        std::cout << "10 - Print From Beginning" << std::endl;
        std::cout << "11 - Print Inverted" << std::endl;
        std::cin >> switcher;
        std::cout << std::endl;
        switch(switcher){
            case 1:
                std::cout << "Pass the value: ";
                std::cin >> value;
                bidirectionalList.addToEnd(value);
                break;

            case 2:
                std::cout << "Pass the value: ";
                std::cin >> value;
                bidirectionalList.addToBeginning(value);
                break;

            case 3:
                std::cout << "Pass the index and value: ";
                std::cin >> index >> value;
                bidirectionalList.addToIndex(index, value);
                break;

            case 4:
                bidirectionalList.deleteEnd();
                break;
            
            case 5:
                bidirectionalList.deleteBeginning();
                break;

            case 6:
                std::cout << "Pass the index: ";
                std::cin >> index;
                bidirectionalList.deleteAtIndex(index);
                break;

            case 7:
                std::cout << "Pass the value: ";
                std::cin >> value;
                bidirectionalList.search(value);
                break;

            case 8:
                std::cout << "Pass the quantity and range: ";
                std::cin >> quantity >> range;
                bidirectionalList.fillRandom(quantity, range);
                break;

            case 9:
                std::cout << "Insert filename: ";
                std::cin >> filename;
                bidirectionalList.fileRead(filename);
                break;

            case 10:
                bidirectionalList.printBeginning();
                break;

            case 11:
                bidirectionalList.printInverted();
                break;
        }
        std::cout << std::endl;
    }
}

void testHeap(){
    Heap heap;
    int switcher = 1;

    while(switcher != 0){
        int value, quantity, range;
        std::string filename;
        std::cout << "0 - Leave Testing" << std::endl;
        std::cout << "1 - Add" << std::endl;
        std::cout << "2 - Delete/Extract Max" << std::endl;
        std::cout << "3 - Search" << std::endl;
        std::cout << "4 - Fill Random" << std::endl;
        std::cout << "5 - Read From File" << std::endl;
        std::cout << "6 - Print" << std::endl;
        std::cout << "7 - Print Heap As Tree" << std::endl;
        std::cin >> switcher;
        std::cout << std::endl;
        switch(switcher){
            case 1:
                std::cout << "Pass the value: ";
                std::cin >> value;
                heap.add(value);
                break;

            case 2:
                heap.deleteMax();
                break;

            case 3:
                std::cout << "Pass the value: ";
                std::cin >> value;
                heap.search(value);
                break;

            case 4:
                std::cout << "Pass the quantity and range: ";
                std::cin >> quantity >> range;
                heap.fillRandom(quantity, range);
                break;

            case 5:
                std::cout << "Insert filename: ";
                std::cin >> filename;
                heap.fileRead(filename);
                break;

            case 6:
                heap.print();
                break;

            case 7:
                heap.printHeapAsTree(0, "", "");
                break;
        }
        std::cout << std::endl;
    }
}

void testBinarySearchTree(){
    BinarySearchTree binarySearchTree;
    int switcher = 1;

    while(switcher != 0){
        int value, quantity, range;
        std::string filename;
        std::cout << "0 - Leave Testing" << std::endl;
        std::cout << "1 - Insert" << std::endl;
        std::cout << "2 - Remove" << std::endl;
        std::cout << "3 - Search" << std::endl;
        std::cout << "4 - DSW Balancing" << std::endl;
        std::cout << "5 - Fill Random" << std::endl;
        std::cout << "6 - Read From File" << std::endl;
        std::cout << "7 - Print In-Order" << std::endl;
        std::cout << "8 - Print BST As Tree" << std::endl;
        std::cin >> switcher;
        std::cout << std::endl;
        switch(switcher){
            case 1:
                std::cout << "Pass the value: ";
                std::cin >> value;
                binarySearchTree.insert(value);
                break;

            case 2:
                std::cout << "Pass the value: ";
                std::cin >> value;
                binarySearchTree.remove(value);
                break;

            case 3:
                std::cout << "Pass the value: ";
                std::cin >> value;
                binarySearchTree.search(value);
                break;

            case 4:
                binarySearchTree.balanceDSW();
                break;

            case 5:
                std::cout << "Pass the quantity and range: ";
                std::cin >> quantity >> range;
                binarySearchTree.fillRandom(quantity, range);
                break;

            case 6:
                std::cout << "Insert filename: ";
                std::cin >> filename;
                binarySearchTree.fileRead(filename);
                break;

            case 7:
                binarySearchTree.printInOrder(binarySearchTree.getRoot());
                break;

            case 8:
                binarySearchTree.printTreeAsTree(binarySearchTree.getRoot(), "", "");
                break;
        }
        std::cout << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
