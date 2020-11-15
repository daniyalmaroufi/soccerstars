#include <iostream>
#include "RSDL/rsdl.hpp"

using namespace std;

int main()
{
    cout << "salam" << endl;
    Window *window = new Window(800, 480, "soccerStars");
    while (true)
    {
        window->draw_rect(Rectangle(100, 100, 200, 200));
        window->update_screen();
        if(window->has_pending_event()){
            Event e=window->poll_for_event();
            switch (e.get_type())
            {
            case Event::EventType::QUIT:
                exit(0);
                break;
            }
        }
    }

    return 0;
} 