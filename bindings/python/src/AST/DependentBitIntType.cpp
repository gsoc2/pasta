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

void RegisterDependentBitIntType(py::module_ &m) {
  py::class_<DependentBitIntType, Type>(m, "DependentBitIntType")
    .def("__hash__", [](const DependentBitIntType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DependentBitIntType& a, const DependentBitIntType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &DependentBitIntType::Desugar)
    .def_property_readonly("num_bits_expression", &DependentBitIntType::NumBitsExpression)
    .def_property_readonly("is_signed", &DependentBitIntType::IsSigned)
    .def_property_readonly("is_sugared", &DependentBitIntType::IsSugared)
    .def_property_readonly("is_unsigned", &DependentBitIntType::IsUnsigned);
}
} // namespace pasta
