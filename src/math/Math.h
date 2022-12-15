#pragma once

//Math header with Vector2 and Vector3, they are also defined in here

template<typename T>
class Vector2
{
public:
	inline Vector2(T _x, T _y)
		: x(_x), y(_y)
	{

	}
	inline Vector2()
		: x(0), y(0)
	{

	}

	T x;
	T y;

	inline Vector2& operator+=(Vector2& v)
	{
		x += v.x;
		y += v.y;

		return *this;
	}
	inline Vector2& operator-=(Vector2& v)
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}
	inline Vector2& operator*=(Vector2& v)
	{
		x *= v.x;
		y *= v.y;

		return *this;
	}
	inline Vector2& operator/= (Vector2 & v)
	{
		x /= v.x;
		y /= v.y;

		return *this;
	}

	inline bool operator==(Vector2& v)
	{
		if (x == v.x && y == v.y)
		{
			return true;
		}

		else
			return false;
	}
};


template<typename T>
class Vector3
{
public:
	inline Vector3(T _x, T _y, T _z)
		: x(_x), y(_y), z(_z)
	{

	}
	inline Vector3()
		: x(0), y(0), z(0)
	{

	}

	T x;
	T y;
	T z;

	inline Vector3& operator+=(Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}
	inline Vector3& operator-=(Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}
	inline Vector3& operator*=(Vector3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;

		return *this;
	}
	inline Vector3& operator/=(Vector3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;

		return *this;
	}

	inline bool operator==(Vector3& v)
	{
		if (x == v.x && y == v.y && z == v.z)
		{
			return true;
		}

		else
			return false;
	}
};

