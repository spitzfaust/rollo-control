//
// Created by tobias on 30/05/17.
//

#pragma once

#include <string>
#include <mosquittopp.h>

namespace rollo {
class MosquittoClient : public mosqpp::mosquittopp {
  std::string host;
  std::string topic;

  void error_check(const int &err, const char* msg);
 public:
  MosquittoClient(const std::string &host, const std::string &topic);
  ~MosquittoClient();
  void init();
  void publish_message(const std::string &msg);

};
}


