/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

// This file is auto-generated.

#ifndef PASTA_IN_BOOTSTRAP
#include <pasta/AST/Decl.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclFriend.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclOpenMP.h>
#include <clang/AST/DeclTemplate.h>
#pragma clang diagnostic pop

#define PASTA_DEFINE_DERIVED_OPERATORS(base, derived) \
    base::base(const class derived &that) \
        : base(that.ast, that.u.Decl) {} \
    base::base(class derived &&that) noexcept \
        : base(std::move(that.ast), that.u.Decl) {} \
    base &base::operator=(const class derived &that) { \
      if (ast != that.ast) { \
        ast = that.ast; \
      } \
      u.Decl = that.u.Decl; \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      if (this != &that) { \
        ast = std::move(that.ast); \
        u.Decl = that.u.Decl; \
      } \
      return *this; \
    }

#define PASTA_DEFINE_DECLCONTEXT_OPERATORS(base, derived) \
    base::base(const class derived &that) \
        : base(that.ast, clang::dyn_cast<clang::derived>(that.u.Decl)) {} \
    base::base(class derived &&that) noexcept \
        : base(std::move(that.ast), clang::dyn_cast<clang::derived>(that.u.Decl)) {} \
    base &base::operator=(const class derived &that) { \
      if (ast != that.ast) { \
        ast = that.ast; \
      } \
      u.DeclContext = clang::dyn_cast<clang::derived>(that.u.Decl); \
      return *this; \
    } \
    base &base::operator=(class derived &&that) noexcept { \
      ast = std::move(that.ast); \
      u.DeclContext = clang::dyn_cast<clang::derived>(that.u.Decl); \
      return *this; \
    }

#include "AST.h"

namespace pasta {

class DeclBuilder {
 public:
  template <typename T, typename D>
  inline static T Create(std::shared_ptr<ASTImpl> ast_, const D *decl_) {
    return T(std::move(ast_), decl_);
  }
};

Decl::Decl(const class DeclContext &context)
   : Decl(context.ast, clang::dyn_cast<clang::Decl>(context.u.DeclContext)) {}

Decl::Decl(class DeclContext &&context) noexcept
   : Decl(std::move(context.ast), clang::dyn_cast<clang::Decl>(context.u.DeclContext)) {}

Decl &Decl::operator=(const class DeclContext &context) {
  if (ast != context.ast) {
    ast = context.ast;
  }
  u.Decl = clang::dyn_cast<clang::Decl>(context.u.DeclContext);
  return *this;
}

Decl &Decl::operator=(class DeclContext &&context) noexcept {
  if (ast != context.ast) {
    ast = std::move(context.ast);
  }
  u.Decl = clang::dyn_cast<clang::Decl>(context.u.DeclContext);
  return *this;
}

PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, BlockDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXConstructorDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXConversionDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXDeductionGuideDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXDestructorDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXMethodDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CXXRecordDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, CapturedDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, EnumDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ExportDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ExternCContextDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, FunctionDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, LinkageSpecDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, NamespaceDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, OMPDeclareMapperDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, OMPDeclareReductionDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCCategoryDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCCategoryImplDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCContainerDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCImplDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCImplementationDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCInterfaceDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCMethodDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, ObjCProtocolDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, RecordDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, RequiresExprBodyDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, TagDecl)
PASTA_DEFINE_DECLCONTEXT_OPERATORS(DeclContext, TranslationUnitDecl)

namespace {
// Return the PASTA `DeclKind` for a Clang `Decl`.
static DeclKind KindOfDecl(const clang::Decl *decl) {
  switch (decl->getKind()) {
#define ABSTRACT_DECL(DECL)
#define DECL(DERIVED, BASE) \
    case clang::Decl::DERIVED: \
      return DeclKind::k ## DERIVED;
#include <clang/AST/DeclNodes.inc>
  }
  __builtin_unreachable();
}

static const std::string_view kKindNames[] = {
  "AccessSpec",
  "Binding",
  "Block",
  "BuiltinTemplate",
  "CXXConstructor",
  "CXXConversion",
  "CXXDeductionGuide",
  "CXXDestructor",
  "CXXMethod",
  "CXXRecord",
  "Captured",
  "ClassScopeFunctionSpecialization",
  "ClassTemplate",
  "ClassTemplatePartialSpecialization",
  "ClassTemplateSpecialization",
  "Concept",
  "ConstructorUsingShadow",
  "Declarator",
  "Decomposition",
  "Empty",
  "EnumConstant",
  "Enum",
  "Export",
  "ExternCContext",
  "Field",
  "FileScopeAsm",
  "Friend",
  "FriendTemplate",
  "Function",
  "FunctionTemplate",
  "ImplicitParam",
  "Import",
  "IndirectField",
  "Label",
  "LifetimeExtendedTemporary",
  "LinkageSpec",
  "MSGuid",
  "MSProperty",
  "Named",
  "NamespaceAlias",
  "Namespace",
  "NonTypeTemplateParm",
  "OMPAllocate",
  "OMPCapturedExpr",
  "OMPDeclareMapper",
  "OMPDeclareReduction",
  "OMPRequires",
  "OMPThreadPrivate",
  "ObjCAtDefsField",
  "ObjCCategory",
  "ObjCCategoryImpl",
  "ObjCCompatibleAlias",
  "ObjCContainer",
  "ObjCImpl",
  "ObjCImplementation",
  "ObjCInterface",
  "ObjCIvar",
  "ObjCMethod",
  "ObjCProperty",
  "ObjCPropertyImpl",
  "ObjCProtocol",
  "ObjCTypeParam",
  "ParmVar",
  "PragmaComment",
  "PragmaDetectMismatch",
  "Record",
  "RedeclarableTemplate",
  "RequiresExprBody",
  "StaticAssert",
  "Tag",
  "Template",
  "TemplateParamObject",
  "TemplateTemplateParm",
  "TemplateTypeParm",
  "TranslationUnit",
  "TypeAlias",
  "TypeAliasTemplate",
  "Type",
  "Typedef",
  "TypedefName",
  "UnresolvedUsingTypename",
  "UnresolvedUsingValue",
  "Using",
  "UsingDirective",
  "UsingPack",
  "UsingShadow",
  "Value",
  "Var",
  "VarTemplate",
  "VarTemplatePartialSpecialization",
  "VarTemplateSpecialization",
};
}  // namespace

std::string_view Decl::KindName(void) const {
  return kKindNames[static_cast<unsigned>(kind)];
}

