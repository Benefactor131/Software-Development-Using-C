#include <iostream>

using namespace std;

int main() {
	size_t time;

	time = 8593;

	size_t hours = time / 3600;
	
	size_t minutes = time % 3600 / 60;

	size_t seconds = time - hours * 3600 - minutes * 60;
	if (hours < 10 || minutes < 10 || seconds < 10)
	{
		if (hours < 10)
		{
			cout << 0 << hours << ":";
		}
		if (minutes < 10)
		{
			cout << 0 << minutes << ":";

		}
		if (seconds < 10)
		{
			cout << 0 << seconds;
		}
	}
	else {
		cout << time / 3600 << ":" << minutes << ":" << seconds << endl;
	}

	return 0;
}