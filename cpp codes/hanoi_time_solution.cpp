#include <iostream>
using namespace std;
#include <chrono>

/*So this code tells you how much time your computer spends calculating the solution to the Towers of Hanoi problem.
You can also use the hanoi method uncommenting the line 13 and it will tell you the steps.*/

void hanoi (int M, int i, int j)
{
  if (M > 0)
    {
      hanoi(M-1, i, 6-i-j);
      //cout << i << " -> " << j << endl;
      hanoi (M-1, 6-i-j, j);
  }
}

int main(int argc, char* argv[])
{
  int M = atoi(argv[1]);
	
	using namespace std::chrono;
	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;
	tantes = high_resolution_clock::now();

	hanoi(M, 1, 2);

	tdespues = high_resolution_clock::now();
	transcurrido = duration_cast<duration<double>>(tdespues - tantes);
	cout << transcurrido.count() << endl;
 
  return 0;
}
