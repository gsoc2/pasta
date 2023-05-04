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

void RegisterOMPTaskDirective(py::module_ &m) {
  py::class_<OMPTaskDirective, OMPExecutableDirective, Stmt>(m, "OMPTaskDirective")
    .def("__hash__", [](const OMPTaskDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPTaskDirective& a, const OMPTaskDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("HasCancel", &OMPTaskDirective::HasCancel);
}
} // namespace pasta
