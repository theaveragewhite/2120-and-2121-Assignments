/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 9/25/2023
 * Lab Section: 007
 * Assignment Name: Lab 3
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below

Grouping::Grouping(string fileName)
{
  ifstream file(fileName);
  if(file.is_open())
  {
    string line;
    int numRows = 0;
    int numCols = 0;
    //Read the entire file to determine numRows and the maximum numCols
    while(getline(file,line))
    {
      numCols = line.length();
      numRows++;
    }
     //Reset the file position to the beginning
     //Can't believe this was what I was missing after getting some help
    file.clear();
    file.seekg(0);
    for(int r = 0; r < numRows; r++)
    {
      getline(file,line);
      for(int c = 0; c < numCols; c++)
      {
        //If the line in the file is a . returns 0
        if(line[c] == '.')
        {
          grid[r][c] = 0;
        }
        else
        {
          grid[r][c] = 1;
        }
      }
    }
  for(int r = 0; r < numRows; r++)
  {
    for(int c = 0; c < numCols; c++)
    {
      if(grid[r][c] == 1)
      {
        groups.push_back(vector<GridSquare>());
        findGroup(r,c);
      }
    }
  }

    file.close();
  }
  else
  {
    cout << "Unable to open file:" << fileName << endl;
  }
}

void Grouping::findGroup(int r, int c)
{
  //Intializes GridSquare constructor
  GridSquare square(r, c);
  groups[groups.size()-1].push_back(square);

  grid[r][c] = 0;
  //Recursion to determine where groups are located
  if(r>0 && grid[r-1][c] == 1)
  {
    findGroup(r - 1, c);
  }
  if(r<10 && grid[r+1][c] == 1)
  {
    findGroup(r + 1, c);
  }
  if(c>0 && grid[r][c-1] == 1)
  {
    findGroup(r, c - 1);
  }
  if(c<10 && grid[r][c+1] == 1)
  {
    findGroup(r, c + 1);
  }



}
//Simple main function to test Grouping
//Be sure to comment out main() before submitting

/*int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();

    return 0;
}*/

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}
