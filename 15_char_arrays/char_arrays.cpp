// array_pointers.cpp

#include <iostream>

using namespace std;

int main()
{
    char text[] = "hello"; // equivalent to {'h','e','l','l','o'};

    // but sizeof(text) = 6 because of the null terminator
    for (int i = 0; i < sizeof(text); i++)
    {
        cout << i << " : " << (int)text[i] << " : " << text[i] << endl;
    }

    int k = 0;
    while (true)
    {
        if (text[k] == 0)
            break;
        cout << text[k] << flush;
        k++;
    }

    cout << endl
         << "Reversing a string" << endl
         << "------------------" << endl;

    // reversing a string in place
    char word[] = "strawberry";
    const int LEN = sizeof(word) - 1;
    char tmp;

    // method 1: using array element reference syntax

    cout << endl
         << endl
         << "Method 1" << endl
         << "--------" << endl;

    // display word
    cout << endl;
    for (int i = 0; i < sizeof(word); i++)
    {
        cout << word[i] << flush;
    }

    for (int i = 0; i < LEN / 2; i++)
    {
        cout << endl
             << word[i] << " <> " << word[LEN - 1 - i] << endl;
        tmp = word[LEN - 1 - i];
        word[LEN - 1 - i] = word[i];
        word[i] = tmp;
        for (int j = 0; j < sizeof(word); j++)
        {
            cout << word[j] << flush;
        }
    }

    // method 2: using pointers

    cout << endl
         << endl
         << "Method 2" << endl
         << "--------" << endl;

    // display word
    cout << endl;
    for (int i = 0; i < sizeof(word); i++)
    {
        cout << word[i] << flush;
    }

    char *pt_init = word;
    char *pt_end = &word[LEN - 1];
    while (pt_init < pt_end)
    {
        cout << endl
             << *pt_init << " <> " << *pt_end << endl;
        tmp = *pt_end;
        *pt_end = *pt_init;
        *pt_init = tmp;

        for (int j = 0; j < sizeof(word); j++)
        {
            cout << word[j] << flush;
        }

        pt_init++;
        pt_end--;
    }
    cout << endl;
    return 0;
}