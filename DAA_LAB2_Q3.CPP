#include <iostream>
#include <vector>

using namespace std;

void insertionSort(std::vector<int> &vec){
   for (auto it = vec.begin(); it != vec.end(); it++){
      auto const insertion_point =
      std::upper_bound(vec.begin(), it, *it);
      std::rotate(insertion_point, it, it+1);
   }
}
//printing the array
void print(std::vector<int> vec){
   for( int x : vec)
   cout << x << " ";
   cout << '\n';
}

vector<int> myVector;

int main()
{
	cout << "Type in a list of 5 numbers " << endl;

	int input = 0;

	for (int i = 0; i < 5; i++) 
	{
		cin >> input;
		myVector.push_back(input);
		
	}

    insertionSort(myVector);
    print(myVector);

	// for (int i = 0; i < 5; i++) 
	// {
	// 	cout << myVector[i] << endl;
	// }

		return 0;
}

