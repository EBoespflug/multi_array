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
class multi_array
{
    using container_type = std::array<T, factorise(Dims...)>;

private:
    container_type arr_;
};
}

#endif
