#include "svmlight.h"
namespace svmlight {
    extern "C" {
        #include "svm_light/svm_common.h"
        #include "svm_light/svm_learn.h"
    }
}
