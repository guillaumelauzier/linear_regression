#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Struct to represent a training example
struct Example
{
  vector<double> features;
  double label;
};

// Function to compute the dot product of two vectors
double dotProduct(const vector<double>& v1, const vector<double>& v2)
{
  double result = 0;
  for (int i = 0; i < v1.size(); i++)
  {
    result += v1[i] * v2[i];
  }
  return result;
}

// Function to train the linear regression model using stochastic gradient descent
vector<double> trainLinearRegression(const vector<Example>& examples, double learningRate, int numIterations)
{
  // Initialize the model parameters to 0
  vector<double> weights(examples[0].features.size(), 0);

  // Perform gradient descent for the specified number of iterations
  for (int i = 0; i < numIterations; i++)
  {
    // Shuffle the training examples to ensure that they are processed in a random order
    vector<Example> shuffledExamples = examples;
    random_shuffle(shuffledExamples.begin(), shuffledExamples.end());

    // Loop over all examples and update the model parameters
    for (int j = 0; j < shuffledExamples.size(); j++)
    {
      // Compute the predicted label for the current example
      double predicted = dotProduct(shuffledExamples[j].features, weights);

      // Update the model parameters based on the error between the predicted and true label
      for (int k = 0; k < weights.size(); k++)
      {
        weights[k] -= learningRate * (predicted - shuffledExamples[j].label) * shuffledExamples[j].features[k];
      }
    }
  }

  return weights;
}

// Function to predict the label of a new example using the trained linear regression model
double predictLinearRegression(const vector<double>& weights, const vector<double>& example)
{
  return dotProduct(weights, example);
}

int main()
{
  // Create some training examples
  vector<Example> examples = {
    {{1, 1}, 2},
    {{1, 2}, 3},
    {{2, 1}, 3},
    {{2, 2}, 4}
  };

  // Train the linear regression model
  vector<double> weights = trainLinearRegression(examples, 0.1, 100);

  // Use the trained model to make predictions on new examples
  vector<double> example1 = {1, 1};
  cout << "Predicted label for example1: " << predictLinearRegression(weights, example1) << endl;

  vector<double> example2 = {1, 2};
  cout << "Predicted label for example2: " << predictLinearRegression(weights, example2) << endl;

  return 0;
}
