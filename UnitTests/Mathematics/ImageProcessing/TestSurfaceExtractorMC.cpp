#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/SurfaceExtractorMC.h>
using namespace gtl;

namespace gtl
{
    class UnitTestSurfaceExtractorMC
    {
    public:
        UnitTestSurfaceExtractorMC();
    };
}

UnitTestSurfaceExtractorMC::UnitTestSurfaceExtractorMC()
{
    UTInformation("Mathematics/ImageProcessing/SurfaceExtractorMC [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/SurfaceExtractorMC.h>

namespace gtl
{
    template class SurfaceExtractorMC<std::uint16_t, float>;
    template class SurfaceExtractorMC<std::uint32_t, float>;
    template class SurfaceExtractorMC<std::uint64_t, float>;
    template class SurfaceExtractorMC<std::size_t, float>;
    template class SurfaceExtractorMC<std::uint16_t, double>;
    template class SurfaceExtractorMC<std::uint32_t, double>;
    template class SurfaceExtractorMC<std::uint64_t, double>;
    template class SurfaceExtractorMC<std::size_t, double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SurfaceExtractorMC)
