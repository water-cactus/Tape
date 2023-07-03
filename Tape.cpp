#include <cstdio>
#include "Tape.hpp"

int* Tape::delayInfo_ = Tape::readConfig();

int Tape::readElem() {
    long pos = ftell(Tape::data_);
    
    fscanf(Tape::data_, "%d", &(Tape::curElem_));
    
    fseek(Tape::data_, pos, SEEK_SET);
    
    return Tape::curElem_;
}

int Tape::shiftRight() {
    int sym = 0;
    while((sym = fgetc(Tape::data_)) != ' ') {
        if (sym == EOF) {
            fseek(Tape::data_, 0, SEEK_SET);
            Tape::curIndex_ = 0;
            return Tape::curIndex_;
        }
    }
    Tape::curIndex_++;

    return Tape::curIndex_;
}

int Tape::rewindLeft() {
    fseek(Tape::data_, 0, SEEK_SET);
    Tape::curIndex_ = 0;
    return Tape::curIndex_;
}

void Tape::writeElem(int value) {
    long pos = ftell(Tape::data_);

    if (Tape::curIndex_ + 1 == Tape::size_)
        fprintf(Tape::data_, "%d", value);
    else
        fprintf(Tape::data_, "%d ", value);

    fseek(Tape::data_, pos, SEEK_SET);
}
