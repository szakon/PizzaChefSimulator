#
# For googletest
#
# Contents coming from https://github.com/google/googletest/tree/main/googletest#incorporating-into-an-existing-cmake-project

cmake_minimum_required(VERSION 2.8.2...3.15)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           main
  SOURCE_DIR        "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-src"
  BINARY_DIR        "/Users/sarahzakon/Desktop/TSP/2A/C++/project/jeu_monsieur_madame/cmake-build-debug/unitTests/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
