# Circle Radius (SDL3 + C)

A small C project using **SDL3** that renders:

* a static circle
* a rotating radius line

The rotation is updated in a **worker thread**, while **all rendering is done on the main thread** (SDL-safe design).

---

## Project Structure

```
Circle_Radius/
├── circle_dir/
│   ├── Include/
│   │   └── circle.h
│   └── src/
│       └── circle.c
├── thread_struct/
│   └── thread_struct.h
├── main.c
├── CMakeLists.txt
├── .gitignore
└── build/        (generated)
```

---

## Requirements

* **C compiler** (gcc / clang)
* **CMake ≥ 3.20**
* **SDL3**
* **pthread** (Linux / Unix)

On Linux (Ubuntu/Debian):

```bash
sudo apt install cmake gcc libsdl3-dev
```

---

## Build Instructions

From the project root:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This produces the executable inside the `build/` directory.

---

## Run

```bash
./app
```

Close the window to exit cleanly.

---

## What to Play With

You can experiment with:

### Rotation speed

In `update_radius()`:

```c
float angular_speed = 0.5f; // radians per second
```

### Frame timing

The update thread uses:

```c
SDL_Delay(16); // ~60 Hz
```

Try different values to see timing effects.

### Threading model

* Worker thread updates **only state**
* Main thread handles **SDL rendering**
* Mutex protects shared data

This project is intentionally minimal and educational.

---

## Notes

* Rendering from worker threads is **not allowed** in SDL
* `delta_time()` provides frame-rate independent motion
* `.vscode/` and `build/` are ignored via `.gitignore`

---

## Purpose

This project is a learning exercise in:

* SDL rendering rules
* basic multithreading with pthreads
* time-based animation (`dt`)
* clean separation of update vs draw logic
