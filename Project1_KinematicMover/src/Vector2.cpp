#include "Vector2.h"

Vector2::Vector2()
    : x(0.0f), y(0.0f)
{
}

Vector2::Vector2(float xVal, float yVal)
    : x(xVal), y(yVal)
{
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator*(float scalar) const
{
    return Vector2(x * scalar, y * scalar);
}
