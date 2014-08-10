CoffeMaker
==========

hypothetical Generic CoffeeMaker Solution



The Software Model is expandable to implement new coffeMakers depending upon vENDOR sPECIFICATIONS
Features  : 

HOW TO RUN

1. Download Source Code
2. Let Coffee_Maker be your Root Directory
3. make all/coffee/rebuild to build source code
4. coffee - gets generated in bin folder

To run Unit Tests, the Production Source Code needs to be compiled into a Library.This library in then linked and referred in
Test Cases

HoW to Run Utest :

 1. Move to utest folder utest
 2. make lib to build the production code into a library
 3. make all/rebuild to compile unit test
 4. coffee_test gets generated in bin folder.

The application is also configured with a GENERIC Makefile , that relies on lots of variables within the Makefile, but can be tuned
to fit for newer applications

To DO :

  1. Write more test cases.
  2. Introduce a seperate thread to monitor the 'Brew Button'

