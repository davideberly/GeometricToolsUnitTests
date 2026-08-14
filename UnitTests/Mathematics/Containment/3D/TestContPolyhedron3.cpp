#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContPolyhedron3.h>
#include <random>
using namespace gtl;

namespace gtl
{
    class UnitTestContPolyhedron3
    {
    public:
        UnitTestContPolyhedron3();

        void TestTriangle();
        void TestConvex();
        void TestSimple();
    };
}

UnitTestContPolyhedron3::UnitTestContPolyhedron3()
{
    UTInformation("Mathematics/Containment/3D/ContPolyhedron3 [NEEDS UNIT TESTS]");

    TestTriangle();
    //TestConvex();
    //TestSimple();
}

void UnitTestContPolyhedron3::TestTriangle()
{
    std::default_random_engine dre{};
    std::uniform_real_distribution<double> urd(-1.0, 1.0);
    std::size_t numRays = 5;
    std::vector<Vector3<double>> directions(numRays);
    for (std::size_t i = 0; i < numRays; ++i)
    {
        for (std::size_t j = 0; j < 3; ++j)
        {
            directions[i][j] = urd(dre);
        }
        Normalize(directions[i]);
    }

    int32_t numPoints = 4;
    std::vector<Vector3<double>> points(numPoints);
    points[0] = { 0.0, 0.0, 0.0 };
    points[1] = { 1.0, 0.0, 0.0 };
    points[2] = { 0.0, 1.0, 0.0 };
    points[3] = { 0.0, 0.0, 1.0 };
    int32_t numFaces = 4;
    std::vector<ContPolyhedron3<double>::Face> faces(numFaces);
    faces[0].indices = { 0, 1, 3 };
    faces[1].indices = { 0, 3, 2 };
    faces[2].indices = { 0, 2, 1 };
    faces[3].indices = { 1, 2, 3 };
    faces[0].plane = Plane3<double>(UnitCross(points[1] - points[0], points[3] - points[0]), points[0]);
    faces[1].plane = Plane3<double>(UnitCross(points[3] - points[0], points[2] - points[0]), points[0]);
    faces[2].plane = Plane3<double>(UnitCross(points[2] - points[0], points[1] - points[0]), points[0]);
    faces[3].plane = Plane3<double>(UnitCross(points[2] - points[1], points[3] - points[1]), points[1]);
    faces[0].triangles = { 0, 1, 3 };
    faces[1].triangles = { 0, 3, 2 };
    faces[2].triangles = { 0, 2, 1 };
    faces[3].triangles = { 1, 2, 3 };

    std::uint32_t method = 0;
    bool contains = false;
    Vector3<double> p{};

    p = { 0.1, 0.2, 0.3 };
    contains = ContPolyhedron3<double>::InContainer(
        ContPolyhedron3<double>::TRIANGLE,
        method,
        p,
        points,
        faces,
        directions);
    UTAssert(contains == true, "Incorrect result.");

    p = { 1.1, 1.2, 1.3 };
    contains = ContPolyhedron3<double>::InContainer(
        ContPolyhedron3<double>::TRIANGLE,
        method,
        p,
        points,
        faces,
        directions);
    UTAssert(contains == false, "Incorrect result.");

    p = { -0.1, 1.2, 1.3 };
    contains = ContPolyhedron3<double>::InContainer(
        ContPolyhedron3<double>::TRIANGLE,
        method,
        p,
        points,
        faces,
        directions);
    UTAssert(contains == false, "Incorrect result.");
}

