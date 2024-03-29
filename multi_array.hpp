/**
 * multi_array.hpp
 * Etienne Boespflug - 2018
 *
 * This file contains preprocessor undef directives
 * corresponding to the ezl_char.hpp header.
 *
 * This software has no license, feel free to use,
 * modify and distribute.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY
 * OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MULTI_ARRAY_HPP
#define MULTI_ARRAY_HPP

#include <array>
#include <cassert>
#include <iostream>

namespace eb{

template<std::size_t, typename T> using sized_t = T;

template<size_t... Dims, typename... Indexes>
size_t linearise(Indexes... indexes_args)
{
    constexpr std::size_t dimensions[] = {Dims...};
    std::size_t indexes[] = {static_cast<std::size_t>(indexes_args)...};

    size_t index = 0;
    size_t product = 1;

    for(std::size_t i{ sizeof...(Dims) }; i != 0; --i) {
        assert(indexes[i - 1] < dimensions[i - 1]);
        index += indexes[i - 1] * product;
        product *= dimensions[i - 1];
    }

    assert(index < (Dims * ...));
    return index;
}

template<typename T, std::size_t... Dims>
class multi_array : std::array<T, (Dims * ...)>
{
    using base_type = std::array<T, (Dims * ...)>;
    using self_type = multi_array<T, Dims...>;

public:

    // Member types
    using typename base_type::value_type;
    using typename base_type::size_type;
    using typename base_type::difference_type;

    using typename base_type::reference;
    using typename base_type::const_reference;
    using typename base_type::pointer;
    using typename base_type::const_pointer;

    using typename base_type::iterator;
    using typename base_type::const_iterator;
    using typename base_type::reverse_iterator;
    using typename base_type::const_reverse_iterator;

    // Element access
    using base_type::at;
    using base_type::operator[];
    using base_type::front;
    using base_type::back;
    using base_type::data;

    // Iterators
    using base_type::begin;
    using base_type::cbegin;
    using base_type::rbegin;
    using base_type::crbegin;

    using base_type::end;
    using base_type::cend;
    using base_type::rend;
    using base_type::crend;

    // Capacity
    using base_type::empty;
    using base_type::size;
    using base_type::max_size;

    // Operations
    using base_type::fill;
    using base_type::swap;

    explicit multi_array(const_reference value = value_type{})
    {
        base_type::fill(value);
    }

    multi_array(const self_type&) = default;
    self_type& operator= (const self_type&) = default;
    multi_array(self_type&&) = default;
    self_type& operator= (self_type&&) = default;
    ~multi_array() noexcept = default;

    template<typename... Indexes>
    reference operator() (Indexes... indexes)
    {
        return base_type::operator[] (linearise<Dims...>(indexes...));
    }

    template<typename... Indexes>
    const_reference operator() (Indexes... indexes) const
    {
        return base_type::operator[] (linearise<Dims...>(indexes...));
    }

private:

    template<typename U, std::size_t... D>
    friend constexpr bool operator== (const multi_array<U, D...>&, const multi_array<U, D...>&);

    template<typename U, std::size_t... D>
    friend constexpr bool operator< (const multi_array<U, D...>&, const multi_array<U, D...>&);
};

template<typename U, std::size_t... D>
constexpr bool operator== (const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    using type = typename std::remove_cv_t<typename std::remove_reference_t<decltype(lhs)>>;
    using base_type = typename type::base_type;

    // overhead ?
    return static_cast<base_type>(lhs) ==
        static_cast<base_type>(rhs);
}

template<typename U, std::size_t... D>
constexpr bool operator< (const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    using type = typename std::remove_cv_t<typename std::remove_reference_t<decltype(lhs)>>;
    using base_type = typename type::base_type;

    // overhead ?
    return static_cast<base_type>(lhs) <
        static_cast<base_type>(rhs);
}

template<typename U, std::size_t... D>
constexpr bool operator!= (const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    return !(lhs == rhs);
}

template<typename U, std::size_t... D>
constexpr bool operator<= (const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}

template<typename U, std::size_t... D>
constexpr bool operator> (const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    return !(lhs <= rhs);
}

template<typename U, std::size_t... D>
constexpr bool operator>= (const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    return !(lhs < rhs);
}

} // namespace eb

#endif // MULTI_ARRAY_HPP
