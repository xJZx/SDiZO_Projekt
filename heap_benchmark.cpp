#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
#include "heap_benchmark.hpp"
#include "heap.hpp"

long long int read_QPC_Heap(){
    LARGE_INTEGER count;
    QueryPerformanceCounter((LARGE_INTEGER*) &count);
    return ((long long int) count.QuadPart);
}

HeapBenchmark::HeapBenchmark(int size){
    heapTestAdd(size);
    heapTestDeleteMax(size);
    heapTestSearch(size);
}

void HeapBenchmark::heapTestAdd(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        Heap * heap = new Heap();
        heap -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Heap();
        heap -> add(size);
        end = read_QPC_Heap();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete heap;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of heapTestAdd() is: " << (resultSum / 100) << std::endl << std::endl;
}

void HeapBenchmark::heapTestDeleteMax(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        Heap * heap = new Heap();
        heap -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Heap();
        heap -> deleteMax();
        end = read_QPC_Heap();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete heap;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of heapTestDeleteMax() is: " << (resultSum / 100) << std::endl << std::endl;
}

void HeapBenchmark::heapTestSearch(int size){
    int results[100];

    for(int i = 0; i < 100; i++){
        Heap * heap = new Heap();
        heap -> fillRandom(size, 1000);

        long long int frequency, start, end, elapsed;
        QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
        
        start = read_QPC_Heap();
        heap -> search(size / 2);
        end = read_QPC_Heap();

        elapsed = end - start;
        results[i] = 1000000000.0 * elapsed / frequency;

        delete heap;
    }

    int resultSum = 0;
    for(int i = 0; i < 100; i++){
        resultSum += results[i];
    }

    std::cout << "Average time [ns] of heapTestSearch() is: " << (resultSum / 100) << std::endl << std::endl;
}