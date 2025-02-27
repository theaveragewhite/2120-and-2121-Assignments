/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 10/27/2023
 * Assignment Name: Anagram Finder
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

/*int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}*/

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Helper function to sort the strings
string sortString(string letters)
{
  sort(letters.begin(), letters.end());
  return letters;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
  unordered_map<string, vector<string>> anagramMap;
  vector<string> anagrams;
  string sortedWord = sortString(word);

  for (const string w : wordlist)
  {
      string sortedW = sortString(w);
      anagramMap[sortedW].push_back(w);
  }
  //Adds the anagram words to the list
  if (anagramMap.find(sortedWord) != anagramMap.end())
  {
    anagrams = anagramMap[sortedWord];
  }

  return anagrams;
}
