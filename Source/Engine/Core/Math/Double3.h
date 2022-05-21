// Copyright (c) 2012-2022 Wojciech Figat. All rights reserved.

#pragma once

#include "Math.h"
#include "Mathd.h"
#include "Engine/Core/Formatting.h"
#include "Engine/Core/Templates.h"

struct Double2;
struct Double4;
struct Vector2;
struct Vector3;
struct Vector4;
struct Int2;
struct Int3;
struct Int4;
struct Color;
struct Matrix;

/// <summary>
/// Represents a two dimensional mathematical vector with 64-bit precision (per-component).
/// </summary>
API_STRUCT() struct FLAXENGINE_API Double3
{
    DECLARE_SCRIPTING_TYPE_MINIMAL(Double3);
public:
    union
    {
        struct
        {
            /// <summary>
            /// The X component of the vector.
            /// </summary>
            API_FIELD() double X;

            /// <summary>
            /// The Y component of the vector.
            /// </summary>
            API_FIELD() double Y;

            /// <summary>
            /// The Z component of the vector.
            /// </summary>
            API_FIELD() double Z;
        };

        // Raw values
        double Raw[3];
    };

public:
    // Vector with all components equal 0.
    static const Double3 Zero;

    // Vector with all components equal 1.
    static const Double3 One;

    // Vector with all components equal half (0.5, 0.5, 0.5).
    static const Double3 Half;

    // Vector X=1, Y=0, Z=0.
    static const Double3 UnitX;

    // Vector X=0, Y=1, Z=0.
    static const Double3 UnitY;

    // Vector X=0, Y=0, Z=1.
    static const Double3 UnitZ;

    // A unit vector designating up (0, 1, 0).
    static const Double3 Up;

    // A unit vector designating down (0, -1, 0).
    static const Double3 Down;

    // A unit vector designating a (-1, 0, 0).
    static const Double3 Left;

    // A unit vector designating b (1, 0, 0).
    static const Double3 Right;

    // A unit vector designating forward in a a-handed coordinate system (0, 0, 1).
    static const Double3 Forward;

    // A unit vector designating backward in a a-handed coordinate system (0, 0, -1).
    static const Double3 Backward;

    // A minimum Double3.
    static const Double3 Minimum;

    // A maximum Double3.
    static const Double3 Maximum;

public:
    /// <summary>
    /// Empty constructor.
    /// </summary>
    Double3()
    {
    }

    // Init
    // @param xyz Value to assign to the all components
    Double3(double xyz)
        : X(xyz)
        , Y(xyz)
        , Z(xyz)
    {
    }

    // Init
    // @param x X component value
    // @param y Y component value
    // @param z Z component value
    Double3(double x, double y, double z)
        : X(x)
        , Y(y)
        , Z(z)
    {
    }

    /// <summary>
    /// Init
    /// </summary>
    /// <param name="xyz">X, Y and Z components in an array</param>
    explicit Double3(double xyz[3])
        : X(xyz[0])
        , Y(xyz[1])
        , Z(xyz[2])
    {
    }

    explicit Double3(const Vector2& xy, double z);
    explicit Double3(const Vector2& xy);
    Double3(const Vector3& xyz);
    explicit Double3(const Vector4& xyzw);
    explicit Double3(const Int2& xy, double z);
    explicit Double3(const Int3& xyz);
    explicit Double3(const Int4& xyzw);
    explicit Double3(const Double2& xy);
    explicit Double3(const Double2& xy, double z);
    explicit Double3(const Double4& xyzw);
    explicit Double3(const Color& color);

public:
    String ToString() const;

public:
    // Gets a value indicting whether this instance is normalized.
    bool IsNormalized() const
    {
        return Math::IsOne(X * X + Y * Y + Z * Z);
    }

    // Gets a value indicting whether this vector is zero.
    bool IsZero() const
    {
        return Math::IsZero(X) && Math::IsZero(Y) && Math::IsZero(Z);
    }

    // Gets a value indicting whether any vector component is zero.
    bool IsAnyZero() const
    {
        return Math::IsZero(X) || Math::IsZero(Y) || Math::IsZero(Z);
    }

    // Gets a value indicting whether this vector is one.
    bool IsOne() const
    {
        return Math::IsOne(X) && Math::IsOne(Y) && Math::IsOne(Z);
    }

    // Calculates the length of the vector.
    double Length() const
    {
        return Math::Sqrt(X * X + Y * Y + Z * Z);
    }

    // Calculates the squared length of the vector.
    double LengthSquared() const
    {
        return X * X + Y * Y + Z * Z;
    }

    // Calculates inverted length of the vector (1 / length).
    double InvLength() const
    {
        return 1.0 / Length();
    }

    /// <summary>
    /// Calculates a vector with values being absolute values of that vector.
    /// </summary>
    Double3 GetAbsolute() const
    {
        return Double3(Math::Abs(X), Math::Abs(Y), Math::Abs(Z));
    }

    /// <summary>
    /// Calculates a vector with values being opposite to values of that vector.
    /// </summary>
    Double3 GetNegative() const
    {
        return Double3(-X, -Y, -Z);
    }

    /// <summary>
    /// Calculates a normalized vector that has length equal to 1.
    /// </summary>
    Double3 GetNormalized() const
    {
        const double rcp = 1.0 / Length();
        return Double3(X * rcp, Y * rcp, Z * rcp);
    }

    /// <summary>
    /// Returns the average arithmetic of all the components.
    /// </summary>
    double AverageArithmetic() const
    {
        return (X + Y + Z) * 0.333333334;
    }

    /// <summary>
    /// Gets the sum of all vector components values.
    /// </summary>
    double SumValues() const
    {
        return X + Y + Z;
    }

    /// <summary>
    /// Returns the minimum value of all the components.
    /// </summary>
    double MinValue() const
    {
        return Math::Min(X, Y, Z);
    }

    /// <summary>
    /// Returns the maximum value of all the components.
    /// </summary>
    double MaxValue() const
    {
        return Math::Max(X, Y, Z);
    }

    /// <summary>
    /// Returns true if vector has one or more components is not a number (NaN).
    /// </summary>
    bool IsNaN() const
    {
        return isnan(X) || isnan(Y) || isnan(Z);
    }

    /// <summary>
    /// Returns true if vector has one or more components equal to +/- infinity.
    /// </summary>
    bool IsInfinity() const
    {
        return isinf(X) || isinf(Y) || isinf(Z);
    }

    /// <summary>
    /// Returns true if vector has one or more components equal to +/- infinity or NaN.
    /// </summary>
    bool IsNanOrInfinity() const
    {
        return IsInfinity() || IsNaN();
    }

public:
    /// <summary>
    /// Performs vector normalization (scales vector up to unit length).
    /// </summary>
    void Normalize()
    {
        const double length = Math::Sqrt(X * X + Y * Y + Z * Z);
        if (Math::Abs(length) >= ZeroTolerance)
        {
            const double inv = 1.0 / length;
            X *= inv;
            Y *= inv;
            Z *= inv;
        }
    }

    /// <summary>
    /// Performs fast vector normalization (scales vector up to unit length).
    /// </summary>
    void NormalizeFast()
    {
        const double inv = 1.0 / Math::Sqrt(X * X + Y * Y + Z * Z);
        X *= inv;
        Y *= inv;
        Z *= inv;
    }

    /// <summary>
    /// Sets all vector components to the absolute values.
    /// </summary>
    void Absolute()
    {
        X = Math::Abs(X);
        Y = Math::Abs(Y);
        Z = Math::Abs(Z);
    }

    /// <summary>
    /// Negates all components of that vector.
    /// </summary>
    void Negate()
    {
        X = -X;
        Y = -Y;
        Z = -Z;
    }

    /// <summary>
    /// When this vector contains Euler angles (degrees), ensure that angles are between +/-180.
    /// </summary>
    void UnwindEuler();

public:
    Double3 operator+(const Double3& b) const
    {
        return Double3(X + b.X, Y + b.Y, Z + b.Z);
    }

    Double3 operator-(const Double3& b) const
    {
        return Double3(X - b.X, Y - b.Y, Z - b.Z);
    }

    Double3 operator*(const Double3& b) const
    {
        return Double3(X * b.X, Y * b.Y, Z * b.Z);
    }

    Double3 operator/(const Double3& b) const
    {
        return Double3(X / b.X, Y / b.Y, Z / b.Z);
    }

    Double3 operator-() const
    {
        return Double3(-X, -Y, -Z);
    }

    Double3 operator^(const Double3& b) const
    {
        return Cross(*this, b);
    }

    double operator|(const Double3& b) const
    {
        return Dot(*this, b);
    }

    Double3& operator+=(const Double3& b)
    {
        X += b.X;
        Y += b.Y;
        Z += b.Z;
        return *this;
    }

    Double3& operator-=(const Double3& b)
    {
        X -= b.X;
        Y -= b.Y;
        Z -= b.Z;
        return *this;
    }

    Double3& operator*=(const Double3& b)
    {
        X *= b.X;
        Y *= b.Y;
        Z *= b.Z;
        return *this;
    }

    Double3& operator/=(const Double3& b)
    {
        X /= b.X;
        Y /= b.Y;
        Z /= b.Z;
        return *this;
    }

    Double3 operator+(double b) const
    {
        return Double3(X + b, Y + b, Z + b);
    }

    Double3 operator-(double b) const
    {
        return Double3(X - b, Y - b, Z - b);
    }

    Double3 operator*(double b) const
    {
        return Double3(X * b, Y * b, Z * b);
    }

    Double3 operator/(double b) const
    {
        return Double3(X / b, Y / b, Z / b);
    }

    Double3& operator+=(double b)
    {
        *this = Add(*this, b);
        return *this;
    }

    Double3& operator-=(double b)
    {
        *this = Subtract(*this, b);
        return *this;
    }

    Double3& operator*=(double b)
    {
        *this = Multiply(*this, b);
        return *this;
    }

    Double3& operator/=(double b)
    {
        *this = Divide(*this, b);
        return *this;
    }

    bool operator==(const Double3& b) const
    {
        return X == b.X && Y == b.Y && Z == b.Z;
    }

    bool operator!=(const Double3& b) const
    {
        return X != b.X || Y != b.Y || Z != b.Z;
    }

    bool operator>(const Double3& b) const
    {
        return X > b.X && Y > b.Y && Z > b.Z;
    }

    bool operator>=(const Double3& b) const
    {
        return X >= b.X && Y >= b.Y && Z >= b.Z;
    }

    bool operator<(const Double3& b) const
    {
        return X < b.X && Y < b.Y && Z < b.Z;
    }

    bool operator<=(const Double3& b) const
    {
        return X <= b.X && Y <= b.Y && Z <= b.Z;
    }

public:
    static bool NearEqual(const Double3& a, const Double3& b)
    {
        return Math::NearEqual(a.X, b.X) && Math::NearEqual(a.Y, b.Y) && Math::NearEqual(a.Z, b.Z);
    }

    static bool NearEqual(const Double3& a, const Double3& b, double epsilon)
    {
        return Math::NearEqual(a.X, b.X, epsilon) && Math::NearEqual(a.Y, b.Y, epsilon) && Math::NearEqual(a.Z, b.Z, epsilon);
    }

public:
    static void Add(const Double3& a, const Double3& b, Double3& result)
    {
        result.X = a.X + b.X;
        result.Y = a.Y + b.Y;
        result.Z = a.Z + b.Z;
    }

    static Double3 Add(const Double3& a, const Double3& b)
    {
        Double3 result;
        Add(a, b, result);
        return result;
    }

    static void Subtract(const Double3& a, const Double3& b, Double3& result)
    {
        result.X = a.X - b.X;
        result.Y = a.Y - b.Y;
        result.Z = a.Z - b.Z;
    }

    static Double3 Subtract(const Double3& a, const Double3& b)
    {
        Double3 result;
        Subtract(a, b, result);
        return result;
    }

    static Double3 Multiply(const Double3& a, const Double3& b)
    {
        return Double3(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
    }

    static void Multiply(const Double3& a, const Double3& b, Double3& result)
    {
        result = Double3(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
    }

    static Double3 Multiply(const Double3& a, double b)
    {
        return Double3(a.X * b, a.Y * b, a.Z * b);
    }

    static Double3 Divide(const Double3& a, const Double3& b)
    {
        return Double3(a.X / b.X, a.Y / b.Y, a.Z / b.Z);
    }

    static void Divide(const Double3& a, const Double3& b, Double3& result)
    {
        result = Double3(a.X / b.X, a.Y / b.Y, a.Z / b.Z);
    }

    static Double3 Divide(const Double3& a, double b)
    {
        return Double3(a.X / b, a.Y / b, a.Z / b);
    }

    static Double3 Floor(const Double3& v);
    static Double3 Frac(const Double3& v);

    static double ScalarProduct(const Double3& a, const Double3& b)
    {
        return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
    }

public:
    // Restricts a value to be within a specified range.
    // @param value The value to clamp.
    // @param min The minimum value.
    // @param max The maximum value.
    // @returns Clamped value
    static Double3 Clamp(const Double3& value, const Double3& min, const Double3& max);

    // Restricts a value to be within a specified range.
    // @param value The value to clamp.
    // @param min The minimum value.
    // @param max The maximum value.
    // @param result When the method completes, contains the clamped value.
    static void Clamp(const Double3& value, const Double3& min, const Double3& max, Double3& result);

    // Calculates the distance between two vectors.
    // @param value1 The first vector.
    // @param value2 The second vector.
    // @returns The distance between the two vectors.
    static double Distance(const Double3& value1, const Double3& value2);

    // Calculates the squared distance between two vectors.
    // @param value1 The first vector.
    // @param value2 The second vector.
    // @returns The squared distance between the two vectors.
    static double DistanceSquared(const Double3& value1, const Double3& value2);

    // Performs vector normalization (scales vector up to unit length).
    // @param inout Input vector to normalize.
    // @returns Output vector that is normalized (has unit length).
    static Double3 Normalize(const Double3& input);

    // Performs vector normalization (scales vector up to unit length). This is a faster version that does not performs check for length equal 0 (it assumes that input vector is not empty).
    // @param inout Input vector to normalize (cannot be zero).
    // @returns Output vector that is normalized (has unit length).
    static Double3 NormalizeFast(const Double3& input)
    {
        const double inv = 1.0 / input.Length();
        return Double3(input.X * inv, input.Y * inv, input.Z * inv);
    }

    // Performs vector normalization (scales vector up to unit length).
    // @param inout Input vector to normalize.
    // @param output Output vector that is normalized (has unit length).
    static void Normalize(const Double3& input, Double3& result);

    // dot product with another vector.
    static double Dot(const Double3& a, const Double3& b)
    {
        return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
    }

    // Calculates the cross product of two vectors.
    // @param a First source vector.
    // @param b Second source vector.
    // @param result When the method completes, contains the cross product of the two vectors.
    static void Cross(const Double3& a, const Double3& b, Double3& result)
    {
        result = Double3(a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X);
    }

    // Calculates the cross product of two vectors.
    // @param a First source vector.
    // @param b Second source vector.
    // @returns Cross product of the two vectors.
    static Double3 Cross(const Double3& a, const Double3& b)
    {
        return Double3(a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X);
    }

    // Performs a linear interpolation between two vectors.
    // @param start Start vector.
    // @param end End vector.
    // @param amount Value between 0 and 1 indicating the weight of end.
    // @param result When the method completes, contains the linear interpolation of the two vectors.
    static void Lerp(const Double3& start, const Double3& end, double amount, Double3& result)
    {
        result.X = Math::Lerp(start.X, end.X, amount);
        result.Y = Math::Lerp(start.Y, end.Y, amount);
        result.Z = Math::Lerp(start.Z, end.Z, amount);
    }

    /// <summary>
    /// Performs a linear interpolation between two vectors.
    /// </summary>
    static Double3 Lerp(const Double3& start, const Double3& end, double amount)
    {
        Double3 result;
        Lerp(start, end, amount, result);
        return result;
    }

    /// <summary>
    /// Performs a cubic interpolation between two vectors
    /// </summary>
    static void SmoothStep(const Double3& start, const Double3& end, double amount, Double3& result)
    {
        amount = Math::SmoothStep(amount);
        Lerp(start, end, amount, result);
    }

    // Performs a Hermite spline interpolation.
    // @param value1 First source position vector
    // @param tangent1 First source tangent vector
    // @param value2 Second source position vector
    // @param tangent2 Second source tangent vector
    // @param amount Weighting factor,
    // @param result When the method completes, contains the result of the Hermite spline interpolation,
    static void Hermite(const Double3& value1, const Double3& tangent1, const Double3& value2, const Double3& tangent2, double amount, Double3& result);

    // Returns the reflection of a vector off a surface that has the specified normal
    // @param vector The source vector
    // @param normal Normal of the surface
    // @param result When the method completes, contains the reflected vector
    static void Reflect(const Double3& vector, const Double3& normal, Double3& result);

    // Transforms a 3D vector by the given Quaternion rotation
    // @param vector The vector to rotate
    // @param rotation The Quaternion rotation to apply
    // @param result When the method completes, contains the transformed Vector4
    static void Transform(const Double3& vector, const Quaternion& rotation, Double3& result);

    // Transforms a 3D vector by the given Quaternion rotation
    // @param vector The vector to rotate
    // @param rotation The Quaternion rotation to apply
    // @returns The transformed Double3
    static Double3 Transform(const Double3& vector, const Quaternion& rotation);

    // Transforms a 3D vector by the given matrix
    // @param vector The source vector
    // @param transform The transformation matrix
    // @param result When the method completes, contains the transformed Double3
    static void Transform(const Double3& vector, const Matrix& transform, Double3& result);

    // Transforms a 3D vectors by the given matrix
    // @param vectors The source vectors
    // @param transform The transformation matrix
    // @param results When the method completes, contains the transformed Vector3s
    // @param vectorsCount Amount of vectors to transform
    static void Transform(const Double3* vectors, const Matrix& transform, Double3* results, int32 vectorsCount);

    // Transforms a 3D vector by the given matrix
    // @param vector The source vector
    // @param transform The transformation matrix
    // @returns Transformed Double3
    static Double3 Transform(const Double3& vector, const Matrix& transform);

    // Transforms a 3D vector by the given matrix
    // @param vector The source vector
    // @param transform The transformation matrix
    // @param result When the method completes, contains the transformed Double4
    static void Transform(const Double3& vector, const Matrix& transform, Double4& result);

    // Performs a coordinate transformation using the given matrix
    // @param coordinate The coordinate vector to transform
    // @param transform The transformation matrix
    // @param result When the method completes, contains the transformed coordinates
    static void TransformCoordinate(const Double3& coordinate, const Matrix& transform, Double3& result);

    // Performs a normal transformation using the given matrix
    // @param normal The normal vector to transform
    // @param transform The transformation matrix
    // @param result When the method completes, contains the transformed normal
    static void TransformNormal(const Double3& normal, const Matrix& transform, Double3& result);

    // Returns a vector containing the largest components of the specified vectors
    // @param a The first source vector
    // @param b The second source vector
    // @param result When the method completes, contains an new vector composed of the largest components of the source vectors
    static Double3 Max(const Double3& a, const Double3& b)
    {
        return Double3(a.X > b.X ? a.X : b.X, a.Y > b.Y ? a.Y : b.Y, a.Z > b.Z ? a.Z : b.Z);
    }

    // Returns a vector containing the smallest components of the specified vectors
    // @param a The first source vector
    // @param b The second source vector
    // @param result When the method completes, contains an new vector composed of the smallest components of the source vectors
    static Double3 Min(const Double3& a, const Double3& b)
    {
        return Double3(a.X < b.X ? a.X : b.X, a.Y < b.Y ? a.Y : b.Y, a.Z < b.Z ? a.Z : b.Z);
    }

    // Returns a vector containing the largest components of the specified vectors
    // @param a The first source vector
    // @param b The second source vector
    // @param result When the method completes, contains an new vector composed of the largest components of the source vectors
    static void Max(const Double3& a, const Double3& b, Double3& result)
    {
        result = Double3(a.X > b.X ? a.X : b.X, a.Y > b.Y ? a.Y : b.Y, a.Z > b.Z ? a.Z : b.Z);
    }

    // Returns a vector containing the smallest components of the specified vectors
    // @param a The first source vector
    // @param b The second source vector
    // @param result When the method completes, contains an new vector composed of the smallest components of the source vectors
    static void Min(const Double3& a, const Double3& b, Double3& result)
    {
        result = Double3(a.X < b.X ? a.X : b.X, a.Y < b.Y ? a.Y : b.Y, a.Z < b.Z ? a.Z : b.Z);
    }

    static Double3 Round(const Double3& v)
    {
        return Double3(Math::Round(v.X), Math::Round(v.Y), Math::Round(v.Z));
    }

    static Double3 Ceil(const Double3& v)
    {
        return Double3(Math::Ceil(v.X), Math::Ceil(v.Y), Math::Ceil(v.Z));
    }

    static Double3 Abs(const Double3& v)
    {
        return Double3(Math::Abs(v.X), Math::Abs(v.Y), Math::Abs(v.Z));
    }

    /// <summary>
    /// Calculates the area of the triangle.
    /// </summary>
    /// <param name="v0">The first triangle vertex.</param>
    /// <param name="v1">The second triangle vertex.</param>
    /// <param name="v2">The third triangle vertex.</param>
    /// <returns>The triangle area.</returns>
    static double TriangleArea(const Double3& v0, const Double3& v1, const Double3& v2);

    /// <summary>
    /// Calculates the angle (in radians) between from and to. This is always the smallest value.
    /// </summary>
    /// <param name="from">The first vector.</param>
    /// <param name="to">The second vector.</param>
    /// <returns>The angle (in radians).</returns>
    static double Angle(const Double3& from, const Double3& to);
};

inline Double3 operator+(double a, const Double3& b)
{
    return b + a;
}

inline Double3 operator-(double a, const Double3& b)
{
    return Double3(a) - b;
}

inline Double3 operator*(double a, const Double3& b)
{
    return b * a;
}

inline Double3 operator/(double a, const Double3& b)
{
    return Double3(a) / b;
}

namespace Math
{
    FORCE_INLINE static bool NearEqual(const Double3& a, const Double3& b)
    {
        return Double3::NearEqual(a, b);
    }
}

template<>
struct TIsPODType<Double3>
{
    enum { Value = true };
};

DEFINE_DEFAULT_FORMATTING(Double3, "X:{0} Y:{1} Z:{2}", v.X, v.Y, v.Z);
