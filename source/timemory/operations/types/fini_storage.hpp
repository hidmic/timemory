// MIT License
//
// Copyright (c) 2020, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to receipt of any
// required approvals from the U.S. Dept. of Energy).  All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "timemory/operations/declaration.hpp"
#include "timemory/operations/types.hpp"

namespace tim
{
namespace operation
{
//
template <typename Tp>
inline fini_storage<Tp>::fini_storage()
{
    sfinae(0);
}
//
template <typename Tp>
template <typename Up, enable_if_t<trait::is_available<Up>::value, char>>
void
fini_storage<Tp>::sfinae(int) const
{
    // reserved for a "timemory_at_thread_exit" callback
}
//
template <typename Tp>
template <typename Up, enable_if_t<!trait::is_available<Up>::value, char>>
void
fini_storage<Tp>::sfinae(long) const
{}
//
}  // namespace operation
}  // namespace tim
