//------------------------------------------------------------------------------
// Copyright (c) 2016 by contributors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

/*
Author: Chao Ma (mctt90@gmail.com)
This file defines the Loss class, which is also called error
function or objective function.
*/

#ifndef XLEARN_LOSS_FILE_SPLITER_H_
#define XLEARN_LOSS_FILE_SPLITER_H_

#include <vector>

#include "src/base/common.h"
#include "src/data/model_parameters.h"
#include "src/updater/updater.h"

namespace xLearn {

//------------------------------------------------------------------------------
// The Loss is an abstract class, which can be implemented by the real
// loss functions such as cross-entropy loss (cross_entropy_loss.h),
// squared loss (squared_loss.h), hinge loss (hinge_loss.h), etc.
//------------------------------------------------------------------------------
class Loss {
 public:
   // Constructor and Desstructor
   Loss();
   virtual ~Loss() { }

   // Given predictions and labels, return loss value.
   virtual real_t Evalute(const std::vector<real_t>& pred,
                          const std::vector<real_t>& label) = 0;

   // Given data sample and current model, return predictions.
   virtual void Predict(const DMatrix* data_matrix,
                        Model* model,
                        std::vector<real_t>& pred);

   // Given data sample and current model, return gradients.
   virtual void CalcGrad(const DMatrix* data_matrix,
                         Model* model,
                         Updater* updater) = 0;

 protected:
  // The score function, e.g. Linear_Score,
  // FM_Score, FFM_Score, etc.
  Score* score_func_;

 private:
  DISALLOW_COPY_AND_ASSIGN(Loss);
};


} // namespace xLearn

#endif // XLEARN_LOSS_FILE_SPLITER_H_