#include "review.h"

//using namespace std;
void ReadStdIn() //int argc, char const *argv[] if needed
{
  int num;
  double bigNum;
  std::string letters;

  std::cin >> num;
  std::cin >> bigNum;
  std::cin >> letters;

  std::cout << num << std::endl;
  std::cout << bigNum << std::endl;
  std::cout << letters << std::endl;

}
/*std::ifstream myFile("T1i.txt");

if(myFile.is_open())
{
  std::string line, input;

  while(getline(myFile, line))
  {
    std::stringstream ss(line);
    std::getline(ss, input, '\n');
    std::cout << input << std::endl;
  }
}

myFile.close();*/
/*
ifstream myFile;
string fileName = argv[1];
myFile.open(filename);
int input = 0;
myFile >> input;
myFile.ignore() = "";
vector<input> inputVector;
*/
