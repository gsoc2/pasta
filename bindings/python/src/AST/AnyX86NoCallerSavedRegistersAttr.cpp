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

void RegisterAnyX86NoCallerSavedRegistersAttr(py::module_ &m) {
  py::class_<AnyX86NoCallerSavedRegistersAttr, InheritableAttr>(m, "AnyX86NoCallerSavedRegistersAttr")
    .def("__hash__", [](const AnyX86NoCallerSavedRegistersAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AnyX86NoCallerSavedRegistersAttr& a, const AnyX86NoCallerSavedRegistersAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &AnyX86NoCallerSavedRegistersAttr::Spelling);
}
} // namespace pasta
