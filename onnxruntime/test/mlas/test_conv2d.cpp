// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "test_conv2d.h"
#include "test_conv2d_fixture.h"

MlasConv2DTest<false>* MlasTestFixture<MlasConv2DTest<false>>::mlas_tester(nullptr);
MlasConv2DTest<true>* MlasTestFixture<MlasConv2DTest<true>>::mlas_tester(nullptr);

static size_t Conv2dRegistLongExecute() {
  size_t count = MlasLongExecuteTests<MlasConv2DTest<false>>::RegisterLongExecute();
  if (GetMlasThreadPool() != nullptr) {
    count += MlasLongExecuteTests<MlasConv2DTest<true>>::RegisterLongExecute();
  }
  return count;
}

static size_t Conv2dRegistShortExecute() {
  size_t count = Conv2dShortExecuteTest<MlasConv2DTest<false>>::RegisterShortExecuteTests();
  if (GetMlasThreadPool() != nullptr) {
    count += Conv2dShortExecuteTest<MlasConv2DTest<true>>::RegisterShortExecuteTests();
  }
  return count;
}

static bool added_to_main = AddTestRegistor([](bool is_short_execute) {
  return is_short_execute ? Conv2dRegistShortExecute() : Conv2dRegistLongExecute();
});
