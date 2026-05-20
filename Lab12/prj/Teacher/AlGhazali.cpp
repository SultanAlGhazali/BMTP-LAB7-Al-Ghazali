#include "AlGhazali.h"

ClassLab12_AlGhazali::ClassLab12_AlGhazali() {
    this->real = 0.0;
    this->imag = 0.0;
}

ClassLab12_AlGhazali::ClassLab12_AlGhazali(double r, double i) {
    this->real = r;
    this->imag = i;
}

double ClassLab12_AlGhazali::getReal() const {
    return this->real;
}

double ClassLab12_AlGhazali::getImag() const {
    return this->imag;
}

void ClassLab12_AlGhazali::setValues(double r, double i) {
    this->real = r;
    this->imag = i;
}

ClassLab12_AlGhazali ClassLab12_AlGhazali::add(const ClassLab12_AlGhazali& other) const {
    double newReal = this->real + other.getReal();
    double newImag = this->imag + other.getImag();
    return ClassLab12_AlGhazali(newReal, newImag);
}
