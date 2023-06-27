/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterDependentSizedExtVectorType(nb::module_ &m) {
  nb::class_<DependentSizedExtVectorType, Type>(m, "DependentSizedExtVectorType")
    .def("__hash__", [](const DependentSizedExtVectorType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &DependentSizedExtVectorType::Desugar)
    .def_prop_ro("attribute_token", &DependentSizedExtVectorType::AttributeToken)
    .def_prop_ro("element_type", &DependentSizedExtVectorType::ElementType)
    .def_prop_ro("size_expression", &DependentSizedExtVectorType::SizeExpression)
    .def_prop_ro("is_sugared", &DependentSizedExtVectorType::IsSugared);
}
} // namespace pasta