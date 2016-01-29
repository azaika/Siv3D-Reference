﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (C) 2008-2016 Ryo Suzuki
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once

# ifndef S3D_MATH_DEFINED
#	define S3D_MATH_DEFINED
# endif

namespace s3d
{
	namespace Math
	{
		/// <summary>
		/// π
		/// </summary>
		constexpr double Pi = 3.14159265358979323846;

		/// <summary>
		/// π (float)
		/// </summary>
		constexpr float PiF = 3.14159265358979323846f;

		/// <summary>
		/// 2π
		/// </summary>
		constexpr double TwoPi = Pi * 2.0;

		/// <summary>
		/// 2π (float)
		/// </summary>
		constexpr float TwoPiF = PiF * 2.0f;

		/// <summary>
		/// (1/2)π
		/// </summary>
		constexpr double HalfPi = Pi / 2.0;

		/// <summary>
		/// (1/2)π (float)
		/// </summary>
		constexpr float HalfPiF = PiF / 2.0f;

		/// <summary>
		/// (1/3)π
		/// </summary>
		constexpr double OneThirdPi = Pi / 3.0;

		/// <summary>
		/// (1/3)π (float)
		/// </summary>
		constexpr float OneThirdPiF = PiF / 3.0f;

		/// <summary>
		/// (1/4)π
		/// </summary>
		constexpr double QuarterPi = Pi / 4.0;

		/// <summary>
		/// (1/4)π (float)
		/// </summary>
		constexpr float QuarterPiF = PiF / 4.0f;

		constexpr double operator"" _pi(long double x)
		{
			return static_cast<double>(x) * Pi;
		}

		constexpr double operator"" _pi(unsigned long long x)
		{
			return x * Pi;
		}
        
        /// <summary>
		/// 度数法からラジアンに変換します。
		/// </summary>
		constexpr double operator"" _deg(long double deg)
		{
			return static_cast<double>(deg) * 3.141592 / 180;
		}
        
        /// <summary>
		/// 度数法からラジアンに変換します。
		/// </summary>
		constexpr double operator"" _deg(unsigned long long deg)
		{
			return static_cast<double>(deg) * 3.141592 / 180;
		}
	}
}
