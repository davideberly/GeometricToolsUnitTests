#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Sphere3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestIntrSphere3Sphere3
    {
    public:
        UnitTestIntrSphere3Sphere3();

    private:
        using TestQuery = TIQuery<double, Sphere3<double>, Sphere3<double>>;
        using TestOutput = TestQuery::Output;
        using FindQuery = FIQuery<double, Sphere3<double>, Sphere3<double>>;
        using FindOutput = FindQuery::Output;

        // The spheres are solid.
        void TestIntersection();
        void FindIntersection();
    };
}

UnitTestIntrSphere3Sphere3::UnitTestIntrSphere3Sphere3()
{
    UTInformation("Mathematics/Intersection/3D/IntrSphere3Sphere3");

    TestIntersection();
    FindIntersection();
}

void UnitTestIntrSphere3Sphere3::TestIntersection()
{
    TestQuery query{};
    TestOutput output{};

    Sphere3<double> sphere0{}, sphere1{};
    sphere0.center = { 0.0, 0.0, 0.0 };
    sphere0.radius = 1.0;

    // sphere0 and sphere1 overlap in a region of positive area, no
    // containment of one sphere by another.
    sphere1.center = { 2.0, 0.0, 0.0 };
    sphere1.radius = 1.125;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid output.");

    // sphere0 and sphere1 are separated/disjoint.
    sphere1.center = { 2.0, 0.0, 0.0 };
    sphere1.radius = 0.125;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == false, "Invalid output.");

    // sphere0 and sphere1 are tangential and disjoint
    sphere1.center = { 2.0, 0.0, 0.0 };
    sphere1.radius = 1.0;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid output.");

    // sphere0 and sphere1 are tangential and one contains the other
    sphere1.center = { 0.75, 0.0, 0.0 };
    sphere1.radius = 0.25;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid output.");

    // sphere0 strictly contains sphere1
    sphere1.center = { 0.0, 0.0, 0.0 };
    sphere1.radius = 0.5;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid output.");

    // sphere0 equals sphere1
    sphere1 = sphere0;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid output.");
}

void UnitTestIntrSphere3Sphere3::FindIntersection()
{
    FindQuery query{};
    FindOutput output{};

    Sphere3<double> sphere0{}, sphere1{};
    sphere0.center = { 0.0, 0.0, 0.0 };
    sphere0.radius = 1.0;

    // sphere0 and sphere1 are separated/disjoint.
    sphere1.center = { 2.0, 0.0, 0.0 };
    sphere1.radius = 0.125;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == false, "Invalid intersect.");
    UTAssert(output.type == 0, "Invalid type.");
    UTAssert(output.point == Vector3<double>::Zero(), "Invalid point.");
    UTAssert(output.circle.center == Vector3<double>::Zero(), "Invalid circle center.");
    UTAssert(output.circle.normal == Vector3<double>::Zero(), "Invalid circle normal.");
    UTAssert(output.circle.radius == 0.0, "Invalid circle radius.");

    // sphere0 and sphere1 are tangential and disjoint
    sphere1.center = { 2.0, 0.0, 0.0 };
    sphere1.radius = 1.0;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid intersect.");
    UTAssert(output.type == 1, "Invalid type.");
    UTAssert(output.point == (Vector3<double>{ 1.0, 0.0, 0.0 }), "Invalid point.");
    UTAssert(output.circle.center == Vector3<double>::Zero(), "Invalid circle center.");
    UTAssert(output.circle.normal == (Vector3<double>{ 0.0, 0.0, 0.0 }), "Invalid circle normal.");
    UTAssert(output.circle.radius == 0.0, "Invalid circle radius.");

    // sphere0 and sphere1 are tangential and one contains the other, compute
    // a point of contact (sphere0.center + r0 * C1mC0)
    sphere1.center = { 0.75, 0.0, 0.0 };
    sphere1.radius = 0.25;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid intersect.");
    UTAssert(output.type == 6, "Invalid type.");
    UTAssert(output.point == (Vector3<double>{ 1.0, 0.0, 0.0 }), "Invalid point.");
    UTAssert(output.circle.center == Vector3<double>::Zero(), "Invalid circle center.");
    UTAssert(output.circle.normal == (Vector3<double>{ 0.0, 0.0, 0.0 }), "Invalid circle normal.");
    UTAssert(output.circle.radius == 0.0, "Invalid circle radius.");

    // sphere0 and sphere1 are tangential and one contains the other, compute
    // a point of contact (sphere1.center - r1 * C1mC0)
    sphere0.center = { 0.75, 0.0, 0.0 };
    sphere0.radius = 0.25;
    sphere1.center = { 0.0, 0.0, 0.0 };
    sphere1.radius = 1.0;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid intersect.");
    UTAssert(output.type == 4, "Invalid type.");
    UTAssert(output.point == (Vector3<double>{ 1.0, 0.0, 0.0 }), "Invalid point.");
    UTAssert(output.circle.center == Vector3<double>::Zero(), "Invalid circle center.");
    UTAssert(output.circle.normal == (Vector3<double>{ 0.0, 0.0, 0.0 }), "Invalid circle normal.");
    UTAssert(output.circle.radius == 0.0, "Invalid circle radius.");

    // sphere0 and sphere1 overlap in a region of positive area, no
    // containment of one sphere by another.
    sphere0.center = { 0.0, 0.0, 0.0 };
    sphere0.radius = 1.0;
    sphere1.center = { 2.0, 0.0, 0.0 };
    sphere1.radius = 1.125;
    output = query(sphere0, sphere1);
    UTAssert(output.intersect == true, "Invalid intersect.");
    UTAssert(output.type == 2, "Invalid type.");
    UTAssert(output.point == (Vector3<double>{ 0.0, 0.0, 0.0 }), "Invalid point.");
    UTAssert(output.circle.center == (Vector3<double>{ 0.93359375, 0.0, 0.0 }), "Invalid circle center.");
    UTAssert(output.circle.normal == (Vector3<double>{ 1.0, 0.0, 0.0 }), "Invalid circle normal.");
    UTAssert(std::fabs(output.circle.radius - 0.35833323870517159) <= 1e-15, "Invalid circle radius.");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Intersection/3D/IntrSphere3Sphere3.h>

namespace gtl
{
    template class TIQuery<float, Sphere3<float>, Sphere3<float>>;
    template class FIQuery<float, Sphere3<float>, Sphere3<float>>;

    template class TIQuery<double, Sphere3<double>, Sphere3<double>>;
    template class FIQuery<double, Sphere3<double>, Sphere3<double>>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class TIQuery<Rational, Sphere3<Rational>, Sphere3<Rational>>;
    template class FIQuery<Rational, Sphere3<Rational>, Sphere3<Rational>>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(IntrSphere3Sphere3)
