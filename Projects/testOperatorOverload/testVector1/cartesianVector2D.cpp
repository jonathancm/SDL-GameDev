#include "cartesianVector2D.h"

Vector2D& operator+=(Vector2D& left, const Vector2D& right)
{
    left.m_x += right.m_x;
    left.m_y += right.m_y;
    return left;
}