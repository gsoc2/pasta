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

void RegisterBTFDeclTagAttr(py::module_ &m) {
  py::class_<BTFDeclTagAttr, Attr, InheritableAttr>(m, "BTFDeclTagAttr")
    .def("__hash__", [](const BTFDeclTagAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const BTFDeclTagAttr& a, const BTFDeclTagAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("BTFDeclTag", &BTFDeclTagAttr::BTFDeclTag)
    .def_property_readonly("BTFDeclTagLength", &BTFDeclTagAttr::BTFDeclTagLength)
    .def_property_readonly("Spelling", &BTFDeclTagAttr::Spelling);
}
} // namespace pasta
