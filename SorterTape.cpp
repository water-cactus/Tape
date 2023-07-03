#include <climits>
#include "SorterTape.hpp"

void SorterTape::sorted() {
    Tape* tmp = new Tape((char*) "tmp/tmp.txt", SorterTape::inputTape_->size_, 0);
    int elem = 0, id = 0, minElem = 0, minId = 0, nSortedElems = 0;

    while (nSortedElems < SorterTape::inputTape_->size_) {
        minElem = INT_MAX;
        minId = 0;
        for (int i = 0; i < SorterTape::inputTape_->size_; i++) {
            elem = SorterTape::inputTape_->readElem();
            id = SorterTape::inputTape_->curIndex_;
            if (elem < minElem) {
                for (int i = 0; i < id; i++) {
                    tmp->shiftRight();
                }
                if (tmp->readElem() == 0) {
                    minElem = elem;
                    minId = id;
                }
                tmp->rewindLeft();
            }
            SorterTape::inputTape_->shiftRight();
        }
        SorterTape::outputTape_->writeElem(minElem);
        SorterTape::outputTape_->shiftRight(); 
        nSortedElems++;
        for (int i = 0; i < minId; i++) {
            tmp->shiftRight();
        }
        tmp->writeElem(1);
        tmp->rewindLeft();
    }
}
