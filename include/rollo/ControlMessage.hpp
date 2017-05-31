#pragma once

#include <string>
#include "Direction.hpp"
namespace rollo {
class ControlMessage {
  std::string id;
  Direction direction;
 public:
  ControlMessage(const std::string id, const Direction direction);
  std::string to_json() const;
};
}