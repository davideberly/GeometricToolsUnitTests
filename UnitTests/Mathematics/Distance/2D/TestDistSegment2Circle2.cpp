#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Distance/2D/DistSegment2Circle2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestDistSegment2Circle2
    {
    public:
        UnitTestDistSegment2Circle2();

    private:
        using SCQuery = DCPQuery<double, Segment2<double>, Circle2<double>>;
        using SCOutput = SCQuery::Output;

        // The expected values are passed to this function.
        void Validate(SCOutput const& output, SCOutput const& expected);

        void Test();
    };
}

UnitTestDistSegment2Circle2::UnitTestDistSegment2Circle2()
{
    UTInformation("Mathematics/Distance/2D/DistSegment2Circle2");

    Test();
}

void UnitTestDistSegment2Circle2::Validate(SCOutput const& output, SCOutput const& expected)
{
    double const maxError = 1e-14;
    double error{};

    UTAssert(output.numClosestPairs == expected.numClosestPairs, "Invalid number of pairs.");
    error = std::fabs(output.sqrDistance - expected.sqrDistance);
    UTAssert(error <= maxError, "Invalid sqrDistance.");
    for (std::size_t i = 0; i < output.numClosestPairs; ++i)
    {
        error = std::fabs(output.parameter[i] - expected.parameter[i]);
        UTAssert(error <= maxError, "Invalid parameter[" + std::to_string(i) + "].");
        error = Length(output.closest[i][0] - expected.closest[i][0]);
        UTAssert(error <= maxError, "Invalid closest[" + std::to_string(i) + "][0].");
        error = Length(output.closest[i][1] - expected.closest[i][1]);
        UTAssert(error <= maxError, "Invalid closest[" + std::to_string(i) + "][1].");
    }
}

