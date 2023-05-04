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

void RegisterBitIntType(py::module_ &m) {
  py::class_<BitIntType, Type>(m, "BitIntType")
    .def_property_readonly("Desugar", &BitIntType::Desugar)
    .def_property_readonly("NumBits", &BitIntType::NumBits)
    .def_property_readonly("IsSigned", &BitIntType::IsSigned)
    .def_property_readonly("IsSugared", &BitIntType::IsSugared)
    .def_property_readonly("IsUnsigned", &BitIntType::IsUnsigned);
}
} // namespace pasta
