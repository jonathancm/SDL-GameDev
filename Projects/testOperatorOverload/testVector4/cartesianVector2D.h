#ifndef __VECTOR2D__
#define __VECTOR2D__

#include <math.h>

class Vector2D
{
public:

	Vector2D(float x=0, float y=0):m_x(x), m_y(y) {}

	float getX() const {return m_x;}
	float getY() const {return m_y;}
	float length() const {return sqrt(m_x*m_x + m_y*m_y);}

	void setX(float x) {m_x = x;}
	void setY(float y) {m_y = y;}

	/* Addition */
	//Vector2D operator+(const Vector2D& v2) const
	//{
	//	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	//}

	Vector2D operator+(const Vector2D& v2)const;

//	Vector2D& operator+=(const Vector2D& right);

	friend Vector2D& operator+=(Vector2D& left, const Vector2D& right);

	/* normalize */
	void normalize();

private:

	float m_x;
	float m_y;

};

	/* Addition */
	// Vector2D operator+(const Vector2D& v2)
	// {
	// 	return Vector2D(this->m_x + v2.m_x, this->m_y + v2.m_y);
	// }





#endif /* defined(__VECTOR2D__) */