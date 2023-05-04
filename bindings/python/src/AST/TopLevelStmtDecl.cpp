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

void RegisterTopLevelStmtDecl(py::module_ &m) {
  py::class_<TopLevelStmtDecl, Decl>(m, "TopLevelStmtDecl")
    .def("__hash__", [](const TopLevelStmtDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const TopLevelStmtDecl& a, const TopLevelStmtDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("Statement", &TopLevelStmtDecl::Statement);
}
} // namespace pasta
