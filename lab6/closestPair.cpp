/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 10/31/2023
 * Lab Section: 007
 * Assignment Name: Lab 6
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct point
{
    double x;
    double y;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/


//Helper Function for finding the distance between two points
double Distance(struct point *p1,  struct point *p2)
{
    double dx = (*p1).x - (*p2).x;
    double dy = (*p1).y - (*p2).y;
    return sqrt((dx * dx) + (dy * dy));
}

double closestPair(string filename)
{
  ifstream myFile(filename);
  int numPoints;
  myFile >> numPoints;
  //Calculates the number of cells based on the square root of the number of points
  int numCells = static_cast<int>(ceil(sqrt(numPoints)));

  vector<vector<vector<point>>> grid(numCells, vector<vector<point>>(numCells));
   //Read points from the file and place them into appropriate cells in the grid
  for (int i = 0; i < numPoints; ++i)
  {
    point points;
    myFile >> points.x >> points.y;
    int cellX = static_cast<int>(points.x * numCells);
    int cellY = static_cast<int>(points.y * numCells);

    grid[cellX][cellY].push_back(points);
  }




  double minDistance = numeric_limits<double>::max();
  for (int i = 0; i < numCells; ++i)
  {
   for (int j = 0; j < numCells; ++j)
   {
     for (int di = -1; di <= 1; ++di)
     {
       for (int dj = -1; dj <= 1; ++dj)
       {
         int ni = i + di;
         int nj = j + dj;

         if (ni >= 0 && ni < numCells && nj >= 0 && nj < numCells)
         {
           for( point& p1: grid[i][j])
           {
             for( point& p2: grid[ni][nj])
             {
               //Update minDistance if the calculated distance is greater than 0
               // and smaller than the current minDistance
               double distance = Distance(&p1, &p2);
               minDistance = (distance > 0 && distance < minDistance) ? distance : minDistance;
             }
           }
         }
       }
      }
     }
    }
    myFile.close();
   return minDistance;
}
/*
int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}*/
