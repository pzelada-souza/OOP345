// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			11-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];

	{
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored

    // Open the file
    std::ifstream file (argv[1]);

    // Check if the file was open successfully.
    if (!file){

      // If there was an error opening the file, exit the program and print an error message.
      std::cerr << "ERROR: failed on openings [" << argv[1] << "].\n";
			return 1;

		} // if(!file)

		size_t x = 0; // Counter variable to iterate through each line.
    std::string str_book; // Control variable that will hold the string with the books info.

    // Iterate through the file to grab the books data.
		do {

      // Grab the current line from the file and store it in the 'book' variable
			std::getline(file, str_book);

      // Check if the getline command was successful.
			if (file){

        // Check if the line starts with '#'. If it does, don't do anything.
        // If not, store the line in the 'library' object;

        if (str_book[0] != '#'){

        	library[x] = sdds::Book(str_book);
					x++;

        } // if( != '#')

			} // if(file)

		} while (file);

    // Close the file
		file.close();

	} // sdds:Book library[]

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object

  // Lambda expression that fixes the price of the book according to the country and year of publication
  // Does nothing if the country is not US or UK
  auto fix_price = [&](sdds::Book & par_book) {

    // If the country is US, multiply the price by 'usdToCadRate';
    if( par_book.country() == "US"){

      par_book.price() *= usdToCadRate;

    // If the country is UK and the year is between 1990 and 199, multiply the price by 'gbpToCadRate';
    } else if (par_book.country() == "UK" && par_book.year() >= 1990 && par_book.year() <= 1999 ) {

      par_book.price() *= gbpToCadRate;

    } // if()

  }; // fix_price()

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.

  // Call the lambda function above to fix the price
  for(auto& book : library)
    fix_price(book);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
