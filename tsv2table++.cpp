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


void make_table(vector <string> result, int maxcols, int maxrows, int maxcellsize);
bool checkHasExactlyOneArg(int count);
void process_stdin(char delimiter);
void process_arg(string fname, char delimiter);

bool checkHasExactlyOneArg(int count)
{
        //cout << "checkHasArgs() called." << endl;
        //cout << "received variable: "  << count << endl;
        if (count == 2) {
                return true;
        } else {
                return false;
        }
}


void process_arg(string fname, char delimiter)
{
        cout << "process_arg() called on " << fname << endl;

        int cols = 0 ;  // Create counter variable for columns.
        int rows = 0 ;  // Create counter variable for rows.
        int maxcols = 0, maxrows = 0; // variables to keep highscores
        int cellsize = 0 , maxcellsize = 0 ; // variables to dynamically size tables based on content
        vector <string> result;
        string line;
        ifstream reader( fname ) ; // Create input file object from argument provided.
        if( ! reader ) // Always check this.
        {
                cout << "Error opening input file." << endl ;
                cout << "Reverting to STDIN..." << endl ;
                process_stdin(delimiter);
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
                        getline( ss, substr, delimiter ) ;

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
        make_table(result, maxcols, maxrows, maxcellsize);
}

void process_stdin(char delimiter)
{

        int cols = 0 ;  // Create counter variable for columns.
        int rows = 0 ;  // Create counter variable for rows.
        int maxcols = 0, maxrows = 0; // variables to keep highscores
        int cellsize = 0 , maxcellsize = 0 ; // variables to dynamically size tables based on content
        cout << "process_stdin() called" << endl;
        vector <string> result;
        string line;

        while( ! cin.eof() ) // Loop through data...
        {
                cols = 0; // reset counter each new line
                getline(cin, line);
                rows++ ;
                if (maxrows < rows)
                        maxrows = rows ;
                stringstream ss( line );
                while( ss.good() )
                {
                        string substr;
                        getline( ss, substr, delimiter ) ;

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
        make_table(result, maxcols, maxrows, maxcellsize);
}


void make_table(vector <string> result, int maxcols, int maxrows, int maxcellsize)
{
        cout << "make_table() called." << endl;
        cout << "Result array size: " << result.size() << endl;
        cout << "Max Cols: " << maxcols << endl;
        cout << "Max Rows: " << maxrows << endl;
        cout << "Max Cell Size: " << maxcellsize << endl;


        int cols = 0 ;  // Reset and re-use counter variable for columns.
        int rows = 0 ;  // Reset and re-use variable for rows.
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
}

int main(int argc, char *argv[])
{
      cout << "Main Function." << endl;
      char delimiter = '\t';
      cout << "Has Exactly One Argument? " << (checkHasExactlyOneArg(argc) ? "true" : "false") << endl;
      checkHasExactlyOneArg(argc) ? process_arg(argv[1], delimiter) : process_stdin(delimiter);

      return 0;
}
