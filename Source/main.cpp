#include <iostream>
#include <fstream>
#include <ctime>
#include "../Headers/AVLTree.h"

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
int main() {
    AVLTree avl;
    clock_t begin;
    clock_t end;
    double elapsed_secs;
    std::string line;
    int count=0;
    std::ifstream myfile;
    myfile.open("../a.txt");

    //Filling the AVL
    if (myfile.is_open())
    {
         begin = clock();
        while ( getline (myfile,line) )
        {
            avl.insert(std::stoi(line));
            count++;
        }
        myfile.close();
        end = clock();
        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        std::cout << "Time passed for filling the tree with " << count << " elements: " << elapsed_secs << std::endl;
    }


    begin = clock();
    avl.insert(23543234);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Time passed for inserting into tree with " << count << " elements: " << elapsed_secs << std::endl;


    //Traverse the AVL
    begin = clock();
    avl.inOrder();
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Time passed for traversing the tree with " << count << " elements: " << elapsed_secs << std::endl;

    //Search AVL
    begin = clock();
    bool search1 = avl.search(56);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Time passed for searching the tree with " << count << " elements: " << elapsed_secs << std::endl;
    std::cout << search1 << "    ";

    return 0;
}

