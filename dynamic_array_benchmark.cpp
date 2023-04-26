#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include "dynamic_array_benchmark.hpp"
#include "dynamic_array.hpp"

long long int read_QPC_Dynamic_Array(){
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

DynamicArrayBenchmark::DynamicArrayBenchmark(int size){
    dynamicArrayTestAddToBeggining(size);
    dynamicArrayTestAddToEnd(size);
    dynamicArrayTestAddToIndex(size);
    dynamicArrayTestDeleteBeggining(size);
    dynamicArrayTestDeleteEnd(size);
    dynamicArrayTestDeleteAtIndex(size);
    dynamicArrayTestSearch(size);
}

void DynamicArrayBenchmark::dynamicArrayTestAddToBeggining(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        DynamicArray * dynamicArray = new DynamicArray();
        dynamicArray -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Dynamic_Array();
        dynamicArray -> addToBeginning(size);
        end = read_QPC_Dynamic_Array();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete dynamicArray;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of dynamicArrayTestAddToBeggining() is: " << (resultSum / 100) << std::endl << std::endl;
}

void DynamicArrayBenchmark::dynamicArrayTestAddToEnd(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        DynamicArray * dynamicArray = new DynamicArray();
        dynamicArray -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Dynamic_Array();
        dynamicArray -> addToEnd(size);
        end = read_QPC_Dynamic_Array();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete dynamicArray;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of dynamicArrayTestAddToEnd() is: " << (resultSum / 100) << std::endl << std::endl;
}

void DynamicArrayBenchmark::dynamicArrayTestAddToIndex(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        DynamicArray * dynamicArray = new DynamicArray();
        dynamicArray -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Dynamic_Array();
        dynamicArray -> addToIndex(size / 2, size);
        end = read_QPC_Dynamic_Array();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete dynamicArray;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of dynamicArrayTestAddToIndex() is: " << (resultSum / 100) << std::endl << std::endl;
}

void DynamicArrayBenchmark::dynamicArrayTestDeleteBeggining(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        DynamicArray * dynamicArray = new DynamicArray();
        dynamicArray -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Dynamic_Array();
        dynamicArray -> deleteBeginning();
        end = read_QPC_Dynamic_Array();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete dynamicArray;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of dynamicArrayTestDeleteBeggining() is: " << (resultSum / 100) << std::endl << std::endl;
}

void DynamicArrayBenchmark::dynamicArrayTestDeleteEnd(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        DynamicArray * dynamicArray = new DynamicArray();
        dynamicArray -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Dynamic_Array();
        dynamicArray -> deleteEnd();
        end = read_QPC_Dynamic_Array();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete dynamicArray;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of dynamicArrayTestDeleteEnd() is: " << (resultSum / 100) << std::endl << std::endl;
}

void DynamicArrayBenchmark::dynamicArrayTestDeleteAtIndex(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        DynamicArray * dynamicArray = new DynamicArray();
        dynamicArray -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Dynamic_Array();
        dynamicArray -> deleteAtIndex(size / 2);
        end = read_QPC_Dynamic_Array();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete dynamicArray;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of dynamicArrayTestDeleteAtIndex() is: " << (resultSum / 100) << std::endl << std::endl;
}

void DynamicArrayBenchmark::dynamicArrayTestSearch(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        DynamicArray * dynamicArray = new DynamicArray();
        dynamicArray -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Dynamic_Array();
        dynamicArray -> search(size / 2);
        end = read_QPC_Dynamic_Array();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete dynamicArray;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of dynamicArrayTestSearch() is: " << (resultSum / 100) << std::endl << std::endl;
}