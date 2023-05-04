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

void RegisterOpenCLIntelReqdSubGroupSizeAttr(py::module_ &m) {
  py::class_<OpenCLIntelReqdSubGroupSizeAttr, Attr, InheritableAttr>(m, "OpenCLIntelReqdSubGroupSizeAttr")
    .def("__hash__", [](const OpenCLIntelReqdSubGroupSizeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const OpenCLIntelReqdSubGroupSizeAttr& a, const OpenCLIntelReqdSubGroupSizeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &OpenCLIntelReqdSubGroupSizeAttr::Spelling)
    .def_property_readonly("SubGroupSize", &OpenCLIntelReqdSubGroupSizeAttr::SubGroupSize);
}
} // namespace pasta
