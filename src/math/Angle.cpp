#include "Angle.h"

#include <math.h>

Angle::Angle(const float _value, const Unit _unit)
{
   value = (_unit == Unit::Degrees) ? ToRadians(_value) : _value;
}

Angle::operator float() const
{
   return value;
}

float Angle::ToRadians(const float angleInDegrees) const
{
   return angleInDegrees * M_PI / 180.f;
}

Angle operator""_deg(long double value)
{
   return Angle(static_cast<float>(value), Angle::Unit::Degrees);
}

Angle operator""_deg(unsigned long long value)
{
   return Angle(static_cast<float>(value), Angle::Unit::Degrees);
}

Angle operator""_rad(long double value)
{
   return Angle(static_cast<float>(value), Angle::Unit::Radians);
}

Angle operator""_rad(unsigned long long value)
{
   return Angle(static_cast<float>(value), Angle::Unit::Radians);
}
