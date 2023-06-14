#include "../Header/Main.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(MmapWidth, MmapHeight), "Testing Box");
    EntityController EC = EntityController(window);


    GuiObject GuiController = GuiObject(window, EC);
    TileController TileCon = TileController(window, MmapHeight, MmapWidth);

    StateController StateCon = StateController(GuiController, window, EC, DeltaClock, TileCon);
    sf::Vector2i mousePosition;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        mousePosition = sf::Mouse::getPosition(window);

        GuiController.renderFrame(DeltaClock);
        StateCon.update(DeltaClock);
        
        TileCon.update(DeltaClock, mousePosition);
        TileCon.draw(window);

        EC.update(DeltaClock);
        EC.draw(window);

        DeltaClock.restart();
        
        
        ImGui::SFML::Render(window); //abstract later
        window.display();
    }
  

    return 0;
}