cmake_minimum_required(VERSION 3.23)
project(cpp_plus_data_structures)

set(CMAKE_CXX_STANDARD 20)

find_package(Catch2 3 REQUIRED)

add_executable(fraction_test c1/fraction_test.cpp c1/Fraction_type.cpp)
add_executable(c1_e17 c1/e17.cpp)
add_executable(data_type c2/Date_type.cpp c2/date_type_test.cpp)
add_executable(card
        c3/Card.cpp
        c3/Card.h
        c3/Unsorted.hpp
#        c3/Item.h
#        c3/Item.cpp
        c3/Deck.cpp
        c3/Deck.h)
target_link_libraries(data_type PRIVATE Catch2::Catch2WithMain)
