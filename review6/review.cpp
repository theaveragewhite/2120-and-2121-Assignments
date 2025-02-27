#include "review.h"



void LoopThrough(double *data, int size)
{
  //&data[size];

  //int i;
  for(int k = 0; k < size; k++)
    {

      data[k] = data[k]+1;
      //data[k]+= 1;
      /*for(i=0;i<k;++i)
      {
        data[i] = k+i;

        //std::cout << *data << std::endl;
      }*/
      std::cout << data[k];
      //for(i = 0; )
      //std::cout << *data;
    }


}

/*for(int i=0;i<=size;++i)
{
  data[k][i] = total;
  total += 1;
  std::cout << data[k][i];
}*/
