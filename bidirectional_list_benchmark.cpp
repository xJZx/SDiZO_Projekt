#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include "bidirectional_list_benchmark.hpp"
#include "bidirectional_list.hpp"

long long int read_QPC_Bidirectional_List(){
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

BidirectionalListBenchmark::BidirectionalListBenchmark(int size){
    bidirectionalListTestAddToBeggining(size);
    bidirectionalListTestAddToEnd(size);
    bidirectionalListTestAddToIndex(size);
    bidirectionalListTestDeleteBeggining(size);
    bidirectionalListTestDeleteEnd(size);
    bidirectionalListTestDeleteAtIndex(size);
    bidirectionalListTestSearch(size);
}

void BidirectionalListBenchmark::bidirectionalListTestAddToBeggining(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BidirectionalList * bidirectionalList = new BidirectionalList();
        bidirectionalList -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Bidirectional_List();
        bidirectionalList -> addToBeginning(size);
        end = read_QPC_Bidirectional_List();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete bidirectionalList;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of bidirectionalListTestAddToBeggining() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BidirectionalListBenchmark::bidirectionalListTestAddToEnd(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BidirectionalList * bidirectionalList = new BidirectionalList();
        bidirectionalList -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Bidirectional_List();
        bidirectionalList -> addToEnd(size);
        end = read_QPC_Bidirectional_List();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete bidirectionalList;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of bidirectionalListTestAddToEnd() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BidirectionalListBenchmark::bidirectionalListTestAddToIndex(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BidirectionalList * bidirectionalList = new BidirectionalList();
        bidirectionalList -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Bidirectional_List();
        bidirectionalList -> addToIndex(size / 2, size);
        end = read_QPC_Bidirectional_List();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete bidirectionalList;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of bidirectionalListTestAddToIndex() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BidirectionalListBenchmark::bidirectionalListTestDeleteBeggining(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BidirectionalList * bidirectionalList = new BidirectionalList();
        bidirectionalList -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Bidirectional_List();
        bidirectionalList -> deleteBeginning();
        end = read_QPC_Bidirectional_List();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete bidirectionalList;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of bidirectionalListTestDeleteBeginning() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BidirectionalListBenchmark::bidirectionalListTestDeleteEnd(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BidirectionalList * bidirectionalList = new BidirectionalList();
        bidirectionalList -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Bidirectional_List();
        bidirectionalList -> deleteEnd();
        end = read_QPC_Bidirectional_List();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete bidirectionalList;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of bidirectionalListTestDeleteEnd() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BidirectionalListBenchmark::bidirectionalListTestDeleteAtIndex(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BidirectionalList * bidirectionalList = new BidirectionalList();
        bidirectionalList -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Bidirectional_List();
        bidirectionalList -> deleteAtIndex(size / 2);
        end = read_QPC_Bidirectional_List();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete bidirectionalList;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of bidirectionalListTestDeleteAtIndex() is: " << (resultSum / 100) << std::endl << std::endl;
}

void BidirectionalListBenchmark::bidirectionalListTestSearch(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        BidirectionalList * bidirectionalList = new BidirectionalList();
        bidirectionalList -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Bidirectional_List();
        bidirectionalList -> search(size / 2);
        end = read_QPC_Bidirectional_List();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete bidirectionalList;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of bidirectionalListTestSearch() is: " << (resultSum / 100) << std::endl << std::endl;
}