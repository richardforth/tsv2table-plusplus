#include <vector> // Include vector support
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::right;
using std::setw;


int main(int argc, char *argv[])
{
    string line, fname ;
    vector <string> result ; // Create a string array.
    int cols = 0 ;  // Create counter variable for columns.
    int rows = 0 ;  // Create counter variable for rows.
    int maxcols = 0, maxrows = 0; // variables to keep highscores
    int cellsize = 0 , maxcellsize = 0 ; // variables to dynamically size tables based on content


    // TODO: check for stdin
    cout << "Argument Count: " << argc << endl;
    cout << "Argument0: " << argv[0] << endl;
    cout << "Argument1: " << argv[1] << endl;

    if (argc != 2)
    {
        cout << "Usage: csv2table++ filename.csv" << endl ;
        return -1 ;
    }

    fname = argv[1] ;
    ifstream reader( fname ) ; // Create input file object from argument provided.
    if( ! reader ) // Always check this.
    {
        cout << "Error opening input file" << endl ;
        return -1 ;
    }

    while( ! reader.eof() ) // Loop through data...
    {
        cols = 0; // reset counter each new line
        getline(reader, line);
        rows++ ;
        if (maxrows < rows)
            maxrows = rows ;
        stringstream ss( line );
        while( ss.good() )
        {
            string substr;
            getline( ss, substr, '\t' ) ;

            cellsize = substr.size() ;
            if (maxcellsize < cellsize)
                maxcellsize = cellsize ;
            cols++ ;
            if (maxcols < cols)
                maxcols = cols ;
            if (substr != "" )
                result.push_back( substr ) ;
            else
                cout << "Empty line ignored." << endl ;
        }
    }
    reader.close() ;

    cout << "Elements in result array: " << result.size() << endl ;
    cout << "Max Columns: " << maxcols << endl ;
    cout << "Max Rows: " << maxrows << endl ;
    cout << "Max Cell Size: " << (maxcellsize + 2) << endl ; // +2 for one space margin each side


    cols = 0 ;  // Reset and re-use counter variable for columns.
    rows = 0 ;  // Reset and re-use variable for rows.
    int i = 0 ; // Add a new counter variable
    while (i < result.size() )
    {
        if ( rows ==  0 )
        {
            cout << right << setw(1) << "+" ;
            cols = 0;
            while ( cols < maxcols )
            {
                cout <<  setw(maxcellsize +2 ) << string((maxcellsize + 2), '-') << setw( 2 ) << "-+" ;
                cols++ ;
            }
            cout << endl ;

            cout << right << setw(1) << "|" ;
            cols = 0 ; // reset cols to 0
            while (cols < maxcols)
            {
                cout << right << setw(maxcellsize +2 ) << result.at( i++ ) << setw( 2 ) << " |" ;
                cols++ ;
            }
            cout << endl ;
            cols = 0 ; // reset cols to 0
            cout << right << setw(1) << "+" ;
            while ( cols < maxcols )
            {
                cout <<  setw(maxcellsize +2 ) << string((maxcellsize + 2), '-') << setw( 2 ) << "-+" ;
                cols++ ;
            }
            cout << endl ;
            rows++ ;
        }
        else
        {
            cout << "|" ;
            cols = 0 ; // reset cols  for new row
            while (cols < maxcols)
            {
                cout << right << setw(maxcellsize +2 ) << result.at( i++ ) << setw( 2 ) << " |" ;
                cols++ ;
            }
            cout << endl ;
            rows++ ;
        }
    }
    cols = 0 ; // reset cols to 0
    cout << right << setw(1) << "+" ;
    while ( cols < maxcols )
    {
        cout <<  setw(maxcellsize +2 ) << string((maxcellsize + 2), '-') << setw( 2 ) << "-+" ;
        cols++ ;
    }
    cout << endl ;
    return 0 ;
}
