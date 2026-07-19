#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Interpolation/3D/IntpLinear3.h>
#include "WICFileIONative.h"
#include <fstream>
using namespace gtl;

namespace gtl
{
    class UnitTestIntpLinear3
    {
    public:
        UnitTestIntpLinear3();
    };
}

UnitTestIntpLinear3::UnitTestIntpLinear3()
{
    UTInformation("Mathematics/Interpolation/3D/IntpLinear3 [NEEDS UNIT TESTS]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Interpolation/3D/IntpLinear3.h>

namespace gtl
{
    template class IntpLinear3<float>;
    template class IntpLinear3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class IntpLinear3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntpLinear3)
