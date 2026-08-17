#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux, int &count)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        count++;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to, count);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    count++;
    towerOfHanoi(n - 1, aux, to, from, count);
}

int main()
{
    int n, count = 0;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B', count);
    cout << "Total moves: " << count << endl;
    return 0;
}