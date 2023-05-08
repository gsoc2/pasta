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

void RegisterAbiTagAttr(py::module_ &m) {
  py::class_<AbiTagAttr, Attr>(m, "AbiTagAttr")
    .def("__hash__", [](const AbiTagAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AbiTagAttr& a, const AbiTagAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &AbiTagAttr::Spelling);
}
} // namespace pasta
