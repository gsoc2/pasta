/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterMinSizeAttr(py::module_ &m) {
  py::class_<MinSizeAttr, InheritableAttr>(m, "MinSizeAttr")
    .def("__hash__", [](const MinSizeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const MinSizeAttr& a, const MinSizeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &MinSizeAttr::Spelling);
}
} // namespace pasta
