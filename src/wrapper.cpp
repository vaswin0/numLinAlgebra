// src/wrapper.cpp
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include "Matrix.h"
#include <sstream>

namespace py = pybind11;

PYBIND11_MODULE(matrix, m) {
    py::class_<Matrix>(m, "Matrix")
        .def(py::init<>())
        .def(py::init<int, int>())
        .def(py::init<const std::vector<std::vector<double>>&>()) //Initialize from a list of lists
        .def("initMatrix", &Matrix::initMatrix)
        .def("__call__", &Matrix::operator(), "Get Matrix element")
        .def("initRand", &Matrix::initRand)
        .def("shape", &Matrix::shape)
        .def("transpose", &Matrix::transpose)
        .def("swapRows", &Matrix::swapRows)
        .def("scaleRow", &Matrix::scaleRow)
        .def("subtractRows", &Matrix::subtractRows)
        .def("gaussEli", &Matrix::gaussEli)
		.def("__add__", &Matrix::operator+)
        .def_static("identity", &Matrix::identity)
        .def("__repr__", [](const Matrix &m) {
            std::ostringstream oss;
            oss << m;
            return oss.str();
        })
    	.def(py::self + py::self)

		.def("cholesky", &Matrix::cholesky);

		m.def("gaussEli", [](Matrix &mat) {
			
				mat.gaussEli();

		});
	    
}

