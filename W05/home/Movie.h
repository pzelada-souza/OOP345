// Name:                            Pedro Zelada Souza
// Seneca Student ID:               116427188
// Seneca email:                    pzelada-souza@myseneca.ca
// Date of completion:              17-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
#include "SpellChecker.h"
#include "Book.h"

namespace sdds {

  class Movie {

    std::string m_title;
    std::string m_description;

    size_t m_year;

  public:

    Movie(); // Default constructor.

    Movie(const std::string &); // One parameter constructor. Extract the object data from received string.

    const std::string& title() const; // Query that returns the movie title.

    template<class T>
    void fixSpelling(T spellChecker) {

      // Pass the movie description to the spell fixing function
      spellChecker(m_description);
      spellChecker(m_title);

    } // void fixSpelling(T)

  private:

    friend std::ostream & operator<<(std::ostream &, const Movie &); // Friend helper that inserts the content of the object into the output stream

  }; // class Movie

} // namespace sdds

#endif