void UnitTestDistSegment2Circle2::Test()
{
    Segment2<double> segment{};
    Circle2<double> circle{};
    SCQuery query{};
    SCQuery::Output output{}, expected{};
    Vector2<double> origin{}, direction{};

    // Line does not intersect with circle or is tangent to the circle.

    // Segment p[0] and p[1] to left of line point closest to circle.
    segment.p[0] = { -2.0, 2.0 };
    segment.p[1] = { -0.5, 2.0 };
    output = query(segment, circle);
    expected.distance = Length(segment.p[1]) - 1.0; // 1.0615528128088303;
    expected.sqrDistance = 1.1268943743823394;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 1.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { -0.5, 2.0 };
    expected.closest[0][1] = { -0.24253562503633297, 0.97014250014533188 }; // = { -0.5, 2 } / distance
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // Segment p[0] to left of line point closest to circle and p[1] to right
    // line point closest to circle.
    segment.p[0] = { -2.0, 2.0 };
    segment.p[1] = { 1.0, 2.0 };
    output = query(segment, circle);
    expected.distance = 1.0;
    expected.sqrDistance = 1.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.66666666666666663;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 0.0, 2.0 };
    expected.closest[0][1] = { 0.0, 1.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // Segment p[0] and p[1] to right of line point closest to circle.
    segment.p[0] = { 0.5, 2.0 };
    segment.p[1] = { 1.0, 2.0 };
    output = query(segment, circle);
    expected.distance = Length(segment.p[0]) - 1.0; // 1.0615528128088303;
    expected.sqrDistance = 1.1268943743823394;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 0.5, 2.0 };
    expected.closest[0][1] = { 0.24253562503633297, 0.97014250014533188 }; // = { 0.5, 2 } / distance
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);


    // Line intersects circle in 2 points. Line interval is [t0,t1].
    // Segment interval is [s0,s1] = [0,1].

    // s0 < s1 < t0 < t1
    segment.p[0] = { -3.0, 0.0 };
    segment.p[1] = { -2.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 1.0;
    expected.sqrDistance = 1.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 1.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { -2.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // s0 < s1 = t0 < t1
    segment.p[0] = { -3.0, 0.0 };
    segment.p[1] = { -1.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 1.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // s0 < t0 < s1 < t1
    segment.p[0] = { -3.0, 0.0 };
    segment.p[1] = { 0.5, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 4.0 / 7.0; // 0.57142857142857140;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // s0 < t0 < t1 < s1
    segment.p[0] = { -2.0, 0.0 };
    segment.p[1] = { 2.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 2;
    expected.parameter[0] = 0.25;
    expected.parameter[1] = 0.75;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 1.0, 0.0 };
    expected.closest[1][1] = { 1.0, 0.0 };
    Validate(output, expected);

    // s0 < t0 < t1 = s1
    segment.p[0] = { -2.0, 0.0 };
    segment.p[1] = { 1.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 2;
    expected.parameter[0] = 1.0 / 3.0; // 0.33333333333333331;
    expected.parameter[1] = 1.0;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 1.0, 0.0 };
    expected.closest[1][1] = { 1.0, 0.0 };
    Validate(output, expected);

    // t0 < t1 < s0 < s1
    segment.p[0] = { 2.0, 0.0 };
    segment.p[1] = { 3.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 1.0;
    expected.sqrDistance = 1.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 2.0, 0.0 };
    expected.closest[0][1] = { 1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // t0 < t1 = s0 < s1
    segment.p[0] = { 1.0, 0.0 };
    segment.p[1] = { 3.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 1.0, 0.0 };
    expected.closest[0][1] = { 1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // t0 < s0 < t1 < s1
    segment.p[0] = { -0.5, 0.0 };
    segment.p[1] = { 3.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 3.0 / 7.0; // 0.42857142857142855;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 1.0, 0.0 };
    expected.closest[0][1] = { 1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // s0 < t0 < t1 < s1
    segment.p[0] = { -2.0, 0.0 };
    segment.p[1] = { 2.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 2;
    expected.parameter[0] = 0.25;
    expected.parameter[1] = 0.75;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 1.0, 0.0 };
    expected.closest[1][1] = { 1.0, 0.0 };
    Validate(output, expected);

    // s0 = t0 < t1 < s1
    segment.p[0] = { -1.0, 0.0 };
    segment.p[1] = { 2.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 2;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 2.0 / 3.0; // 0.66666666666666663;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 1.0, 0.0 };
    expected.closest[1][1] = { 1.0, 0.0 };
    Validate(output, expected);

    // t0 < s0 < s1 < t1
    segment.p[0] = { -0.25, 0.0 };
    segment.p[1] = { 0.75, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.25;
    expected.sqrDistance = 0.0625;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 1.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 0.75, 0.0 };
    expected.closest[0][1] = { 1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // Test for the distance comparison in Update{ segment,circle,output }.
    segment.p[0] = { -0.75, 0.0 };
    segment.p[1] = { 0.25, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.25;
    expected.sqrDistance = 0.0625;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { -0.75, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // Test for the distance { equality } comparison in Update{ segment,circle,output }.
    segment.p[0] = { -0.75, 0.0 };
    segment.p[1] = { 0.75, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.25;
    expected.sqrDistance = 0.0625;
    expected.numClosestPairs = 2;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 1.0;
    expected.closest[0][0] = { -0.75, 0.0 };
    expected.closest[0][1] = { 0.75, 0.0 };
    expected.closest[1][0] = { -1.0, 0.0 };
    expected.closest[1][1] = { 1.0, 0.0 };
    Validate(output, expected);

    // t0 < s0 < s1 = t1
    segment.p[0] = { -0.75, 0.0 };
    segment.p[1] = { 1.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 1.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 1.0, 0.0 };
    expected.closest[0][1] = { 1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // t0 = s0 < s1 < t1
    segment.p[0] = { -1.0, 0.0 };
    segment.p[1] = { 0.75, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // t0 = s0 < s1 = t1
    segment.p[0] = { -1.0, 0.0 };
    segment.p[1] = { 1.0, 0.0 };
    output = query(segment, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 2;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 1.0;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 1.0, 0.0 };
    expected.closest[1][1] = { 1.0, 0.0 };
    Validate(output, expected);
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Distance/2D/DistSegment2Circle2.h>

namespace gtl
{
    template class DCPQuery<float, Segment<float, 2>, Circle2<float>>;
    template class DCPQuery<double, Segment<double, 2>, Circle2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class DCPQuery<Rational, Segment<Rational, 2>, Circle2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(DistSegment2Circle2)
