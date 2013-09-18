#ifndef NEURALNET_H
#define NEURALNET_H

#include "includes.h"
using namespace std;
class NeuralNet
{
private:
    unsigned int numInputNeurons;
    unsigned int numOutputNeurons;
    unsigned int numLayers;
    unsigned int numHiddenNeurons;

    struct fann *ptrNeuralNet;
    struct fann_train_data *ptrData;

public:
    NeuralNet();
    void trainNet(char* ptrDataFileName);
    void runNet(char* ptrDataFileName);
    void writeDataHeader(char *ptrFileName, int numExamples);
};

#endif // NEURALNET_H
