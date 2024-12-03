#include <iostream>
#include <cstdlib>

struct Matrix {
    int** data_ = nullptr;
    size_t x_ = 0u;
    size_t y_ = 0u;
};


void Construct(Matrix& mat, size_t x, size_t y) {
    mat.x_ = x;
    mat.y_ = y;
    mat.data_ = new int*[x];
    for (size_t i = 0; i < x; ++i) {
        mat.data_[i] = new int[y]();
    }
}


void Destruct(Matrix& mat) {
    if (mat.data_ != nullptr) {
        for (size_t i = 0; i < mat.x_; ++i) {
            delete[] mat.data_[i];
        }
        delete[] mat.data_;
        mat.data_ = nullptr;
        mat.x_ = 0;
        mat.y_ = 0;
    }
}


Matrix Copy(const Matrix& mat) {
    Matrix copy;
    Construct(copy, mat.x_, mat.y_);
    for (size_t i = 0; i < mat.x_; ++i) {
        for (size_t j = 0; j < mat.y_; ++j) {
            copy.data_[i][j] = mat.data_[i][j];
        }
    }
    return copy;
}


Matrix Add(const Matrix& a, const Matrix& b) {
    if (a.x_ != b.x_ || a.y_ != b.y_) {
        return Matrix();
    }
    Matrix result;
    Construct(result, a.x_, a.y_);
    for (size_t i = 0; i < a.x_; ++i) {
        for (size_t j = 0; j < a.y_; ++j) {
            result.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return result;
}


Matrix Sub(const Matrix& a, const Matrix& b) {
    if (a.x_ != b.x_ || a.y_ != b.y_) {
        return Matrix();
    }
    Matrix result;
    Construct(result, a.x_, a.y_);
    for (size_t i = 0; i < a.x_; ++i) {
        for (size_t j = 0; j < a.y_; ++j) {
            result.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return result;
}


Matrix Mult(const Matrix& a, const Matrix& b) {
    if (a.y_ != b.x_) {
        return Matrix();
    }
    Matrix result;
    Construct(result, a.x_, b.y_);
    for (size_t i = 0; i < a.x_; ++i) {
        for (size_t j = 0; j < b.y_; ++j) {
            result.data_[i][j] = 0;
            for (size_t k = 0; k < a.y_; ++k) {
                result.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
    return result;
}


void Transposition(Matrix& mat) {
    Matrix temp;
    Construct(temp, mat.y_, mat.x_);
    for (size_t i = 0; i < mat.x_; ++i) {
        for (size_t j = 0; j < mat.y_; ++j) {
            temp.data_[j][i] = mat.data_[i][j];
        }
    }
    Destruct(mat);
    mat = temp;
}


bool operator==(const Matrix& a, const Matrix& b) {
    if (a.x_ != b.x_ || a.y_ != b.y_) {
        return false;
    }
    for (size_t i = 0; i < a.x_; ++i) {
        for (size_t j = 0; j < a.y_; ++j) {
            if (a.data_[i][j] != b.data_[i][j]) {
                return false;
            }
        }
    }
    return true;
}
