#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/CurveExtractorSquares.h>
using namespace gtl;

namespace gtl
{
    class UnitTestCurveExtractorSquares
    {
    public:
        UnitTestCurveExtractorSquares();
    };
}

UnitTestCurveExtractorSquares::UnitTestCurveExtractorSquares()
{
    UTInformation("Mathematics/ImageProcessing/CurveExtractorSquares [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/CurveExtractorSquares.h>

namespace gtl
{
    template class CurveExtractorSquares<std::int8_t, float>;
    template class CurveExtractorSquares<std::int16_t, float>;
    template class CurveExtractorSquares<std::int32_t, float>;
    template class CurveExtractorSquares<std::uint8_t, float>;
    template class CurveExtractorSquares<std::uint16_t, float>;
    template class CurveExtractorSquares<std::uint32_t, float>;
    template class CurveExtractorSquares<std::int8_t, double>;
    template class CurveExtractorSquares<std::int16_t, double>;
    template class CurveExtractorSquares<std::int32_t, double>;
    template class CurveExtractorSquares<std::uint8_t, double>;
    template class CurveExtractorSquares<std::uint16_t, double>;
    template class CurveExtractorSquares<std::uint32_t, double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(CurveExtractorSquares)
