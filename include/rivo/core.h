
#include <math.h>

#ifndef RIVO_CORE_H
#define RIVO_CORE_H
#include <rivo/precision.h>
namespace rivo{
    /**
     * Holds a vector in 3 d. Four data members are allocated
     * to ensure alignment in an array.
    */
   class Vector3
   {
    public:
        /** Holds the value along the x axis */
        real x;

        /** Holds the value along the y axis */
        real y;

        /** Holds the value along the z axis */
        real z;
    
    private:
        /** Padding to ensure 4-word alignment. */
        real pad;
    
    public:
        /** The defualt constructor creates a zero vector. */
        Vector3() : x(0), y(0), z(0) {}

        /** The explicit constructor creates a vector with the given
         * conponents.
        */
        Vector3(const real x, const real y, const real z)
            :x(x), y(y), z(z) {}

        /** Multiplies the given scalar to this vector. */
        void operator*=(const real value)
        {
            x *= value;
            y *= value;
            z *= value;
        }

        /** Returns the copy of this vector scaled by the given value. */
        Vector3 operator*(const real value) const
        {
            return Vector3(x*value, y*value, z*value);
        }

        /** Adds the given vector to this. */
        void operator+=(const Vector3& vec)
        {
            x += vec.x;
            y += vec.y;
            z += vec.z;
        }

        /** Returns a copy of this vector after adding the given vector. */
        Vector3 operator+(const Vector3& vec) const
        {
            return Vector3(x+vec.x, y+vec.y, z+vec.z);
        }

        /** Subtracts the given vector to this. */
        void operator-=(const Vector3& vec)
        {
            x -= vec.x;
            y -= vec.y;
            z -= vec.z;
        }

        /** Returns a copy of this vector after subtracting the given vector. */
        Vector3 operator-(const Vector3& vec) const
        {
            return Vector3(x-vec.x, y-vec.y, z-vec.z);
        }

        /** Adds scaled vector by the given amount to this vector. */
        void addScaledVector(const Vector3& vec, const real scale)
        {
            x += vec.x*scale;
            y += vec.y*scale;
            z += vec.z*scale;
        }

        
        /** Flips all the components of the vector. */
        void invert()
        {
            x = -x;
            y = -y;
            z = -z;
        }

        /** Gets the magnitude of this vector. */
        real magnitude() const
        {
            return real_sqrt(x*x+y*y+z*z);
        }

        /** Gets the squared magnitude of this vector. */
        real squareMagnitude() const
        {
            return x*x+y*y+z*z;
        }

        /** Turns a non-zero vector into a vector of unit length. */
        void normalize()
        {
            real l = magnitude();
            if(l>0)
            {
                (*this) *= ((real)1)/l;
            }
        }

        /** Calculates component wise product of this vector with the given vector and returns it. */
        Vector3 componentProduct(const Vector3& vec) const
        {
            return Vector3(x * vec.x, y * vec.y, z * vec.z);
        }

        /** Performs component wise product of this vector with the given vector and updates this vector. */
        void componentProductUpdate(const Vector3& vec)
        {
            x *= vec.x;
            y *= vec.y;
            z *= vec.z;
        }

        /** Calculates and returns dot product with the given vector. */
        real scalarProduct(const Vector3& vec) const
        {
            return x * vec.x + y * vec.y + z * vec.z;
        }

        /** Calculates and returns dot product with the given vector. */
        real operator*(const Vector3& vec) const
        {
            return x * vec.x + y * vec.y + z * vec.z;
        }

        /** Calculates and returns vector product of this vector with the given vector. */
        Vector3 vectorProduct(const Vector3& vec) const
        {
            return Vector3( 
                y * vec.z - z * vec.y,
                z * vec.x - x * vec.z,
                x * vec.y - y * vec.x);
        }

        /** Update this vector to be the vector product of this and given vector. */
        void operator%=(const Vector3& vec)
        {
            *this = vectorProduct(vec);
        }

        /** Calculates and returns vector product of this vector with the given vector. */
        Vector3 operator%(const Vector3& vec) const
        {
            return Vector3( 
                y * vec.z - z * vec.y,
                z * vec.x - x * vec.z,
                x * vec.y - y * vec.x);
        }

        /** Zero all the component of the vector. */
        void clear()
        {
            x = y = z = 0;
        }
   };
}

#endif