#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Interpolation/1D/IntpAkimaNonuniform1.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntpAkimaNonuniform1
    {
    public:
        UnitTestIntpAkimaNonuniform1();
    };
}

UnitTestIntpAkimaNonuniform1::UnitTestIntpAkimaNonuniform1()
{
    UTInformation("Mathematics/Interpolation/1D/IntpAkimaNonuniform1 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Interpolation/1D/IntpAkimaNonuniform1.h>

namespace gtl
{
    template class IntpAkimaNonuniform1<float>;
    template class IntpAkimaNonuniform1<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class IntpAkimaNonuniform1<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntpAkimaNonuniform1)
