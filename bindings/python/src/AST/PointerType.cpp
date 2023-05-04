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

void RegisterPointerType(py::module_ &m) {
  py::class_<PointerType, Type>(m, "PointerType")
    .def("__hash__", [](const PointerType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const PointerType& a, const PointerType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &PointerType::Desugar)
    .def_property_readonly("PointeeType", &PointerType::PointeeType)
    .def_property_readonly("IsSugared", &PointerType::IsSugared);
}
} // namespace pasta
