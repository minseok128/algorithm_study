#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	char c;
	int N;
	int score[] = {0, 0};
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		if (c == 'D')
			score[0]++;
		else
			score[1]++;
		if (abs(score[0] - score[1]) == 2)
			break ;
	}
	cout << score[0] << ':' << score[1] << '\n';
}