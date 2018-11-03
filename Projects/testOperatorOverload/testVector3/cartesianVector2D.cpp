#include "cartesianVector2D.h"

Vector2D& Vector2D::operator+=(const Vector2D& right)
{
    this->m_x += right.m_x;
    this->m_y += right.m_y;
    return *this;
}