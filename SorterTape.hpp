#ifndef SORTER_TAPE_HPP_
#define SORTER_TAPE_HPP_

#include "Tape.hpp"

class SorterTape {
    public:
        Tape* inputTape_;
        Tape* outputTape_;
    public:
        SorterTape(Tape* inputTape, Tape* outputTape):
        inputTape_(inputTape),
        outputTape_(outputTape)
        {}

        void sorted();

        ~SorterTape() {}
};

#endif // SORTER_TAPE_HPP_
