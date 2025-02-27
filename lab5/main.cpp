/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 10/27/2023
 * Lab Section: 007
 * Assignment Name: Lab 5
 */

 #include "stringset.h"
 #include <iostream>
 #include <fstream>

 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);

 /*int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }*/

 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }

 void loadStringset(Stringset& words, string filename)
 {
     //Implement this function
     ifstream myFile(filename);
     string word;
     while(myFile.is_open())
     {
       while(myFile >> word)
       words.insert(word);
     }
     myFile.close();
 }

 vector<string> spellcheck(const Stringset& words, string word)
 {
     //Implement this function
   vector <string> suggestions;
   if(words.find(word))
   {
      suggestions.push_back("Word is spelled correctly.");
   }
   else
   {
      suggestions.push_back("Word is not spelled correctly.");
   }
    return suggestions;
 }
