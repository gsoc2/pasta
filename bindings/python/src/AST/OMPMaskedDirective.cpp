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

void RegisterOMPMaskedDirective(py::module_ &m) {
  py::class_<OMPMaskedDirective, OMPExecutableDirective, Stmt>(m, "OMPMaskedDirective")
    .def("__hash__", [](const OMPMaskedDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPMaskedDirective& a, const OMPMaskedDirective& b) { return a.RawStmt() == b.RawStmt(); });
}
} // namespace pasta
