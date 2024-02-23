#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>
#include "ImageModifier.cpp"

namespace py = pybind11;

PYBIND11_MODULE(ImageModifierModule, m) {
    m.doc() = "Image Modifier Module";

    py::class_<ImageModifier>(m, "ImageModifier")
        .def(py::init<std::string, double, int>())
        .def("change_contrast", &ImageModifier::changeContrast)
        .def("display_images", &ImageModifier::displayImages);
}