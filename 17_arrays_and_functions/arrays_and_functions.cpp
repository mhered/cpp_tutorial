// arrays_and_functions.cpp

#include <iostream>
using namespace std;

void show1(string texts[])
{
    // this does not work because texts[] is a pointer, equivalent to
    // *texts, so we lose the number of elements!
    int LEN = sizeof(texts) / sizeof(string); // gives warning

    for (int i = 0; i < 3; i++) // I put 3 here manually
    {
        cout << texts[i] << endl;
    }
}

void show2(const int LEN, string texts[]) // texts[] == *texts.
                                          // I can even specify a dimension texts[4] and C++ will ignore it
{

    for (int i = 0; i < LEN; i++)
    {
        cout << texts[i] << endl;
    }
}

void show3(string (&texts)[3]) // Ugly but retains size info
                               // array of 3 references to strings
                               // here C++ checks the size of the array
{
    int LEN = sizeof(texts) / sizeof(string);

    for (int i = 0; i < LEN; i++)
    {
        cout << texts[i] << endl;
    }
}

// returning an array

string *get_array_wrong()
{
    string texts[] = {"one", "two", "three"};
    // dont do this
    return texts; // returns pointer to a scoped array that will be destroyed!!
}

string *get_array_right()
{
    string *pt_texts = new string[3];
    pt_texts[0] = "one";
    pt_texts[1] = "two";
    pt_texts[2] = "three";

    return pt_texts; // returns pointer to heap memory
                     // size information is lost
}

void free_array(string *pt_mem) // common C++ pattern to provide a cleanup function
{
    delete[] pt_mem;
}

int main()
{
    string texts[] = {"apple", "orange", "banana"};

    show1(texts);

    int LEN = sizeof(texts) / sizeof(string);
    show2(LEN, texts);

    show3(texts);

    string *pt_string = get_array_right();
    show2(3, pt_string);
    free_array(pt_string);
    return 0;
}