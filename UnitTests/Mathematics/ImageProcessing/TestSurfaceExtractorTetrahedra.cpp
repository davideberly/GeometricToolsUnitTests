#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/SurfaceExtractorTetrahedra.h>
using namespace gtl;

namespace gtl
{
    class UnitTestSurfaceExtractorTetrahedra
    {
    public:
        UnitTestSurfaceExtractorTetrahedra();
    };
}

UnitTestSurfaceExtractorTetrahedra::UnitTestSurfaceExtractorTetrahedra()
{
    UTInformation("Mathematics/ImageProcessing/SurfaceExtractorTetrahedra [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/SurfaceExtractorTetrahedra.h>

namespace gtl
{
    template class SurfaceExtractorTetrahedra<std::uint16_t, float>;
    template class SurfaceExtractorTetrahedra<std::uint32_t, float>;
    template class SurfaceExtractorTetrahedra<std::uint64_t, float>;
    template class SurfaceExtractorTetrahedra<std::size_t, float>;
    template class SurfaceExtractorTetrahedra<std::uint16_t, double>;
    template class SurfaceExtractorTetrahedra<std::uint32_t, double>;
    template class SurfaceExtractorTetrahedra<std::uint64_t, double>;
    template class SurfaceExtractorTetrahedra<std::size_t, double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SurfaceExtractorTetrahedra)
