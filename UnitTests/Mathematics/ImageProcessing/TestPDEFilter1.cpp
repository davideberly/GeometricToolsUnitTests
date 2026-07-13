#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/PDEFilter1.h>
using namespace gtl;

namespace gtl
{
    class UnitTestPDEFilter1
    {
    public:
        UnitTestPDEFilter1();
    };
}

UnitTestPDEFilter1::UnitTestPDEFilter1()
{
    UTInformation("Mathematics/ImageProcessing/PDEFilter1 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/PDEFilter1.h>

namespace gtl
{
    template class PDEFilter1<std::int32_t>;
    template class PDEFilter1<std::int64_t>;
    template class PDEFilter1<float>;
    template class PDEFilter1<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(PDEFilter1)
