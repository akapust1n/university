#ifndef DRAW_H
#define DRAW_H
#include "matrixworks.h"
#include "conversions.h"
eCodeFile ChangeRotation(sModel &renderdata, sMove move);
eCodeFile SetRotation(sModel &renderdata, sMove move);
eCodeFile ChangeScale(sModel &renderdata, double scale);
eCodeFile ChangeShift(sModel &renderdata, sMove move);
eCodeFile update_model_info(sModel &model);
eCodeFile SaveModel(sModel model, sSavedModels &S_models); // не реализована
eCodeFile DelModels(sModel &model, sSavedModels &smodels);
sModel initModel();
sSavedModels initSavedModels();
eCodeFile switchModel(sModel s, sSavedModels d);
#endif // DRAW_H
