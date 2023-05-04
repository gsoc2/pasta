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

void RegisterAlignMac68kAttr(py::module_ &m) {
  py::class_<AlignMac68kAttr, Attr, InheritableAttr>(m, "AlignMac68kAttr")
    .def("__hash__", [](const AlignMac68kAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AlignMac68kAttr& a, const AlignMac68kAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &AlignMac68kAttr::Spelling);
}
} // namespace pasta
