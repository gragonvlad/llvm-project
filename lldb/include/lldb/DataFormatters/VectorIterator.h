//===-- VectorIterator.h ----------------------------------------------*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef liblldb_VectorIterator_h_
#define liblldb_VectorIterator_h_

#include "lldb/lldb-forward.h"

#include "lldb/DataFormatters/TypeSynthetic.h"
#include "lldb/Target/ExecutionContext.h"
#include "lldb/Utility/ConstString.h"

namespace lldb_private {
namespace formatters {
class VectorIteratorSyntheticFrontEnd : public SyntheticChildrenFrontEnd {
public:
  VectorIteratorSyntheticFrontEnd(lldb::ValueObjectSP valobj_sp,
                                  ConstString item_name);

  size_t CalculateNumChildren() override;

  lldb::ValueObjectSP GetChildAtIndex(size_t idx) override;

  bool Update() override;

  bool MightHaveChildren() override;

  size_t GetIndexOfChildWithName(const ConstString &name) override;

private:
  ExecutionContextRef m_exe_ctx_ref;
  ConstString m_item_name;
  lldb::ValueObjectSP m_item_sp;
};

} // namespace formatters
} // namespace lldb_private

#endif // liblldb_CF_h_
