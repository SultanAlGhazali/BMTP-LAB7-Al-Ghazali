#pragma once
#include <iostream>

class ClassLab12_AlGhazali {
private:
    double real;
    double imag;

public:
    ClassLab12_AlGhazali();
    ClassLab12_AlGhazali(double r, double i);

    double getReal() const;
    double getImag() const;
    void setValues(double r, double i);

    ClassLab12_AlGhazali add(const ClassLab12_AlGhazali& other) const;
};
