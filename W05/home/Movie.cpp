// Name:                            Pedro Zelada Souza
// Seneca Student ID:               116427188
// Seneca email:                    pzelada-souza@myseneca.ca
// Date of completion:              17-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <iomanip>
#include "Movie.h"

namespace sdds {

  // Default constructor. Sets the object into a safe empty state
  Movie::Movie(){

    m_title = "";
    m_year = 0;

    m_description = "";

  } // Movie::Movie()

  // Constructor that receives a string with movie information.
  // Retrieves the movie info from the string and store them in the object.
  Movie::Movie(const std::string & str_movie){

    size_t count = 0, previous = 0, current = str_movie.find(','); // Temp variables to get the tokens.
    std::string tokens[3]; // Temporary variable to hold values from token string

    // Search the string for ',' characters
    if(current > 0){

      // Extract substrings from the tokens string until it reaches the second last
      while(count < 2){

        tokens[count] = str_movie.substr(previous, current - previous); // Capture the token before the ',' delimiter

        tokens[count] = trim(tokens[count]); // Trim the white spaces from the token

        previous = current + 1; // Tells where to begin the next substr
        current = str_movie.find(',', previous); // Tells where to end the next substr

        count++;

      } // while()

      // The last token may contain comma characters ',', so manually extract it from the string.
      tokens[2] = str_movie.substr(previous);
      tokens[2] = trim(tokens[2]);

      // Populate the object
      m_title = tokens[0];
      m_year = std::stoi(tokens[1]);
      m_description = tokens[2];

    } // if (current > 0)

  } // Movie::Movie(const std::string &)

  // Query that returns the movie title
  const std::string & Movie::title() const{

    return m_title;

  } // const std::string & Movie::title() const

  // Friend Helpers

  // Friend helper that inserts the content of the object into the output stream
  std::ostream & operator<<(std::ostream & os, const Movie & movie){

    os
      << std::setw(40) << movie.m_title << " | "
      << std::setw( 4) << movie.m_year << " | "
      << movie.m_description << std::endl;

    return os;

  } // std::ostream & operator<<(std::ostream &, const Movie &)

  // Free Helpers

} // namespace sdds
