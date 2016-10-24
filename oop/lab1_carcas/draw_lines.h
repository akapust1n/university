#ifndef DRAW_LINES_H
#define DRAW_LINES_H
#include "render.h"
#include "canvasworks.h"
#include "conversions.h"
#include <QGraphicsScene>
#include <entrypoint.h>
#include <file_read.h>
void DrawLine(uLinePoints& m, QGraphicsScene* scene);
void DrawEdges(sConvertedPoints* converted, uChangeData data, sModel& mdl);
void ClearScene(QGraphicsScene* dt);



#endif // DRAW_LINES_H
