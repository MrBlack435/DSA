#include <iostream>

using namespace std;

int main()
{
    char ch = 'a';

    do
    {
        if (ch <= 'z')
        {
            cout << ch << " ";
        }
        ch += 4;
    } while (ch <= 'z');

    cout << endl;
    return 0;
}
