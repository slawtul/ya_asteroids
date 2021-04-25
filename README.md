# YA_asteroids

![s1](screenshots/s1.png)

## How to launch on local machine

### Fedora

**(minimum g++ version 10.2.1)**

```bash
sudo dnf install g++ cmake SDL2-devel SDL2_image-devel SDL2_ttf-devel
cd Ya_asteroids
mkdir build
cd build
cmake ..
make
./asteroids
```

### Debian based distros (eg. Ubuntu, elementary os)

**(minimum g++ version 10.2.1)**

```bash
sudo apt install g++ cmake libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-gfx-dev
cd Ya_asteroids
mkdir build
cd build
cmake ..
make
./asteroids
```

---

#### Current status

- [x] Move from runtime polymorphism to std::variant solution
- [x] Spaceships (spaceship 1 keys: W, A, D, SPACE and spaceship 2 keys: UP, LEFT, RIGHT, ENTER)
- [x] Bullets
- [ ] Collisions
- [x] Debug info
- [ ] Extra weapons
- [ ] Extra effects

#### Author

Linkedin: [https://www.linkedin.com/in/slawektuleja/](https://www.linkedin.com/in/slawektuleja/)

#### License

You can use this software freely in any free or commercial project except files placed in 'resources' folder


#### Performance on

    Operating System: Fedora 32
    Processors: 16 × AMD Ryzen 7 3700X 8-Core Processor
    Memory: 32 GiB of RAM
    Monitor: LG, screen resolution 4K (3840 x 2160)
    Graphics card: AMD Radeon RX 5700 XT

    # Using runtime polymorphism (runtime-polymorphism branch)
    1. Avg ~60 FPS with 9900 objects on the screen
    2. Avg ~2700 FPS with 2 objects on the screen

    # With std::variant (std-variant branch)
    1. Avg ~60 FPS with 11800 objects on the screen
    2. Avg ~3600 FPS with 2 objects on the screen

    Summary
    1. Around 20% more objects with std::variant against runtime polymorphism
    2. Around 33% more FPS with std::variant against runtime polymorphism

    Fantastic results!

    (I merged std-variant branch into master)

