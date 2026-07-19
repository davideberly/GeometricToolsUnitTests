#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/ExtremalQuery3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestExtremalQuery3
    {
    public:
        UnitTestExtremalQuery3();

    private:
    };
}

UnitTestExtremalQuery3::UnitTestExtremalQuery3()
{
    UTInformation("Mathematics/Geometry/3D/ExtremalQuery3 [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/ExtremalQuery3.h>

namespace gtl
{
    template class ExtremalQuery3<float>;
    template class ExtremalQuery3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ExtremalQuery3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ExtremalQuery3)
