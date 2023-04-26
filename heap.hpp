#include <string>

class Heap
{
    private:
        // wskaźnik na pierwszy element kopca
        int * heapArray;
        // obecny rozmiar kopca
        unsigned int currentSize;

        // zamiana drzewa binarnego na strukturę kopca
        void heapify(int nodeIndex);

    public:
        Heap();
        // destruktor funkcji
        ~Heap();
        // dodaj na kopiec
        void add(int value);
        // usuwanie korzenia drzewa max sterty
        void deleteMax();
        // wypisz zawartość kopca
        void print();
        void printHeapAsTree(int v, std::string sp, std::string sn);
        // wyszukaj na kopcu
        int search(int value);
        // wypełnij losowymi wartościami
        void fillRandom(int quantity, int range);

        // zczytanie z pliku
        bool fileRead(std::string filename);
};