#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/SurfaceExtractorCubes.h>
using namespace gtl;

namespace gtl
{
    class UnitTestSurfaceExtractorCubes
    {
    public:
        UnitTestSurfaceExtractorCubes();
    };
}

UnitTestSurfaceExtractorCubes::UnitTestSurfaceExtractorCubes()
{
    UTInformation("Mathematics/ImageProcessing/SurfaceExtractorCubes [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/SurfaceExtractorCubes.h>

namespace gtl
{
    template class SurfaceExtractorCubes<std::uint16_t, float>;
    template class SurfaceExtractorCubes<std::uint32_t, float>;
    template class SurfaceExtractorCubes<std::uint64_t, float>;
    template class SurfaceExtractorCubes<std::size_t, float>;
    template class SurfaceExtractorCubes<std::uint16_t, double>;
    template class SurfaceExtractorCubes<std::uint32_t, double>;
    template class SurfaceExtractorCubes<std::uint64_t, double>;
    template class SurfaceExtractorCubes<std::size_t, double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SurfaceExtractorCubes)
