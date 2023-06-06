# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-src"
  "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-build"
  "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-subbuild/pugixml-populate-prefix"
  "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-subbuild/pugixml-populate-prefix/tmp"
  "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp"
  "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-subbuild/pugixml-populate-prefix/src"
  "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-release/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
