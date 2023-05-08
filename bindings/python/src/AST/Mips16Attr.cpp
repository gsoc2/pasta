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

void RegisterMips16Attr(py::module_ &m) {
  py::class_<Mips16Attr, InheritableAttr>(m, "Mips16Attr")
    .def("__hash__", [](const Mips16Attr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const Mips16Attr& a, const Mips16Attr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &Mips16Attr::Spelling);
}
} // namespace pasta
