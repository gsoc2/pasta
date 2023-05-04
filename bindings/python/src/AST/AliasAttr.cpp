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

void RegisterAliasAttr(py::module_ &m) {
  py::class_<AliasAttr, Attr>(m, "AliasAttr")
    .def("__hash__", [](const AliasAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AliasAttr& a, const AliasAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Aliasee", &AliasAttr::Aliasee)
    .def_property_readonly("AliaseeLength", &AliasAttr::AliaseeLength)
    .def_property_readonly("Spelling", &AliasAttr::Spelling);
}
} // namespace pasta
