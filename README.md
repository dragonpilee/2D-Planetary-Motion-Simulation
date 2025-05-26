# 🌌 2D Planetary Motion Simulation

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue)
![SFML](https://img.shields.io/badge/Graphics-SFML-green)
![Linux](https://img.shields.io/badge/Platform-Linux-informational)
![Simulation](https://img.shields.io/badge/Type-Simulation-purple)

> **Developed by Alan Cyril Sunny**  
> If you find this project helpful, please consider ⭐ [starring the repository](https://github.com/dragonpilee/planetary-motion-simulation)!

---

## 📜 Project Description

This project is a graphical simulation of planetary motion in a 2D plane, inspired by our Solar System. Each planet orbits the Sun at varying speeds and distances, providing an intuitive representation of celestial mechanics. You can visualize planets like Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, and Neptune, complete with orbit paths and names.

---

### ✨ Features

- 🌞 **Realistic Orbital Motion**: Watch planets orbit the Sun with varying speeds and distances.
- 🪐 **Planetary Details**: Each planet is named and colored uniquely, with their orbits clearly shown.
- 🌠 **Customizable and Extensible**: Easily modify the simulation parameters to add more planets or change their behaviors.
- 🖥️ **Interactive Visualization**: Smooth animations with SFML graphics, designed for a seamless user experience.

---

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler**: Make sure you have `g++` installed.
- **SFML Library**: Install SFML on your system:
  ```bash
  sudo apt-get install libsfml-dev
  ```

---

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/dragonpilee/planetary-motion-simulation.git
   cd planetary-motion-simulation
   ```

2. **Compile the project**
   ```bash
   g++ PlanetaryMotion.cpp -o PlanetaryMotion -lsfml-graphics -lsfml-window -lsfml-system
   ```

3. **Run the executable**
   ```bash
   ./PlanetaryMotion
   ```

---

### 🛠️ Customization

- **Modify the Planets**: Open `PlanetaryMotion.cpp` and adjust the `planets` vector to add new planets or change existing parameters like distance, speed, or color.
- **Change the Background**: Customize the background color or add your own textures to enhance the visual appeal.

---

## 🤝 Contributions

Contributions are welcome! Feel free to fork this repository and submit a pull request. If you have any ideas or suggestions, please open an issue or contact me directly.

### To Contribute:

1. **Fork the repository**
2. Create a new branch  
   ```bash
   git checkout -b feature-branch
   ```
3. Make your changes.
4. Commit your changes  
   ```bash
   git commit -am 'Add new feature'
   ```
5. Push to the branch  
   ```bash
   git push origin feature-branch
   ```
6. Open a Pull Request.

---

## 🧰 Built With

- **C++**: Core programming language used for logic and calculations.
- **SFML**: Simple and Fast Multimedia Library for graphics and window management.
- **Linux**: Developed and tested on Linux Mint, but compatible with other platforms.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙏 Acknowledgements

- SFML community for the wonderful graphics library.
- Open-source contributors for making tools and resources available.
- Special thanks to Alan Cyril for designing and developing this project.

---

## 🚧 Future Improvements

- Add more planets, dwarf planets, or even asteroids!
- Implement zoom and pan features for better navigation.
- Add interactive elements like speed controls or planet information panels.

---

For more information, updates, and documentation, visit the  
👉 [GitHub Repository](https://github.com/dragonpilee/planetary-motion-simulation)

Feel free to fork, star ⭐, and contribute!
