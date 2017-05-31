//
// Created by tobias on 30/05/17.
//

#include <string>
#include "MosquittoClient.hpp"

#pragma once

namespace rollo {
class RolloController {
  MosquittoClient mosquitto_client;
 public:
  RolloController(const MosquittoClient &mosquitto_client);
  void move_up(const std::string &id);
  void move_down(const std::string &id);
};
}