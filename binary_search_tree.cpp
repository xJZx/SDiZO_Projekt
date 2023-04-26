#include "binary_search_tree.hpp"
#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include <string>

BinarySearchTree::~BinarySearchTree(){
	clear();
}

BinarySearchTree::Node* BinarySearchTree::getRoot(){
    return root;
}

void BinarySearchTree::setRoot(Node* newRoot) {
    root = newRoot;
}

void BinarySearchTree::insert(int value){
	Node* node = new Node(value);
    if (!root) {
        root = node;
        return;
    }
    Node* current = root;
    while (true) {
        if (value < current->value) {
            if (!current->left){
                current->left = node;
                return;
            }
            current = current->left;
        }
        else {
            if (!current->right){
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

bool BinarySearchTree::search(int value){
    return find(value) != nullptr;
}

void BinarySearchTree::remove(int value){
    Node* node = find(value);
    if (!node) {
        return;
    }
    if (!node->left && !node->right) {
        if (node == root) {
            root = nullptr;
        }
        else {
            Node* parent = find(value);
            if (parent->left == node) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        delete node;
    }
    else if (node->left && !node->right) {
        Node* child = node->left;
        *node = *child;
        delete child;
    }
    else if (!node->left && node->right) {
        Node* child = node->right;
        *node = *child;
        delete child;
    }
    else {
        Node* successor = node->right;
        while (successor->left) {
            successor = successor->left;
        }
        node->value = successor->value;
        remove(successor->value);
    }
}

void BinarySearchTree::clear(){
    destroy(root);
    root = nullptr;
}

BinarySearchTree::Node* BinarySearchTree::find(int value){
    Node* current = root;
    while (current) {
        if (current->value == value) {
            return current;
        }
        if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return nullptr;
}

int BinarySearchTree::buildVine() {
    Node* temp = root;
    Node* parent = nullptr;
    int count = 0;
    while (temp) {
        //printTree(getRoot(), false);
        //std::cout << std::endl;
        // If left exist for node
        // pointed by tmp then
        // right rotate it.
        if (temp->left) {
            if (temp == root) {
                Node* oldTemp = temp;
                temp = temp->left;
                if (!temp) break; // check if temp is not null
                oldTemp->left = temp->right;
                temp->right = oldTemp;
                root = temp; //nowy root
                parent = temp;
            }
            else {
                Node* oldTemp = temp;
                temp = temp->left;
                if (!temp) break; // check if temp is not null
                oldTemp->left = temp->right;
                temp->right = oldTemp;
                parent->right = temp;
            }
        }
 
        // If left dont exists
        // add 1 to count and
        // traverse further right to
        // flatten remaining BST.
        else {
            count++;
            parent = temp;
            temp = temp->right;
        }
    }
    return count;
}

void BinarySearchTree::compress(int count) {
    // Make tmp pointer to traverse
    // and compress the given BST.
    Node* temp = root;
    Node* parent = nullptr;
 
    // Traverse and left-rotate root m times
    // to compress given vine form of BST.
    for (int i = 0; i < count; i++) {
        if (temp == root) {
            Node* oldTemp = temp;
            temp = temp->right;
            if (!temp) break; // check if temp is not null
            root = temp;
            parent = root;
            oldTemp->right = temp->left;
            temp->left = oldTemp;
            temp = temp->right;
        }
        else {
            Node* oldTemp = temp;
            temp = temp->right;
            if (!temp) break; // check if temp is not null
            parent->right = temp;
            parent = temp;
            oldTemp->right = temp->left;
            temp->left = oldTemp;
            temp = temp->right;
        }
    }
}

BinarySearchTree::Node* BinarySearchTree::balanceDSW() {
    //printTree(getRoot(), false);
    //std::cout << std::endl;

    int count = buildVine();

    //printTree(getRoot(), false);
    //std::cout << std::endl;


    int m = pow(2, floor(log2(count + 1))) - 1;
    compress(count - m);

    //printTree(getRoot(), false);
    //std::cout << std::endl;

    for(m = m / 2; m >= 1; m /= 2){
        compress(m);
    }

    //printTree(getRoot(), false);
    //std::cout << std::endl;

    return root;
}

void BinarySearchTree::destroy(Node* node){
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

int BinarySearchTree::countNodes(Node* node){
    if (!node) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

void BinarySearchTree::printInOrder(BinarySearchTree::Node* node){
    if (!node) {
		// std::cout << "Binary Search Tree is empty!" << std::endl;
        return;
    }
    printInOrder(node->left);
    std::cout << node->value << " ";
    printInOrder(node->right);
}

void BinarySearchTree::fillRandom(int quantity, int range){
    srand(time(NULL));
    for(int i = 0; i < quantity; i++){
        int randomNumber = rand() % range;
        insert(randomNumber);
    }
}

void BinarySearchTree::printTree(Node* node, bool isLeft) {
    if (node != nullptr) {
        std::cout << "";
        if(node == root){
            std::cout << ("Root");
        }
        else{
            std::cout << (isLeft ? "L" : "R");
        }
        std::cout << node->value << std::endl;

        printTree(node->left, true);
        printTree(node->right, false);
    }
}

void BinarySearchTree::printTreeAsTree(Node* root, std::string sp, std::string sn) {
    if (root == nullptr) {
        return;
    }

    std::string s;
    std::string cr = "  ";
    std::string cl = "  ";
    std::string cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    if (root)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printTreeAsTree(root->right, s + cp, cr);

        s = s.substr(0, sp.length() - 2);
        std::cout << s << sn << root->value << std::endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printTreeAsTree(root->left, s + cp, cl);
    }
}

bool BinarySearchTree::fileRead(std::string filename){
    std::string line;
    std::ifstream file;
    file.open(filename);
    if(file.is_open()){
        while(std::getline(file, line)){
            insert(std::stoi(line));
        }
        file.close();
        
        return true;
    }

    return false;
}