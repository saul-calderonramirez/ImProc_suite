#ifndef SVMLIGHT_H
#define SVMLIGHT_H
#include <stdio.h>
#include <vector>
#include "includes.h"

namespace svmlight {
    extern "C" {
        #include "svm_light/svm_common.h"
        #include "svm_light/svm_learn.h"
    }
}

using namespace svmlight;

class SVMLight{
private:
    // training examples
    DOC** docs;
    // support vector stuff
    long totwords, totdoc, i;
    double* target;
    double* alpha_in;
    KERNEL_CACHE* kernel_cache;
    MODEL* model; // SVM model

public:
    SVMLight(){
       alpha_in = NULL;
       kernel_cache = NULL; // Cache not needed with linear kernel
       model = (MODEL *) malloc(sizeof (MODEL));

    }
};

#endif
