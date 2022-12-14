#pragma once

#include <string>

/**
 * @brief Simple example data container
 * A class like this should be used to implement your domain logic, e.g. a driver.
 */
class Data
{
public:
  Data();
  ~Data();

  std::string getTitle() const;
  void setTitle(const std::string &title);
  std::string getMessage(const std::string &name) const;

private:
  std::string title;
};
