//
// Created by tobias on 30/05/17.
//

#include "rollo/Direction.hpp"
#include "rollo/ControlMessage.hpp"
#include "rollo/RolloController.hpp"

namespace rollo {

RolloController::RolloController(const MosquittoClient &mosquitto_client) : mosquitto_client(mosquitto_client) {}

void RolloController::move_up(const std::string &id) {
  mosquitto_client.publish_message(rollo::ControlMessage{id, rollo::UP}.to_json());
}

void RolloController::move_down(const std::string &id) {
  mosquitto_client.publish_message(rollo::ControlMessage{id, rollo::DOWN}.to_json());
}
}