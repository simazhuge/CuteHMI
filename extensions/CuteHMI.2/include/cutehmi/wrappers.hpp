#ifndef H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_WRAPPERS_HPP
#define H_EXTENSIONS_CUTEHMI_2_INCLUDE_CUTEHMI_WRAPPERS_HPP

#include <algorithm>
#include <iterator>

namespace cutehmi {

template <class INPUT_IT, class SIZE, class OUTPUT_IT>
OUTPUT_IT copy_n(INPUT_IT first, SIZE count, OUTPUT_IT result);

template <class INPUT_IT1, class INPUT_IT2>
bool equal(INPUT_IT1 first1, INPUT_IT1 last1, INPUT_IT2 first2);

template <class INPUT_IT, class SIZE, class OUTPUT_IT>
OUTPUT_IT copy_n(INPUT_IT first, SIZE count, OUTPUT_IT result)
{
	// Avoid MSVC C4996 warning, when using std::copy_n with raw pointers.
#ifdef _MSC_VER
	return ::std::copy_n(first, count, ::stdext::checked_array_iterator<OUTPUT_IT>(result, count)).base();
#else
	return ::std::copy_n(first, count, result);
#endif
}

template <class INPUT_IT1, class INPUT_IT2>
bool equal(INPUT_IT1 first1, INPUT_IT1 last1, INPUT_IT2 first2)
{
	// Avoid MSVC C4996 warning, when using std::copy_n with raw pointers.
#ifdef _MSC_VER
	return ::std::equal(first1, last1, ::stdext::make_unchecked_array_iterator(first2));
#else
	return ::std::equal(first1, last1, first2);
#endif
}

}

#endif

//(c)C: Copyright © 2019-2020, Michał Policht <michal@policht.pl>. All rights reserved.
//(c)C: SPDX-License-Identifier: LGPL-3.0-or-later OR MIT
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
//(c)C: Additionally, this file is licensed under terms of MIT license as expressed below.
//(c)C: Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//(c)C: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//(c)C: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
