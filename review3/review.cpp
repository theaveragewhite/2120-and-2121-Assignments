#include "review.h"


void ReadStdIn2()
{
  //using string_int = boost::variant<std::string, int>;
  //std::vector <string_int> large;
  //char q = 't';
  int i = 0;
  std::string word;
  while(word != "q")
  {
    //std::cout << "Enter a number" << std::endl;
    std::cin >> word;
    //large.push_back();
    //std::cout << "If you would like to quit press q" << std::endl;
    //std::cin >> q;
    ++i;
    if(word == "q")
    {
      --i;
    }
  }
  std::cout << i;

}
