/*************************************************
* Erica Buchanan                Merge Assignment *
* ICS4U                                          *
* 21/04/2021                                     *
*                                                *
* This program will read in ordered lists from   *
* two files, combine them, and print them in     *
* order to a third file.                         *
*************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // Declare variables
    int list1[100];
    int list2[100];
    int list3[200];
    int k = 0;
    int j = 0;

    // Initialize the arrays to a number outside of the array range
    for (int i = 0; i < 100; i++){
        list1[i] = -1;
        list2[i] = -1;
    }
    for (int i = 0; i < 200; i++){
        list3[i] = -1;
    }

    // Open the data files to read and an output file to write
    ifstream inFile1("data1.dat");
    ifstream inFile2("data2.dat");
    ofstream outFile("output.dat");

    // Check if the files are open and print error if they are not
    if (!inFile1.is_open() || !inFile2.is_open()){
        cout << "Unable to open file" << endl;
        return 1;
    // If files are open, read the data from both into two arrays
    }else{
        for (int i = 0; i < 100; i++){
            inFile1 >> list1[i];
            inFile2 >> list2[i];
        }
        // Iterate through both arrays and put them into a third array in order
        for (int i = 0; i < 200; i++){
            // If both arrays' values are still what they were initialized to, do nothing
            if (list1[k] == -1 && list2[j] == -1){
                break;
            // If either array's value has not changed from initialization, assign the other's value to the third array
            }else if (list1[k]== -1){
                list3[i] = list2[j];
                j += 1;
            }else if (list2[j]== -1){
                list3[i] = list1[k];
                k += 1;
            // Assign the smaller value in either array to the third array
            }else if (list1[k] < list2[j]){
                list3[i] = list1[k];
                k += 1;
            }else if (list1[k] > list2[j]){
                list3[i] = list2[j];
                j += 1;
            // If the values are equal, put them one after the other in the third array
            }else if (list1[k] == list2[j]){
                list3[i] = list1[k];
                i += 1;
                list3[i] = list2[j];
                j += 1;
                k += 1;
            }else{
                cout << "error" << endl;
            }
        }
        for (int i = 0; i < 100; i++){
            // Print the list to the output file
            outFile << list3[i] << endl;
        }
    }
    // Close all files
    inFile1.close();
    inFile2.close();
    outFile.close();
    return 0;
}



