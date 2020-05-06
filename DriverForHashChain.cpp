#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "hashTableChaining.hpp"


/*
    This is the Test/Performance for the Hash Table with collision resolution of type chaining
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
        return -1;
    }

    int arrayOfData[40000];

    if(in_file.fail()){
        std::cout<< "File failed to open. Error xfilex." << std::endl;
        return -1;
    }
    int c = 0;
    while(getline(in_file,line, ',')){  // loop reading from data file and storing into an array
        arrayOfData[c] = stoi(line);
        c++;
    }
    int numCollisions[400]; // array of number of collisions
    float insertData[400];  // array for averaged inserting times
    float searchData[400];  // array for averaged searching times

    HashChain HashChain(40009);
    using namespace std::chrono;
    int z = 100; // variable for loop condition. pointed to by x, which allows for z to be updated.
    int* zPtr;  // pointer to z.
    zPtr = &z;
    int j = 0;  // index counter for the insertData array
    int k = 0;  // index counter for the serachData array

/*==================================Inserting Test data entries into Hash Table via Chaining===================================================*/
    while(z < 40001){
        high_resolution_clock::time_point start = high_resolution_clock::now();

        for(int i = z - 100; i < z; i++){
            HashChain.insert(arrayOfData[i]);
        }
        std::cout << "Value of z: " << *zPtr << std::endl;

        high_resolution_clock::time_point end = high_resolution_clock::now();

        duration<double> execTime = duration_cast<microseconds>(end - start);

        double insertPerformance = 0.0, insertPerformanceAVG = 0.0;
        insertPerformance = execTime.count();
        insertPerformanceAVG = insertPerformance/100;
        insertData[j] = insertPerformanceAVG;   // AVG of inserting data times

        numCollisions[j] = HashChain.getNumCollisions();

/*=========================================Searching Test data Hash Table via Chainging==========================================================*/
        int* valueToSearchFor = new int[100];
        for(int a = z - 100; a < z; a++){   // generating random values withing designated data interval
            valueToSearchFor[a] = arrayOfData[random(0,(z-1))] ;
        }

        start = high_resolution_clock::now();

        for(int i = 0; i < 100; i++){
            HashChain.search(valueToSearchFor[i]);
        }


        end = high_resolution_clock::now();

        execTime = duration_cast<microseconds>(end - start);
        std::cout << "Search: Value of z: " << *zPtr << std::endl;

        double searchPerformance = 0.0, searchPerformanceAVG = 0.0;
        searchPerformance = execTime.count();
        searchPerformanceAVG = searchPerformance/100;
        searchData[k] = searchPerformanceAVG;   // AVG of search data times
        delete [] valueToSearchFor;

        j++;    // incrememnting index for insert array and num of collisions
        k++;    // incrementing index for search array
        z = *zPtr + 100;
        // std::cout<< "Value of J: " << j << std::endl;
        // std::cout<< "Value of k: " << k << std::endl;

    }
    // bellow is formatted to write to a csv file
    out_File << "Insert Data" << "," << "Search Data" << "," << "Number Of Collisions" << std::endl;
    
    for(int y = 0; y < 400; y++){
        out_File << insertData[y] << "," << searchData[y] << "," << numCollisions[y] << std::endl;
    }

    in_file.close();
    out_File.close();
    return 0;
}