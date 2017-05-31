#include <iostream>

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <rollo/MosquittoClient.hpp>
#include <rollo/RolloController.hpp>
#include "rollo/ControlMessage.hpp"

int abort_with_error(const char *msg) {
  nana::msgbox mb(nullptr, "Error", nana::msgbox::ok);
  mb.icon(mb.icon_error);
  mb << msg;
  mb.show();
  return EXIT_FAILURE;
}

int main() {

  auto exception = std::make_unique<std::exception>();
  auto mosquitto_client = rollo::MosquittoClient("localhost", "test");
  try {
    mosquitto_client.init();
  } catch (const std::runtime_error &error) {
    return abort_with_error(error.what());
  }

  const std::string rollo_id = "7c2204fa-a38e-40c0-a7aa-a61a9d4d97c2";

  auto rollo_controller = std::make_unique<rollo::RolloController>(mosquitto_client);

  // GUI Stuff

  //Define a form.
  nana::form fm;
  const auto bg_color = nana::colors::papaya_whip;
  //Define a label and display a text.
  nana::label lab{fm, "<size=16> Next Level Rollo Ctrl </>"};
  lab.text_align(nana::align::center, nana::align_v::center);
  lab.transparent(true);
  lab.format(true);

  //Define a button and answer the click event.
  nana::button up_btn{fm, "UP"};
  nana::button down_btn{fm, "DOWN"};
  down_btn.enabled(false);

  up_btn.events().click([&] {
    up_btn.enabled(false);
    down_btn.enabled(true);
    try {
      rollo_controller->move_up(rollo_id);
    } catch (const std::runtime_error &error) {
      abort_with_error(error.what());
      fm.close();
    }

  });

  down_btn.events().click([&] {
    down_btn.enabled(false);
    up_btn.enabled(true);
    try {
      rollo_controller->move_down(rollo_id);
    } catch (const std::runtime_error &error) {
      abort_with_error(error.what());
      fm.close();
    }
  });

  //Layout management
  fm.size(nana::size{800, 600});
  fm.bgcolor(bg_color);
  fm.div("<vert <<> <text> <>> <vert <up_button margin=10> <down_button margin=10>>>");
  fm["text"] << lab;
  fm["up_button"] << up_btn;
  fm["down_button"] << down_btn;
  fm.collocate();

  //Show the form
  fm.show();

  //Start to event loop process, it blocks until the form is closed.
  nana::exec();
}

