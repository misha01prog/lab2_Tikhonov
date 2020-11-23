#include "calc.h"
#include <fstream>
#include <sstream>

Calc::Calc(const Calc& other) {
    initial = other.initial;
    this->data = other.data;
}

Calc::Calc(Calc&& other) {
    initial = other.initial;
    this->data = move(other.data);
}

void Calc::Push(const ComplexNumber& c, Sign s) {
    data.Push({ c, s });
}
void Calc::Push(ComplexNumber&& c, Sign s) {
    data.Push({ move(c), s });
}

void Calc::Pop() {
    data.Pop();
}

void Calc::Clear() {
    data.~Stack();
    initial = { 0,0 };
}

ComplexNumber Calc::Calculate() const {
    ComplexNumber number = initial;
    auto it = Top();
    while (it != nullptr) {
        if (it->value.second == Sign::SUM) {
            number = number + it->value.first;
        }
        else if (it->value.second == Sign::SUBSTRACT) {
            number = number - it->value.first;
        }
        else if (it->value.second == Sign::MULTIPLY) {
            number = number * it->value.first;
        }
        else if (it->value.second == Sign::DIVIDE) {
            number = number / it->value.first;
        }
        else throw runtime_error("Error while stack calculating");
        it = it->next;
    }
    return number;
}

bool Calc::operator==(const Calc& other) {
    auto it1 = Top();
    auto it2 = other.Top();
    while (it1 != nullptr && it2 != nullptr) {
        if (!(it1->value.first == it2->value.first
            && it1->value.second == it2->value.second))
            return false;
        it1 = it1->next;
        it2 = it2->next;
    }
    return it1 == nullptr && it2 == nullptr ? 1 : 0;
}

void Calc::operator=(const Calc& other) {
    initial = other.initial;
    data = other.data;
}

void Calc::operator=(Calc&& other) {
    initial = move(other.initial);
    data = move(other.data);
}

ostream& operator<<(ostream& os, const Calc& calc) {
    auto it = calc.Top();
    while (it != nullptr) {
        if (it->value.second == Sign::SUM) {
            os << "SUM " << it->value.first.toString() << '\n';
        }
        else if (it->value.second == Sign::SUBSTRACT) {
            os << "SUB " << it->value.first.toString() << '\n';
        }
        else if (it->value.second == Sign::MULTIPLY) {
            os << "MUL " << it->value.first.toString() << '\n';
        }
        else if (it->value.second == Sign::DIVIDE) {
            os << "DIV " << it->value.first.toString() << '\n';
        }
        else throw runtime_error("Error while stack iterating");
        it = it->next;
    }
    return os;
}

void Calc::SateToFile(const string& filename) {
    ofstream file;
    try {
        file.open(filename, ios::out);
    }
    catch (exception& e) {
        cout << "File was not opened, " << e.what();
    }
    auto it = Top();
    while (it != nullptr) {
        file << it;
    }
}


void Calc::LoadFromFile(const string& filename) {
    ifstream file;
    try {
        file.open(filename, ios::in);
    }
    catch (exception& e) {
        cout << "File was not opened, " << e.what();
    }
    string line;
    Calc calc;
    while (file) {
        getline(file, line, '\n');
        istringstream ss(line);
        ComplexNumber n;
        Sign si;
        {
            string type, sign, todo;
            float real, image;
            ss >> type >> real >> todo >> image >> sign;
            n.setReal(real);
            n.setImag(image);
            if (todo == "SUM") {
                si = Sign::SUM;
            }
            else if (todo == "SUB") {
                si = Sign::SUBSTRACT;
            }
            else if (todo == "MUL") {
                si = Sign::MULTIPLY;
            }
            else if (todo == "DIV") {
                si = Sign::DIVIDE;
            }
            else { si = Sign::SUM; }
        }
        calc.Push(n, si);
    }
    *this = calc;

}