// 1: DeclContext::Equals
std::vector<::pasta::Decl> DeclContext::Declarations(void) const {
  auto val = u.DeclContext->decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::DeclKind DeclContext::DeclKind(void) const {
  auto val = u.DeclContext->getDeclKind();
  return static_cast<::pasta::DeclKind>(val);
}

::pasta::DeclContext DeclContext::EnclosingNamespaceContext(void) const {
  auto val = u.DeclContext->getEnclosingNamespaceContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::EnclosingNamespaceContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::LexicalParent(void) const {
  auto val = u.DeclContext->getLexicalParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::LexicalParent can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::LookupParent(void) const {
  auto val = u.DeclContext->getLookupParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::LookupParent can return nullptr!");
  __builtin_unreachable();
}

// 0: DeclContext::LookupPtr
::pasta::Decl DeclContext::NonClosureAncestor(void) const {
  auto val = u.DeclContext->getNonClosureAncestor();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "DeclContext::NonClosureAncestor can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl DeclContext::OuterLexicalRecordContext(void) const {
  auto val = u.DeclContext->getOuterLexicalRecordContext();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "DeclContext::OuterLexicalRecordContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::Parent(void) const {
  auto val = u.DeclContext->getParent();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::Parent can return nullptr!");
  __builtin_unreachable();
}

// 0: DeclContext::ParentASTContext
::pasta::DeclContext DeclContext::PrimaryContext(void) const {
  auto val = u.DeclContext->getPrimaryContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::PrimaryContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext DeclContext::RedeclContext(void) const {
  auto val = u.DeclContext->getRedeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "DeclContext::RedeclContext can return nullptr!");
  __builtin_unreachable();
}

bool DeclContext::HasExternalLexicalStorage(void) const {
  auto val = u.DeclContext->hasExternalLexicalStorage();
  return val;
}

bool DeclContext::HasExternalVisibleStorage(void) const {
  auto val = u.DeclContext->hasExternalVisibleStorage();
  return val;
}

bool DeclContext::IsClosure(void) const {
  auto val = u.DeclContext->isClosure();
  return val;
}

// 1: DeclContext::IsDeclInLexicalTraversal
bool DeclContext::IsFileContext(void) const {
  auto val = u.DeclContext->isFileContext();
  return val;
}

bool DeclContext::IsFunctionOrMethod(void) const {
  auto val = u.DeclContext->isFunctionOrMethod();
  return val;
}

bool DeclContext::IsLookupContext(void) const {
  auto val = u.DeclContext->isLookupContext();
  return val;
}

bool DeclContext::IsNamespace(void) const {
  auto val = u.DeclContext->isNamespace();
  return val;
}

bool DeclContext::IsObjCContainer(void) const {
  auto val = u.DeclContext->isObjCContainer();
  return val;
}

bool DeclContext::IsRecord(void) const {
  auto val = u.DeclContext->isRecord();
  return val;
}

bool DeclContext::IsTranslationUnit(void) const {
  auto val = u.DeclContext->isTranslationUnit();
  return val;
}

std::vector<::pasta::Decl> DeclContext::AlreadyLoadedDecls(void) const {
  auto val = u.DeclContext->noload_decls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
  }
  return ret;
}

bool DeclContext::ShouldUseQualifiedLookup(void) const {
  auto val = u.DeclContext->shouldUseQualifiedLookup();
  return val;
}

Decl::Decl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_, KindOfDecl(decl_)) {}
PASTA_DEFINE_DERIVED_OPERATORS(Decl, AccessSpecDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, BindingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, BlockDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, BuiltinTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, CapturedDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassScopeFunctionSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ConceptDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ConstructorUsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, DeclaratorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, EmptyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, EnumConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ExportDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ExternCContextDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FileScopeAsmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FriendDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FriendTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ImportDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, IndirectFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, LabelDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, LifetimeExtendedTemporaryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, LinkageSpecDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, MSGuidDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NamedDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NamespaceAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NamespaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPAllocateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclarativeDirectiveDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclarativeDirectiveValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclareMapperDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPDeclareReductionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPRequiresDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, OMPThreadPrivateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCCategoryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCCompatibleAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCContainerDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCImplementationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCInterfaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCPropertyImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCProtocolDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, PragmaCommentDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, PragmaDetectMismatchDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, RecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, RedeclarableTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, RequiresExprBodyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, StaticAssertDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TagDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateParamObjectDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TemplateTypeParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TranslationUnitDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypeDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypedefDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, TypedefNameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingDirectiveDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingPackDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, ValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(Decl, VarTemplateSpecializationDecl)
// 0: Decl::Attributes
AccessSpecifier Decl::Access(void) const {
  auto val = u.Decl->getAccess();
  return static_cast<::pasta::AccessSpecifier>(static_cast<unsigned int>(val));
}

AccessSpecifier Decl::AccessUnsafe(void) const {
  auto val = u.Decl->getAccessUnsafe();
  return static_cast<::pasta::AccessSpecifier>(static_cast<unsigned int>(val));
}

::pasta::FunctionDecl Decl::AsFunction(void) const {
  auto val = u.Decl->getAsFunction();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "Decl::AsFunction can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token Decl::BeginToken(void) const {
  auto val = u.Decl->getBeginLoc();
  return ast->TokenAt(val);
}

// 0: Decl::Body
::pasta::Decl Decl::CanonicalDecl(void) const {
  auto val = u.Decl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::DeclContext Decl::DeclContext(void) const {
  auto val = u.Decl->getDeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::DeclContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token Decl::EndToken(void) const {
  auto val = u.Decl->getEndLoc();
  return ast->TokenAt(val);
}

::pasta::FriendObjectKind Decl::FriendObjectKind(void) const {
  auto val = u.Decl->getFriendObjectKind();
  return static_cast<::pasta::FriendObjectKind>(val);
}

uint32_t Decl::GlobalID(void) const {
  auto val = u.Decl->getGlobalID();
  return val;
}

uint32_t Decl::IdentifierNamespace(void) const {
  auto val = u.Decl->getIdentifierNamespace();
  return val;
}

// 0: Decl::ImportedOwningModule
::pasta::DeclContext Decl::LexicalDeclContext(void) const {
  auto val = u.Decl->getLexicalDeclContext();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "Decl::LexicalDeclContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::LocalOwningModule
::pasta::Token Decl::Token(void) const {
  auto val = u.Decl->getLocation();
  return ast->TokenAt(val);
}

::pasta::ModuleOwnershipKind Decl::ModuleOwnershipKind(void) const {
  auto val = u.Decl->getModuleOwnershipKind();
  return static_cast<::pasta::ModuleOwnershipKind>(val);
}

::pasta::Decl Decl::MostRecentDecl(void) const {
  auto val = u.Decl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Decl Decl::NextDeclInContext(void) const {
  auto val = u.Decl->getNextDeclInContext();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::NextDeclInContext can return nullptr!");
  __builtin_unreachable();
}

::pasta::Decl Decl::NonClosureContext(void) const {
  auto val = u.Decl->getNonClosureContext();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::NonClosureContext can return nullptr!");
  __builtin_unreachable();
}

// 0: Decl::OwningModule
uint32_t Decl::OwningModuleID(void) const {
  auto val = u.Decl->getOwningModuleID();
  return val;
}

::pasta::Decl Decl::PreviousDecl(void) const {
  auto val = u.Decl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "Decl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange Decl::TokenRange(void) const {
  auto val = u.Decl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::TranslationUnitDecl Decl::TranslationUnitDecl(void) const {
  auto val = u.Decl->getTranslationUnitDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TranslationUnitDecl>(ast, val);
  }
  assert(false && "Decl::TranslationUnitDecl can return nullptr!");
  __builtin_unreachable();
}

bool Decl::HasAttributes(void) const {
  auto val = u.Decl->hasAttrs();
  return val;
}

bool Decl::HasBody(void) const {
  auto val = u.Decl->hasBody();
  return val;
}

bool Decl::HasOwningModule(void) const {
  auto val = u.Decl->hasOwningModule();
  return val;
}

bool Decl::HasTagIdentifierNamespace(void) const {
  auto val = u.Decl->hasTagIdentifierNamespace();
  return val;
}

bool Decl::IsCanonicalDecl(void) const {
  auto val = u.Decl->isCanonicalDecl();
  return val;
}

bool Decl::IsDefinedOutsideFunctionOrMethod(void) const {
  auto val = u.Decl->isDefinedOutsideFunctionOrMethod();
  return val;
}

bool Decl::IsDeprecated(void) const {
  auto val = u.Decl->isDeprecated();
  return val;
}

bool Decl::IsFirstDecl(void) const {
  auto val = u.Decl->isFirstDecl();
  return val;
}

bool Decl::IsFromASTFile(void) const {
  auto val = u.Decl->isFromASTFile();
  return val;
}

bool Decl::IsFunctionOrFunctionTemplate(void) const {
  auto val = u.Decl->isFunctionOrFunctionTemplate();
  return val;
}

bool Decl::IsImplicit(void) const {
  auto val = u.Decl->isImplicit();
  return val;
}

// 1: Decl::IsInIdentifierNamespace
bool Decl::IsInvalidDecl(void) const {
  auto val = u.Decl->isInvalidDecl();
  return val;
}

bool Decl::IsModulePrivate(void) const {
  auto val = u.Decl->isModulePrivate();
  return val;
}

bool Decl::IsTemplateParameter(void) const {
  auto val = u.Decl->isTemplateParameter();
  return val;
}

bool Decl::IsThisDeclarationReferenced(void) const {
  auto val = u.Decl->isThisDeclarationReferenced();
  return val;
}

bool Decl::IsTopLevelDeclInObjCContainer(void) const {
  auto val = u.Decl->isTopLevelDeclInObjCContainer();
  return val;
}

bool Decl::IsUnavailable(void) const {
  auto val = u.Decl->isUnavailable();
  return val;
}

bool Decl::IsUnconditionallyVisible(void) const {
  auto val = u.Decl->isUnconditionallyVisible();
  return val;
}

std::vector<::pasta::Decl> Decl::Redeclarations(void) const {
  auto val = u.Decl->redecls();
  std::vector<::pasta::Decl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::Decl>(ast, decl_ptr));
  }
  return ret;
}

EmptyDecl::EmptyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

ExportDecl::ExportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

::pasta::Token ExportDecl::EndToken(void) const {
  auto val = u.ExportDecl->getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExportDecl::ExportToken(void) const {
  auto val = u.ExportDecl->getExportLoc();
  return ast->TokenAt(val);
}

::pasta::Token ExportDecl::RBraceToken(void) const {
  auto val = u.ExportDecl->getRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ExportDecl::TokenRange(void) const {
  auto val = u.ExportDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ExportDecl::HasBraces(void) const {
  auto val = u.ExportDecl->hasBraces();
  return val;
}

ExternCContextDecl::ExternCContextDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

FileScopeAsmDecl::FileScopeAsmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

::pasta::Token FileScopeAsmDecl::AsmToken(void) const {
  auto val = u.FileScopeAsmDecl->getAsmLoc();
  return ast->TokenAt(val);
}

// 0: FileScopeAsmDecl::AsmString
::pasta::Token FileScopeAsmDecl::RParenToken(void) const {
  auto val = u.FileScopeAsmDecl->getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange FileScopeAsmDecl::TokenRange(void) const {
  auto val = u.FileScopeAsmDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

FriendDecl::FriendDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

::pasta::NamedDecl FriendDecl::FindFriendDecl(void) const {
  auto val = u.FriendDecl->getFriendDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "FriendDecl::FindFriendDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FriendDecl::FriendToken(void) const {
  auto val = u.FriendDecl->getFriendLoc();
  return ast->TokenAt(val);
}

// 0: FriendDecl::FriendType
uint32_t FriendDecl::FriendTypeNumTemplateParameterLists(void) const {
  auto val = u.FriendDecl->getFriendTypeNumTemplateParameterLists();
  return val;
}

// 1: FriendDecl::FriendTypeTemplateParameterList
::pasta::TokenRange FriendDecl::TokenRange(void) const {
  auto val = u.FriendDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool FriendDecl::IsUnsupportedFriend(void) const {
  auto val = u.FriendDecl->isUnsupportedFriend();
  return val;
}

FriendTemplateDecl::FriendTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

::pasta::NamedDecl FriendTemplateDecl::FindFriendDecl(void) const {
  auto val = u.FriendTemplateDecl->getFriendDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "FriendTemplateDecl::FindFriendDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FriendTemplateDecl::FriendToken(void) const {
  auto val = u.FriendTemplateDecl->getFriendLoc();
  return ast->TokenAt(val);
}

// 0: FriendTemplateDecl::FriendType
uint32_t FriendTemplateDecl::NumTemplateParameters(void) const {
  auto val = u.FriendTemplateDecl->getNumTemplateParameters();
  return val;
}

// 1: FriendTemplateDecl::TemplateParameterList
ImportDecl::ImportDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

// 0: ImportDecl::ImportedModule
LifetimeExtendedTemporaryDecl::LifetimeExtendedTemporaryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

// 0: LifetimeExtendedTemporaryDecl::ChildrenExpr
::pasta::ValueDecl LifetimeExtendedTemporaryDecl::ExtendingDecl(void) const {
  auto val = u.LifetimeExtendedTemporaryDecl->getExtendingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ValueDecl>(ast, val);
  }
  assert(false && "LifetimeExtendedTemporaryDecl::ExtendingDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t LifetimeExtendedTemporaryDecl::ManglingNumber(void) const {
  auto val = u.LifetimeExtendedTemporaryDecl->getManglingNumber();
  return val;
}

// 0: LifetimeExtendedTemporaryDecl::TemporaryExpr
// 0: LifetimeExtendedTemporaryDecl::Value
LinkageSpecDecl::LinkageSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

::pasta::Token LinkageSpecDecl::EndToken(void) const {
  auto val = u.LinkageSpecDecl->getEndLoc();
  return ast->TokenAt(val);
}

::pasta::Token LinkageSpecDecl::ExternToken(void) const {
  auto val = u.LinkageSpecDecl->getExternLoc();
  return ast->TokenAt(val);
}

::pasta::LanguageIDs LinkageSpecDecl::Language(void) const {
  auto val = u.LinkageSpecDecl->getLanguage();
  return static_cast<::pasta::LanguageIDs>(val);
}

::pasta::Token LinkageSpecDecl::RBraceToken(void) const {
  auto val = u.LinkageSpecDecl->getRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange LinkageSpecDecl::TokenRange(void) const {
  auto val = u.LinkageSpecDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool LinkageSpecDecl::HasBraces(void) const {
  auto val = u.LinkageSpecDecl->hasBraces();
  return val;
}

NamedDecl::NamedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, BindingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, BuiltinTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ConceptDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ConstructorUsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, DeclaratorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, EnumConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, IndirectFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, LabelDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, MSGuidDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, NamespaceAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, NamespaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPDeclarativeDirectiveValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPDeclareMapperDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, OMPDeclareReductionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCCategoryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCCompatibleAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCContainerDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCImplementationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCInterfaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCProtocolDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, RecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, RedeclarableTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TagDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateParamObjectDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TemplateTypeParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypeDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypedefDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, TypedefNameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingTypenameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingDirectiveDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingPackDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, UsingShadowDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, ValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(NamedDecl, VarTemplateSpecializationDecl)
// 0: NamedDecl::DeclName
Linkage NamedDecl::FormalLinkage(void) const {
  auto val = u.NamedDecl->getFormalLinkage();
  return static_cast<::pasta::Linkage>(static_cast<unsigned char>(val));
}

// 0: NamedDecl::Identifier
::pasta::NamedDecl NamedDecl::MostRecentDecl(void) const {
  auto val = u.NamedDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamedDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

std::string_view NamedDecl::Name(void) const {
  auto val = u.NamedDecl->getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

std::string NamedDecl::NameAsString(void) const {
  auto val = u.NamedDecl->getNameAsString();
  return val;
}

::pasta::NamedDecl NamedDecl::UnderlyingDecl(void) const {
  auto val = u.NamedDecl->getUnderlyingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamedDecl::UnderlyingDecl can return nullptr!");
  __builtin_unreachable();
}

Visibility NamedDecl::Visibility(void) const {
  auto val = u.NamedDecl->getVisibility();
  return static_cast<::pasta::Visibility>(static_cast<unsigned int>(val));
}

bool NamedDecl::HasExternalFormalLinkage(void) const {
  auto val = u.NamedDecl->hasExternalFormalLinkage();
  return val;
}

bool NamedDecl::HasLinkageBeenComputed(void) const {
  auto val = u.NamedDecl->hasLinkageBeenComputed();
  return val;
}

bool NamedDecl::IsCXXClassMember(void) const {
  auto val = u.NamedDecl->isCXXClassMember();
  return val;
}

bool NamedDecl::IsExternallyDeclarable(void) const {
  auto val = u.NamedDecl->isExternallyDeclarable();
  return val;
}

bool NamedDecl::IsExternallyVisible(void) const {
  auto val = u.NamedDecl->isExternallyVisible();
  return val;
}

NamespaceAliasDecl::NamespaceAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

::pasta::Token NamespaceAliasDecl::AliasToken(void) const {
  auto val = u.NamespaceAliasDecl->getAliasLoc();
  return ast->TokenAt(val);
}

::pasta::NamedDecl NamespaceAliasDecl::AliasedNamespace(void) const {
  auto val = u.NamespaceAliasDecl->getAliasedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::AliasedNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceAliasDecl NamespaceAliasDecl::CanonicalDecl(void) const {
  auto val = u.NamespaceAliasDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceAliasDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamespaceDecl NamespaceAliasDecl::Namespace(void) const {
  auto val = u.NamespaceAliasDecl->getNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceAliasDecl::Namespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceAliasDecl::NamespaceToken(void) const {
  auto val = u.NamespaceAliasDecl->getNamespaceLoc();
  return ast->TokenAt(val);
}

// 0: NamespaceAliasDecl::Qualifier
// 0: NamespaceAliasDecl::QualifierToken
::pasta::TokenRange NamespaceAliasDecl::TokenRange(void) const {
  auto val = u.NamespaceAliasDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token NamespaceAliasDecl::TargetNameToken(void) const {
  auto val = u.NamespaceAliasDecl->getTargetNameLoc();
  return ast->TokenAt(val);
}

NamespaceDecl::NamespaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

::pasta::NamespaceDecl NamespaceDecl::AnonymousNamespace(void) const {
  auto val = u.NamespaceDecl->getAnonymousNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::AnonymousNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceDecl::BeginToken(void) const {
  auto val = u.NamespaceDecl->getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::NamespaceDecl NamespaceDecl::CanonicalDecl(void) const {
  auto val = u.NamespaceDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "NamespaceDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token NamespaceDecl::RBraceToken(void) const {
  auto val = u.NamespaceDecl->getRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange NamespaceDecl::TokenRange(void) const {
  auto val = u.NamespaceDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool NamespaceDecl::IsAnonymousNamespace(void) const {
  auto val = u.NamespaceDecl->isAnonymousNamespace();
  return val;
}

bool NamespaceDecl::IsInline(void) const {
  auto val = u.NamespaceDecl->isInline();
  return val;
}

ObjCCompatibleAliasDecl::ObjCCompatibleAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

::pasta::ObjCInterfaceDecl ObjCCompatibleAliasDecl::ClassInterface(void) const {
  auto val = u.ObjCCompatibleAliasDecl->getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCCompatibleAliasDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

ObjCContainerDecl::ObjCContainerDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCImplementationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCInterfaceDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCContainerDecl, ObjCProtocolDecl)
std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::ClassMethods(void) const {
  auto val = u.ObjCContainerDecl->class_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::ClassProperties(void) const {
  auto val = u.ObjCContainerDecl->class_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
  }
  return ret;
}

// 2: CollectPropertiesToImplement
::pasta::TokenRange ObjCContainerDecl::AtEndRange(void) const {
  auto val = u.ObjCContainerDecl->getAtEndRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token ObjCContainerDecl::AtStartToken(void) const {
  auto val = u.ObjCContainerDecl->getAtStartLoc();
  return ast->TokenAt(val);
}

// 1: ObjCContainerDecl::ClassMethod
// 1: ObjCContainerDecl::InstanceMethod
::pasta::TokenRange ObjCContainerDecl::TokenRange(void) const {
  auto val = u.ObjCContainerDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::InstanceMethods(void) const {
  auto val = u.ObjCContainerDecl->instance_methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::InstanceProperties(void) const {
  auto val = u.ObjCContainerDecl->instance_properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCMethodDecl> ObjCContainerDecl::Methods(void) const {
  auto val = u.ObjCContainerDecl->methods();
  std::vector<::pasta::ObjCMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCPropertyDecl> ObjCContainerDecl::Properties(void) const {
  auto val = u.ObjCContainerDecl->properties();
  std::vector<::pasta::ObjCPropertyDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, decl_ptr));
  }
  return ret;
}

ObjCImplDecl::ObjCImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(ObjCImplDecl, ObjCCategoryImplDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ObjCImplDecl, ObjCImplementationDecl)
::pasta::ObjCInterfaceDecl ObjCImplDecl::ClassInterface(void) const {
  auto val = u.ObjCImplDecl->getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCImplDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

std::vector<::pasta::ObjCPropertyImplDecl> ObjCImplDecl::PropertyImplementations(void) const {
  auto val = u.ObjCImplDecl->property_impls();
  std::vector<::pasta::ObjCPropertyImplDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCPropertyImplDecl>(ast, decl_ptr));
  }
  return ret;
}

ObjCImplementationDecl::ObjCImplementationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCImplDecl(std::move(ast_), decl_) {}

// 0: ObjCImplementationDecl::Identifier
::pasta::Token ObjCImplementationDecl::IvarLBraceToken(void) const {
  auto val = u.ObjCImplementationDecl->getIvarLBraceLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCImplementationDecl::IvarRBraceToken(void) const {
  auto val = u.ObjCImplementationDecl->getIvarRBraceLoc();
  return ast->TokenAt(val);
}

std::string_view ObjCImplementationDecl::Name(void) const {
  auto val = u.ObjCImplementationDecl->getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

std::string ObjCImplementationDecl::NameAsString(void) const {
  auto val = u.ObjCImplementationDecl->getNameAsString();
  return val;
}

uint32_t ObjCImplementationDecl::NumIvarInitializers(void) const {
  auto val = u.ObjCImplementationDecl->getNumIvarInitializers();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCImplementationDecl::SuperClass(void) const {
  auto val = u.ObjCImplementationDecl->getSuperClass();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCImplementationDecl::SuperClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCImplementationDecl::SuperClassToken(void) const {
  auto val = u.ObjCImplementationDecl->getSuperClassLoc();
  return ast->TokenAt(val);
}

bool ObjCImplementationDecl::HasDestructors(void) const {
  auto val = u.ObjCImplementationDecl->hasDestructors();
  return val;
}

bool ObjCImplementationDecl::HasNonZeroConstructors(void) const {
  auto val = u.ObjCImplementationDecl->hasNonZeroConstructors();
  return val;
}

// 0: ObjCImplementationDecl::Initializers
std::vector<::pasta::ObjCIvarDecl> ObjCImplementationDecl::InstanceVariables(void) const {
  auto val = u.ObjCImplementationDecl->ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
  }
  return ret;
}

ObjCInterfaceDecl::ObjCInterfaceDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

std::vector<::pasta::ObjCProtocolDecl> ObjCInterfaceDecl::AllReferencedProtocols(void) const {
  auto val = u.ObjCInterfaceDecl->all_referenced_protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

bool ObjCInterfaceDecl::DeclaresOrInheritsDesignatedInitializers(void) const {
  auto val = u.ObjCInterfaceDecl->declaresOrInheritsDesignatedInitializers();
  return val;
}

::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::CanonicalDecl(void) const {
  auto val = u.ObjCInterfaceDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCInterfaceDecl::CategoryListRaw(void) const {
  auto val = u.ObjCInterfaceDecl->getCategoryListRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::CategoryListRaw can return nullptr!");
  __builtin_unreachable();
}

// 2: CategoryMethod
::pasta::ObjCInterfaceDecl ObjCInterfaceDecl::Definition(void) const {
  auto val = u.ObjCInterfaceDecl->getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCInterfaceDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCInterfaceDecl::EndOfDefinitionToken(void) const {
  auto val = u.ObjCInterfaceDecl->getEndOfDefinitionLoc();
  return ast->TokenAt(val);
}

// 0: ObjCInterfaceDecl::ReferencedProtocols
::pasta::TokenRange ObjCInterfaceDecl::TokenRange(void) const {
  auto val = u.ObjCInterfaceDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: ObjCInterfaceDecl::SuperClassTInfo
// 0: ObjCInterfaceDecl::SuperClassType
// 0: ObjCInterfaceDecl::TypeForDecl
// 0: ObjCInterfaceDecl::TypeParamListAsWritten
bool ObjCInterfaceDecl::HasDefinition(void) const {
  auto val = u.ObjCInterfaceDecl->hasDefinition();
  return val;
}

bool ObjCInterfaceDecl::IsImplicitInterfaceDecl(void) const {
  auto val = u.ObjCInterfaceDecl->isImplicitInterfaceDecl();
  return val;
}

// 1: ObjCInterfaceDecl::IsSuperClassOf
bool ObjCInterfaceDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.ObjCInterfaceDecl->isThisDeclarationADefinition();
  return val;
}

std::vector<::pasta::ObjCIvarDecl> ObjCInterfaceDecl::InstanceVariables(void) const {
  auto val = u.ObjCInterfaceDecl->ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownCategories(void) const {
  auto val = u.ObjCInterfaceDecl->known_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::KnownExtensions(void) const {
  auto val = u.ObjCInterfaceDecl->known_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
  }
  return ret;
}

// 1: ObjCInterfaceDecl::LookupClassMethod
// 1: ObjCInterfaceDecl::LookupInstanceMethod
// 3: ObjCInterfaceDecl::LookupPropertyAccessor
std::vector<::pasta::Token> ObjCInterfaceDecl::ProtocolLocations(void) const {
  auto val = u.ObjCInterfaceDecl->protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCProtocolDecl> ObjCInterfaceDecl::Protocols(void) const {
  auto val = u.ObjCInterfaceDecl->protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleCategories(void) const {
  auto val = u.ObjCInterfaceDecl->visible_categories();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::ObjCCategoryDecl> ObjCInterfaceDecl::VisibleExtensions(void) const {
  auto val = u.ObjCInterfaceDecl->visible_extensions();
  std::vector<::pasta::ObjCCategoryDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, decl_ptr));
  }
  return ret;
}

ObjCMethodDecl::ObjCMethodDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(ast_, decl_) {}

::pasta::Token ObjCMethodDecl::BeginToken(void) const {
  auto val = u.ObjCMethodDecl->getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCMethodDecl::CanonicalDecl(void) const {
  auto val = u.ObjCMethodDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCMethodDecl::Category(void) const {
  auto val = u.ObjCMethodDecl->getCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::Category can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCInterfaceDecl ObjCMethodDecl::ClassInterface(void) const {
  auto val = u.ObjCMethodDecl->getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::ImplicitParamDecl ObjCMethodDecl::CmdDecl(void) const {
  auto val = u.ObjCMethodDecl->getCmdDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::CmdDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCMethodDecl::DeclaratorEndToken(void) const {
  auto val = u.ObjCMethodDecl->getDeclaratorEndLoc();
  return ast->TokenAt(val);
}

::pasta::ImplementationControl ObjCMethodDecl::ImplementationControl(void) const {
  auto val = u.ObjCMethodDecl->getImplementationControl();
  return static_cast<::pasta::ImplementationControl>(val);
}

uint32_t ObjCMethodDecl::NumSelectorLocs(void) const {
  auto val = u.ObjCMethodDecl->getNumSelectorLocs();
  return val;
}

// 0: ObjCMethodDecl::ObjCDeclQualifier
// 1: ObjCMethodDecl::ParamDecl
// 0: ObjCMethodDecl::ReturnType
// 0: ObjCMethodDecl::ReturnTypeSourceInfo
// 0: ObjCMethodDecl::Selector
// 1: ObjCMethodDecl::SelectorToken
::pasta::Token ObjCMethodDecl::SelectorStartToken(void) const {
  auto val = u.ObjCMethodDecl->getSelectorStartLoc();
  return ast->TokenAt(val);
}

::pasta::ImplicitParamDecl ObjCMethodDecl::SelfDecl(void) const {
  auto val = u.ObjCMethodDecl->getSelfDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "ObjCMethodDecl::SelfDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange ObjCMethodDecl::TokenRange(void) const {
  auto val = u.ObjCMethodDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ObjCMethodDecl::HasBody(void) const {
  auto val = u.ObjCMethodDecl->hasBody();
  return val;
}

bool ObjCMethodDecl::HasRedeclaration(void) const {
  auto val = u.ObjCMethodDecl->hasRedeclaration();
  return val;
}

bool ObjCMethodDecl::HasRelatedResultType(void) const {
  auto val = u.ObjCMethodDecl->hasRelatedResultType();
  return val;
}

bool ObjCMethodDecl::HasSkippedBody(void) const {
  auto val = u.ObjCMethodDecl->hasSkippedBody();
  return val;
}

bool ObjCMethodDecl::IsClassMethod(void) const {
  auto val = u.ObjCMethodDecl->isClassMethod();
  return val;
}

bool ObjCMethodDecl::IsDefined(void) const {
  auto val = u.ObjCMethodDecl->isDefined();
  return val;
}

bool ObjCMethodDecl::IsInstanceMethod(void) const {
  auto val = u.ObjCMethodDecl->isInstanceMethod();
  return val;
}

bool ObjCMethodDecl::IsOptional(void) const {
  auto val = u.ObjCMethodDecl->isOptional();
  return val;
}

bool ObjCMethodDecl::IsOverriding(void) const {
  auto val = u.ObjCMethodDecl->isOverriding();
  return val;
}

bool ObjCMethodDecl::IsPropertyAccessor(void) const {
  auto val = u.ObjCMethodDecl->isPropertyAccessor();
  return val;
}

bool ObjCMethodDecl::IsRedeclaration(void) const {
  auto val = u.ObjCMethodDecl->isRedeclaration();
  return val;
}

bool ObjCMethodDecl::IsSynthesizedAccessorStub(void) const {
  auto val = u.ObjCMethodDecl->isSynthesizedAccessorStub();
  return val;
}

bool ObjCMethodDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.ObjCMethodDecl->isThisDeclarationADefinition();
  return val;
}

bool ObjCMethodDecl::IsVariadic(void) const {
  auto val = u.ObjCMethodDecl->isVariadic();
  return val;
}

std::vector<::pasta::ParmVarDecl> ObjCMethodDecl::Parameters(void) const {
  auto val = u.ObjCMethodDecl->parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
  }
  return ret;
}

ObjCPropertyDecl::ObjCPropertyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

::pasta::Token ObjCPropertyDecl::AtToken(void) const {
  auto val = u.ObjCPropertyDecl->getAtLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCMethodDecl ObjCPropertyDecl::GetterMethodDecl(void) const {
  auto val = u.ObjCPropertyDecl->getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::GetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::GetterName
::pasta::Token ObjCPropertyDecl::GetterNameToken(void) const {
  auto val = u.ObjCPropertyDecl->getGetterNameLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCPropertyDecl::LParenToken(void) const {
  auto val = u.ObjCPropertyDecl->getLParenLoc();
  return ast->TokenAt(val);
}

// 0: ObjCPropertyDecl::PropertyAttributes
// 0: ObjCPropertyDecl::PropertyAttributesAsWritten
::pasta::PropertyControl ObjCPropertyDecl::PropertyImplementation(void) const {
  auto val = u.ObjCPropertyDecl->getPropertyImplementation();
  return static_cast<::pasta::PropertyControl>(val);
}

::pasta::ObjCIvarDecl ObjCPropertyDecl::PropertyIvarDecl(void) const {
  auto val = u.ObjCPropertyDecl->getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::PropertyIvarDecl can return nullptr!");
  __builtin_unreachable();
}

ObjCPropertyQueryKind ObjCPropertyDecl::QueryKind(void) const {
  auto val = u.ObjCPropertyDecl->getQueryKind();
  return static_cast<::pasta::ObjCPropertyQueryKind>(static_cast<unsigned char>(val));
}

::pasta::SetterKind ObjCPropertyDecl::SetterKind(void) const {
  auto val = u.ObjCPropertyDecl->getSetterKind();
  return static_cast<::pasta::SetterKind>(val);
}

::pasta::ObjCMethodDecl ObjCPropertyDecl::SetterMethodDecl(void) const {
  auto val = u.ObjCPropertyDecl->getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyDecl::SetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyDecl::SetterName
::pasta::Token ObjCPropertyDecl::SetterNameToken(void) const {
  auto val = u.ObjCPropertyDecl->getSetterNameLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange ObjCPropertyDecl::TokenRange(void) const {
  auto val = u.ObjCPropertyDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: ObjCPropertyDecl::Type
// 0: ObjCPropertyDecl::TypeSourceInfo
bool ObjCPropertyDecl::IsAtomic(void) const {
  auto val = u.ObjCPropertyDecl->isAtomic();
  return val;
}

bool ObjCPropertyDecl::IsClassProperty(void) const {
  auto val = u.ObjCPropertyDecl->isClassProperty();
  return val;
}

bool ObjCPropertyDecl::IsDirectProperty(void) const {
  auto val = u.ObjCPropertyDecl->isDirectProperty();
  return val;
}

bool ObjCPropertyDecl::IsInstanceProperty(void) const {
  auto val = u.ObjCPropertyDecl->isInstanceProperty();
  return val;
}

bool ObjCPropertyDecl::IsOptional(void) const {
  auto val = u.ObjCPropertyDecl->isOptional();
  return val;
}

bool ObjCPropertyDecl::IsReadOnly(void) const {
  auto val = u.ObjCPropertyDecl->isReadOnly();
  return val;
}

bool ObjCPropertyDecl::IsRetaining(void) const {
  auto val = u.ObjCPropertyDecl->isRetaining();
  return val;
}

ObjCPropertyImplDecl::ObjCPropertyImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

::pasta::Token ObjCPropertyImplDecl::BeginToken(void) const {
  auto val = u.ObjCPropertyImplDecl->getBeginLoc();
  return ast->TokenAt(val);
}

// 0: ObjCPropertyImplDecl::GetterCXXConstructor
::pasta::ObjCMethodDecl ObjCPropertyImplDecl::GetterMethodDecl(void) const {
  auto val = u.ObjCPropertyImplDecl->getGetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::GetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCPropertyDecl ObjCPropertyImplDecl::PropertyDecl(void) const {
  auto val = u.ObjCPropertyImplDecl->getPropertyDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCPropertyDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::PropertyDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCPropertyImplDecl::PropertyImplementation
::pasta::ObjCIvarDecl ObjCPropertyImplDecl::PropertyIvarDecl(void) const {
  auto val = u.ObjCPropertyImplDecl->getPropertyIvarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::PropertyIvarDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCPropertyImplDecl::PropertyIvarDeclToken(void) const {
  auto val = u.ObjCPropertyImplDecl->getPropertyIvarDeclLoc();
  return ast->TokenAt(val);
}

// 0: ObjCPropertyImplDecl::SetterCXXAssignment
::pasta::ObjCMethodDecl ObjCPropertyImplDecl::SetterMethodDecl(void) const {
  auto val = u.ObjCPropertyImplDecl->getSetterMethodDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCMethodDecl>(ast, val);
  }
  assert(false && "ObjCPropertyImplDecl::SetterMethodDecl can return nullptr!");
  __builtin_unreachable();
}

bool ObjCPropertyImplDecl::IsIvarNameSpecified(void) const {
  auto val = u.ObjCPropertyImplDecl->isIvarNameSpecified();
  return val;
}

ObjCProtocolDecl::ObjCProtocolDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

::pasta::ObjCProtocolDecl ObjCProtocolDecl::CanonicalDecl(void) const {
  auto val = u.ObjCProtocolDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  assert(false && "ObjCProtocolDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCProtocolDecl ObjCProtocolDecl::Definition(void) const {
  auto val = u.ObjCProtocolDecl->getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, val);
  }
  assert(false && "ObjCProtocolDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCProtocolDecl::ReferencedProtocols
::pasta::TokenRange ObjCProtocolDecl::TokenRange(void) const {
  auto val = u.ObjCProtocolDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ObjCProtocolDecl::HasDefinition(void) const {
  auto val = u.ObjCProtocolDecl->hasDefinition();
  return val;
}

bool ObjCProtocolDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.ObjCProtocolDecl->isThisDeclarationADefinition();
  return val;
}

// 1: ObjCProtocolDecl::LookupClassMethod
// 1: ObjCProtocolDecl::LookupInstanceMethod
std::vector<::pasta::Token> ObjCProtocolDecl::ProtocolLocations(void) const {
  auto val = u.ObjCProtocolDecl->protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCProtocolDecl> ObjCProtocolDecl::Protocols(void) const {
  auto val = u.ObjCProtocolDecl->protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

PragmaCommentDecl::PragmaCommentDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

std::string_view PragmaCommentDecl::Arg(void) const {
  auto val = u.PragmaCommentDecl->getArg();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

PragmaMSCommentKind PragmaCommentDecl::CommentKind(void) const {
  auto val = u.PragmaCommentDecl->getCommentKind();
  return static_cast<::pasta::PragmaMSCommentKind>(static_cast<unsigned int>(val));
}

PragmaDetectMismatchDecl::PragmaDetectMismatchDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

std::string_view PragmaDetectMismatchDecl::Name(void) const {
  auto val = u.PragmaDetectMismatchDecl->getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

std::string_view PragmaDetectMismatchDecl::Value(void) const {
  auto val = u.PragmaDetectMismatchDecl->getValue();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

RequiresExprBodyDecl::RequiresExprBodyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

StaticAssertDecl::StaticAssertDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

// 0: StaticAssertDecl::AssertExpr
// 0: StaticAssertDecl::Message
::pasta::Token StaticAssertDecl::RParenToken(void) const {
  auto val = u.StaticAssertDecl->getRParenLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange StaticAssertDecl::TokenRange(void) const {
  auto val = u.StaticAssertDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool StaticAssertDecl::IsFailed(void) const {
  auto val = u.StaticAssertDecl->isFailed();
  return val;
}

TemplateDecl::TemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, BuiltinTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, ConceptDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, RedeclarableTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, TemplateTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TemplateDecl, VarTemplateDecl)
::pasta::TokenRange TemplateDecl::TokenRange(void) const {
  auto val = u.TemplateDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: TemplateDecl::TemplateParameters
::pasta::NamedDecl TemplateDecl::TemplatedDecl(void) const {
  auto val = u.TemplateDecl->getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "TemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

TemplateTemplateParmDecl::TemplateTemplateParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

bool TemplateTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  auto val = u.TemplateTemplateParmDecl->defaultArgumentWasInherited();
  return val;
}

// 0: TemplateTemplateParmDecl::DefaultArgStorage
// 0: TemplateTemplateParmDecl::DefaultArgument
// 1: TemplateTemplateParmDecl::ExpansionTemplateParameters
uint32_t TemplateTemplateParmDecl::NumExpansionTemplateParameters(void) const {
  auto val = u.TemplateTemplateParmDecl->getNumExpansionTemplateParameters();
  return val;
}

::pasta::TokenRange TemplateTemplateParmDecl::TokenRange(void) const {
  auto val = u.TemplateTemplateParmDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool TemplateTemplateParmDecl::HasDefaultArgument(void) const {
  auto val = u.TemplateTemplateParmDecl->hasDefaultArgument();
  return val;
}

bool TemplateTemplateParmDecl::IsExpandedParameterPack(void) const {
  auto val = u.TemplateTemplateParmDecl->isExpandedParameterPack();
  return val;
}

bool TemplateTemplateParmDecl::IsPackExpansion(void) const {
  auto val = u.TemplateTemplateParmDecl->isPackExpansion();
  return val;
}

bool TemplateTemplateParmDecl::IsParameterPack(void) const {
  auto val = u.TemplateTemplateParmDecl->isParameterPack();
  return val;
}

TranslationUnitDecl::TranslationUnitDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

// 0: TranslationUnitDecl::ASTContext
::pasta::NamespaceDecl TranslationUnitDecl::AnonymousNamespace(void) const {
  auto val = u.TranslationUnitDecl->getAnonymousNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "TranslationUnitDecl::AnonymousNamespace can return nullptr!");
  __builtin_unreachable();
}

TypeDecl::TypeDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, RecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TagDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TemplateTypeParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TypedefDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, TypedefNameDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypeDecl, UnresolvedUsingTypenameDecl)
::pasta::Token TypeDecl::BeginToken(void) const {
  auto val = u.TypeDecl->getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange TypeDecl::TokenRange(void) const {
  auto val = u.TypeDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: TypeDecl::TypeForDecl
TypedefNameDecl::TypedefNameDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(TypedefNameDecl, ObjCTypeParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypedefNameDecl, TypeAliasDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TypedefNameDecl, TypedefDecl)
::pasta::TypedefNameDecl TypedefNameDecl::CanonicalDecl(void) const {
  auto val = u.TypedefNameDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  assert(false && "TypedefNameDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: TypedefNameDecl::TypeSourceInfo
// 0: TypedefNameDecl::UnderlyingType
bool TypedefNameDecl::IsModed(void) const {
  auto val = u.TypedefNameDecl->isModed();
  return val;
}

bool TypedefNameDecl::IsTransparentTag(void) const {
  auto val = u.TypedefNameDecl->isTransparentTag();
  return val;
}

UnresolvedUsingTypenameDecl::UnresolvedUsingTypenameDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

::pasta::UnresolvedUsingTypenameDecl UnresolvedUsingTypenameDecl::CanonicalDecl(void) const {
  auto val = u.UnresolvedUsingTypenameDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingTypenameDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingTypenameDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UnresolvedUsingTypenameDecl::EllipsisToken(void) const {
  auto val = u.UnresolvedUsingTypenameDecl->getEllipsisLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedUsingTypenameDecl::NameInfo
// 0: UnresolvedUsingTypenameDecl::Qualifier
// 0: UnresolvedUsingTypenameDecl::QualifierToken
::pasta::Token UnresolvedUsingTypenameDecl::TypenameToken(void) const {
  auto val = u.UnresolvedUsingTypenameDecl->getTypenameLoc();
  return ast->TokenAt(val);
}

::pasta::Token UnresolvedUsingTypenameDecl::UsingToken(void) const {
  auto val = u.UnresolvedUsingTypenameDecl->getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingTypenameDecl::IsPackExpansion(void) const {
  auto val = u.UnresolvedUsingTypenameDecl->isPackExpansion();
  return val;
}

UsingDecl::UsingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

::pasta::UsingDecl UsingDecl::CanonicalDecl(void) const {
  auto val = u.UsingDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingDecl>(ast, val);
  }
  assert(false && "UsingDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: UsingDecl::NameInfo
// 0: UsingDecl::Qualifier
// 0: UsingDecl::QualifierToken
::pasta::Token UsingDecl::UsingToken(void) const {
  auto val = u.UsingDecl->getUsingLoc();
  return ast->TokenAt(val);
}

bool UsingDecl::HasTypename(void) const {
  auto val = u.UsingDecl->hasTypename();
  return val;
}

bool UsingDecl::IsAccessDeclaration(void) const {
  auto val = u.UsingDecl->isAccessDeclaration();
  return val;
}

std::vector<::pasta::UsingShadowDecl> UsingDecl::Shadows(void) const {
  auto val = u.UsingDecl->shadows();
  std::vector<::pasta::UsingShadowDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, decl_ptr));
  }
  return ret;
}

UsingDirectiveDecl::UsingDirectiveDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

::pasta::DeclContext UsingDirectiveDecl::CommonAncestor(void) const {
  auto val = u.UsingDirectiveDecl->getCommonAncestor();
  if (val) {
    return ::pasta::DeclContext(ast, val);
  }
  assert(false && "UsingDirectiveDecl::CommonAncestor can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UsingDirectiveDecl::IdentLocation(void) const {
  auto val = u.UsingDirectiveDecl->getIdentLocation();
  return ast->TokenAt(val);
}

::pasta::Token UsingDirectiveDecl::NamespaceKeyLocation(void) const {
  auto val = u.UsingDirectiveDecl->getNamespaceKeyLocation();
  return ast->TokenAt(val);
}

::pasta::NamespaceDecl UsingDirectiveDecl::NominatedNamespace(void) const {
  auto val = u.UsingDirectiveDecl->getNominatedNamespace();
  if (val) {
    return DeclBuilder::Create<::pasta::NamespaceDecl>(ast, val);
  }
  assert(false && "UsingDirectiveDecl::NominatedNamespace can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingDirectiveDecl::NominatedNamespaceAsWritten(void) const {
  auto val = u.UsingDirectiveDecl->getNominatedNamespaceAsWritten();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingDirectiveDecl::NominatedNamespaceAsWritten can return nullptr!");
  __builtin_unreachable();
}

// 0: UsingDirectiveDecl::Qualifier
// 0: UsingDirectiveDecl::QualifierToken
::pasta::TokenRange UsingDirectiveDecl::TokenRange(void) const {
  auto val = u.UsingDirectiveDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::Token UsingDirectiveDecl::UsingToken(void) const {
  auto val = u.UsingDirectiveDecl->getUsingLoc();
  return ast->TokenAt(val);
}

UsingPackDecl::UsingPackDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

std::vector<::pasta::NamedDecl> UsingPackDecl::Expansions(void) const {
  auto val = u.UsingPackDecl->expansions();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::UsingPackDecl UsingPackDecl::CanonicalDecl(void) const {
  auto val = u.UsingPackDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingPackDecl>(ast, val);
  }
  assert(false && "UsingPackDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingPackDecl::InstantiatedFromUsingDecl(void) const {
  auto val = u.UsingPackDecl->getInstantiatedFromUsingDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingPackDecl::InstantiatedFromUsingDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TokenRange UsingPackDecl::TokenRange(void) const {
  auto val = u.UsingPackDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

UsingShadowDecl::UsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(UsingShadowDecl, ConstructorUsingShadowDecl)
::pasta::UsingShadowDecl UsingShadowDecl::CanonicalDecl(void) const {
  auto val = u.UsingShadowDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::UsingShadowDecl UsingShadowDecl::NextUsingShadowDecl(void) const {
  auto val = u.UsingShadowDecl->getNextUsingShadowDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UsingShadowDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::NextUsingShadowDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::NamedDecl UsingShadowDecl::TargetDecl(void) const {
  auto val = u.UsingShadowDecl->getTargetDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::NamedDecl>(ast, val);
  }
  assert(false && "UsingShadowDecl::TargetDecl can return nullptr!");
  __builtin_unreachable();
}

ValueDecl::ValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, BindingDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, DeclaratorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, EnumConstantDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, IndirectFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, MSGuidDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPDeclarativeDirectiveValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPDeclareMapperDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, OMPDeclareReductionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, TemplateParamObjectDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, UnresolvedUsingValueDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(ValueDecl, VarTemplateSpecializationDecl)
// 0: ValueDecl::Type
OMPDeclarativeDirectiveDecl::OMPDeclarativeDirectiveDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPAllocateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPRequiresDecl)
PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveDecl, OMPThreadPrivateDecl)
OMPDeclarativeDirectiveValueDecl::OMPDeclarativeDirectiveValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(OMPDeclarativeDirectiveValueDecl, OMPDeclareMapperDecl)
AccessSpecDecl::AccessSpecDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

::pasta::Token AccessSpecDecl::AccessSpecifierToken(void) const {
  auto val = u.AccessSpecDecl->getAccessSpecifierLoc();
  return ast->TokenAt(val);
}

::pasta::Token AccessSpecDecl::ColonToken(void) const {
  auto val = u.AccessSpecDecl->getColonLoc();
  return ast->TokenAt(val);
}

::pasta::TokenRange AccessSpecDecl::TokenRange(void) const {
  auto val = u.AccessSpecDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

BindingDecl::BindingDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

// 0: BindingDecl::Binding
BlockDecl::BlockDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

bool BlockDecl::BlockMissingReturnType(void) const {
  auto val = u.BlockDecl->blockMissingReturnType();
  return val;
}

bool BlockDecl::CanAvoidCopyToHeap(void) const {
  auto val = u.BlockDecl->canAvoidCopyToHeap();
  return val;
}

// 0: BlockDecl::Captures
bool BlockDecl::CapturesCXXThis(void) const {
  auto val = u.BlockDecl->capturesCXXThis();
  return val;
}

bool BlockDecl::DoesNotEscape(void) const {
  auto val = u.BlockDecl->doesNotEscape();
  return val;
}

::pasta::Decl BlockDecl::BlockManglingContextDecl(void) const {
  auto val = u.BlockDecl->getBlockManglingContextDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::Decl>(ast, val);
  }
  assert(false && "BlockDecl::BlockManglingContextDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t BlockDecl::BlockManglingNumber(void) const {
  auto val = u.BlockDecl->getBlockManglingNumber();
  return val;
}

// 0: BlockDecl::Body
::pasta::Token BlockDecl::CaretLocation(void) const {
  auto val = u.BlockDecl->getCaretLocation();
  return ast->TokenAt(val);
}

// 0: BlockDecl::CompoundBody
uint32_t BlockDecl::NumCaptures(void) const {
  auto val = u.BlockDecl->getNumCaptures();
  return val;
}

uint32_t BlockDecl::NumParams(void) const {
  auto val = u.BlockDecl->getNumParams();
  return val;
}

// 1: BlockDecl::ParamDecl
// 0: BlockDecl::SignatureAsWritten
bool BlockDecl::HasCaptures(void) const {
  auto val = u.BlockDecl->hasCaptures();
  return val;
}

bool BlockDecl::IsConversionFromLambda(void) const {
  auto val = u.BlockDecl->isConversionFromLambda();
  return val;
}

bool BlockDecl::IsVariadic(void) const {
  auto val = u.BlockDecl->isVariadic();
  return val;
}

std::vector<::pasta::ParmVarDecl> BlockDecl::Parameters(void) const {
  auto val = u.BlockDecl->parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
  }
  return ret;
}

BuiltinTemplateDecl::BuiltinTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

// 0: BuiltinTemplateDecl::BuiltinTemplateKind
::pasta::TokenRange BuiltinTemplateDecl::TokenRange(void) const {
  auto val = u.BuiltinTemplateDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

CapturedDecl::CapturedDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(ast_, decl_) {}

::pasta::ImplicitParamDecl CapturedDecl::ContextParam(void) const {
  auto val = u.CapturedDecl->getContextParam();
  if (val) {
    return DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, val);
  }
  assert(false && "CapturedDecl::ContextParam can return nullptr!");
  __builtin_unreachable();
}

uint32_t CapturedDecl::ContextParamPosition(void) const {
  auto val = u.CapturedDecl->getContextParamPosition();
  return val;
}

uint32_t CapturedDecl::NumParams(void) const {
  auto val = u.CapturedDecl->getNumParams();
  return val;
}

// 1: CapturedDecl::Param
std::vector<::pasta::ImplicitParamDecl> CapturedDecl::Parameters(void) const {
  auto val = u.CapturedDecl->parameters();
  std::vector<::pasta::ImplicitParamDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ImplicitParamDecl>(ast, decl_ptr));
  }
  return ret;
}

ClassScopeFunctionSpecializationDecl::ClassScopeFunctionSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : Decl(std::move(ast_), decl_) {}

::pasta::CXXMethodDecl ClassScopeFunctionSpecializationDecl::Specialization(void) const {
  auto val = u.ClassScopeFunctionSpecializationDecl->getSpecialization();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "ClassScopeFunctionSpecializationDecl::Specialization can return nullptr!");
  __builtin_unreachable();
}

// 0: ClassScopeFunctionSpecializationDecl::TemplateArgsAsWritten
bool ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArgs(void) const {
  auto val = u.ClassScopeFunctionSpecializationDecl->hasExplicitTemplateArgs();
  return val;
}

ConceptDecl::ConceptDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

::pasta::ConceptDecl ConceptDecl::CanonicalDecl(void) const {
  auto val = u.ConceptDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConceptDecl>(ast, val);
  }
  assert(false && "ConceptDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: ConceptDecl::ConstraintExpr
::pasta::TokenRange ConceptDecl::TokenRange(void) const {
  auto val = u.ConceptDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

bool ConceptDecl::IsTypeConcept(void) const {
  auto val = u.ConceptDecl->isTypeConcept();
  return val;
}

ConstructorUsingShadowDecl::ConstructorUsingShadowDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : UsingShadowDecl(std::move(ast_), decl_) {}

bool ConstructorUsingShadowDecl::ConstructsVirtualBase(void) const {
  auto val = u.ConstructorUsingShadowDecl->constructsVirtualBase();
  return val;
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::ConstructedBaseClass(void) const {
  auto val = u.ConstructorUsingShadowDecl->getConstructedBaseClass();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::ConstructedBaseClass can return nullptr!");
  __builtin_unreachable();
}

::pasta::ConstructorUsingShadowDecl ConstructorUsingShadowDecl::ConstructedBaseClassShadowDecl(void) const {
  auto val = u.ConstructorUsingShadowDecl->getConstructedBaseClassShadowDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::ConstructedBaseClassShadowDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ConstructorUsingShadowDecl ConstructorUsingShadowDecl::NominatedBaseClassShadowDecl(void) const {
  auto val = u.ConstructorUsingShadowDecl->getNominatedBaseClassShadowDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ConstructorUsingShadowDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::NominatedBaseClassShadowDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ConstructorUsingShadowDecl::Parent(void) const {
  auto val = u.ConstructorUsingShadowDecl->getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ConstructorUsingShadowDecl::Parent can return nullptr!");
  __builtin_unreachable();
}

DeclaratorDecl::DeclaratorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, CXXMethodDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, FieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, FunctionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, MSPropertyDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, NonTypeTemplateParmDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ObjCIvarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, VarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(DeclaratorDecl, VarTemplateSpecializationDecl)
::pasta::Token DeclaratorDecl::BeginToken(void) const {
  auto val = u.DeclaratorDecl->getBeginLoc();
  return ast->TokenAt(val);
}

::pasta::Token DeclaratorDecl::InnerLocStart(void) const {
  auto val = u.DeclaratorDecl->getInnerLocStart();
  return ast->TokenAt(val);
}

uint32_t DeclaratorDecl::NumTemplateParameterLists(void) const {
  auto val = u.DeclaratorDecl->getNumTemplateParameterLists();
  return val;
}

// 0: DeclaratorDecl::Qualifier
// 0: DeclaratorDecl::QualifierToken
// 1: DeclaratorDecl::TemplateParameterList
// 0: DeclaratorDecl::TrailingRequiresClause
// 0: DeclaratorDecl::TypeSourceInfo
EnumConstantDecl::EnumConstantDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

::pasta::EnumConstantDecl EnumConstantDecl::CanonicalDecl(void) const {
  auto val = u.EnumConstantDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, val);
  }
  assert(false && "EnumConstantDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: EnumConstantDecl::InitExpr
// 0: EnumConstantDecl::InitVal
FieldDecl::FieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(FieldDecl, ObjCAtDefsFieldDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FieldDecl, ObjCIvarDecl)
// 0: FieldDecl::BitWidth
::pasta::FieldDecl FieldDecl::CanonicalDecl(void) const {
  auto val = u.FieldDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "FieldDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: FieldDecl::CapturedVLAType
InClassInitStyle FieldDecl::InClassInitStyle(void) const {
  auto val = u.FieldDecl->getInClassInitStyle();
  return static_cast<::pasta::InClassInitStyle>(static_cast<unsigned int>(val));
}

// 0: FieldDecl::InClassInitializer
::pasta::RecordDecl FieldDecl::Parent(void) const {
  auto val = u.FieldDecl->getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "FieldDecl::Parent can return nullptr!");
  __builtin_unreachable();
}

bool FieldDecl::HasCapturedVLAType(void) const {
  auto val = u.FieldDecl->hasCapturedVLAType();
  return val;
}

bool FieldDecl::HasInClassInitializer(void) const {
  auto val = u.FieldDecl->hasInClassInitializer();
  return val;
}

bool FieldDecl::IsBitField(void) const {
  auto val = u.FieldDecl->isBitField();
  return val;
}

bool FieldDecl::IsMutable(void) const {
  auto val = u.FieldDecl->isMutable();
  return val;
}

bool FieldDecl::IsUnnamedBitfield(void) const {
  auto val = u.FieldDecl->isUnnamedBitfield();
  return val;
}

FunctionDecl::FunctionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(ast_, decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXDeductionGuideDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXDestructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(FunctionDecl, CXXMethodDecl)
bool FunctionDecl::DoesThisDeclarationHaveABody(void) const {
  auto val = u.FunctionDecl->doesThisDeclarationHaveABody();
  return val;
}

// 1: FunctionDecl::AssociatedConstraints
// 0: FunctionDecl::Body
// 0: FunctionDecl::CallResultType
::pasta::FunctionDecl FunctionDecl::CanonicalDecl(void) const {
  auto val = u.FunctionDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

ConstexprSpecKind FunctionDecl::ConstexprKind(void) const {
  auto val = u.FunctionDecl->getConstexprKind();
  return static_cast<::pasta::ConstexprSpecKind>(static_cast<int>(val));
}

// 0: FunctionDecl::DeclaredReturnType
::pasta::FunctionDecl FunctionDecl::Definition(void) const {
  auto val = u.FunctionDecl->getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token FunctionDecl::EllipsisToken(void) const {
  auto val = u.FunctionDecl->getEllipsisLoc();
  return ast->TokenAt(val);
}

ExceptionSpecificationType FunctionDecl::ExceptionSpecType(void) const {
  auto val = u.FunctionDecl->getExceptionSpecType();
  return static_cast<::pasta::ExceptionSpecificationType>(static_cast<unsigned int>(val));
}

// 0: FunctionDecl::NameInfo
// 1: FunctionDecl::ParamDecl
// 0: FunctionDecl::ReturnType
StorageClass FunctionDecl::StorageClass(void) const {
  auto val = u.FunctionDecl->getStorageClass();
  return static_cast<::pasta::StorageClass>(static_cast<unsigned int>(val));
}

bool FunctionDecl::HasBody(void) const {
  auto val = u.FunctionDecl->hasBody();
  return val;
}

bool FunctionDecl::HasImplicitReturnZero(void) const {
  auto val = u.FunctionDecl->hasImplicitReturnZero();
  return val;
}

bool FunctionDecl::HasInheritedPrototype(void) const {
  auto val = u.FunctionDecl->hasInheritedPrototype();
  return val;
}

bool FunctionDecl::HasPrototype(void) const {
  auto val = u.FunctionDecl->hasPrototype();
  return val;
}

bool FunctionDecl::HasSkippedBody(void) const {
  auto val = u.FunctionDecl->hasSkippedBody();
  return val;
}

bool FunctionDecl::HasWrittenPrototype(void) const {
  auto val = u.FunctionDecl->hasWrittenPrototype();
  return val;
}

bool FunctionDecl::InstantiationIsPending(void) const {
  auto val = u.FunctionDecl->instantiationIsPending();
  return val;
}

bool FunctionDecl::IsConsteval(void) const {
  auto val = u.FunctionDecl->isConsteval();
  return val;
}

bool FunctionDecl::IsConstexpr(void) const {
  auto val = u.FunctionDecl->isConstexpr();
  return val;
}

bool FunctionDecl::IsConstexprSpecified(void) const {
  auto val = u.FunctionDecl->isConstexprSpecified();
  return val;
}

bool FunctionDecl::IsDefaulted(void) const {
  auto val = u.FunctionDecl->isDefaulted();
  return val;
}

bool FunctionDecl::IsDefined(void) const {
  auto val = u.FunctionDecl->isDefined();
  return val;
}

bool FunctionDecl::IsDeleted(void) const {
  auto val = u.FunctionDecl->isDeleted();
  return val;
}

bool FunctionDecl::IsDeletedAsWritten(void) const {
  auto val = u.FunctionDecl->isDeletedAsWritten();
  return val;
}

bool FunctionDecl::IsExplicitlyDefaulted(void) const {
  auto val = u.FunctionDecl->isExplicitlyDefaulted();
  return val;
}

bool FunctionDecl::IsFunctionTemplateSpecialization(void) const {
  auto val = u.FunctionDecl->isFunctionTemplateSpecialization();
  return val;
}

bool FunctionDecl::IsInlineSpecified(void) const {
  auto val = u.FunctionDecl->isInlineSpecified();
  return val;
}

bool FunctionDecl::IsInlined(void) const {
  auto val = u.FunctionDecl->isInlined();
  return val;
}

bool FunctionDecl::IsLateTemplateParsed(void) const {
  auto val = u.FunctionDecl->isLateTemplateParsed();
  return val;
}

bool FunctionDecl::IsMultiVersion(void) const {
  auto val = u.FunctionDecl->isMultiVersion();
  return val;
}

bool FunctionDecl::IsOverloadedOperator(void) const {
  auto val = u.FunctionDecl->isOverloadedOperator();
  return val;
}

bool FunctionDecl::IsPure(void) const {
  auto val = u.FunctionDecl->isPure();
  return val;
}

bool FunctionDecl::IsStatic(void) const {
  auto val = u.FunctionDecl->isStatic();
  return val;
}

bool FunctionDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.FunctionDecl->isThisDeclarationADefinition();
  return val;
}

bool FunctionDecl::IsTrivial(void) const {
  auto val = u.FunctionDecl->isTrivial();
  return val;
}

bool FunctionDecl::IsTrivialForCall(void) const {
  auto val = u.FunctionDecl->isTrivialForCall();
  return val;
}

bool FunctionDecl::IsUserProvided(void) const {
  auto val = u.FunctionDecl->isUserProvided();
  return val;
}

bool FunctionDecl::IsVirtualAsWritten(void) const {
  auto val = u.FunctionDecl->isVirtualAsWritten();
  return val;
}

std::vector<::pasta::ParmVarDecl> FunctionDecl::Parameters(void) const {
  auto val = u.FunctionDecl->parameters();
  std::vector<::pasta::ParmVarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ParmVarDecl>(ast, decl_ptr));
  }
  return ret;
}

bool FunctionDecl::UsesSEHTry(void) const {
  auto val = u.FunctionDecl->usesSEHTry();
  return val;
}

bool FunctionDecl::WillHaveBody(void) const {
  auto val = u.FunctionDecl->willHaveBody();
  return val;
}

IndirectFieldDecl::IndirectFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

std::vector<::pasta::NamedDecl> IndirectFieldDecl::Chain(void) const {
  auto val = u.IndirectFieldDecl->chain();
  std::vector<::pasta::NamedDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::NamedDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::FieldDecl IndirectFieldDecl::AnonField(void) const {
  auto val = u.IndirectFieldDecl->getAnonField();
  if (val) {
    return DeclBuilder::Create<::pasta::FieldDecl>(ast, val);
  }
  assert(false && "IndirectFieldDecl::AnonField can return nullptr!");
  __builtin_unreachable();
}

::pasta::IndirectFieldDecl IndirectFieldDecl::CanonicalDecl(void) const {
  auto val = u.IndirectFieldDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::IndirectFieldDecl>(ast, val);
  }
  assert(false && "IndirectFieldDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t IndirectFieldDecl::ChainingSize(void) const {
  auto val = u.IndirectFieldDecl->getChainingSize();
  return val;
}

::pasta::VarDecl IndirectFieldDecl::VarDecl(void) const {
  auto val = u.IndirectFieldDecl->getVarDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "IndirectFieldDecl::VarDecl can return nullptr!");
  __builtin_unreachable();
}

LabelDecl::LabelDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : NamedDecl(std::move(ast_), decl_) {}

std::string_view LabelDecl::MSAsmLabel(void) const {
  auto val = u.LabelDecl->getMSAsmLabel();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

::pasta::TokenRange LabelDecl::TokenRange(void) const {
  auto val = u.LabelDecl->getSourceRange();
  return ast->TokenRangeFrom(val);
}

// 0: LabelDecl::Stmt
bool LabelDecl::IsGnuLocal(void) const {
  auto val = u.LabelDecl->isGnuLocal();
  return val;
}

bool LabelDecl::IsMSAsmLabel(void) const {
  auto val = u.LabelDecl->isMSAsmLabel();
  return val;
}

bool LabelDecl::IsResolvedMSAsmLabel(void) const {
  auto val = u.LabelDecl->isResolvedMSAsmLabel();
  return val;
}

MSGuidDecl::MSGuidDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

// 0: MSGuidDecl::Parts
MSPropertyDecl::MSPropertyDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

// 0: MSPropertyDecl::GetterId
// 0: MSPropertyDecl::SetterId
bool MSPropertyDecl::HasGetter(void) const {
  auto val = u.MSPropertyDecl->hasGetter();
  return val;
}

bool MSPropertyDecl::HasSetter(void) const {
  auto val = u.MSPropertyDecl->hasSetter();
  return val;
}

NonTypeTemplateParmDecl::NonTypeTemplateParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

bool NonTypeTemplateParmDecl::DefaultArgumentWasInherited(void) const {
  auto val = u.NonTypeTemplateParmDecl->defaultArgumentWasInherited();
  return val;
}

// 1: NonTypeTemplateParmDecl::AssociatedConstraints
// 0: NonTypeTemplateParmDecl::DefaultArgStorage
// 0: NonTypeTemplateParmDecl::DefaultArgument
// 1: NonTypeTemplateParmDecl::ExpansionType
// 1: NonTypeTemplateParmDecl::ExpansionTypeSourceInfo
uint32_t NonTypeTemplateParmDecl::NumExpansionTypes(void) const {
  auto val = u.NonTypeTemplateParmDecl->getNumExpansionTypes();
  return val;
}

// 0: NonTypeTemplateParmDecl::PlaceholderTypeConstraint
bool NonTypeTemplateParmDecl::HasDefaultArgument(void) const {
  auto val = u.NonTypeTemplateParmDecl->hasDefaultArgument();
  return val;
}

bool NonTypeTemplateParmDecl::HasPlaceholderTypeConstraint(void) const {
  auto val = u.NonTypeTemplateParmDecl->hasPlaceholderTypeConstraint();
  return val;
}

bool NonTypeTemplateParmDecl::IsExpandedParameterPack(void) const {
  auto val = u.NonTypeTemplateParmDecl->isExpandedParameterPack();
  return val;
}

bool NonTypeTemplateParmDecl::IsPackExpansion(void) const {
  auto val = u.NonTypeTemplateParmDecl->isPackExpansion();
  return val;
}

bool NonTypeTemplateParmDecl::IsParameterPack(void) const {
  auto val = u.NonTypeTemplateParmDecl->isParameterPack();
  return val;
}

OMPAllocateDecl::OMPAllocateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveDecl(std::move(ast_), decl_) {}

// 0: OMPAllocateDecl::Clauses
// 0: OMPAllocateDecl::Varlists
OMPDeclareMapperDecl::OMPDeclareMapperDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveValueDecl(ast_, decl_) {}

// 0: OMPDeclareMapperDecl::Clauses
// 0: OMPDeclareMapperDecl::MapperVarRef
OMPDeclareReductionDecl::OMPDeclareReductionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(ast_, decl_) {}

// 0: OMPDeclareReductionDecl::Combiner
// 0: OMPDeclareReductionDecl::CombinerIn
// 0: OMPDeclareReductionDecl::CombinerOut
// 0: OMPDeclareReductionDecl::InitOrig
// 0: OMPDeclareReductionDecl::InitPriv
// 0: OMPDeclareReductionDecl::Initializer
// 0: OMPDeclareReductionDecl::InitializerKind
OMPRequiresDecl::OMPRequiresDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveDecl(std::move(ast_), decl_) {}

// 0: OMPRequiresDecl::Clauses
OMPThreadPrivateDecl::OMPThreadPrivateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : OMPDeclarativeDirectiveDecl(std::move(ast_), decl_) {}

// 0: OMPThreadPrivateDecl::Varlists
ObjCAtDefsFieldDecl::ObjCAtDefsFieldDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FieldDecl(std::move(ast_), decl_) {}

ObjCCategoryDecl::ObjCCategoryDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCContainerDecl(std::move(ast_), decl_) {}

bool ObjCCategoryDecl::IsClassExtension(void) const {
  auto val = u.ObjCCategoryDecl->IsClassExtension();
  return val;
}

::pasta::Token ObjCCategoryDecl::CategoryNameToken(void) const {
  auto val = u.ObjCCategoryDecl->getCategoryNameLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCInterfaceDecl ObjCCategoryDecl::ClassInterface(void) const {
  auto val = u.ObjCCategoryDecl->getClassInterface();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCInterfaceDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::ClassInterface can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token ObjCCategoryDecl::IvarLBraceToken(void) const {
  auto val = u.ObjCCategoryDecl->getIvarLBraceLoc();
  return ast->TokenAt(val);
}

::pasta::Token ObjCCategoryDecl::IvarRBraceToken(void) const {
  auto val = u.ObjCCategoryDecl->getIvarRBraceLoc();
  return ast->TokenAt(val);
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategory(void) const {
  auto val = u.ObjCCategoryDecl->getNextClassCategory();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::NextClassCategory can return nullptr!");
  __builtin_unreachable();
}

::pasta::ObjCCategoryDecl ObjCCategoryDecl::NextClassCategoryRaw(void) const {
  auto val = u.ObjCCategoryDecl->getNextClassCategoryRaw();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCCategoryDecl>(ast, val);
  }
  assert(false && "ObjCCategoryDecl::NextClassCategoryRaw can return nullptr!");
  __builtin_unreachable();
}

// 0: ObjCCategoryDecl::ReferencedProtocols
// 0: ObjCCategoryDecl::TypeParamList
std::vector<::pasta::ObjCIvarDecl> ObjCCategoryDecl::InstanceVariables(void) const {
  auto val = u.ObjCCategoryDecl->ivars();
  std::vector<::pasta::ObjCIvarDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, decl_ptr));
  }
  return ret;
}

std::vector<::pasta::Token> ObjCCategoryDecl::ProtocolLocations(void) const {
  auto val = u.ObjCCategoryDecl->protocol_locs();
  std::vector<::pasta::Token> ret;
  for (auto loc : val) {
    if (auto tok = ast->TokenAt(loc); tok) {
      ret.emplace_back(std::move(tok));
    }
  }
  return ret;
}

std::vector<::pasta::ObjCProtocolDecl> ObjCCategoryDecl::Protocols(void) const {
  auto val = u.ObjCCategoryDecl->protocols();
  std::vector<::pasta::ObjCProtocolDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ObjCProtocolDecl>(ast, decl_ptr));
  }
  return ret;
}

ObjCCategoryImplDecl::ObjCCategoryImplDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ObjCImplDecl(std::move(ast_), decl_) {}

::pasta::Token ObjCCategoryImplDecl::CategoryNameToken(void) const {
  auto val = u.ObjCCategoryImplDecl->getCategoryNameLoc();
  return ast->TokenAt(val);
}

ObjCIvarDecl::ObjCIvarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FieldDecl(std::move(ast_), decl_) {}

// 0: ObjCIvarDecl::AccessControl
// 0: ObjCIvarDecl::CanonicalAccessControl
::pasta::ObjCIvarDecl ObjCIvarDecl::NextIvar(void) const {
  auto val = u.ObjCIvarDecl->getNextIvar();
  if (val) {
    return DeclBuilder::Create<::pasta::ObjCIvarDecl>(ast, val);
  }
  assert(false && "ObjCIvarDecl::NextIvar can return nullptr!");
  __builtin_unreachable();
}

bool ObjCIvarDecl::Synthesize(void) const {
  auto val = u.ObjCIvarDecl->getSynthesize();
  return val;
}

ObjCTypeParamDecl::ObjCTypeParamDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

::pasta::Token ObjCTypeParamDecl::ColonToken(void) const {
  auto val = u.ObjCTypeParamDecl->getColonLoc();
  return ast->TokenAt(val);
}

uint32_t ObjCTypeParamDecl::Index(void) const {
  auto val = u.ObjCTypeParamDecl->getIndex();
  return val;
}

ObjCTypeParamVariance ObjCTypeParamDecl::Variance(void) const {
  auto val = u.ObjCTypeParamDecl->getVariance();
  return static_cast<::pasta::ObjCTypeParamVariance>(static_cast<unsigned char>(val));
}

::pasta::Token ObjCTypeParamDecl::VarianceToken(void) const {
  auto val = u.ObjCTypeParamDecl->getVarianceLoc();
  return ast->TokenAt(val);
}

bool ObjCTypeParamDecl::HasExplicitBound(void) const {
  auto val = u.ObjCTypeParamDecl->hasExplicitBound();
  return val;
}

RedeclarableTemplateDecl::RedeclarableTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TemplateDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, ClassTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, FunctionTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, TypeAliasTemplateDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RedeclarableTemplateDecl, VarTemplateDecl)
::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::CanonicalDecl(void) const {
  auto val = u.RedeclarableTemplateDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  assert(false && "RedeclarableTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::RedeclarableTemplateDecl RedeclarableTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto val = u.RedeclarableTemplateDecl->getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::RedeclarableTemplateDecl>(ast, val);
  }
  assert(false && "RedeclarableTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

bool RedeclarableTemplateDecl::IsMemberSpecialization(void) const {
  auto val = u.RedeclarableTemplateDecl->isMemberSpecialization();
  return val;
}

TagDecl::TagDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(ast_, decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, ClassTemplateSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, EnumDecl)
PASTA_DEFINE_DERIVED_OPERATORS(TagDecl, RecordDecl)
::pasta::TokenRange TagDecl::BraceRange(void) const {
  auto val = u.TagDecl->getBraceRange();
  return ast->TokenRangeFrom(val);
}

::pasta::TagDecl TagDecl::CanonicalDecl(void) const {
  auto val = u.TagDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TagDecl>(ast, val);
  }
  assert(false && "TagDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token TagDecl::InnerLocStart(void) const {
  auto val = u.TagDecl->getInnerLocStart();
  return ast->TokenAt(val);
}

std::string_view TagDecl::KindName(void) const {
  auto val = u.TagDecl->getKindName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return std::string_view();
  }
}

uint32_t TagDecl::NumTemplateParameterLists(void) const {
  auto val = u.TagDecl->getNumTemplateParameterLists();
  return val;
}

// 0: TagDecl::Qualifier
// 0: TagDecl::QualifierToken
TagTypeKind TagDecl::TagKind(void) const {
  auto val = u.TagDecl->getTagKind();
  return static_cast<::pasta::TagTypeKind>(static_cast<unsigned int>(val));
}

// 1: TagDecl::TemplateParameterList
::pasta::TypedefNameDecl TagDecl::TypedefNameForAnonDecl(void) const {
  auto val = u.TagDecl->getTypedefNameForAnonDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypedefNameDecl>(ast, val);
  }
  assert(false && "TagDecl::TypedefNameForAnonDecl can return nullptr!");
  __builtin_unreachable();
}

bool TagDecl::HasNameForLinkage(void) const {
  auto val = u.TagDecl->hasNameForLinkage();
  return val;
}

bool TagDecl::IsBeingDefined(void) const {
  auto val = u.TagDecl->isBeingDefined();
  return val;
}

bool TagDecl::IsClass(void) const {
  auto val = u.TagDecl->isClass();
  return val;
}

bool TagDecl::IsCompleteDefinition(void) const {
  auto val = u.TagDecl->isCompleteDefinition();
  return val;
}

bool TagDecl::IsCompleteDefinitionRequired(void) const {
  auto val = u.TagDecl->isCompleteDefinitionRequired();
  return val;
}

bool TagDecl::IsDependentType(void) const {
  auto val = u.TagDecl->isDependentType();
  return val;
}

bool TagDecl::IsEmbeddedInDeclarator(void) const {
  auto val = u.TagDecl->isEmbeddedInDeclarator();
  return val;
}

bool TagDecl::IsEnum(void) const {
  auto val = u.TagDecl->isEnum();
  return val;
}

bool TagDecl::IsFreeStanding(void) const {
  auto val = u.TagDecl->isFreeStanding();
  return val;
}

bool TagDecl::IsInterface(void) const {
  auto val = u.TagDecl->isInterface();
  return val;
}

bool TagDecl::IsStruct(void) const {
  auto val = u.TagDecl->isStruct();
  return val;
}

bool TagDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.TagDecl->isThisDeclarationADefinition();
  return val;
}

bool TagDecl::IsUnion(void) const {
  auto val = u.TagDecl->isUnion();
  return val;
}

bool TagDecl::MayHaveOutOfDateDef(void) const {
  auto val = u.TagDecl->mayHaveOutOfDateDef();
  return val;
}

TemplateParamObjectDecl::TemplateParamObjectDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

::pasta::TemplateParamObjectDecl TemplateParamObjectDecl::CanonicalDecl(void) const {
  auto val = u.TemplateParamObjectDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateParamObjectDecl>(ast, val);
  }
  assert(false && "TemplateParamObjectDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: TemplateParamObjectDecl::Value
TemplateTypeParmDecl::TemplateTypeParmDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypeDecl(std::move(ast_), decl_) {}

bool TemplateTypeParmDecl::DefaultArgumentWasInherited(void) const {
  auto val = u.TemplateTypeParmDecl->defaultArgumentWasInherited();
  return val;
}

// 1: TemplateTypeParmDecl::AssociatedConstraints
// 0: TemplateTypeParmDecl::DefaultArgStorage
// 0: TemplateTypeParmDecl::DefaultArgument
// 0: TemplateTypeParmDecl::DefaultArgumentInfo
uint32_t TemplateTypeParmDecl::NumExpansionParameters(void) const {
  auto val = u.TemplateTypeParmDecl->getNumExpansionParameters();
  return val;
}

// 0: TemplateTypeParmDecl::TypeConstraint
bool TemplateTypeParmDecl::HasDefaultArgument(void) const {
  auto val = u.TemplateTypeParmDecl->hasDefaultArgument();
  return val;
}

bool TemplateTypeParmDecl::HasTypeConstraint(void) const {
  auto val = u.TemplateTypeParmDecl->hasTypeConstraint();
  return val;
}

bool TemplateTypeParmDecl::IsExpandedParameterPack(void) const {
  auto val = u.TemplateTypeParmDecl->isExpandedParameterPack();
  return val;
}

bool TemplateTypeParmDecl::IsPackExpansion(void) const {
  auto val = u.TemplateTypeParmDecl->isPackExpansion();
  return val;
}

bool TemplateTypeParmDecl::WasDeclaredWithTypename(void) const {
  auto val = u.TemplateTypeParmDecl->wasDeclaredWithTypename();
  return val;
}

TypeAliasDecl::TypeAliasDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

::pasta::TypeAliasTemplateDecl TypeAliasDecl::DescribedAliasTemplate(void) const {
  auto val = u.TypeAliasDecl->getDescribedAliasTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasDecl::DescribedAliasTemplate can return nullptr!");
  __builtin_unreachable();
}

TypeAliasTemplateDecl::TypeAliasTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::CanonicalDecl(void) const {
  auto val = u.TypeAliasTemplateDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto val = u.TypeAliasTemplateDecl->getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeAliasTemplateDecl TypeAliasTemplateDecl::PreviousDecl(void) const {
  auto val = u.TypeAliasTemplateDecl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasTemplateDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::TypeAliasDecl TypeAliasTemplateDecl::TemplatedDecl(void) const {
  auto val = u.TypeAliasTemplateDecl->getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::TypeAliasDecl>(ast, val);
  }
  assert(false && "TypeAliasTemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

TypedefDecl::TypedefDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TypedefNameDecl(std::move(ast_), decl_) {}

UnresolvedUsingValueDecl::UnresolvedUsingValueDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ValueDecl(std::move(ast_), decl_) {}

::pasta::UnresolvedUsingValueDecl UnresolvedUsingValueDecl::CanonicalDecl(void) const {
  auto val = u.UnresolvedUsingValueDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::UnresolvedUsingValueDecl>(ast, val);
  }
  assert(false && "UnresolvedUsingValueDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::Token UnresolvedUsingValueDecl::EllipsisToken(void) const {
  auto val = u.UnresolvedUsingValueDecl->getEllipsisLoc();
  return ast->TokenAt(val);
}

// 0: UnresolvedUsingValueDecl::NameInfo
// 0: UnresolvedUsingValueDecl::Qualifier
// 0: UnresolvedUsingValueDecl::QualifierToken
::pasta::Token UnresolvedUsingValueDecl::UsingToken(void) const {
  auto val = u.UnresolvedUsingValueDecl->getUsingLoc();
  return ast->TokenAt(val);
}

bool UnresolvedUsingValueDecl::IsAccessDeclaration(void) const {
  auto val = u.UnresolvedUsingValueDecl->isAccessDeclaration();
  return val;
}

bool UnresolvedUsingValueDecl::IsPackExpansion(void) const {
  auto val = u.UnresolvedUsingValueDecl->isPackExpansion();
  return val;
}

VarDecl::VarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : DeclaratorDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, DecompositionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, ImplicitParamDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, OMPCapturedExprDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, ParmVarDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, VarTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(VarDecl, VarTemplateSpecializationDecl)
::pasta::VarDecl VarDecl::ActingDefinition(void) const {
  auto val = u.VarDecl->getActingDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::ActingDefinition can return nullptr!");
  __builtin_unreachable();
}

// 0: VarDecl::AnyInitializer
::pasta::VarDecl VarDecl::CanonicalDecl(void) const {
  auto val = u.VarDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: VarDecl::Init
// 0: VarDecl::InitStyle
::pasta::VarDecl VarDecl::InitializingDeclaration(void) const {
  auto val = u.VarDecl->getInitializingDeclaration();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarDecl::InitializingDeclaration can return nullptr!");
  __builtin_unreachable();
}

StorageClass VarDecl::StorageClass(void) const {
  auto val = u.VarDecl->getStorageClass();
  return static_cast<::pasta::StorageClass>(static_cast<unsigned int>(val));
}

StorageDuration VarDecl::StorageDuration(void) const {
  auto val = u.VarDecl->getStorageDuration();
  return static_cast<::pasta::StorageDuration>(static_cast<unsigned int>(val));
}

ThreadStorageClassSpecifier VarDecl::TSCSpec(void) const {
  auto val = u.VarDecl->getTSCSpec();
  return static_cast<::pasta::ThreadStorageClassSpecifier>(static_cast<unsigned int>(val));
}

// 0: VarDecl::HasDefinition
bool VarDecl::HasExternalStorage(void) const {
  auto val = u.VarDecl->hasExternalStorage();
  return val;
}

bool VarDecl::HasGlobalStorage(void) const {
  auto val = u.VarDecl->hasGlobalStorage();
  return val;
}

bool VarDecl::HasLocalStorage(void) const {
  auto val = u.VarDecl->hasLocalStorage();
  return val;
}

bool VarDecl::IsARCPseudoStrong(void) const {
  auto val = u.VarDecl->isARCPseudoStrong();
  return val;
}

bool VarDecl::IsCXXForRangeDecl(void) const {
  auto val = u.VarDecl->isCXXForRangeDecl();
  return val;
}

bool VarDecl::IsConstexpr(void) const {
  auto val = u.VarDecl->isConstexpr();
  return val;
}

bool VarDecl::IsDirectInit(void) const {
  auto val = u.VarDecl->isDirectInit();
  return val;
}

bool VarDecl::IsExceptionVariable(void) const {
  auto val = u.VarDecl->isExceptionVariable();
  return val;
}

bool VarDecl::IsFileVarDecl(void) const {
  auto val = u.VarDecl->isFileVarDecl();
  return val;
}

bool VarDecl::IsFunctionOrMethodVarDecl(void) const {
  auto val = u.VarDecl->isFunctionOrMethodVarDecl();
  return val;
}

bool VarDecl::IsInitCapture(void) const {
  auto val = u.VarDecl->isInitCapture();
  return val;
}

bool VarDecl::IsInline(void) const {
  auto val = u.VarDecl->isInline();
  return val;
}

bool VarDecl::IsInlineSpecified(void) const {
  auto val = u.VarDecl->isInlineSpecified();
  return val;
}

bool VarDecl::IsLocalVarDecl(void) const {
  auto val = u.VarDecl->isLocalVarDecl();
  return val;
}

bool VarDecl::IsLocalVarDeclOrParm(void) const {
  auto val = u.VarDecl->isLocalVarDeclOrParm();
  return val;
}

bool VarDecl::IsNRVOVariable(void) const {
  auto val = u.VarDecl->isNRVOVariable();
  return val;
}

bool VarDecl::IsObjCForDecl(void) const {
  auto val = u.VarDecl->isObjCForDecl();
  return val;
}

bool VarDecl::IsPreviousDeclInSameBlockScope(void) const {
  auto val = u.VarDecl->isPreviousDeclInSameBlockScope();
  return val;
}

bool VarDecl::IsStaticDataMember(void) const {
  auto val = u.VarDecl->isStaticDataMember();
  return val;
}

bool VarDecl::IsStaticLocal(void) const {
  auto val = u.VarDecl->isStaticLocal();
  return val;
}

// 0: VarDecl::IsThisDeclarationADefinition
bool VarDecl::IsThisDeclarationADemotedDefinition(void) const {
  auto val = u.VarDecl->isThisDeclarationADemotedDefinition();
  return val;
}

VarTemplateDecl::VarTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

::pasta::VarTemplateDecl VarTemplateDecl::CanonicalDecl(void) const {
  auto val = u.VarTemplateDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto val = u.VarTemplateDecl->getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::MostRecentDecl(void) const {
  auto val = u.VarTemplateDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarTemplateDecl VarTemplateDecl::PreviousDecl(void) const {
  auto val = u.VarTemplateDecl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::VarDecl VarTemplateDecl::TemplatedDecl(void) const {
  auto val = u.VarTemplateDecl->getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::VarDecl>(ast, val);
  }
  assert(false && "VarTemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

bool VarTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.VarTemplateDecl->isThisDeclarationADefinition();
  return val;
}

std::vector<::pasta::VarTemplateSpecializationDecl> VarTemplateDecl::Specializations(void) const {
  auto val = u.VarTemplateDecl->specializations();
  std::vector<::pasta::VarTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::VarTemplateSpecializationDecl>(ast, decl_ptr));
  }
  return ret;
}

VarTemplateSpecializationDecl::VarTemplateSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(VarTemplateSpecializationDecl, VarTemplatePartialSpecializationDecl)
// 1: VarTemplateSpecializationDecl::Profile
::pasta::Token VarTemplateSpecializationDecl::ExternToken(void) const {
  auto val = u.VarTemplateSpecializationDecl->getExternLoc();
  return ast->TokenAt(val);
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::InstantiatedFrom(void) const {
  auto val = u.VarTemplateSpecializationDecl->getInstantiatedFrom();
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::VarTemplateDecl *>()) {
      return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::VarTemplatePartialSpecializationDecl *>()) {
      return DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, b_ptr);
    }
  }
  return {};
}

::pasta::Token VarTemplateSpecializationDecl::PointOfInstantiation(void) const {
  auto val = u.VarTemplateSpecializationDecl->getPointOfInstantiation();
  return ast->TokenAt(val);
}

TemplateSpecializationKind VarTemplateSpecializationDecl::SpecializationKind(void) const {
  auto val = u.VarTemplateSpecializationDecl->getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> VarTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const {
  auto val = u.VarTemplateSpecializationDecl->getSpecializedTemplateOrPartial();
  std::variant<std::monostate, ::pasta::VarTemplateDecl, ::pasta::VarTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::VarTemplateDecl *>()) {
      return DeclBuilder::Create<::pasta::VarTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::VarTemplatePartialSpecializationDecl *>()) {
      return DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, b_ptr);
    }
  }
  return {};
}

// 0: VarTemplateSpecializationDecl::TemplateArgs
// 0: VarTemplateSpecializationDecl::TemplateArgsInfo
// 0: VarTemplateSpecializationDecl::TemplateInstantiationArgs
::pasta::Token VarTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  auto val = u.VarTemplateSpecializationDecl->getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

// 0: VarTemplateSpecializationDecl::TypeAsWritten
bool VarTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  auto val = u.VarTemplateSpecializationDecl->isClassScopeExplicitSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  auto val = u.VarTemplateSpecializationDecl->isExplicitInstantiationOrSpecialization();
  return val;
}

bool VarTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  auto val = u.VarTemplateSpecializationDecl->isExplicitSpecialization();
  return val;
}

CXXDeductionGuideDecl::CXXDeductionGuideDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FunctionDecl(std::move(ast_), decl_) {}

::pasta::TemplateDecl CXXDeductionGuideDecl::DeducedTemplate(void) const {
  auto val = u.CXXDeductionGuideDecl->getDeducedTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::TemplateDecl>(ast, val);
  }
  assert(false && "CXXDeductionGuideDecl::DeducedTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXDeductionGuideDecl::ExplicitSpecifier
bool CXXDeductionGuideDecl::IsCopyDeductionCandidate(void) const {
  auto val = u.CXXDeductionGuideDecl->isCopyDeductionCandidate();
  return val;
}

bool CXXDeductionGuideDecl::IsExplicit(void) const {
  auto val = u.CXXDeductionGuideDecl->isExplicit();
  return val;
}

CXXMethodDecl::CXXMethodDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : FunctionDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(CXXMethodDecl, CXXConstructorDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXMethodDecl, CXXConversionDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXMethodDecl, CXXDestructorDecl)
::pasta::CXXMethodDecl CXXMethodDecl::CanonicalDecl(void) const {
  auto val = u.CXXMethodDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 1: CXXMethodDecl::CorrespondingMethodDeclaredInClass
// 1: CXXMethodDecl::CorrespondingMethodInClass
// 2: DevirtualizedMethod
// 0: CXXMethodDecl::MethodQualifiers
::pasta::CXXMethodDecl CXXMethodDecl::MostRecentDecl(void) const {
  auto val = u.CXXMethodDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXMethodDecl::Parent(void) const {
  auto val = u.CXXMethodDecl->getParent();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXMethodDecl::Parent can return nullptr!");
  __builtin_unreachable();
}

RefQualifierKind CXXMethodDecl::RefQualifier(void) const {
  auto val = u.CXXMethodDecl->getRefQualifier();
  return static_cast<::pasta::RefQualifierKind>(static_cast<unsigned int>(val));
}

bool CXXMethodDecl::IsConst(void) const {
  auto val = u.CXXMethodDecl->isConst();
  return val;
}

bool CXXMethodDecl::IsInstance(void) const {
  auto val = u.CXXMethodDecl->isInstance();
  return val;
}

bool CXXMethodDecl::IsVirtual(void) const {
  auto val = u.CXXMethodDecl->isVirtual();
  return val;
}

bool CXXMethodDecl::IsVolatile(void) const {
  auto val = u.CXXMethodDecl->isVolatile();
  return val;
}

ClassTemplateDecl::ClassTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

::pasta::ClassTemplateDecl ClassTemplateDecl::CanonicalDecl(void) const {
  auto val = u.ClassTemplateDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto val = u.ClassTemplateDecl->getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::MostRecentDecl(void) const {
  auto val = u.ClassTemplateDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplateDecl ClassTemplateDecl::PreviousDecl(void) const {
  auto val = u.ClassTemplateDecl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl ClassTemplateDecl::TemplatedDecl(void) const {
  auto val = u.ClassTemplateDecl->getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "ClassTemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

bool ClassTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.ClassTemplateDecl->isThisDeclarationADefinition();
  return val;
}

std::vector<::pasta::ClassTemplateSpecializationDecl> ClassTemplateDecl::Specializations(void) const {
  auto val = u.ClassTemplateDecl->specializations();
  std::vector<::pasta::ClassTemplateSpecializationDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::ClassTemplateSpecializationDecl>(ast, decl_ptr));
  }
  return ret;
}

DecompositionDecl::DecompositionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

std::vector<::pasta::BindingDecl> DecompositionDecl::Bindings(void) const {
  auto val = u.DecompositionDecl->bindings();
  std::vector<::pasta::BindingDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::BindingDecl>(ast, decl_ptr));
  }
  return ret;
}

EnumDecl::EnumDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TagDecl(std::move(ast_), decl_) {}

std::vector<::pasta::EnumConstantDecl> EnumDecl::Enumerators(void) const {
  auto val = u.EnumDecl->enumerators();
  std::vector<::pasta::EnumConstantDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::EnumConstantDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::EnumDecl EnumDecl::CanonicalDecl(void) const {
  auto val = u.EnumDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::EnumDecl EnumDecl::Definition(void) const {
  auto val = u.EnumDecl->getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

// 0: EnumDecl::IntegerType
// 0: EnumDecl::IntegerTypeSourceInfo
// 0: EnumDecl::MemberSpecializationInfo
::pasta::EnumDecl EnumDecl::MostRecentDecl(void) const {
  auto val = u.EnumDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t EnumDecl::NumNegativeBits(void) const {
  auto val = u.EnumDecl->getNumNegativeBits();
  return val;
}

uint32_t EnumDecl::NumPositiveBits(void) const {
  auto val = u.EnumDecl->getNumPositiveBits();
  return val;
}

::pasta::EnumDecl EnumDecl::PreviousDecl(void) const {
  auto val = u.EnumDecl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::EnumDecl>(ast, val);
  }
  assert(false && "EnumDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: EnumDecl::PromotionType
bool EnumDecl::IsComplete(void) const {
  auto val = u.EnumDecl->isComplete();
  return val;
}

bool EnumDecl::IsFixed(void) const {
  auto val = u.EnumDecl->isFixed();
  return val;
}

bool EnumDecl::IsScoped(void) const {
  auto val = u.EnumDecl->isScoped();
  return val;
}

bool EnumDecl::IsScopedUsingClassTag(void) const {
  auto val = u.EnumDecl->isScopedUsingClassTag();
  return val;
}

FunctionTemplateDecl::FunctionTemplateDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RedeclarableTemplateDecl(std::move(ast_), decl_) {}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::CanonicalDecl(void) const {
  auto val = u.FunctionTemplateDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::InstantiatedFromMemberTemplate(void) const {
  auto val = u.FunctionTemplateDecl->getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::MostRecentDecl(void) const {
  auto val = u.FunctionTemplateDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionTemplateDecl FunctionTemplateDecl::PreviousDecl(void) const {
  auto val = u.FunctionTemplateDecl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionTemplateDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionDecl FunctionTemplateDecl::TemplatedDecl(void) const {
  auto val = u.FunctionTemplateDecl->getTemplatedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "FunctionTemplateDecl::TemplatedDecl can return nullptr!");
  __builtin_unreachable();
}

bool FunctionTemplateDecl::IsAbbreviated(void) const {
  auto val = u.FunctionTemplateDecl->isAbbreviated();
  return val;
}

bool FunctionTemplateDecl::IsThisDeclarationADefinition(void) const {
  auto val = u.FunctionTemplateDecl->isThisDeclarationADefinition();
  return val;
}

// 0: FunctionTemplateDecl::Specializations
ImplicitParamDecl::ImplicitParamDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

::pasta::ImplicitParamKind ImplicitParamDecl::ParameterKind(void) const {
  auto val = u.ImplicitParamDecl->getParameterKind();
  return static_cast<::pasta::ImplicitParamKind>(val);
}

OMPCapturedExprDecl::OMPCapturedExprDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

ParmVarDecl::ParmVarDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarDecl(std::move(ast_), decl_) {}

// 0: ParmVarDecl::DefaultArg
uint32_t ParmVarDecl::FunctionScopeDepth(void) const {
  auto val = u.ParmVarDecl->getFunctionScopeDepth();
  return val;
}

uint32_t ParmVarDecl::FunctionScopeIndex(void) const {
  auto val = u.ParmVarDecl->getFunctionScopeIndex();
  return val;
}

// 0: ParmVarDecl::ObjCDeclQualifier
// 0: ParmVarDecl::UninstantiatedDefaultArg
bool ParmVarDecl::HasInheritedDefaultArg(void) const {
  auto val = u.ParmVarDecl->hasInheritedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUninstantiatedDefaultArg(void) const {
  auto val = u.ParmVarDecl->hasUninstantiatedDefaultArg();
  return val;
}

bool ParmVarDecl::HasUnparsedDefaultArg(void) const {
  auto val = u.ParmVarDecl->hasUnparsedDefaultArg();
  return val;
}

bool ParmVarDecl::IsKNRPromoted(void) const {
  auto val = u.ParmVarDecl->isKNRPromoted();
  return val;
}

bool ParmVarDecl::IsObjCMethodParameter(void) const {
  auto val = u.ParmVarDecl->isObjCMethodParameter();
  return val;
}

RecordDecl::RecordDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : TagDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(RecordDecl, CXXRecordDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RecordDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(RecordDecl, ClassTemplateSpecializationDecl)
bool RecordDecl::CanPassInRegisters(void) const {
  auto val = u.RecordDecl->canPassInRegisters();
  return val;
}

std::vector<::pasta::FieldDecl> RecordDecl::Fields(void) const {
  auto val = u.RecordDecl->fields();
  std::vector<::pasta::FieldDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::FieldDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::ArgPassingKind RecordDecl::ArgPassingRestrictions(void) const {
  auto val = u.RecordDecl->getArgPassingRestrictions();
  return static_cast<::pasta::ArgPassingKind>(val);
}

::pasta::RecordDecl RecordDecl::Definition(void) const {
  auto val = u.RecordDecl->getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl RecordDecl::MostRecentDecl(void) const {
  auto val = u.RecordDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::RecordDecl RecordDecl::PreviousDecl(void) const {
  auto val = u.RecordDecl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::RecordDecl>(ast, val);
  }
  assert(false && "RecordDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

bool RecordDecl::HasFlexibleArrayMember(void) const {
  auto val = u.RecordDecl->hasFlexibleArrayMember();
  return val;
}

bool RecordDecl::HasLoadedFieldsFromExternalStorage(void) const {
  auto val = u.RecordDecl->hasLoadedFieldsFromExternalStorage();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveCopyCUnion(void) const {
  auto val = u.RecordDecl->hasNonTrivialToPrimitiveCopyCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDefaultInitializeCUnion(void) const {
  auto val = u.RecordDecl->hasNonTrivialToPrimitiveDefaultInitializeCUnion();
  return val;
}

bool RecordDecl::HasNonTrivialToPrimitiveDestructCUnion(void) const {
  auto val = u.RecordDecl->hasNonTrivialToPrimitiveDestructCUnion();
  return val;
}

bool RecordDecl::HasObjectMember(void) const {
  auto val = u.RecordDecl->hasObjectMember();
  return val;
}

bool RecordDecl::HasVolatileMember(void) const {
  auto val = u.RecordDecl->hasVolatileMember();
  return val;
}

bool RecordDecl::IsAnonymousStructOrUnion(void) const {
  auto val = u.RecordDecl->isAnonymousStructOrUnion();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveCopy(void) const {
  auto val = u.RecordDecl->isNonTrivialToPrimitiveCopy();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDefaultInitialize(void) const {
  auto val = u.RecordDecl->isNonTrivialToPrimitiveDefaultInitialize();
  return val;
}

bool RecordDecl::IsNonTrivialToPrimitiveDestroy(void) const {
  auto val = u.RecordDecl->isNonTrivialToPrimitiveDestroy();
  return val;
}

bool RecordDecl::IsParamDestroyedInCallee(void) const {
  auto val = u.RecordDecl->isParamDestroyedInCallee();
  return val;
}

VarTemplatePartialSpecializationDecl::VarTemplatePartialSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : VarTemplateSpecializationDecl(std::move(ast_), decl_) {}

// 1: VarTemplatePartialSpecializationDecl::Profile
// 1: VarTemplatePartialSpecializationDecl::AssociatedConstraints
::pasta::VarTemplatePartialSpecializationDecl VarTemplatePartialSpecializationDecl::InstantiatedFromMember(void) const {
  auto val = u.VarTemplatePartialSpecializationDecl->getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::VarTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "VarTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
  __builtin_unreachable();
}

// 0: VarTemplatePartialSpecializationDecl::TemplateArgsAsWritten
// 0: VarTemplatePartialSpecializationDecl::TemplateParameters
bool VarTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  auto val = u.VarTemplatePartialSpecializationDecl->hasAssociatedConstraints();
  return val;
}

CXXConstructorDecl::CXXConstructorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

::pasta::CXXConstructorDecl CXXConstructorDecl::CanonicalDecl(void) const {
  auto val = u.CXXConstructorDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, val);
  }
  assert(false && "CXXConstructorDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXConstructorDecl::ExplicitSpecifier
// 0: CXXConstructorDecl::InheritedConstructor
uint32_t CXXConstructorDecl::NumCtorInitializers(void) const {
  auto val = u.CXXConstructorDecl->getNumCtorInitializers();
  return val;
}

// 0: CXXConstructorDecl::Initializers
bool CXXConstructorDecl::IsCopyConstructor(void) const {
  auto val = u.CXXConstructorDecl->isCopyConstructor();
  return val;
}

bool CXXConstructorDecl::IsCopyOrMoveConstructor(void) const {
  auto val = u.CXXConstructorDecl->isCopyOrMoveConstructor();
  return val;
}

bool CXXConstructorDecl::IsDelegatingConstructor(void) const {
  auto val = u.CXXConstructorDecl->isDelegatingConstructor();
  return val;
}

bool CXXConstructorDecl::IsExplicit(void) const {
  auto val = u.CXXConstructorDecl->isExplicit();
  return val;
}

bool CXXConstructorDecl::IsInheritingConstructor(void) const {
  auto val = u.CXXConstructorDecl->isInheritingConstructor();
  return val;
}

bool CXXConstructorDecl::IsMoveConstructor(void) const {
  auto val = u.CXXConstructorDecl->isMoveConstructor();
  return val;
}

CXXConversionDecl::CXXConversionDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

::pasta::CXXConversionDecl CXXConversionDecl::CanonicalDecl(void) const {
  auto val = u.CXXConversionDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXConversionDecl>(ast, val);
  }
  assert(false && "CXXConversionDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXConversionDecl::ConversionType
// 0: CXXConversionDecl::ExplicitSpecifier
bool CXXConversionDecl::IsExplicit(void) const {
  auto val = u.CXXConversionDecl->isExplicit();
  return val;
}

CXXDestructorDecl::CXXDestructorDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXMethodDecl(std::move(ast_), decl_) {}

::pasta::CXXDestructorDecl CXXDestructorDecl::CanonicalDecl(void) const {
  auto val = u.CXXDestructorDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXDestructorDecl>(ast, val);
  }
  assert(false && "CXXDestructorDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::FunctionDecl CXXDestructorDecl::OperatorDelete(void) const {
  auto val = u.CXXDestructorDecl->getOperatorDelete();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXDestructorDecl::OperatorDelete can return nullptr!");
  __builtin_unreachable();
}

// 0: CXXDestructorDecl::OperatorDeleteThisArg
CXXRecordDecl::CXXRecordDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : RecordDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplatePartialSpecializationDecl)
PASTA_DEFINE_DERIVED_OPERATORS(CXXRecordDecl, ClassTemplateSpecializationDecl)
bool CXXRecordDecl::AllowConstDefaultInit(void) const {
  auto val = u.CXXRecordDecl->allowConstDefaultInit();
  return val;
}

// 0: CXXRecordDecl::Bases
// 0: CXXRecordDecl::Captures
std::vector<::pasta::CXXConstructorDecl> CXXRecordDecl::Constructors(void) const {
  auto val = u.CXXRecordDecl->ctors();
  std::vector<::pasta::CXXConstructorDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::CXXConstructorDecl>(ast, decl_ptr));
  }
  return ret;
}

bool CXXRecordDecl::DefaultedCopyConstructorIsDeleted(void) const {
  auto val = u.CXXRecordDecl->defaultedCopyConstructorIsDeleted();
  return val;
}

bool CXXRecordDecl::DefaultedDefaultConstructorIsConstexpr(void) const {
  auto val = u.CXXRecordDecl->defaultedDefaultConstructorIsConstexpr();
  return val;
}

bool CXXRecordDecl::DefaultedDestructorIsConstexpr(void) const {
  auto val = u.CXXRecordDecl->defaultedDestructorIsConstexpr();
  return val;
}

bool CXXRecordDecl::DefaultedDestructorIsDeleted(void) const {
  auto val = u.CXXRecordDecl->defaultedDestructorIsDeleted();
  return val;
}

bool CXXRecordDecl::DefaultedMoveConstructorIsDeleted(void) const {
  auto val = u.CXXRecordDecl->defaultedMoveConstructorIsDeleted();
  return val;
}

std::vector<::pasta::FriendDecl> CXXRecordDecl::Friends(void) const {
  auto val = u.CXXRecordDecl->friends();
  std::vector<::pasta::FriendDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::FriendDecl>(ast, decl_ptr));
  }
  return ret;
}

::pasta::CXXRecordDecl CXXRecordDecl::CanonicalDecl(void) const {
  auto val = u.CXXRecordDecl->getCanonicalDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::CanonicalDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXRecordDecl::Definition(void) const {
  auto val = u.CXXRecordDecl->getDefinition();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::Definition can return nullptr!");
  __builtin_unreachable();
}

LambdaCaptureDefault CXXRecordDecl::LambdaCaptureDefault(void) const {
  auto val = u.CXXRecordDecl->getLambdaCaptureDefault();
  return static_cast<::pasta::LambdaCaptureDefault>(static_cast<unsigned int>(val));
}

uint32_t CXXRecordDecl::LambdaManglingNumber(void) const {
  auto val = u.CXXRecordDecl->getLambdaManglingNumber();
  return val;
}

// 0: CXXRecordDecl::LambdaTypeInfo
::pasta::CXXRecordDecl CXXRecordDecl::MostRecentDecl(void) const {
  auto val = u.CXXRecordDecl->getMostRecentDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::MostRecentDecl can return nullptr!");
  __builtin_unreachable();
}

::pasta::CXXRecordDecl CXXRecordDecl::MostRecentNonInjectedDecl(void) const {
  auto val = u.CXXRecordDecl->getMostRecentNonInjectedDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::MostRecentNonInjectedDecl can return nullptr!");
  __builtin_unreachable();
}

uint32_t CXXRecordDecl::NumBases(void) const {
  auto val = u.CXXRecordDecl->getNumBases();
  return val;
}

uint32_t CXXRecordDecl::NumVBases(void) const {
  auto val = u.CXXRecordDecl->getNumVBases();
  return val;
}

::pasta::CXXRecordDecl CXXRecordDecl::PreviousDecl(void) const {
  auto val = u.CXXRecordDecl->getPreviousDecl();
  if (val) {
    return DeclBuilder::Create<::pasta::CXXRecordDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::PreviousDecl can return nullptr!");
  __builtin_unreachable();
}

bool CXXRecordDecl::HasConstexprDefaultConstructor(void) const {
  auto val = u.CXXRecordDecl->hasConstexprDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasConstexprNonCopyMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->hasConstexprNonCopyMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasCopyAssignmentWithConstParam(void) const {
  auto val = u.CXXRecordDecl->hasCopyAssignmentWithConstParam();
  return val;
}

bool CXXRecordDecl::HasCopyConstructorWithConstParam(void) const {
  auto val = u.CXXRecordDecl->hasCopyConstructorWithConstParam();
  return val;
}

bool CXXRecordDecl::HasDefaultConstructor(void) const {
  auto val = u.CXXRecordDecl->hasDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasDefinition(void) const {
  auto val = u.CXXRecordDecl->hasDefinition();
  return val;
}

bool CXXRecordDecl::HasDirectFields(void) const {
  auto val = u.CXXRecordDecl->hasDirectFields();
  return val;
}

bool CXXRecordDecl::HasFriends(void) const {
  auto val = u.CXXRecordDecl->hasFriends();
  return val;
}

bool CXXRecordDecl::HasInClassInitializer(void) const {
  auto val = u.CXXRecordDecl->hasInClassInitializer();
  return val;
}

bool CXXRecordDecl::HasInheritedAssignment(void) const {
  auto val = u.CXXRecordDecl->hasInheritedAssignment();
  return val;
}

bool CXXRecordDecl::HasInheritedConstructor(void) const {
  auto val = u.CXXRecordDecl->hasInheritedConstructor();
  return val;
}

bool CXXRecordDecl::HasIrrelevantDestructor(void) const {
  auto val = u.CXXRecordDecl->hasIrrelevantDestructor();
  return val;
}

bool CXXRecordDecl::HasKnownLambdaInternalLinkage(void) const {
  auto val = u.CXXRecordDecl->hasKnownLambdaInternalLinkage();
  return val;
}

bool CXXRecordDecl::HasMoveAssignment(void) const {
  auto val = u.CXXRecordDecl->hasMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->hasMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasMutableFields(void) const {
  auto val = u.CXXRecordDecl->hasMutableFields();
  return val;
}

bool CXXRecordDecl::HasNonLiteralTypeFieldsOrBases(void) const {
  auto val = u.CXXRecordDecl->hasNonLiteralTypeFieldsOrBases();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyAssignment(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyConstructor(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialCopyConstructorForCall(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialCopyConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDefaultConstructor(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDestructor(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialDestructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialDestructorForCall(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialDestructorForCall();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveAssignment(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasNonTrivialMoveConstructorForCall(void) const {
  auto val = u.CXXRecordDecl->hasNonTrivialMoveConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasPrivateFields(void) const {
  auto val = u.CXXRecordDecl->hasPrivateFields();
  return val;
}

bool CXXRecordDecl::HasProtectedFields(void) const {
  auto val = u.CXXRecordDecl->hasProtectedFields();
  return val;
}

bool CXXRecordDecl::HasSimpleCopyAssignment(void) const {
  auto val = u.CXXRecordDecl->hasSimpleCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasSimpleCopyConstructor(void) const {
  auto val = u.CXXRecordDecl->hasSimpleCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasSimpleDestructor(void) const {
  auto val = u.CXXRecordDecl->hasSimpleDestructor();
  return val;
}

bool CXXRecordDecl::HasSimpleMoveAssignment(void) const {
  auto val = u.CXXRecordDecl->hasSimpleMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasSimpleMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->hasSimpleMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyAssignment(void) const {
  auto val = u.CXXRecordDecl->hasTrivialCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyConstructor(void) const {
  auto val = u.CXXRecordDecl->hasTrivialCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialCopyConstructorForCall(void) const {
  auto val = u.CXXRecordDecl->hasTrivialCopyConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasTrivialDefaultConstructor(void) const {
  auto val = u.CXXRecordDecl->hasTrivialDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialDestructor(void) const {
  auto val = u.CXXRecordDecl->hasTrivialDestructor();
  return val;
}

bool CXXRecordDecl::HasTrivialDestructorForCall(void) const {
  auto val = u.CXXRecordDecl->hasTrivialDestructorForCall();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveAssignment(void) const {
  auto val = u.CXXRecordDecl->hasTrivialMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->hasTrivialMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasTrivialMoveConstructorForCall(void) const {
  auto val = u.CXXRecordDecl->hasTrivialMoveConstructorForCall();
  return val;
}

bool CXXRecordDecl::HasUninitializedReferenceMember(void) const {
  auto val = u.CXXRecordDecl->hasUninitializedReferenceMember();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredConstructor(void) const {
  auto val = u.CXXRecordDecl->hasUserDeclaredConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredCopyAssignment(void) const {
  auto val = u.CXXRecordDecl->hasUserDeclaredCopyAssignment();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredCopyConstructor(void) const {
  auto val = u.CXXRecordDecl->hasUserDeclaredCopyConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredDestructor(void) const {
  auto val = u.CXXRecordDecl->hasUserDeclaredDestructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveAssignment(void) const {
  auto val = u.CXXRecordDecl->hasUserDeclaredMoveAssignment();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->hasUserDeclaredMoveConstructor();
  return val;
}

bool CXXRecordDecl::HasUserDeclaredMoveOperation(void) const {
  auto val = u.CXXRecordDecl->hasUserDeclaredMoveOperation();
  return val;
}

bool CXXRecordDecl::HasUserProvidedDefaultConstructor(void) const {
  auto val = u.CXXRecordDecl->hasUserProvidedDefaultConstructor();
  return val;
}

bool CXXRecordDecl::HasVariantMembers(void) const {
  auto val = u.CXXRecordDecl->hasVariantMembers();
  return val;
}

bool CXXRecordDecl::ImplicitCopyAssignmentHasConstParam(void) const {
  auto val = u.CXXRecordDecl->implicitCopyAssignmentHasConstParam();
  return val;
}

bool CXXRecordDecl::ImplicitCopyConstructorHasConstParam(void) const {
  auto val = u.CXXRecordDecl->implicitCopyConstructorHasConstParam();
  return val;
}

bool CXXRecordDecl::IsAbstract(void) const {
  auto val = u.CXXRecordDecl->isAbstract();
  return val;
}

bool CXXRecordDecl::IsAggregate(void) const {
  auto val = u.CXXRecordDecl->isAggregate();
  return val;
}

bool CXXRecordDecl::IsCXX11StandardLayout(void) const {
  auto val = u.CXXRecordDecl->isCXX11StandardLayout();
  return val;
}

bool CXXRecordDecl::IsDependentLambda(void) const {
  auto val = u.CXXRecordDecl->isDependentLambda();
  return val;
}

bool CXXRecordDecl::IsDynamicClass(void) const {
  auto val = u.CXXRecordDecl->isDynamicClass();
  return val;
}

bool CXXRecordDecl::IsEmpty(void) const {
  auto val = u.CXXRecordDecl->isEmpty();
  return val;
}

bool CXXRecordDecl::IsLambda(void) const {
  auto val = u.CXXRecordDecl->isLambda();
  return val;
}

bool CXXRecordDecl::IsLiteral(void) const {
  auto val = u.CXXRecordDecl->isLiteral();
  return val;
}

::pasta::FunctionDecl CXXRecordDecl::IsLocalClass(void) const {
  auto val = u.CXXRecordDecl->isLocalClass();
  if (val) {
    return DeclBuilder::Create<::pasta::FunctionDecl>(ast, val);
  }
  assert(false && "CXXRecordDecl::IsLocalClass can return nullptr!");
  __builtin_unreachable();
}

bool CXXRecordDecl::IsPOD(void) const {
  auto val = u.CXXRecordDecl->isPOD();
  return val;
}

bool CXXRecordDecl::IsParsingBaseSpecifiers(void) const {
  auto val = u.CXXRecordDecl->isParsingBaseSpecifiers();
  return val;
}

bool CXXRecordDecl::IsPolymorphic(void) const {
  auto val = u.CXXRecordDecl->isPolymorphic();
  return val;
}

bool CXXRecordDecl::IsStandardLayout(void) const {
  auto val = u.CXXRecordDecl->isStandardLayout();
  return val;
}

bool CXXRecordDecl::IsStructural(void) const {
  auto val = u.CXXRecordDecl->isStructural();
  return val;
}

bool CXXRecordDecl::IsTrivial(void) const {
  auto val = u.CXXRecordDecl->isTrivial();
  return val;
}

bool CXXRecordDecl::MayBeDynamicClass(void) const {
  auto val = u.CXXRecordDecl->mayBeDynamicClass();
  return val;
}

bool CXXRecordDecl::MayBeNonDynamicClass(void) const {
  auto val = u.CXXRecordDecl->mayBeNonDynamicClass();
  return val;
}

std::vector<::pasta::CXXMethodDecl> CXXRecordDecl::Methods(void) const {
  auto val = u.CXXRecordDecl->methods();
  std::vector<::pasta::CXXMethodDecl> ret;
  for (auto decl_ptr : val) {
    ret.emplace_back(DeclBuilder::Create<::pasta::CXXMethodDecl>(ast, decl_ptr));
  }
  return ret;
}

bool CXXRecordDecl::NeedsImplicitCopyAssignment(void) const {
  auto val = u.CXXRecordDecl->needsImplicitCopyAssignment();
  return val;
}

bool CXXRecordDecl::NeedsImplicitCopyConstructor(void) const {
  auto val = u.CXXRecordDecl->needsImplicitCopyConstructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitDefaultConstructor(void) const {
  auto val = u.CXXRecordDecl->needsImplicitDefaultConstructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitDestructor(void) const {
  auto val = u.CXXRecordDecl->needsImplicitDestructor();
  return val;
}

bool CXXRecordDecl::NeedsImplicitMoveAssignment(void) const {
  auto val = u.CXXRecordDecl->needsImplicitMoveAssignment();
  return val;
}

bool CXXRecordDecl::NeedsImplicitMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->needsImplicitMoveConstructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyAssignment(void) const {
  auto val = u.CXXRecordDecl->needsOverloadResolutionForCopyAssignment();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForCopyConstructor(void) const {
  auto val = u.CXXRecordDecl->needsOverloadResolutionForCopyConstructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForDestructor(void) const {
  auto val = u.CXXRecordDecl->needsOverloadResolutionForDestructor();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveAssignment(void) const {
  auto val = u.CXXRecordDecl->needsOverloadResolutionForMoveAssignment();
  return val;
}

bool CXXRecordDecl::NeedsOverloadResolutionForMoveConstructor(void) const {
  auto val = u.CXXRecordDecl->needsOverloadResolutionForMoveConstructor();
  return val;
}

// 0: CXXRecordDecl::VirtualBases
ClassTemplateSpecializationDecl::ClassTemplateSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : CXXRecordDecl(std::move(ast_), decl_) {}

PASTA_DEFINE_DERIVED_OPERATORS(ClassTemplateSpecializationDecl, ClassTemplatePartialSpecializationDecl)
// 1: ClassTemplateSpecializationDecl::Profile
::pasta::Token ClassTemplateSpecializationDecl::ExternToken(void) const {
  auto val = u.ClassTemplateSpecializationDecl->getExternLoc();
  return ast->TokenAt(val);
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::InstantiatedFrom(void) const {
  auto val = u.ClassTemplateSpecializationDecl->getInstantiatedFrom();
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::ClassTemplateDecl *>()) {
      return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::ClassTemplatePartialSpecializationDecl *>()) {
      return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, b_ptr);
    }
  }
  return {};
}

::pasta::Token ClassTemplateSpecializationDecl::PointOfInstantiation(void) const {
  auto val = u.ClassTemplateSpecializationDecl->getPointOfInstantiation();
  return ast->TokenAt(val);
}

TemplateSpecializationKind ClassTemplateSpecializationDecl::SpecializationKind(void) const {
  auto val = u.ClassTemplateSpecializationDecl->getSpecializationKind();
  return static_cast<::pasta::TemplateSpecializationKind>(static_cast<unsigned int>(val));
}

std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ClassTemplateSpecializationDecl::SpecializedTemplateOrPartial(void) const {
  auto val = u.ClassTemplateSpecializationDecl->getSpecializedTemplateOrPartial();
  std::variant<std::monostate, ::pasta::ClassTemplateDecl, ::pasta::ClassTemplatePartialSpecializationDecl> ret;
  if (val) {
    if (auto a_ptr = val.dyn_cast<clang::ClassTemplateDecl *>()) {
      return DeclBuilder::Create<::pasta::ClassTemplateDecl>(ast, a_ptr);
    } else if (auto b_ptr = val.dyn_cast<clang::ClassTemplatePartialSpecializationDecl *>()) {
      return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, b_ptr);
    }
  }
  return {};
}

// 0: ClassTemplateSpecializationDecl::TemplateArgs
// 0: ClassTemplateSpecializationDecl::TemplateInstantiationArgs
::pasta::Token ClassTemplateSpecializationDecl::TemplateKeywordToken(void) const {
  auto val = u.ClassTemplateSpecializationDecl->getTemplateKeywordLoc();
  return ast->TokenAt(val);
}

// 0: ClassTemplateSpecializationDecl::TypeAsWritten
bool ClassTemplateSpecializationDecl::IsClassScopeExplicitSpecialization(void) const {
  auto val = u.ClassTemplateSpecializationDecl->isClassScopeExplicitSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitInstantiationOrSpecialization(void) const {
  auto val = u.ClassTemplateSpecializationDecl->isExplicitInstantiationOrSpecialization();
  return val;
}

bool ClassTemplateSpecializationDecl::IsExplicitSpecialization(void) const {
  auto val = u.ClassTemplateSpecializationDecl->isExplicitSpecialization();
  return val;
}

ClassTemplatePartialSpecializationDecl::ClassTemplatePartialSpecializationDecl(
    std::shared_ptr<ASTImpl> ast_,
    const ::clang::Decl *decl_)
    : ClassTemplateSpecializationDecl(std::move(ast_), decl_) {}

// 1: ClassTemplatePartialSpecializationDecl::Profile
// 1: ClassTemplatePartialSpecializationDecl::AssociatedConstraints
// 0: ClassTemplatePartialSpecializationDecl::InjectedSpecializationType
::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMember(void) const {
  auto val = u.ClassTemplatePartialSpecializationDecl->getInstantiatedFromMember();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "ClassTemplatePartialSpecializationDecl::InstantiatedFromMember can return nullptr!");
  __builtin_unreachable();
}

::pasta::ClassTemplatePartialSpecializationDecl ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate(void) const {
  auto val = u.ClassTemplatePartialSpecializationDecl->getInstantiatedFromMemberTemplate();
  if (val) {
    return DeclBuilder::Create<::pasta::ClassTemplatePartialSpecializationDecl>(ast, val);
  }
  assert(false && "ClassTemplatePartialSpecializationDecl::InstantiatedFromMemberTemplate can return nullptr!");
  __builtin_unreachable();
}

// 0: ClassTemplatePartialSpecializationDecl::TemplateArgsAsWritten
// 0: ClassTemplatePartialSpecializationDecl::TemplateParameters
bool ClassTemplatePartialSpecializationDecl::HasAssociatedConstraints(void) const {
  auto val = u.ClassTemplatePartialSpecializationDecl->hasAssociatedConstraints();
  return val;
}

}  // namespace pasta
#endif  // PASTA_IN_BOOTSTRAP
