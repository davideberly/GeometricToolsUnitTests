#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/FastMarch3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestFastMarch3
    {
    public:
        UnitTestFastMarch3();
    };
}

UnitTestFastMarch3::UnitTestFastMarch3()
{
    UTInformation("Mathematics/ImageProcessing/FastMarch3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/FastMarch3.h>

namespace gtl
{
    template class FastMarch3<float>;
    template class FastMarch3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(FastMarch3)
