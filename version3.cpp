#include <iostream>
#include <Eigen/Dense> // Bibliothèque pour les calculs matriciels

using namespace std;
using namespace Eigen; // Pour utiliser les fonctions de la bibliothèque Eigen

int main()
{
  // Définir les données d'entraînement
  MatrixXd X(5, 2);
  X << 1, 1,
       1, 2,
       2, 1,
       2, 2,
       3, 1;

  VectorXd y(5);
  y << 0,
       0,
       0,
       1,
       1;

  // Calculer les paramètres de régression (w)
  MatrixXd Xt = X.transpose();
  MatrixXd XtX = Xt * X;
  MatrixXd XtX_inv = XtX.inverse();
  MatrixXd XtX_inv_Xt = XtX_inv * Xt;
  VectorXd w = XtX_inv_Xt * y;

  // Afficher les paramètres de régression
  cout << "Les paramètres de régression (w) sont :" << endl;
  cout << w << endl;

  return 0;
}
