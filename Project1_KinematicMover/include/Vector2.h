#pragma once

struct Vector2
{
    float x;
    float y;

    Vector2();
    Vector2(float xVal, float yVal);

    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator*(float scalar) const;
};
