/*! 
 * \file  mfront/include/MFront/SearchFile.hxx
 * \brief
 * \author Helfer Thomas
 * \brief 21 mai 2013
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_MFRONT_MFRONTSEARCHFILE_H_
#define LIB_MFRONT_MFRONTSEARCHFILE_H_ 

#include<set>
#include<string>

#include"MFront/MFrontConfig.hxx"

namespace mfront
{

  /*!
   * structure in charge of:
   * - storing search paths
   * - searching imported mfront file
   */
  struct MFRONT_VISIBILITY_EXPORT SearchFile
  {
    /*!
     * search a file in the specified paths.
     * The file is searched using
     * the following conventions :
     * - search in the current directory.
     * - search in the search paths from the most recently declared
         search path to the older ones.
     *
     * Search paths declared through the MFRONT_INCLUDE_PATH are
     * stored at the end of the list.
     *
     * \param[in] f : file name
     * \return the full path of the file
     */
    static std::string
    search(const std::string&);
    /*!
     * \param[in] p : new search paths
     */
    static void
    addSearchPaths(const std::string&);
    /*!
     * \return the list of the search paths
     */
    static const std::vector<std::string>&
    getSearchPaths(void);
  private:
    /*!
     * return the uniq instance of the class
     */
    static TFEL_VISIBILITY_LOCAL SearchFile&
    getSearchFile(void);
    /*!
     * Default constructor
     *
     * The MFRONT_INCLUDE_PATH environnement variable
     * is used to fill the search paths.
     */
    TFEL_VISIBILITY_LOCAL SearchFile();
    SearchFile(const SearchFile&) = delete;
    SearchFile(SearchFile&&) = delete;
    SearchFile& operator=(const SearchFile&) = delete;
    SearchFile& operator=(SearchFile&&) = delete;
    //! list of search paths
    std::vector<std::string> paths;
  };

} // end of SearchFile

#endif /* LIB_MFRONT_MFRONTSEARCHFILE_H_ */

