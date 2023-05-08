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

void RegisterEnforceTCBLeafAttr(py::module_ &m) {
  py::class_<EnforceTCBLeafAttr, InheritableAttr>(m, "EnforceTCBLeafAttr")
    .def("__hash__", [](const EnforceTCBLeafAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const EnforceTCBLeafAttr& a, const EnforceTCBLeafAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &EnforceTCBLeafAttr::Spelling)
    .def_property_readonly("tcb_name", &EnforceTCBLeafAttr::TCBName)
    .def_property_readonly("tcb_name_length", &EnforceTCBLeafAttr::TCBNameLength);
}
} // namespace pasta
