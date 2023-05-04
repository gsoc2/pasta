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

void RegisterObjCReturnsInnerPointerAttr(py::module_ &m) {
  py::class_<ObjCReturnsInnerPointerAttr, Attr, InheritableAttr>(m, "ObjCReturnsInnerPointerAttr")
    .def("__hash__", [](const ObjCReturnsInnerPointerAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ObjCReturnsInnerPointerAttr& a, const ObjCReturnsInnerPointerAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &ObjCReturnsInnerPointerAttr::Spelling);
}
} // namespace pasta
