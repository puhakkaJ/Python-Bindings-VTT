# Python-Bindings-VTT
**Repository for a pre-assignment in VTT interview utilizing Python bindings for C++.**

We build a simple ImageModifier Class in c++ that takes a picture as input, adjusted the saturation, and returns the modified picture. Then we build Python bindings for the Class using pybind11. 

## Structure
- `ImageModifier.cpp` :C++ Class
- `bindings.cpp` :Python bindings for the C++ Class using pybind11
- `CMakeLists.txt` :cmake build file
- `/build` :build directory
- `run.py` :Python script for running the new library


## Requirements
> Consider the following requirements and their depencies
- openCV
- pybind11

## Running details
`python run.py`

> (Testing the C++ Class individually `g++ $(pkg-config --cflags --libs opencv4) imgClass.cpp -o Test -std=c++11`)

## References
- pybind11  documentation: https://pybind11.readthedocs.io/en/stable/index.html
- Computer Vision: Algorithms and Applications, 2nd ed.: http://szeliski.org/Book/



