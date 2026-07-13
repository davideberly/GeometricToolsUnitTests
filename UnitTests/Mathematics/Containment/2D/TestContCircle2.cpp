#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/2D/ContCircle2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContCircle2
    {
    public:
        UnitTestContCircle2();

    private:
        void TestCircumscribe();
        void TestInscribe();
    };
}

UnitTestContCircle2::UnitTestContCircle2()
{
    UTInformation("Mathematics/Containment/2D/ContCircle2 [NEEDS UNIT TESTS]");
}

void UnitTestContCircle2::TestCircumscribe()
{
    Vector2<double> v0{ 0.0, 0.0 };
    Vector2<double> v1{ 1.0, 0.0 };
    Vector2<double> v2{ 0.0, 1.0 };

    Circle2<double> circle;
    bool success = ContCircle2<double>::Circumscribe(v0, v1, v2, circle);
    UTAssert(success, "Circumscribe failed for noncollinear.");

    v0 = { -1.0, 0.0 };
    v1 = { 0.0, 0.0 };
    v2 = { +1.0, 0.0 };
    success = ContCircle2<double>::Circumscribe(v0, v1, v2, circle);
    UTAssert(!success, "Circumscribe failed for collinear.");
}

void UnitTestContCircle2::TestInscribe()
{
    Vector2<double> v0{ 0.0, 0.0 };
    Vector2<double> v1{ 1.0, 0.0 };
    Vector2<double> v2{ 0.0, 1.0 };

    Circle2<double> circle;
    bool success = ContCircle2<double>::Inscribe(v0, v1, v2, circle);
    UTAssert(success, "Inscribe failed for noncollinear.");

    v0 = { -1.0, 0.0f };
    v1 = { 0.0, 0.0 };
    v2 = { +1.0, 0.0f };
    success = ContCircle2<double>::Inscribe(v0, v1, v2, circle);
    UTAssert(!success, "Inscribe failed for collinear.");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/2D/ContCircle2.h>

namespace gtl
{
    template class ContCircle2<float>;
    template class ContCircle2<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContCircle2<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContCircle2)
