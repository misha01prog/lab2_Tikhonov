#include "stack.h"
#include <iostream>

class Calc {
public:
    Calc() = default;
    Calc(const Calc& other);
    Calc(Calc&& other);

    void Push(const ComplexNumber& c, Sign s);
    void Push(ComplexNumber&& c, Sign s);
    void Pop();

    Stack::Node* Top() { return data.Top(); }
    const Stack::Node* Top() const { return data.Top(); }
    int Size() { return data.Size(); }

    bool operator==(const Calc& other);
    void operator=(const Calc& other);
    void operator=(Calc&& other);


    void Clear();

    ComplexNumber Calculate() const;

    void SateToFile(const string& filename);
    void LoadFromFile(const string& filename);

private:
    ComplexNumber initial{ 0,0 };
    Stack data;
};

ostream& operator<<(ostream& os, const Calc& calc);
