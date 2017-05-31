//
// Created by tobias on 30/05/17.
//

#include "nlohmann/json.hpp"
#include "rollo/ControlMessage.hpp"

namespace rollo {

ControlMessage::ControlMessage(const std::string id, const Direction direction) : id(id), direction(direction) {
}

std::string ControlMessage::to_json() const {
  nlohmann::json json = {
      {"id", id},
      {"direction", direction}
  };
  return json.dump();
}

}