#ifndef LOAN_H
#define LOAN_H

class Loan {
public:
    double principal;
    double rate;
    int time;

    Loan(double p, double r, int t) : principal(p), rate(r), time(t) {}

    double calculate() {
        return (principal * rate * time) / 100;
    }
};

#endif