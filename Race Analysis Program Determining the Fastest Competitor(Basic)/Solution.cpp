#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int no[15], x, y, i = 0, win;
	double max = 100000000;
	double distance[15];
	int xFlag, yFlag;
	string name[15];
	double speed[15], time[15];
	cout << "Bayrak x ve y : ";
	cin >> xFlag >> yFlag;
	ifstream fPtr("yarisci.txt", ios::in);
	if (!fPtr)
	{
		cerr << ("File could not be opened .");
		exit(EXIT_FAILURE);
	}
	ofstream wPtr("analiz.txt", ios::out);
	if (!wPtr)
	{
		cerr << ("File could not be opened .");
		exit(EXIT_FAILURE);
	}
	wPtr << "No	Ad	Mesafe	Süre	Hýz" << endl;
	while (fPtr >> no[i] >> name[i] >> x >> y >> speed[i])
	{
		distance[i] = sqrt((pow((xFlag - x), 2)) - pow((yFlag - y), 2));
		time[i] = distance[i] / speed[i];
		i++;
		wPtr << no[i] << setw(5) << name[i] << setw(5) << distance[i] << setw(5) << time[i] << setw(5) << speed[i] << endl;
	}
	for (int k = 0;k < 15;k++)
	{
		if (time[k] < max)
		{
			max = time[k];
			win = k;
		}
	}
	cout << "Kazanan " << name[win] << " dir" << endl;
	cout << distance[win] << "metreyi " << time[win] << " surede kostu." << endl;
	return 0;
}

