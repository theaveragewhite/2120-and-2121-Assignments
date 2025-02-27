#include "review.h"


void ReadWrite()
{
  //using string_int = boost::variant<std::string, int>;
  std::vector <std::string> large;
  //char q = 't';
  int i = 0;
  //int total = 0;
  std::string word;
  while(word != "q")
  {
    //std::cout << "Enter a number" << std::endl;
    std::cin >> word;
    large.push_back(word);
    //std::cout << "If you would like to quit press q" << std::endl;
    //std::cin >> q;
    ++i;
    if(word == "q")
    {
      --i;

    }

  }
  large.erase(large.end()-1);
  for(auto element : large )
  std::cout << element << " ";

}