void UnitTestContPolyhedron3::TestConvex()
{
#if 0
    std::default_random_engine dre{};
    std::uniform_real_distribution<double> urd(-1.0, 1.0);
    int32_t numRays = 5;
    std::vector<Vector3<double>> directions(numRays);
    for (std::int32_t i = 0; i < numRays; ++i)
    {
        for (std::int32_t j = 0; j < 3; ++j)
        {
            directions[i][j] = urd(dre);
        }
        Normalize(directions[i]);
    }

    int32_t numPoints = 4;
    std::vector<Vector3<double>> points(numPoints);
    points[0] = { 0.0, 0.0, 0.0 };
    points[1] = { 1.0, 0.0, 0.0 };
    points[2] = { 0.0, 1.0, 0.0 };
    points[3] = { 0.0, 0.0, 1.0 };
    int32_t numFaces = 4;
    std::vector<PointInPolyhedron3<double>::Face> faces(numFaces);
    faces[0].indices = { 0, 1, 3 };
    faces[1].indices = { 0, 3, 2 };
    faces[2].indices = { 0, 2, 1 };
    faces[3].indices = { 1, 2, 3 };
    faces[0].plane = Plane3<double>(UnitCross(points[1] - points[0], points[3] - points[0]), points[0]);
    faces[1].plane = Plane3<double>(UnitCross(points[3] - points[0], points[2] - points[0]), points[0]);
    faces[2].plane = Plane3<double>(UnitCross(points[2] - points[0], points[1] - points[0]), points[0]);
    faces[3].plane = Plane3<double>(UnitCross(points[2] - points[1], points[3] - points[1]), points[1]);
    faces[0].triangles = { 0, 1, 3 };
    faces[1].triangles = { 0, 3, 2 };
    faces[2].triangles = { 0, 2, 1 };
    faces[3].triangles = { 1, 2, 3 };

    uint32_t method = 0;
    bool contains = false;

    method = 0;
    PointInPolyhedron3<double> tquery0(
        PointInPolyhedron3<double>::TRIANGLE,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = tquery0.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = tquery0.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = tquery0.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 0;
    PointInPolyhedron3<double> cquery0(
        PointInPolyhedron3<double>::CONVEX,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = cquery0.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = cquery0.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = cquery0.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 1;
    PointInPolyhedron3<double> cquery1(
        PointInPolyhedron3<double>::CONVEX,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = cquery1.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = cquery1.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = cquery1.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 2;
    PointInPolyhedron3<double> cquery2(
        PointInPolyhedron3<double>::CONVEX,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = cquery2.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = cquery2.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = cquery2.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 0;
    PointInPolyhedron3<double> squery0(
        PointInPolyhedron3<double>::SIMPLE,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = squery0.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = squery0.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = squery0.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 1;
    PointInPolyhedron3<double> squery1(
        PointInPolyhedron3<double>::SIMPLE,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = squery1.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = squery1.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = squery1.Contains({ -0.1, 1.2, 1.3 });  // false
#endif
}

void UnitTestContPolyhedron3::TestSimple()
{
#if 0
    std::default_random_engine dre{};
    std::uniform_real_distribution<double> urd(-1.0, 1.0);
    int32_t numRays = 5;
    std::vector<Vector3<double>> directions(numRays);
    for (std::int32_t i = 0; i < numRays; ++i)
    {
        for (std::int32_t j = 0; j < 3; ++j)
        {
            directions[i][j] = urd(dre);
        }
        Normalize(directions[i]);
    }

    int32_t numPoints = 4;
    std::vector<Vector3<double>> points(numPoints);
    points[0] = { 0.0, 0.0, 0.0 };
    points[1] = { 1.0, 0.0, 0.0 };
    points[2] = { 0.0, 1.0, 0.0 };
    points[3] = { 0.0, 0.0, 1.0 };
    int32_t numFaces = 4;
    std::vector<PointInPolyhedron3<double>::Face> faces(numFaces);
    faces[0].indices = { 0, 1, 3 };
    faces[1].indices = { 0, 3, 2 };
    faces[2].indices = { 0, 2, 1 };
    faces[3].indices = { 1, 2, 3 };
    faces[0].plane = Plane3<double>(UnitCross(points[1] - points[0], points[3] - points[0]), points[0]);
    faces[1].plane = Plane3<double>(UnitCross(points[3] - points[0], points[2] - points[0]), points[0]);
    faces[2].plane = Plane3<double>(UnitCross(points[2] - points[0], points[1] - points[0]), points[0]);
    faces[3].plane = Plane3<double>(UnitCross(points[2] - points[1], points[3] - points[1]), points[1]);
    faces[0].triangles = { 0, 1, 3 };
    faces[1].triangles = { 0, 3, 2 };
    faces[2].triangles = { 0, 2, 1 };
    faces[3].triangles = { 1, 2, 3 };

    uint32_t method = 0;
    bool contains = false;

    method = 0;
    PointInPolyhedron3<double> tquery0(
        PointInPolyhedron3<double>::TRIANGLE,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = tquery0.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = tquery0.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = tquery0.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 0;
    PointInPolyhedron3<double> cquery0(
        PointInPolyhedron3<double>::CONVEX,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = cquery0.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = cquery0.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = cquery0.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 1;
    PointInPolyhedron3<double> cquery1(
        PointInPolyhedron3<double>::CONVEX,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = cquery1.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = cquery1.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = cquery1.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 2;
    PointInPolyhedron3<double> cquery2(
        PointInPolyhedron3<double>::CONVEX,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = cquery2.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = cquery2.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = cquery2.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 0;
    PointInPolyhedron3<double> squery0(
        PointInPolyhedron3<double>::SIMPLE,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = squery0.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = squery0.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = squery0.Contains({ -0.1, 1.2, 1.3 });  // false

    method = 1;
    PointInPolyhedron3<double> squery1(
        PointInPolyhedron3<double>::SIMPLE,
        numPoints, points.data(),
        numFaces, faces.data(),
        numRays, directions.data(),
        method);
    contains = squery1.Contains({ 0.1, 0.2, 0.3 });  // true
    contains = squery1.Contains({ 1.1, 1.2, 1.3 });  // false
    contains = squery1.Contains({ -0.1, 1.2, 1.3 });  // false
#endif
}


#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContPolyhedron3.h>

namespace gtl
{
    template class ContPolyhedron3<float>;
    template class ContPolyhedron3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContPolyhedron3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContPolyhedron3)
