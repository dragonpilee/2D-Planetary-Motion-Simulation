#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

// Define a structure for planets
struct Planet {
    sf::CircleShape shape;
    sf::Text label; // Text label for the planet
    float distance; // Distance from the sun
    float angle;    // Current angle in orbit
    float speed;    // Orbital speed
};

int main() {
    // Create the main window with 720p resolution
    sf::RenderWindow window(sf::VideoMode(1280, 720), "2D Planetary Motion");

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        // If loading the font fails, print an error and exit
        return -1;
    }

    // Define the sun
    sf::CircleShape sun(40); // Sun's radius (slightly increased for visibility)
    sun.setFillColor(sf::Color::Yellow);
    sun.setOrigin(40, 40); // Set origin to center
    sun.setPosition(640, 360); // Center of the 720p window

    // Create a text label for the sun
    sf::Text sunLabel("Sun", font, 20);
    sunLabel.setFillColor(sf::Color::White);
    sunLabel.setPosition(sun.getPosition().x + 45, sun.getPosition().y - 15);

    // Create a vector to hold the planets
    std::vector<Planet> planets;

    // Define planets with realistic names, sizes, distances, and speeds
    planets.push_back({sf::CircleShape(4), sf::Text("Mercury", font, 15), 90, 0, 0.015f});   // Mercury
    planets.push_back({sf::CircleShape(7), sf::Text("Venus", font, 15), 150, 0, 0.012f});    // Venus
    planets.push_back({sf::CircleShape(8), sf::Text("Earth", font, 15), 210, 0, 0.01f});     // Earth
    planets.push_back({sf::CircleShape(6), sf::Text("Mars", font, 15), 270, 0, 0.008f});     // Mars
    planets.push_back({sf::CircleShape(15), sf::Text("Jupiter", font, 15), 350, 0, 0.005f}); // Jupiter
    planets.push_back({sf::CircleShape(13), sf::Text("Saturn", font, 15), 450, 0, 0.004f});  // Saturn
    planets.push_back({sf::CircleShape(9), sf::Text("Uranus", font, 15), 570, 0, 0.003f});   // Uranus
    planets.push_back({sf::CircleShape(8), sf::Text("Neptune", font, 15), 680, 0, 0.0025f}); // Neptune

    // Set planet colors, origins, and labels
    sf::Color colors[] = {sf::Color(169, 169, 169), sf::Color(255, 215, 0), sf::Color::Blue, 
                          sf::Color(255, 69, 0), sf::Color(255, 165, 0), sf::Color(210, 180, 140),
                          sf::Color(173, 216, 230), sf::Color(0, 0, 139)};
    
    for (size_t i = 0; i < planets.size(); ++i) {
        planets[i].shape.setFillColor(colors[i]); // Set color for each planet
        planets[i].shape.setOrigin(planets[i].shape.getRadius(), planets[i].shape.getRadius());
        planets[i].label.setFillColor(sf::Color::White);
    }

    // Create orbit paths for each planet
    std::vector<sf::CircleShape> orbits;
    for (const auto& planet : planets) {
        sf::CircleShape orbit(planet.distance);
        orbit.setFillColor(sf::Color::Transparent); // Transparent fill
        orbit.setOutlineColor(sf::Color(128, 128, 128, 100)); // Grey outline with some transparency
        orbit.setOutlineThickness(1);
        orbit.setOrigin(planet.distance, planet.distance); // Set origin to the center
        orbit.setPosition(sun.getPosition()); // Position at the sun's center
        orbits.push_back(orbit);
    }

    // Create a label for "Designed and Developed by Alan Cyril"
    sf::Text creditLabel("Developed by Alan Cyril", font, 18);
    creditLabel.setFillColor(sf::Color::White);
    creditLabel.setPosition(10, 680); // Position near the bottom of the screen

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update planet positions and labels
        for (auto& planet : planets) {
            planet.angle += planet.speed;
            if (planet.angle > 2 * M_PI) {
                planet.angle -= 2 * M_PI; // Keep angle within 0 to 2π
            }
            // Calculate new position based on angle and distance from the sun
            float x = sun.getPosition().x + planet.distance * std::cos(planet.angle);
            float y = sun.getPosition().y + planet.distance * std::sin(planet.angle);
            planet.shape.setPosition(x, y);

            // Update planet label position
            planet.label.setPosition(x + 15, y - 15);
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the sun and its label
        window.draw(sun);
        window.draw(sunLabel);

        // Draw the orbit paths
        for (const auto& orbit : orbits) {
            window.draw(orbit);
        }

        // Draw the planets and their labels
        for (const auto& planet : planets) {
            window.draw(planet.shape);
            window.draw(planet.label);
        }

        // Draw the "Designed and Developed by Alan Cyril" label
        window.draw(creditLabel);

        // Update the window
        window.display();

        // Slow down the animation
        sf::sleep(sf::milliseconds(15));
    }

    return 0;
}
