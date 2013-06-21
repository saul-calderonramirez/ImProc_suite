#include "neuralnet.h"

NeuralNet::NeuralNet(){
    cout << "Initializing neural network" << endl;
    this->numInputNeurons = 144;
    this->numOutputNeurons = 1;
    this->numLayers = 3;
    this->numHiddenNeurons = 140;
    this->ptrNeuralNet = fann_create_standard(numLayers, numInputNeurons, numHiddenNeurons, numOutputNeurons);
    fann_set_activation_steepness_hidden(this->ptrNeuralNet, 1);
    fann_set_activation_steepness_output(this->ptrNeuralNet, 1);
    //sigmoidal function
    fann_set_activation_function_hidden(this->ptrNeuralNet, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(this->ptrNeuralNet, FANN_SIGMOID_SYMMETRIC);

    fann_set_train_stop_function(this->ptrNeuralNet, FANN_STOPFUNC_BIT);
    fann_set_bit_fail_limit(this->ptrNeuralNet, 0.01f);

    fann_set_training_algorithm(this->ptrNeuralNet, FANN_TRAIN_RPROP);
}

void NeuralNet::trainNet(char* ptrDataFileName){
    const unsigned int maxEpochs = 1000;
    const float desiredError = 0;
    this->ptrData = fann_read_train_from_file(ptrDataFileName);
    const unsigned int epochsBetweenReports = 10;
    fann_train_on_data(this->ptrNeuralNet, this->ptrData, maxEpochs, epochsBetweenReports, desiredError);
}

void NeuralNet::runNet(char* ptrDataFileName){
    struct fann_train_data *ptrDataTest = fann_read_train_from_file(ptrDataFileName);
    fann_reset_MSE(this->ptrNeuralNet);
    fann_test_data(this->ptrNeuralNet, ptrDataTest);
    printf("Mean Square Error: %f\n", fann_get_MSE(this->ptrNeuralNet));

    fann_type *calc_out;
    for(int i = 0; i < fann_length_train_data(ptrDataTest); i++){
        calc_out = fann_run(this->ptrNeuralNet, ptrDataTest->input[i]);
        cout << "Sample testing:  "<< calc_out[0] << " " << ptrDataTest->output[i][0] << " " << fann_abs(calc_out[0] - ptrDataTest->output[i][0]) << endl;
    }


    fann_destroy_train(ptrDataTest);
}

void NeuralNet::writeDataHeader(char* ptrFileName, int numExamples){
    ofstream file;
    file.open (ptrFileName, std::ios_base::trunc);
    file << numExamples << " " << this->numInputNeurons << " " <<  this->numOutputNeurons << "\n";
    file.close();
}
