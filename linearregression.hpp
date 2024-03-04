#ifndef LINEARREGRESSION_HPP
#define LINEARREGRESSION_HPP
LinearRegression::LinearRegression(double arr1[], double arr2[], unsigned int size){
    if (CheckSize(arr1, size)) {
        CalcLine(arr1,arr2,size);
    }
    else {
        std::cout<<"Bad Data"<<std::endl;
        check_size = false;
    }

}
void LinearRegression::Sum_XY(double arr1[], double arr2[], unsigned int size){
    sum_xy = 0;
    for (unsigned int i = 0; i < size; i++) {
            sum_xy = sum_xy + (arr1[i] * arr2[i]);
        }
}
void LinearRegression::Sum_X(double arr1[], unsigned int size){
    sum_x = 0;
    for (unsigned int i = 0; i < size; i++) {
            sum_x = sum_x + arr1[i];
        }
}
void LinearRegression::Sum_Y(double arr2[], unsigned int size){
    sum_y = 0;
    for (unsigned int i = 0; i < size; i++) {
            sum_y = sum_y + arr2[i];
        }
}
void LinearRegression::Sum_XSquared(double arr1[], unsigned int size) {
    sum_xsquared = 0;
    for (unsigned int i = 0; i < size; i++) {
            sum_xsquared = sum_xsquared + (arr1[i] * arr1[i]);
        }
}
void LinearRegression::CalcLine(double arr1[], double arr2[], unsigned int size) {
    Sum_XY(arr1,arr2,size);
    Sum_X(arr1,size);
    Sum_Y(arr2,size);
    Sum_XSquared(arr1,size);
    double denom = ((size * sum_xsquared) - (sum_x * sum_x));
    if (denom != 0.0) {
        m = ((size * sum_xy) - (sum_x * sum_y)) / denom;
        b = (sum_y - (m * sum_x)) / size;
    }
    else {
        std::cout << "Zero Division Error!"<<std::endl;
        check_size = false;
    }

}
double LinearRegression::Predict(double x) {
    if (check_size == false) {
        throw std::runtime_error("Cannot Predict");
    }
    y_pred = (m * x) + b;
    return y_pred;

}
bool LinearRegression::CheckSize(double arr1[], unsigned int size) {
    if (size < 2) {
        return false;
    }
    double check = 0;
    for (unsigned int i = 0; i < size; i++) {
        check = check + arr1[i];
    }
    check = check / size;
    if (check == arr1[0]) {
        return false;
    }
    return true;
}
#endif