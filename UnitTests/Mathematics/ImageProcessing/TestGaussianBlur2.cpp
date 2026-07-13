#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/GaussianBlur2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestGaussianBlur2
    {
    public:
        UnitTestGaussianBlur2();
    };
}

UnitTestGaussianBlur2::UnitTestGaussianBlur2()
{
    UTInformation("Mathematics/ImageProcessing/GaussianBlur2 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/GaussianBlur2.h>

namespace gtl
{
    template class GaussianBlur2<std::int32_t>;
    template class GaussianBlur2<std::int64_t>;
    template class GaussianBlur2<float>;
    template class GaussianBlur2<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(GaussianBlur2)
