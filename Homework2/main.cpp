// The following program collects 3 arrays: integers, floats and chars, and
// writes them to a text file. Then it prints the second largest value for each
// array, then sorts the arrays, prints the data, and saves them to a file
// then retrieves the arrays and prints the retrived data.

// The app is designed to work on Mac OS. In order to run the app on other OS
// might need to specify a different file path in the constructor of the stream
// (functions saveArray & retrieveArray)


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//function template to print arrays of different data types
template <class T>
void printarray (T *array, const int n){
    for (int i = 0; i < n; i++)
        cout << array[i] << "  ";
    cout << endl;
}


// Ask user to enter data
template <class T>
void loadArray(T *array, const int arraySize, string dataType) {
    cout << "Enter " << arraySize << " " << dataType << ": ";
    for (int i = 0; i < arraySize; i++)
        cin >> array[i];
}


// Find the second largest number in an array and print it
template <class T>
void secondLargestNumber(T *array, const int arraySize) {
    T max{ *array };
    T max2{ *array };
    
    for (int j{}; j < arraySize; j++)
    {
        if (*(array + j) > max2)
            max2 = *(array + j);
        if (max < (*(array + j)))
        {
            max2 = max;
            max = *(array + j);
        }
    }
    cout << "The second largest value is: " << max2 << endl << endl;
}


// Sort an array in ascending order and print it
template <class T>
void sortArray(T *array, const int arraySize) {
    
    for (int i{}; i < arraySize; i++)
    {
        for (int j{}; j < arraySize; j++)
        {
            if (*(array + i) < *(array + j))
            {
                T temp{};
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
    
    // Print the sorted array
    cout << "The sorted array is: ";
    printarray(array, arraySize);
}


// Saves an array to a text file
template <class T>
void saveArray(T *array, const int arraySize, string fileName) {
    // An example of an absolute path
    //string filePath = "/Users/Averru/Desktop/College/C++/Projects/Homework2/" + fileName + ".dat";
    
    // Define a relative path
    string filePath = "./" + fileName + ".dat";
    ofstream outfile(filePath, ios::out);
    
    // Check if outfile was successfully opened
    if (!outfile) {
        cout << "Couldn't open " << fileName << endl;
    }
    else {
        for (int i = 0; i < arraySize; i++) {
            outfile << array[i] << " ";
        }
        
        outfile.close();
        cout << endl;
    }
}


// Retrieves an array from a text file and prints the array
template <class T>
void retrieveArray(T *array, const int arraySize, string fileName) {
    // An example of an absolute path
    //string filePath = "/Users/Averru/Desktop/College/C++/Projects/Homework2/" + fileName + ".dat";
    
    // Define relative path
    string filePath = "./" + fileName + ".dat";
    ifstream infile(filePath, ios::in);
    
    // Check if infile exists
    if (!infile) {
        cout << "Couldn't open " << fileName << endl;
    }
    else {
        for (int i = 0; i < arraySize; i++) {
            infile >> array[i];
        }
        infile.close();
        
        cout << "Retrieved the following data from " << fileName << ": " << endl;
        printarray(array, arraySize);
        cout << endl;
    }
}


int main() {
    const int n1 = 5, n2 = 7, n3 = 6; // 3 sizes of the arrays
    int a[n1]{};
    float b[n2]{};
    char c[n3]{};
    
    // Testing arrays
//    int a[n1] = {4, 2, 10, 8, 6};
//    float b[n2] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
//    char c[n3] = "HELLO";
//
//    cout <<"the integer array" << endl;
//    printarray(a, n1);
//
//    cout <<"the float array" << endl;
//    printarray(b,n2);
//
//    cout <<"the string is" << endl;
//    printarray(c,n3);
    
    // Array types
    string ints = "integers", floats = "floats", chars = "characters";
    
    // Get data from a user
    loadArray(a, n1, ints);
    loadArray(b, n2, floats);
    loadArray(c, n3, chars);

    // Find the second largerst value in each array
    secondLargestNumber(a, n1);
    secondLargestNumber(b, n2);
    secondLargestNumber(c, n3);

    // Sort and print the arrays
    sortArray(a, n1);
    sortArray(b, n2);
    sortArray(c, n3);
    
    // Save the arrays to a file
    saveArray(a, n1, ints);
    saveArray(b, n2, floats);
    saveArray(c, n3, chars);
    
    // Retrieve the data from the file and print it
    retrieveArray(a, n1, ints);
    retrieveArray(b, n2, floats);
    retrieveArray(c, n3, chars);
    
    return 0;
}

/*
EXAMPLE OF INPUT & OUTPUT
 
Enter 5 integers: 5 4 3 7 1
Enter 7 floats: 1.1 2.2 3.3 4.4 5.5 6.6 7.7
Enter 6 characters: hello!
The second largest value is: 5

The second largest value is: 6.6

The second largest value is: l

The sorted array is: 1  3  4  5  7
The sorted array is: 1.1  2.2  3.3  4.4  5.5  6.6  7.7
The sorted array is: !  e  h  l  l  o


Retrieved the following data from integers:
1  3  4  5  7

Retrieved the following data from floats:
1.1  2.2  3.3  4.4  5.5  6.6  7.7

Retrieved the following data from characters:
!  e  h  l  l  o
*/
