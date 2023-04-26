#include <string>

class BidirectionalList
{

    // struktura przechowująca wartość elementu oraz wskaźniki do poprzedniego i następnego elementu
    struct listElement
    {
        int value;
        listElement *previous;
        listElement *next;
    };

    private:
        // wskaznik na pierwszy element listy
        listElement * start;
        // wskaźnik na ostatni element list
        listElement * end;
        // zmienna przechowujaca rozmiar listy
        unsigned int size;

    public:

        // konstruktor
        BidirectionalList();
        // destruktor
        ~BidirectionalList();

        // DODAWANIE ELEMENTU
        // dodanie elementu na poczatek
        void addToBeginning(int value);
        // dodanie elementu na koniec
        void addToEnd(int value);
        // dodanie elementu w konkretne miejsce 
        void addToIndex(int index, int value);

        // USUWANIE ELEMENTU
        // usuniecie na poczatku
        void deleteBeginning();
        // usuniecie na koncu
        void deleteEnd();
        // usuniecie w konkretnym miejscu
        void deleteAtIndex(int index);

        // wyszukanie elementu w liscie
        int search(int value);

        // wypisanie listy od początku
        void printBeginning();
        // wypisz zawartość listy od tyłu
        void printInverted();

        void fillRandom(int quantity, int range);

        // zczytanie z pliku
        bool fileRead(std::string filename);
};