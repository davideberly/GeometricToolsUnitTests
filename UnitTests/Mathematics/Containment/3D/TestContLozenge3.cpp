#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContLozenge3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContLozenge3
    {
    public:
        UnitTestContLozenge3();
    };
}

UnitTestContLozenge3::UnitTestContLozenge3()
{
    UTInformation("Mathematics/Containment/3D/ContLozenge3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContLozenge3.h>

namespace gtl
{
    template class ContLozenge3<float>;
    template class ContLozenge3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContLozenge3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContLozenge3)
