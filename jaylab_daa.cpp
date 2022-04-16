#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 10

void merge(vector<string> arr, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    vector<string> a;
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            a[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= r)
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }
    if (j > r)
    {
        while (i <= mid)
        {
            a[k] = arr[i];
            i++;
            k++;
        }
    }
    for (int m = l; m <= r; m++)
    {
        arr[m] = a[m];
    }
}

void mergesort(vector<string> arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    // Create a text string, which is used to output the text file
     string myText;

    // // Read from the text file
     ifstream MyReadFile("filename.txt");

     vector<string> v;

     // Use a while loop together with the getline() function to read the file line by line
     while (getline(MyReadFile, myText))
     {
       // Output the text from the file
         v.push_back(myText);
     }

    // // Close the file
     MyReadFile.close();

    mergesort(v, 0, v.size());

    
    printf("\nThe Sorted Array is: ");

    for (int i=0; i<v.size(); ++i)
    std::cout << v[i] << ' ';
}
