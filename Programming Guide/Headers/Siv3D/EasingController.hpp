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
# include "Fwd.hpp"
# include "Easing.hpp"
# include "Stopwatch.hpp"

namespace s3d
{
	template <class Type>
	class EasingController
	{
	private:

		Type m_start, m_end;

		double m_timeMillisec;

		Stopwatch m_stopwatch;

		std::function<double(double)> m_easingFunction;

		bool m_swapped = false;

		double elapsed() const
		{
			return Min<double>(m_stopwatch.ms(), m_timeMillisec) / m_timeMillisec;
		}

	public:

		EasingController() = default;
        
        /// <param name="start">
        /// 初期値
        /// </param>
        /// <param name="end">
        /// 最終値
        /// </param>
        /// <param name="easingFunction">
        /// Easingに使う関数
        /// </param>
        /// <param name="timeMillisec">
        /// 何ミリ秒かけてEasingするか
        /// </param>
		EasingController(const Type& start, const Type& end, std::function<double(double)> easingFunction = Easing::Sine, double timeMillisec = 1000)
			: m_easingFunction(easingFunction)
			, m_timeMillisec(timeMillisec)
			, m_start(start)
			, m_end(end) {}
        
        /// <summary>
        /// EasingControllerを開始、再開します。
        /// </summary>
         /// <returns>
        /// なし
        /// </returns>
		void start()
		{
			if (m_stopwatch.isActive() && m_stopwatch.ms() >= m_timeMillisec)
			{
				m_stopwatch.reset();

				std::swap(m_start, m_end);

				m_swapped = true;
			}

			m_stopwatch.start();
		}
        
        /// <summary>
        /// 経過時間を0にリセットして、EasingControllerを開始します。
        /// </summary>
         /// <returns>
        /// なし
        /// </returns>
		void restart()
		{
			std::swap(m_start, m_end);

			m_swapped = true;

			m_stopwatch.restart();
		}
        
        /// <summary>
        /// EasingControllerを一時停止します。
        /// </summary>
         /// <returns>
        /// なし
        /// </returns>
		void pause()
		{
			m_stopwatch.pause();
		}

        /// <summary>
        /// EasingControllerが一時停止中である場合、再開します。
        /// </summary>
        /// <returns>
        /// なし
        /// </returns>
		void resume()
		{
			m_stopwatch.resume();
		}
        
        /// <summary>
        /// EasingControllerを停止し、経過時間を0にリセットします。
        /// </summary>
         /// <returns>
        /// なし
        /// </returns>
		void reset()
		{
			if (m_swapped)
			{
				std::swap(m_start, m_end);

				m_swapped = false;
			}

			m_stopwatch.reset();
		}

		Type easeIn() const
		{
			return EaseIn(m_start, m_end, m_easingFunction, elapsed());
		}

		Type easeOut() const
		{
			return EaseOut(m_start, m_end, m_easingFunction, elapsed());
		}

		Type easeInOut() const
		{
			return EaseInOut(m_start, m_end, m_easingFunction, elapsed());
		}

		bool isActive() const
		{
			return m_stopwatch.isActive() && !isEnd();
		}

		bool isEnd() const
		{
			return m_stopwatch.ms() >= m_timeMillisec;
		}

		Type base() const
		{
			return isEnd() ? m_end : m_start;
		}
	};
}
