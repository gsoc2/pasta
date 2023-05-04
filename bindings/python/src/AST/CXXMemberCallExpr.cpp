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

void RegisterCXXMemberCallExpr(py::module_ &m) {
  py::class_<CXXMemberCallExpr, CallExpr, Expr, Stmt, ValueStmt>(m, "CXXMemberCallExpr")
    .def("__hash__", [](const CXXMemberCallExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXMemberCallExpr& a, const CXXMemberCallExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("ExpressionToken", &CXXMemberCallExpr::ExpressionToken)
    .def_property_readonly("ImplicitObjectArgument", &CXXMemberCallExpr::ImplicitObjectArgument)
    .def_property_readonly("MethodDeclaration", &CXXMemberCallExpr::MethodDeclaration)
    .def_property_readonly("ObjectType", &CXXMemberCallExpr::ObjectType)
    .def_property_readonly("RecordDeclaration", &CXXMemberCallExpr::RecordDeclaration);
}
} // namespace pasta
