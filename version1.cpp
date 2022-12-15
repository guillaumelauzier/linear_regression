#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Compute the mean of a vector of numbers
double mean(vector<double> x) {
  double sum = 0;
  for (int i = 0; i < x.size(); i++) {
    sum += x[i];
  }
  return sum / x.size();
}

// Compute the variance of a vector of numbers
double variance(vector<double> x) {
  double mean_x = mean(x);
  double sum_sq_diff = 0;
  for (int i = 0; i < x.size(); i++) {
    sum_sq_diff += pow(x[i] - mean_x, 2);
  }
  return sum_sq_diff / x.size();
}

// Compute the covariance between two vectors of numbers
double covariance(vector<double> x, vector<double> y) {
  double mean_x = mean(x);
  double mean_y = mean(y);
  double sum_xy = 0;
  for (int i = 0; i < x.size(); i++) {
    sum_xy += (x[i] - mean_x) * (y[i] - mean_y);
  }
  return sum_xy / x.size();
}

// Compute the coefficients of a linear regression model
// using the least squares method
void linear_regression(vector<double> x, vector<double> y,
                       double& intercept, double& slope) {
  double cov = covariance(x, y);
  double var = variance(x);
  slope = cov / var;
  intercept = mean(y) - slope * mean(x);
}

int main() {
  // Define the x and y data for the linear regression model
  vector<double> x = {1, 2, 3, 4, 5};
  vector<double> y = {1, 3, 2, 3, 5};

  // Compute the coefficients of the linear regression model
  double intercept, slope;
  linear_regression(x, y, intercept, slope);

  cout << "Intercept: " << intercept << endl;
  cout << "Slope: " << slope << endl;

  return 0;
}
