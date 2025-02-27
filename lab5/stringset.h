/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 10/18/2023
 * Lab Section: 007
 * Assignment Name: Lab 5
 */

#pragma once

#include <string>
#include <vector>
#include <list>
using namespace std;

//Stringset class, do not modify definitions for existing members
class Stringset
{
    private:
        vector<list<string>> table;
        int num_elems;
        int size;
        int hash_function(string word) const;
        void resize_table();
    public:
        Stringset();
        vector<list<string>> getTable() const;
        int getNumElems() const;
        int getSize() const;
        void insert(string word);
        bool find(string word) const;
        void remove(string word);
};
