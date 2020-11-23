#include <assert.h>
#include "stack.h"
#include "calc.h"
#include <sstream>

void TestComplexNum() {
    ComplexNumber complexNum1(2.0, 7.0);
    ComplexNumber complexNum2(complexNum1);

    // проверка на гетеры, конструктор инициализации, копирования и непараметризованный
    assert(complexNum1.getReal() == 2.0);
    assert(complexNum1.getImag() == 7.0);
    assert(complexNum2.getReal() == complexNum1.getReal());
    assert(complexNum2.getImag() == complexNum1.getImag());
    //assert(complexNum3.getReal() == 4.0);
    //assert(complexNum3.getImag() == 0.0);

    // проверка на сетеры
    complexNum1.setReal(5.0);
    complexNum1.setImag(8.0);
    assert(complexNum1.getReal() == 5.0);
    assert(complexNum1.getImag() == 8.0);

    complexNum1.setReal(1.0);
    complexNum1.setImag(2.0);
    complexNum2.setReal(0.0);
    complexNum2.setImag(0.0);
    assert((complexNum1 + complexNum2).toString() == "1.000000 + 2.000000i");
    assert((complexNum1 - complexNum2).toString() == "1.000000 + 2.000000i");
    assert((complexNum1 * complexNum2).toString() == "0.000000 + 0.000000i");
    cerr << "ComplexNum TEST OK" << endl;

}

void TestCalc() {
    Calc stack; // создали дефортный конструктор
    ComplexNumber complexNum1(2.0, 4.0);
    ComplexNumber complexNum2(complexNum1);
    complexNum2.setReal(4.0);
    complexNum2.setImag(4.0);
    stack.Push(complexNum1, Sign::MULTIPLY);
    assert(stack.Calculate().toString() == "0.000000 + 0.000000i");
    stack.Push(complexNum2, Sign::SUM);
    assert(stack.Calculate().toString() == "24.000000 + 24.000000i");
    stack.Push({ 2,2 }, Sign::SUM);
    assert(stack.Size() == 3);
    assert(stack.Top()->value.first.toString() == "2.000000 + 2.000000i");
    assert(stack.Calculate().toString() == "36.000000 + 36.000000i");

    Calc calcCopy = stack; // провкрка копирования
    assert(calcCopy.Top()->value.first.toString() == "2.000000 + 2.000000i");
    stack.Pop();
    assert(!(stack == calcCopy)); // проверка копия != оригинал
    cerr << "Calculator TEST OK" << endl;
}

int main()
{
    TestComplexNum();
    TestCalc();
    cout << "All tests are done!" << endl;
}
