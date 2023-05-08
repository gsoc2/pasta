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

void RegisterIndirectFieldDecl(py::module_ &m) {
  py::class_<IndirectFieldDecl, ValueDecl>(m, "IndirectFieldDecl")
    .def("__hash__", [](const IndirectFieldDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const IndirectFieldDecl& a, const IndirectFieldDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("Chain", &IndirectFieldDecl::Chain)
    .def_property_readonly("AnonymousField", &IndirectFieldDecl::AnonymousField)
    .def_property_readonly("CanonicalDeclaration", &IndirectFieldDecl::CanonicalDeclaration)
    .def_property_readonly("ChainingSize", &IndirectFieldDecl::ChainingSize)
    .def_property_readonly("VariableDeclaration", &IndirectFieldDecl::VariableDeclaration);
}
} // namespace pasta
