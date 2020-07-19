#pragma once

#include <ostream>

class Vector2D
{

public:

	float x_{ 0.0f }, y_{ 0.0f };

	Vector2D() = default;
	Vector2D(float x, float y);

	Vector2D Add(const Vector2D& vec);
	Vector2D Subtract(const Vector2D& vec);
	Vector2D Multiply(const Vector2D& vec);
	Vector2D Divide(const Vector2D& vec);

    Vector2D operator+(const Vector2D& vec);
	Vector2D operator-(const Vector2D& vec);
    Vector2D operator*(const Vector2D& vec);
    Vector2D operator/(const Vector2D& vec);

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);

	friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);

};

