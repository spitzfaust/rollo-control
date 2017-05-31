//
// Created by tobias on 30/05/17.
//

#include <stdexcept>
#include "rollo/MosquittoClient.hpp"

namespace rollo {

MosquittoClient::MosquittoClient(const std::string &host, const std::string &topic) : host(host), topic(topic) {

}

MosquittoClient::~MosquittoClient() {
  disconnect();
  loop_stop();
  mosqpp::lib_cleanup();
}

void MosquittoClient::init() {
  error_check(mosqpp::lib_init(), "Could not initialise mosquitto.");
  error_check(connect_async(host.c_str()), "Could not connect to mosquitto broker.");
  error_check(loop_start(), "Could not start the mosquitto loop.");
}

void MosquittoClient::publish_message(const std::string &msg) {
  error_check(publish(nullptr, "test", msg.length(), msg.c_str()), "Could not publish message.");
}

void MosquittoClient::error_check(const int &err, const char *msg) {
  if (err != MOSQ_ERR_SUCCESS) {
    throw std::runtime_error(msg);
  }
}
}