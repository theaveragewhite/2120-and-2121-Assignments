 #include "review.h"
//#include "review.cpp"



//using namespace std;
int main()
{
  int size;
  std::cin >> size;
  std::vector <int> array = InitializeArray(size);
  for(int i = 0; i < size; ++i)
  {
    std::cout << array[i];
  }


  return 0;
}

//takes the input of a myFile and assigns it as an arguement

//std::string fileName = argv[1];
//myFile.open(fileName);
//  int input = 0;
//  myFile >> input;
//  myFile.ignore();
