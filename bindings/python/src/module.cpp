#include "bindings.h"

#include <pasta/Util/Init.h>

namespace pasta {
void RegisterAllAST(pybind11::module_&);
};

PYBIND11_MODULE(pypasta, m) {
    static pasta::InitPasta initPasta;
    pasta::RegisterArgumentVector(m);
    pasta::RegisterCompileCommand(m);
    pasta::RegisterFileSystem(m);
    pasta::RegisterFileManager(m);
    pasta::RegisterCompileJob(m);
    pasta::RegisterCompiler(m);

    pasta::RegisterAST(m);
    pasta::RegisterAllAST(m);
}