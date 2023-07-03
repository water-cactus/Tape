#include <iostream>
#include "Tape.hpp"
#include "SorterTape.hpp"

/**
 * @brief Program that sort data from input tape and output them on other tape
 * @param argc - number of parameters in command line must be eaual 3
*         argv[1] - name for input tape
 *        argv[2] - name for output tape
 */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Invalid number of args to program." << std::endl;
        return 0;
    } else {
        Tape* inputTape  = new Tape(argv[1]);
        Tape* outputTape = new Tape(argv[2], inputTape->size_);

        SorterTape* sorterTape = new SorterTape(inputTape, outputTape);

        sorterTape->sorted();

        return 0;
    }
}
