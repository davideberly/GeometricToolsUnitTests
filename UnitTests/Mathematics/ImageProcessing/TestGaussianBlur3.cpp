#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/GaussianBlur3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestGaussianBlur3
    {
    public:
        UnitTestGaussianBlur3();
    };
}

UnitTestGaussianBlur3::UnitTestGaussianBlur3()
{
    UTInformation("Mathematics/ImageProcessing/GaussianBlur3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/GaussianBlur3.h>

namespace gtl
{
    template class GaussianBlur3<std::int32_t>;
    template class GaussianBlur3<std::int64_t>;
    template class GaussianBlur3<float>;
    template class GaussianBlur3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(GaussianBlur3)
