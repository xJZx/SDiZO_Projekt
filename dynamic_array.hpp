#include <string>

class DynamicArray
{
    private:
        // wskaznik na pierwszy element tablicy
        int * array;
        // zmienna przechowujaca rozmiar tablicy
        unsigned int size;

    public:
        // konstruktor klasy
        DynamicArray();
        // destruktor klasy
        ~DynamicArray();

        // GETTERS
        unsigned int getSize();

        // DODAWANIE ELEMENTU
        // dodanie elementu na poczatek
        void addToBeginning(int value);
        // dodanie elementu na koniec
        void addToEnd(int value);
        // dodanie elementu w konkretne miejsce 
        bool addToIndex(int index, int value);

        // USUWANIE ELEMENTU
        // usuniecie na poczatku
        void deleteBeginning();     //ACHTUNG PRZERÓB NA BULLA
        // usuniecie na koncu
        void deleteEnd();           //ACHTUNG PRZERÓB NA BULLA
        // usuniecie w konkretnym miejscu
        bool deleteAtIndex(int index);

        // wyszukanie elementu w tablicy
        // zwraca pierwsze wystąpienie wartości szukanej
        int search(int value);
        // wypełnij losowymi
        void fillRandom(int quantity, int range);   //DO TESTÓW
        // zczytanie z pliku
        bool fileRead(std::string filename);

        // wypisanie tablicy
        void print();
};