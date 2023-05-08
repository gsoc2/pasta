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

void RegisterAArch64VectorPcsAttr(py::module_ &m) {
  py::class_<AArch64VectorPcsAttr, InheritableAttr>(m, "AArch64VectorPcsAttr")
    .def("__hash__", [](const AArch64VectorPcsAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AArch64VectorPcsAttr& a, const AArch64VectorPcsAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &AArch64VectorPcsAttr::Spelling);
}
} // namespace pasta
