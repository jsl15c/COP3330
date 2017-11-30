//  Bob Myers
//  userfile.cpp
//
//  Example of user-entered filenames for both input and output

#include <iostream>
#include <fstream>    // for ifstream, ofstream

using namespace std;

int main()
{
   char filename[25];	// a string for filenames
   ifstream in1;	// a file input stream
   ofstream out1;       // a file output stream

   do
   {
	in1.clear();	// to clear status flags in the stream

       	cout << "Please enter the name of the input file.\n";
       	cout << "Filename:  ";
       	cin >> filename;

       	in1.open(filename);
       	if (!in1)
            cout << "That is not a valid file.  Try again!\n";

   } while (!in1);

   do
   {
	out1.clear();	// to clear status flags in the stream

       	cout << "Please enter the name of the output file.\n";
       	cout << "Filename:  ";
       	cin >> filename;

       	out1.open(filename);
       	if (!out1)
            cout << "That is not a valid file.  Try again!\n";

   } while (!out1);

   int x, y, z;
   in1 >> x >> y >> z;		// read three integers from the file

   // write the integers in a different order
   out1 << z << '\n';
   out1 << y << '\n';
   out1 << x << '\n';

   in1.close();
   out1.close();

   cout << "Processing complete\n";
   return 1;
}
