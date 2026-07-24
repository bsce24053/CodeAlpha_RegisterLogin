#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

// Test case: Add Element and Check Size
TEST_CASE("Add Element and Check Size") {
    Sort sorter(5);
    
    sorter.addElement(10);
    sorter.addElement(20);
    sorter.addElement(30);

    REQUIRE(sorter.getSize() == 3);

    REQUIRE(sorter.getArray()[0] == 10);
    REQUIRE(sorter.getArray()[1] == 20);
    REQUIRE(sorter.getArray()[2] == 30);
}

//Test case: Merge Sort
TEST_CASE("Merge Sort") {
    Sort sorter(5);
    
    sorter.addElement(5);
    sorter.addElement(3);
    sorter.addElement(8);
    sorter.addElement(1);
    sorter.addElement(2);

    sorter.mergeSort();

    REQUIRE(sorter.getArray()[0] == 1);
    REQUIRE(sorter.getArray()[1] == 2);
    REQUIRE(sorter.getArray()[2] == 3);
    REQUIRE(sorter.getArray()[3] == 5);
    REQUIRE(sorter.getArray()[4] == 8);
}

//Test case: Add Element when Array is Full
TEST_CASE("Add Element when Array is Full") {
    Sort sorter(3);
    
    // Add elements to the sorter
    sorter.addElement(20);
    sorter.addElement(10);
    sorter.addElement(30);

    sorter.mergeSort();
    sorter.addElement(40);  
    
    REQUIRE(sorter.getSize() == 4);
    REQUIRE(sorter.getArray()[0] == 10);
    REQUIRE(sorter.getArray()[1] == 20);
    REQUIRE(sorter.getArray()[2] == 30);
}


//Test case: Edge Case with Empty Array
TEST_CASE("Edge Case with Empty Array") {
    Sort sorter(0); 

    sorter.addElement(10);
    
    sorter.mergeSort();
    
    REQUIRE(sorter.getSize() == 1);
    REQUIRE(sorter.getArray()[0] == 10);
}

TEST_CASE("Multiple Sorts on Same Array") {
    Sort sorter(5);
    
    sorter.addElement(9);
    sorter.addElement(4);
    sorter.addElement(7);
    sorter.addElement(2);
    sorter.addElement(6);

    sorter.mergeSort();
    REQUIRE(sorter.getArray()[0] == 2);
    REQUIRE(sorter.getArray()[1] == 4);
    REQUIRE(sorter.getArray()[2] == 6);
    REQUIRE(sorter.getArray()[3] == 7);
    REQUIRE(sorter.getArray()[4] == 9);

    sorter.addElement(11);
    sorter.insertionSort();
    
    REQUIRE(sorter.getSize() == 6);
    REQUIRE(sorter.getArray()[0] == 2);
    REQUIRE(sorter.getArray()[1] == 4);
    REQUIRE(sorter.getArray()[2] == 6);
    REQUIRE(sorter.getArray()[3] == 7);
    REQUIRE(sorter.getArray()[4] == 9);
    REQUIRE(sorter.getArray()[5] == 11);
}

