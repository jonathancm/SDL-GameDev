#include "cartesianVector2D.h"

Vector2D Vector2D::operator+(const Vector2D& v2)const
{
    return Vector2D(this->getX() + v2.getX(), this->getY() + v2.getY());
}

// Vector2D& Vector2D::operator+=(const Vector2D& right)
// {
//     this->m_x += right.m_x;
//     this->m_y += right.m_y;
//     return *this;
// }

Vector2D& operator+=(Vector2D& left, const Vector2D& right)
{
    left.m_x += right.m_x;
    left.m_y += right.m_y;
    return left;
}