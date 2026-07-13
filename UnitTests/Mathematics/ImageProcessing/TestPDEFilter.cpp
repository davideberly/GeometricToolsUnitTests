#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/PDEFilter.h>
using namespace gtl;

namespace gtl
{
    class UnitTestPDEFilter
    {
    public:
        UnitTestPDEFilter();
    };
}

UnitTestPDEFilter::UnitTestPDEFilter()
{
    UTInformation("Mathematics/ImageProcessing/PDEFilter [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/PDEFilter.h>

namespace gtl
{
    template class PDEFilter<std::int32_t>;
    template class PDEFilter<std::int64_t>;
    template class PDEFilter<float>;
    template class PDEFilter<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(PDEFilter)
