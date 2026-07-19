#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Interpolation/3D/IntpAkimaUniform3.h>
#include "WICFileIONative.h"
#include <fstream>
using namespace gtl;

namespace gtl
{
    class UnitTestIntpAkimaUniform3
    {
    public:
        UnitTestIntpAkimaUniform3();
    };
}

UnitTestIntpAkimaUniform3::UnitTestIntpAkimaUniform3()
{
    UTInformation("Mathematics/Interpolation/3D/IntpAkimaUniform3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Interpolation/3D/IntpAkimaUniform3.h>

namespace gtl
{
    template class IntpAkimaUniform3<float>;
    template class IntpAkimaUniform3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class IntpAkimaUniform3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntpAkimaUniform3)
