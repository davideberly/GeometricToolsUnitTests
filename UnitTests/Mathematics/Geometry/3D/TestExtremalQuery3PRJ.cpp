#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/ExtremalQuery3PRJ.h>
using namespace gtl;

namespace gtl
{
    class UnitTestExtremalQuery3PRJ
    {
    public:
        UnitTestExtremalQuery3PRJ();

    private:
    };
}

UnitTestExtremalQuery3PRJ::UnitTestExtremalQuery3PRJ()
{
    UTInformation("Mathematics/Geometry/3D/ExtremalQuery3PRJ [NEEDS UNIT TESTING]");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Geometry/3D/ExtremalQuery3PRJ.h>

namespace gtl
{
    template class ExtremalQuery3PRJ<float>;
    template class ExtremalQuery3PRJ<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ExtremalQuery3PRJ<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ExtremalQuery3PRJ)
