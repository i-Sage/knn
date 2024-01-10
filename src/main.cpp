#include <cstdlib>
#include <fmt/core.h>
#include <lib/reader.hpp>
#include <optional>

int main ()
{
  constexpr size_t traning_data_size = 60000;
  constexpr size_t test_data_size = 10000;
  std::vector< rd::Data > traning_data (traning_data_size);
  std::vector< rd::Data > test_data (test_data_size);

  // get traning data
  auto temp
      = rd::get_data ("../data_set/mnist_train.csv", traning_data_size, ',');
  // if (temp.has_value ()) { traning_data = std::move (temp.value ()); }
  if (temp.has_value ()) { traning_data = temp.value (); }
  else { throw std::runtime_error ("Failed to read traning data"); }

  // get test data
  temp = rd::get_data ("../data_set/mnist_test.csv", test_data_size, ',');
  // if (temp.has_value ()) { test_data = std::move (temp.value ()); }
  if (temp.has_value ()) { test_data = temp.value (); }
  else { throw std::runtime_error ("Failed to read traning data"); }

  // testing
  fmt::println ("Traning Data first label: {}", traning_data[0].get_label ());
  fmt::println ("Traning Data last label: {}",
                traning_data[59999].get_label ());

  fmt::println ("Test Data first label: {}", test_data[0].get_label ());
  fmt::println ("Test Data last label: {}", test_data[9999].get_label ());

  return EXIT_SUCCESS;
}