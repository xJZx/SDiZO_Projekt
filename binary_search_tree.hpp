#include <string>

class BinarySearchTree 
{
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // funkcja szukajaca
    Node* find(int value);
    // usuwa węzeł
    void destroy(Node* node);
    // zlicza ilość węzłów
    int countNodes(Node* node);
    // rotacja w prawo
    int buildVine();
    // rotacja w lewo
    void compress(int m);


public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree();

    // dodanie wartosci
    void insert(int value);
    // wyszukanie wartosci
    bool search(int value);
    // usuniecie wartosci
    void remove(int value);
    // równoważenie drzewa za pomocą metody DSW
    Node* balanceDSW();
    // funkcja czyszcaca do destruktora
    void clear();
    // wypisanie in-order
    void printInOrder(Node* node);
    void printTree(Node* node, bool isLeft);
    void printTreeAsTree(Node* root, std::string sp, std::string sn);

    void fillRandom(int quantity, int range);

    // zczytanie z pliku
    bool fileRead(std::string filename);

    // getter na root
    Node* getRoot();
    void setRoot(Node* newRoot);
};