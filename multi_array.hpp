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

    using base_type::size;

    explicit multi_array(const_reference value = value_type{})
    {
        base_type::fill(value);
    }
    multi_array(const self_type&) = default;
    self_type& operator=(const self_type&) = default;
    multi_array(self_type&&) = default;
    self_type& operator=(self_type&&) = default;
    ~multi_array() noexcept = default;
};
}

#endif // MULTI_ARRAY_HPP
