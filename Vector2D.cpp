#include "Vector2D.h"
#include <stdexcept>

Vector2D::Vector2D(float x, float y) :x_(x), y_(y) {

}


Vector2D Vector2D::Add(const Vector2D& vec) {

	Vector2D res;
	res.y_ = y_ + vec.y_;
	res.x_ = x_ + vec.x_;

	return res;
}
Vector2D Vector2D::Subtract(const Vector2D& vec) {

	Vector2D res;
	res.y_ = y_ - vec.y_;
	res.x_ = x_ - vec.x_;

	return res;
}
Vector2D Vector2D::Multiply(const Vector2D& vec) {
	Vector2D res;
	res.y_ = y_ * vec.y_;
	res.x_ = x_ * vec.x_;

	return res;
}
Vector2D Vector2D::Divide(const Vector2D& vec) {

	if (!vec.x_ || !vec.y_) {
		throw std::runtime_error("invalid right hand operator for division\n");
	}

	Vector2D res;

	res.y_ = y_ / vec.y_;
	res.x_ = x_ / vec.x_;

	return res;
}

Vector2D Vector2D::operator+(const Vector2D& vec) {

	return this->Add(vec);
}

Vector2D Vector2D::operator-(const Vector2D& vec) {

	return this->Subtract(vec);

}

Vector2D Vector2D::operator*(const Vector2D& vec) {

	return this->Multiply(vec);

}

Vector2D Vector2D::operator/(const Vector2D& vec) {

	return this->Divide(vec);

}

Vector2D& Vector2D::operator+=(const Vector2D& vec) {

	*this = this->Add(vec);
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& vec) {

	*this = this->Subtract(vec);
	return *this;

}

Vector2D& Vector2D::operator*=(const Vector2D& vec) {

	*this = this->Multiply(vec);
	return *this;

}

Vector2D& Vector2D::operator/=(const Vector2D& vec) {

	*this = this->Divide(vec);
	return *this;

}

std::ostream & operator<<(std::ostream & os, const Vector2D & vec)
{
	os << "(" << vec.x_ <<
		"," << vec.y_ << ")";

	return os;

}
