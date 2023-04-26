#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include "binary_search_tree_benchmark.hpp"
#include "binary_search_tree.hpp"

long long int read_QPC_Binary_Search_Tree(){
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

BinarySearchTreeBenchmark::BinarySearchTreeBenchmark(int size){
    binarySearchTreeTestInsert(size);
    binarySearchTreeTestRemove(size);
    binarySearchTreeTestSearch(size);
    binarySearchTreeBalancingDSW(size);
}

void BinarySearchTreeBenchmark::binarySearchTreeTestInsert(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BinarySearchTree * binarySearchTree = new BinarySearchTree();
        binarySearchTree -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Binary_Search_Tree();
        binarySearchTree -> insert(size);
        end = read_QPC_Binary_Search_Tree();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete binarySearchTree;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of binarySearchTreeTestInsert() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BinarySearchTreeBenchmark::binarySearchTreeTestRemove(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BinarySearchTree * binarySearchTree = new BinarySearchTree();
        binarySearchTree -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Binary_Search_Tree();
        binarySearchTree -> remove(size / 2);
        end = read_QPC_Binary_Search_Tree();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete binarySearchTree;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of binarySearchTreeTestRemove() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BinarySearchTreeBenchmark::binarySearchTreeTestSearch(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BinarySearchTree * binarySearchTree = new BinarySearchTree();
        binarySearchTree -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Binary_Search_Tree();
        binarySearchTree -> search(size / 2);
        end = read_QPC_Binary_Search_Tree();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete binarySearchTree;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of binarySearchTreeTestSearch() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BinarySearchTreeBenchmark::binarySearchTreeBalancingDSW(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BinarySearchTree * binarySearchTree = new BinarySearchTree();
        binarySearchTree -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Binary_Search_Tree();
        binarySearchTree -> balanceDSW();
        end = read_QPC_Binary_Search_Tree();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete binarySearchTree;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of binarySearchTreeBalancingDSW() is: " << (resultSum / 100) << std::endl << std::endl;
}