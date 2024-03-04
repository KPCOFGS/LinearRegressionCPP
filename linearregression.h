#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H
#include <iostream>
namespace LinearRegression {
    class LinearRegression {
        public:
            LinearRegression(double arr1[], double arr2[], unsigned int size);
            void CalcLine(double arr1[], double arr2[], unsigned int size);
            void Sum_XY(double arr1[], double arr2[], unsigned int size);
            void Sum_X(double arr1[], unsigned int size);
            void Sum_Y(double arr2[], unsigned int size);
            void Sum_XSquared(double arr1[], unsigned int size);
            double Predict(double x);
            bool CheckSize(double arr1[], unsigned int size);
        private:
            double sum_y;
            double m;
            double sum_x;
            double sum_xsquared;
            double b;
            double sum_xy;
            double y_pred;
            bool check_size = true;
    };
#include "linearregression.hpp"
}
#endif