#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/FastGaussianBlur3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestFastGaussianBlur3
    {
    public:
        UnitTestFastGaussianBlur3();
    };
}

UnitTestFastGaussianBlur3::UnitTestFastGaussianBlur3()
{
    UTInformation("Mathematics/ImageProcessing/FastGaussianBlur3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/FastGaussianBlur3.h>

namespace gtl
{
    template class FastGaussianBlur3<std::int16_t>;
    template class FastGaussianBlur3<std::int32_t>;
    template class FastGaussianBlur3<float>;
    template class FastGaussianBlur3<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(FastGaussianBlur3)
