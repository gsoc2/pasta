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

void RegisterBuiltinBitCastExpr(py::module_ &m) {
  py::class_<BuiltinBitCastExpr, ExplicitCastExpr>(m, "BuiltinBitCastExpr")
    .def("__hash__", [](const BuiltinBitCastExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const BuiltinBitCastExpr& a, const BuiltinBitCastExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("begin_token", &BuiltinBitCastExpr::BeginToken)
    .def_property_readonly("end_token", &BuiltinBitCastExpr::EndToken);
}
} // namespace pasta
