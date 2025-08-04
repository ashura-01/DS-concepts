#include <bits/stdc++.h>
using namespace std;

struct student
{

    int id;
    char name[100];
    double cgpa;
};

void inputData(vector<student> &arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        student element;

        cout << "input ID: ";
        cin >> element.id;

        cin.ignore();

        cout << "input NAME: ";
        cin.getline(element.name, 100);

        cout << "input CGPA: ";
        cin >> element.cgpa;

        arr.push_back(element);
    }
}

void outputData(vector<student> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "NAME: " << arr[i].name << endl;

        cout << "ID: " << arr[i].id << endl;

        cout << "CGPA: " << arr[i].cgpa << endl
             << endl;
    }

    cout << endl
         << endl
         << endl;
}

int partition(vector<student> &arr, int low, int high)
{
    double pivot = arr[low].cgpa;
    int left = low + 1;
    int right = high;

    while (left < right)
    {
        while (left <= high && arr[left].cgpa <= pivot)
            left++;

        while (arr[right].cgpa > pivot)
            right--;

        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]);

    return right;
}

void quickSort(vector<student> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int32_t main()
{
    int n;
    cout << "input the number of student: ";
    cin >> n;
    vector<student> arr;

    inputData(arr, n);

    outputData(arr);

    quickSort(arr, 0, arr.size() - 1);

    outputData(arr);

    return 0;
}
