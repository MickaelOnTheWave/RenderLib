#ifndef ANGLE_H
#define ANGLE_H

class Angle
{
   public:
      enum class Unit { Degrees, Radians };

      Angle(const float _value, const Unit _unit = Unit::Radians);

      operator float() const;

   private:
      float ToRadians(const float angleInDegrees) const;

      float value;
};

Angle operator""_deg(long double value);
Angle operator""_deg(unsigned long long value);
Angle operator""_rad(long double value);
Angle operator""_rad(unsigned long long value);

#endif // ANGLE_H
