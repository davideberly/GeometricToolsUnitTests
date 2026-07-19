#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Interpolation/1D/IntpAkimaUniform1.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntpAkimaUniform1
    {
    public:
        UnitTestIntpAkimaUniform1();
    };
}

UnitTestIntpAkimaUniform1::UnitTestIntpAkimaUniform1()
{
    UTInformation("Mathematics/Interpolation/1D/IntpAkimaUniform1 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Interpolation/1D/IntpAkimaUniform1.h>

namespace gtl
{
    template class IntpAkimaUniform1<float>;
    template class IntpAkimaUniform1<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class IntpAkimaUniform1<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntpAkimaUniform1)
