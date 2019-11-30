// Name:                            Pedro Zelada Souza
// Seneca Student ID:               116427188
// Seneca email:                    pzelada-souza@myseneca.ca
// Date of completion:              17-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the book
	sdds::Collection<sdds::Book> library("Bestsellers");
	{
		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored

    // Open the file
		// std::ifstream book_file (argv[1]);
    std::ifstream book_file ("books.txt");

    // Check if the file was open successfully.
    if (!book_file){

      // If there was an error opening the file, exit the program and print an error message.
      std::cerr << "ERROR: failed on openings [" << argv[1] << "].\n";
			return 1;

		} // if(!book_file)

		size_t x = 0; // Counter variable to iterate through each line.
    std::string str_book; // Control variable that will hold the string with the books info.

    // Iterate through the file to grab the books data.
		do {

      // Grab the current line from the file and store it in the 'book' variable
			std::getline(book_file, str_book);

      // Check if the getline command was successful.
			if (book_file){

        // Check if the line starts with '#'. If it does, don't do anything.
        // If not, store the line in the 'library' object;
        if (str_book[0] != '#'){

        	library += sdds::Book(str_book);
					x++;

        } // if( != '#')

			} // if(book_file)

		} while (book_file && x < 4);

		library.setObserver(bookAddedObserver);

		// TODO: add the rest of the books from the file.

    // Iterate through the file to grab the books data.
		do {

      // Grab the current line from the file and store it in the 'book' variable
			std::getline(book_file, str_book);

      // Check if the getline command was successful.
			if (book_file){

        // Check if the line starts with '#'. If it does, don't do anything.
        // If not, store the line in the 'library' object;
        if (str_book[0] != '#')
					library += sdds::Book(str_book);

			} // if(book_file)

		} while (book_file);

    // Close the file
		book_file.close();

	} // Book file block

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: (from in-lab) create a lambda expression that fixes the price of a book accoding to the rules
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
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from in-lab): iterate over the library and update the price of each book
	//         using the lambda defined above.

  // Call the lambda function above to fix the price
  for(size_t x = 0; x < library.size(); x++)
    fix_price(library[x]);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";


	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	{
		// TODO: load 5 movies from the file "argv[2]".
		//       - read one line at a time, and pass it to the Movie constructor
		//       - store each movie read into the array "movies"
		//       - lines that start with "#" are considered comments and should be ignored

		// Open the file
    // std::ifstream movie_file (argv[2]);
		std::ifstream movie_file ("movies.txt");

    // Check if the file was open successfully.
    if (!movie_file){

      // If there was an error opening the file, exit the program and print an error message.
      std::cerr << "ERROR: failed on openings [" << argv[1] << "].\n";
			return 1;

		} // if(!file)

		size_t x = 0; // Counter variable to iterate through each line.
    std::string str_movie; // Control variable that will hold the string with the books info.

    // Iterate through the file to grab the books data.
		do {

      // Grab the current line from the file and store it in the 'book' variable
			std::getline(movie_file, str_movie);

      // Check if the getline command was successful.
			if (movie_file){

        // Check if the line starts with '#'. If it does, don't do anything.
        // If not, store the line in the 'library' object;
        if (str_movie[0] != '#'){

        	movies[x] = sdds::Movie(str_movie);
					x++;

        } // if( != '#')

			} // if(movie_file)

		} while (movie_file && x < 5);

    // Close the file
		movie_file.close();

	} // Movie file block

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	// Add a few movies to collection; no observer is set
	((theCollection += movies[0]) += movies[1]) += movies[2];
	theCollection += movies[1];
	// add more movies; now we get a callback from the collection
	theCollection.setObserver(movieAddedObserver);
	theCollection += movies[3];
	theCollection += movies[3];
	theCollection += movies[4];
	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";
	
		// TODO: The following loop can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.
		
		// Handle exception
		try {
			
			for (auto i = 0u; i < 10; ++i){
			
				std::cout << theCollection[i];
			
			} // for()

		} catch(const std::exception& e) {
			
			std::cerr << "EXCEPTION: " << e.what() << '\n';
		
		} // try catch()


	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3u; i <= 4u; ++i)
	{
			// TODO: The following statement can generate generate an exception
			//         write code to handle the exception
			//       If an exception occurs print a message in the following format
			//EXCEPTION: ERROR_MESSAGE<endl>
			//         where ERROR_MESSAGE is extracted from the exception object.

			// Handle exception
			try {
				SpellChecker sp(argv[i]);
				for (auto j = 0u; j < theCollection.size(); ++j)
					theCollection[j].fixSpelling(sp);
				for (auto j = 0u; j < library.size(); ++j)
					library[j].fixSpelling(sp);

			} catch(char const * err) {
				
				std::cerr << "EXCEPTION: " << err << '\n';
			
			} // try catch()

	}
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";
	/*
  */

	return 0;
}
