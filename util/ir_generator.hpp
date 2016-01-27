#ifndef IR_GENERATOR_INCLUDED
#define IR_GENERATOR_INCLUDED    1
#include <iostream>

#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>

#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/raw_os_ostream.h>

#include <memory>

namespace ir_generator {
  struct Options {
    bool remove_ir_file;
    std::string output_file_path;
    std::ostream& err = std::cerr;
    std::ostream& log = std::cout;
  };

  struct Context {
    std::unique_ptr<llvm::Module> currentModule;
    llvm::LLVMContext &llvmContext = llvm::getGlobalContext();
    llvm::IRBuilder<> Builder = llvm::IRBuilder<>(llvmContext);

    Context(std::string name);

  };

  int print_module(std::string file_path, Context& ctx);
  int generate_example_code(Context& ctx);
}

#endif
