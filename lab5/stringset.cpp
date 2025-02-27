/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 10/18/2023
 * Lab Section: 007
 * Assignment Name: Lab 5
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    //Implement this function
    if(!find(word))
    {
      int index = hash_function(word);
      table[index].push_back(word);
      //num_elems;
      if(static_cast<double>(num_elems) / size >= .75)
      {
        resize_table();
      }
    }

}

bool Stringset::find(string word) const
{
    //Implement this function
    int index = hash_function(word);
    for(const string& s : table[index])
    {
      if(s == word)
      {
        return true;
      }
    }
    return false;

}

void Stringset::remove(string word)
{
    //Implement this function
    if(find(word))
    {
      int index = hash_function(word);
      table[index].remove(word);
      num_elems--;
    }
}

int Stringset::hash_function(string word) const
{
    int hash = 0;
    for (char c : word)
    {
        hash = (hash * 31) + c;
    }
    return abs(hash) % size;
}

void Stringset::resize_table()
{
    int new_size = size * 2; // Double the size of the table

    // Create a new table with the new size
    vector<list<string>> new_table(new_size);

    // Rehash all elements into the new table
    for (const list<string>& old_bucket : table)
    {
        for (const string& word : old_bucket)
        {
            int index = hash_function(word) % new_size;
            new_table[index].push_back(word);
        }
    }

    // Update the size and table
    size = new_size;
    table = new_table;
}
