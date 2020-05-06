#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "LinkedList.hpp"


/*
    This is the Test/Performance for the Linked List implementation of inserting and searching.
    There are 40,000 data points.
    The searching is perfromed by looping and updating variabels via pointers.

    Inserting and searching are performed every 100 data points.
        EX: inserting/searching from [0,99], then from [100,199], then [200,299] and so on.
    Meaning that each 100 iterations and searching is avergaed.
        The seraching is perfored on randomly generated key values to search for

*/
int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

int main(int argc, char* argv[]){

    std::ifstream in_file;
    in_file.open(argv[1]);  // argv[1] is data set to be read from
    std::string line;
    std::stringstream ss;

    std::ofstream out_File;
    out_File.open(argv[2]); // argv[2] is file to have data written to
    if (out_File.fail()){
        std::cout << "Output file failed to open. Error xfilex." << std::endl;
    }

    int arrayOfData[40000];

    if(in_file.fail()){
        std::cout<< "File failed to open. Error xfilex." << std::endl;
    }
    int c = 0;
    while(getline(in_file,line, ',')){  // loop reading from data file and storing into an array
        arrayOfData[c] = stoi(line);
        c++;
    }

    float insertData[400];  // array for averaged inserting times
    float searchData[400];  // array for averaged searching times

    LinkedList LLinked;
    using namespace std::chrono;
    int z = 100; // variable for loop condition. pointed to by x, which allows for z to be updated.
    int* zPtr;  // pointer to z.
    zPtr = &z;
    int j = 0;  // index counter for the insertData array
    int k = 0;  // index counter for the serachData array

/*========================================= inserting Test data entries into LL===================================================*/
    while(z < 40001){
        high_resolution_clock::time_point start = high_resolution_clock::now();

        for(int i = z - 100; i < z; i++){
            LLinked.addNode(arrayOfData[i]);
        }
        std::cout << "Value of z: " << *zPtr << std::endl;

        high_resolution_clock::time_point end = high_resolution_clock::now();

        duration<double> execTime = duration_cast<microseconds>(end - start);

        double insertPerformance = 0.0, insertPerformanceAVG = 0.0;
        insertPerformance = execTime.count();
        insertPerformanceAVG = insertPerformance/100;
        insertData[j] = insertPerformanceAVG;   // AVG of Inserting

/*========================================= Searching Test data entries in LL===================================================*/
        int valueToSearchFor[z];
        for(int a = z - 100; a < z; a++){   // generating random values withing designated data interval
            valueToSearchFor[a] = arrayOfData[random(0,(z-1))] ;
        }

        start = high_resolution_clock::now();

        for(int i = 0; i < 100; i++){
            LLinked.searchLL(valueToSearchFor[i]);
        }


        end = high_resolution_clock::now();

        execTime = duration_cast<microseconds>(end - start);

        double searchPerformance = 0.0, searchPerformanceAVG = 0.0;
        searchPerformance = execTime.count();
        searchPerformanceAVG = searchPerformance/100;
        searchData[k] = searchPerformanceAVG;   // AVG of Searching


        j++;    // incrementing the index at which inserting times are entered into designated array
        k++;    // incrementing the index at which seraching times are entered into designated array
        z = *zPtr + 100;    // updating the condition of while loop
    }   // End of While loop of iterating through data set every 100 entries
    
    // bellow is formatted to write to a csv file
    out_File << "Insert Data" << "," << "Search Data" << std::endl;
    
    for(int y = 0; y < 400; y++){
        out_File << insertData[y] << "," << searchData[y] << std::endl;
    }

    in_file.close();
    out_File.close();
    return 0;
}