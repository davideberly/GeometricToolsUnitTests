#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/SurfaceExtractor.h>
using namespace gtl;

namespace gtl
{
    class UnitTestSurfaceExtractor
    {
    public:
        UnitTestSurfaceExtractor();
    };
}

UnitTestSurfaceExtractor::UnitTestSurfaceExtractor()
{
    UTInformation("Mathematics/ImageProcessing/SurfaceExtractor [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/SurfaceExtractor.h>

namespace gtl
{
    template class SurfaceExtractor<std::uint16_t, float>;
    template class SurfaceExtractor<std::uint32_t, float>;
    template class SurfaceExtractor<std::uint64_t, float>;
    template class SurfaceExtractor<std::size_t, float>;
    template class SurfaceExtractor<std::uint16_t, double>;
    template class SurfaceExtractor<std::uint32_t, double>;
    template class SurfaceExtractor<std::uint64_t, double>;
    template class SurfaceExtractor<std::size_t, double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SurfaceExtractor)
