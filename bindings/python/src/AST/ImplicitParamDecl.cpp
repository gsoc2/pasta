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

void RegisterImplicitParamDecl(py::module_ &m) {
  py::class_<ImplicitParamDecl, Decl, DeclaratorDecl, NamedDecl, ValueDecl, VarDecl>(m, "ImplicitParamDecl")
    .def("__hash__", [](const ImplicitParamDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const ImplicitParamDecl& a, const ImplicitParamDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("ParameterKind", &ImplicitParamDecl::ParameterKind);
}
} // namespace pasta
