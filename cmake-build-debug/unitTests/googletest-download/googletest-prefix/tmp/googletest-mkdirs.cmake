# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-src"
  "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-build"
  "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-download/googletest-prefix"
  "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-download/googletest-prefix/tmp"
  "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-download/googletest-prefix/src/googletest-stamp"
  "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-download/googletest-prefix/src"
  "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-download/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-download/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/iris/JIN/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-download/googletest-prefix/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
