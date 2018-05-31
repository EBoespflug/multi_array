/**
 * ezl_char_undef.hpp
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




namespace eb{

constexpr std::size_t factorise(std::size_t value)
{
    return value;
}

template<typename... Ts>
constexpr std::size_t factorise(std::size_t value, Ts... values)
{
    return value * factorise(values...);
}

template<typename T, std::size_t... Dims>
class multi_array : std::array<T, factorise(Dims...)>
{
    using base_type = std::array<T, factorise(Dims...)>;
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
    self_type& operator=(const self_type&) = default;
    multi_array(self_type&&) = default;
    self_type& operator=(self_type&&) = default;
    ~multi_array() noexcept = default;

private:
    constexpr bool equalTo(const multi_array<T, Dims...>& rhs) const
    {
        base_type::operator==(rhs);
    }

    constexpr bool lowerThan(const multi_array<T, Dims...>& rhs) const
    {
        base_type::operator<(rhs);
    }

    template<typename U, std::size_t... D>
    friend constexpr bool operator==(const multi_array<U, D...>&, const multi_array<U, D...>&);

    template<typename U, std::size_t... D>
    friend constexpr bool operator<(const multi_array<U, D...>&, const multi_array<U, D...>&);
};

template<typename U, std::size_t... D>
constexpr bool operator==(const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    return lhs.equalTo(rhs);
    /* overhead :
    using array_type = typename decltype(lhs)::base_type;
    return static_cast<array_type>(lhs) ==
        static_cast<array_type>(rhs);*/
}

template<typename U, std::size_t... D>
constexpr bool operator<(const multi_array<U, D...>& lhs, const multi_array<U, D...>& rhs)
{
    return lhs.lowerThan(rhs);
    /* overhead :
    using array_type = typename decltype(lhs)::base_type;
    return static_cast<array_type>(lhs) <
        static_cast<array_type>(rhs);*/
}
}

#endif // MULTI_ARRAY_HPP
