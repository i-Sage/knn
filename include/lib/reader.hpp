#pragma once

#include <cstdint>
#include <fstream>
#include <optional>
#include <sstream>
#include <vector>

namespace rd
{
  [[nodiscard]]
  inline std::vector< uint8_t > iterative_split (const std::string &str,
                                                 char delim)
  {
    std::vector< uint8_t > temp (785);
    size_t l = 0, i = 0;
    std::string::size_type pos = 0;

    while ((pos = str.find (delim, l)) != std::string::npos)
      {
        uint8_t data
            = static_cast< uint8_t > (std::stoi (str.substr (l, pos - l)));
        temp[i++] = data;
        l = pos + 1;
      }
    temp[i] = static_cast< uint8_t > (std::stoi (str.substr (l)));
    return temp;
  }

  class Data
  {
  public:
    std::vector< uint8_t > m_data;
    uint8_t get_label () const { return this->m_data[0]; }
    auto &get_data () { return this->m_data; }
    void set_data (std::vector< uint8_t > data) { this->m_data = data; }
    Data () = default;
    // Data (std::string &line, char delim) : m_data (split (line, delim)) {}
    Data (std::string &line, char delim)
        : m_data (iterative_split (line, delim))
    {
    }
  };

  [[nodiscard]]
  inline std::optional< std::vector< rd::Data > >
  get_data (std::string path, size_t size, char delim)
  {
    std::vector< rd::Data > temp (size);
    std::string buffer;
    if (std::fstream file { path }; file)
      {
        // discard the first line;
        std::getline (file, buffer);
        for (size_t i = 0; i < size; i++)
          {
            std::getline (file, buffer);
            temp[i] = rd::Data (buffer, delim);
          }
      }
    else { return std::nullopt; }
    return temp;
  }

}

namespace dont_use
{

  std::vector< uint8_t > split (const std::string &str, char delim)
  {
    std::vector< uint8_t > result;
    std::istringstream ss (str);
    std::string token;

    while (std::getline (ss, token, delim))
      {
        result.push_back (static_cast< uint8_t > (std::stoi (token)));
      }

    return result;
  }

  [[nodiscard]]
  auto __split (std::string &str, char delim)
  {
    std::vector< uint8_t > result (785);
    std::string::size_type pos = 0;

    size_t counter { 0 };
    while ((pos = str.find (delim)) != std::string::npos)
      {
        uint8_t data
            = static_cast< uint8_t > (std::stoi (str.substr (0, pos)));
        result[counter++] = data;
        str = str.substr (pos + 1);
      }
    result[counter] = static_cast< uint8_t > (std::stoi (str));
    return result;
  }
}