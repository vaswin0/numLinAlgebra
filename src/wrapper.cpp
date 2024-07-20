// src/wrapper.cpp
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "Matrix.h"
#include <sstream>

namespace py = pybind11;

PYBIND11_MODULE(matrix, m) {
    py::class_<Matrix>(m, "Matrix")
        .def(py::init<>())
        .def(py::init<int, int>())
        .def("initMatrix", &Matrix::initMatrix)
        .def("initRand", &Matrix::initRand)
        .def("shape", &Matrix::shape)
        .def("transpose", &Matrix::transpose)
        .def("swapRows", &Matrix::swapRows)
        .def("scaleRow", &Matrix::scaleRow)
        .def("subtractRows", &Matrix::subtractRows)
        .def("gaussEli", &Matrix::gaussEli)
        .def_static("identity", &Matrix::identity)
        .def("__repr__", [](const Matrix &m) {
            std::ostringstream oss;
            oss << m;
            return oss.str();
        })
    	.def(py::self + py::self)

		.def("cholesky", &Matrix::cholesky);
	    // Add more bindings as needed
}

