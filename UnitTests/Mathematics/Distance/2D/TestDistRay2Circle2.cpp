#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Distance/2D/DistRay2Circle2.h>
using namespace gtl;

namespace gtl
{
    class UnitTestDistRay2Circle2
    {
    public:
        UnitTestDistRay2Circle2();

    private:
        using RCQuery = DCPQuery<double, Ray2<double>, Circle2<double>>;
        using RCOutput = RCQuery::Output;

        // The expected values are passed to this function.
        void Validate(RCOutput const& output, RCOutput const& expected);

        void Test();
    };
}

UnitTestDistRay2Circle2::UnitTestDistRay2Circle2()
{
    UTInformation("Mathematics/Distance/2D/DistRay2Circle2");

    Test();
}

void UnitTestDistRay2Circle2::Validate(RCOutput const& output, RCOutput const& expected)
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

void UnitTestDistRay2Circle2::Test()
{
    Ray2<double> ray{};
    Circle2<double> circle{};
    RCQuery query{};
    RCQuery::Output output{}, expected{};

    circle.center = { 0.0, 0.0 };
    circle.radius = 1.0;

    // Line does not intersect with circle or is tangent to the circle.

    // Ray outside circle with origin to left of line point closest to circle.
    ray.origin = { -1.0, 2.0 };
    ray.direction = { 1.0, 0.0 };
    output = query(ray, circle);
    expected.distance = 1.0;
    expected.sqrDistance = 1.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 1.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 0.0, 2.0 };
    expected.closest[0][1] = { 0.0, 1.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // Ray outside circle with origin to right of line point closest to circle.
    ray.origin = { +1.0, 2.0 };
    ray.direction = { 1.0, 0.0 };
    output = query(ray, circle);
    expected.distance = std::sqrt(5.0) - 1; // 1.2360679774997898;
    expected.sqrDistance = 6.0 - 2 * std::sqrt(5.0); // 1.5278640450004208;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 1.0, 2.0 };
    expected.closest[0][1] = { 0.44721359549995793, 0.89442719099991586 }; // = { 1 / sqrt{ 5 }, 2 / sqrt{ 5 } }
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // Line intersects circle in 2 points.

    // Ray intersects circle in 2 points.
    ray.origin = { -2.0, 0.0 };
    ray.direction = { 1.0, 0.0 };
    output = query(ray, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 2;
    expected.parameter[0] = 1.0;
    expected.parameter[1] = 3.0;
    expected.closest[0][0] = { -1.0, 0.0 };
    expected.closest[0][1] = { -1.0, 0.0 };
    expected.closest[1][0] = { 1.0, 0.0 };
    expected.closest[1][1] = { 1.0, 0.0 };
    Validate(output, expected);

    // Ray origin inside circle, ray intersects circle in 1 point.
    ray.origin = { 0.5, 0.0 };
    ray.direction = { 1.0, 0.0 };
    output = query(ray, circle);
    expected.distance = 0.0;
    expected.sqrDistance = 0.0;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.5;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 1.0, 0.0 };
    expected.closest[0][1] = { 1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);

    // Ray origin inside circle, ray intersects circle in 1 point.
    ray.origin = { 1.5, 0.0 };
    ray.direction = { 1.0, 0.0 };
    output = query(ray, circle);
    expected.distance = 0.5;
    expected.sqrDistance = 0.25;
    expected.numClosestPairs = 1;
    expected.parameter[0] = 0.0;
    expected.parameter[1] = 0.0;
    expected.closest[0][0] = { 1.5, 0.0 };
    expected.closest[0][1] = { 1.0, 0.0 };
    expected.closest[1][0] = { 0.0, 0.0 };
    expected.closest[1][1] = { 0.0, 0.0 };
    Validate(output, expected);
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Distance/2D/DistRay2Circle2.h>

namespace gtl
{
    template class DCPQuery<float, Ray<float, 2>, Circle2<float>>;
    template class DCPQuery<double, Ray<double, 2>, Circle2<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class DCPQuery<Rational, Ray<Rational, 2>, Circle2<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(DistRay2Circle2)
