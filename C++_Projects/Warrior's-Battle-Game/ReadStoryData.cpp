#include <iostream>
#include <fstream>
#include <string>
#include "ReadStoryData.h"

using namespace std;

void readFiles (string& myName)
{
     string isRead;
     
     ifstream inFile;
     inFile.open("AboutGame.txt");
     
     if (inFile.fail())
     {
         cout << "About Game load failed!!" << endl;
         exit(1);
     }
     
     system ("CLS");
     while (getline(inFile, isRead))
     {
           cout << isRead << endl;
     }
     inFile.close();
}
