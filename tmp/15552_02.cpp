#include <iostream>
#define fast_io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int T, A, B;

void solve()
{
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> A >> B;
		cout << A + B << "\n";
	}
}

int main(void)
{
	fast_io;
	solve();
	return (0);
}
