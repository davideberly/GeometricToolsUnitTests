#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/FastMarch2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestFastMarch2
    {
    public:
        UnitTestFastMarch2();
    };
}

UnitTestFastMarch2::UnitTestFastMarch2()
{
    UTInformation("Mathematics/ImageProcessing/FastMarch2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/FastMarch2.h>

namespace gtl
{
    template class FastMarch2<float>;
    template class FastMarch2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(FastMarch2)
